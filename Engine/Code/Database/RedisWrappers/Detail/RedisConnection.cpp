///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/25 09:27)

#include "Database/DatabaseExport.h"

#include "RedisConnection.h"
#include "RedisReply.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/FieldName.h"
#include "Database/Statement/RedisStatement.h"

using namespace std::literals;

#ifdef DATABASE_USE_REDIS

Database::RedisConnection::RedisConnection(const ConfigurationStrategy& configurationStrategy)
    : configurationStrategy{ configurationStrategy },
      redisContext{ configurationStrategy },
      container{},
      thread{},
      mutex{},
      conditionVariable{},
      isStop{ false }
{
    RedisReply redisReply{ redisContext, "auth " + configurationStrategy.GetDBPassword() };

    SetThread();

    DATABASE_SELF_CLASS_IS_VALID_9;
}

void Database::RedisConnection::SetThread()
{
    std::lock_guard lockGuard{ mutex };

    isStop = false;

    thread = std::thread{ &ClassType::WaitThread, this };
}

Database::RedisConnection::~RedisConnection() noexcept
{
    EXCEPTION_TRY
    {
        Stop();
        Join();
    }
    EXCEPTION_ALL_CATCH(Database)

    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, RedisConnection)

void Database::RedisConnection::ChangeDatabase(const BasisDatabaseContainer& basisDatabaseContainer)
{
    DATABASE_CLASS_IS_VALID_9;

    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    container.emplace_back(basisDatabaseContainer);

    conditionVariable.notify_one();
}

void Database::RedisConnection::Stop()
{
    std::lock_guard lockGuard{ mutex };

    isStop = true;

    conditionVariable.notify_one();
}

void Database::RedisConnection::Join()
{
    if (thread.joinable())
    {
        thread.join();
    }
}

Database::BasisDatabase Database::RedisConnection::GetBasisDatabase(const FieldName& fieldName, const redisReply* redisReply)
{
    switch (fieldName.GetDataType())
    {
        case DataType::String:
            return BasisDatabase{ fieldName.GetFieldName(), std::string{ redisReply->str } };

        case DataType::Int32:
        case DataType::Int32Count:
            return BasisDatabase{ fieldName.GetFieldName(), boost::numeric_cast<int32_t>(redisReply->integer) };

        case DataType::Int64:
        case DataType::Int64Count:
            return BasisDatabase{ fieldName.GetFieldName(), redisReply->integer };

        case DataType::Double:
            return BasisDatabase{ fieldName.GetFieldName(), redisReply->dval };

        case DataType::Bool:
            return BasisDatabase{ fieldName.GetFieldName(), redisReply->integer != 0 };

        default:
            return BasisDatabase{ fieldName.GetFieldName(), ""s };
    }
}

void Database::RedisConnection::WaitThread()
{
    do
    {
        std::unique_lock uniqueLock{ mutex };
        conditionVariable.wait(uniqueLock, [this] {
            return isStop || !container.empty();
        });

        Execution();

    } while (!isStop);
}

void Database::RedisConnection::Execution()
{
    while (!container.empty())
    {
        EXCEPTION_TRY
        {
            const auto basisDatabaseContainer = ExtractNext();

            const auto sql = RedisStatement::GenerateStatement(basisDatabaseContainer);

            RedisReply redisReply{ redisContext, sql };
        }
        EXCEPTION_ALL_CATCH(Database)
    }
}

Database::BasisDatabaseContainer Database::RedisConnection::ExtractNext() noexcept
{
    auto basisDatabaseContainer = container.front();

    container.pop_front();

    return basisDatabaseContainer;
}

Database::BasisDatabaseContainer Database::RedisConnection::SelectOne(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    const auto statement = RedisStatement::GenerateSelectStatement(fieldNameContainer, basisDatabaseContainer);

    RedisReply redisReply{ redisContext, statement };

    BasisDatabaseContainer select{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, basisDatabaseContainer.GetKey() };

    if (const auto* result = redisReply.GetRedisReply();
        result != nullptr)
    {
        switch (result->type)
        {
            case REDIS_REPLY_NIL:
                return select;
            case REDIS_REPLY_INTEGER:
            case REDIS_REPLY_DOUBLE:
            case REDIS_REPLY_BOOL:
            case REDIS_REPLY_STRING:
                select.Modify(GetBasisDatabase(fieldNameContainer.at(0), result));
                break;
            case REDIS_REPLY_ARRAY:
            {
                for (auto i = 0u; i < result->elements; ++i)
                {
                    select.Modify(GetBasisDatabase(fieldNameContainer.at(i), *result->element));
                }
            }
            break;
            default:
                break;
        }
    }

    return select;
}

Database::RedisConnection::ResultContainer Database::RedisConnection::SelectAll(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    const auto statement = RedisStatement::GenerateSelectStatement(fieldNameContainer, basisDatabaseContainer);

    RedisReply redisReply{ redisContext, statement };

    ResultContainer resultContainer{};

    BasisDatabaseContainer select{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, basisDatabaseContainer.GetKey() };

    if (const auto* result = redisReply.GetRedisReply();
        result != nullptr)
    {
        switch (result->type)
        {
            case REDIS_REPLY_INTEGER:
            case REDIS_REPLY_DOUBLE:
            case REDIS_REPLY_BOOL:
            case REDIS_REPLY_STRING:
                select.Modify(GetBasisDatabase(fieldNameContainer.at(0), result));
                break;
            case REDIS_REPLY_ARRAY:
            {
                for (auto i = 0u; i < result->elements; ++i)
                {
                    select.Modify(GetBasisDatabase(fieldNameContainer.at(i), *result->element));
                }
            }
            break;
            case REDIS_REPLY_NIL:
            default:
                return resultContainer;
        }
    }

    resultContainer.emplace_back(select);

    return resultContainer;
}

#endif  // DATABASE_USE_REDIS