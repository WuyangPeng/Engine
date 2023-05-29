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
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseField.h"
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

void Database::RedisConnection::ChangeDatabase(const BasisDatabaseManager& basisDatabaseContainer)
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

Database::BasisDatabase Database::RedisConnection::GetBasisDatabase(const DatabaseField& fieldName, const redisReply* redisReply)
{
    switch (fieldName.GetDataType())
    {
        case DataType::String:
            return BasisDatabase{ fieldName.GetFieldName(), std::string{ redisReply->str } };

        case DataType::Int32:
        case DataType::Int32Count:
            return BasisDatabase{ fieldName.GetFieldName(), boost::lexical_cast<int32_t>(redisReply->str) };

        case DataType::Int64:
        case DataType::Int64Count:
            return BasisDatabase{ fieldName.GetFieldName(), boost::lexical_cast<int64_t>(redisReply->str) };

        case DataType::Double:
            return BasisDatabase{ fieldName.GetFieldName(), boost::lexical_cast<double>(redisReply->str) };

        case DataType::Bool:
            return BasisDatabase{ fieldName.GetFieldName(), redisReply->str == "true"s };

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

    } while (!isStop || !container.empty());
}

void Database::RedisConnection::Execution()
{
    if (!container.empty())
    {
        EXCEPTION_TRY
        {
            const auto basisDatabaseContainer = ExtractNext();

            const auto sql = RedisStatement::GenerateStatement(configurationStrategy.GetDBHostName(), basisDatabaseContainer);

            RedisReply redisReply{ redisContext, sql };
        }
        EXCEPTION_ALL_CATCH(Database)
    }
}

Database::BasisDatabaseManager Database::RedisConnection::ExtractNext() noexcept
{
    auto basisDatabaseContainer = container.front();

    container.pop_front();

    return basisDatabaseContainer;
}

Database::BasisDatabaseManager Database::RedisConnection::SelectOne(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    std::unique_lock uniqueLock{ mutex };

    const auto statement = RedisStatement::GenerateSelectStatement(configurationStrategy.GetDBHostName(), fieldNameContainer, basisDatabaseContainer);

    RedisReply redisReply{ redisContext, statement };

    BasisDatabaseManager select{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, basisDatabaseContainer.GetKey() };

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
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26481)

                    select.Modify(GetBasisDatabase(fieldNameContainer.at(i), result->element[i]));

    #include STSTEM_WARNING_POP
                }
            }
            break;
            default:
                break;
        }
    }

    return select;
}

Database::RedisConnection::ResultContainer Database::RedisConnection::SelectAll(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    std::unique_lock uniqueLock{ mutex };

    const auto statement = RedisStatement::GenerateSelectStatement(configurationStrategy.GetDBHostName(), fieldNameContainer, basisDatabaseContainer);

    RedisReply redisReply{ redisContext, statement };

    uniqueLock.unlock();

    ResultContainer resultContainer{};

    BasisDatabaseManager select{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, basisDatabaseContainer.GetKey() };

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
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26481)

                    select.Modify(GetBasisDatabase(fieldNameContainer.at(i), result->element[i]));

    #include STSTEM_WARNING_POP
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