///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 14:25)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorConnection.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/FieldName.h"
#include "Database/Statement/SqlStatement.h"

using namespace std::literals;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorConnection::MysqlConnectorConnection(ConfigurationStrategy configurationStrategy)
    : configurationStrategy{ std::move(configurationStrategy) },
      client{ mysqlx::SessionOption::USER,
              configurationStrategy.GetDBUserName(),
              mysqlx::SessionOption::PWD,
              configurationStrategy.GetDBPassword(),
              mysqlx::SessionOption::HOST,
              configurationStrategy.GetIp(),
              mysqlx::SessionOption::PORT,
              configurationStrategy.GetPort(),
              mysqlx::SessionOption::DB,
              configurationStrategy.GetDBHostName(),
              mysqlx::SessionOption::SSL_MODE,
              configurationStrategy.IsUseSSL() ? mysqlx::SSLMode::VERIFY_CA : mysqlx::SSLMode::REQUIRED,
              mysqlx::ClientOption::POOLING,
              configurationStrategy.GetPooling(),
              mysqlx::ClientOption::POOL_MAX_SIZE,
              configurationStrategy.GetPoolMaxSize(),
              mysqlx::ClientOption::POOL_QUEUE_TIMEOUT,
              configurationStrategy.GetPoolQueueTimeout(),
              mysqlx::ClientOption::POOL_MAX_IDLE_TIME,
              configurationStrategy.GetPoolMaxIdleTime() },
      session{ client.getSession() },
      container{},
      thread{},
      mutex{},
      conditionVariable{},
      isStop{ false }
{
    SetThread();

    DATABASE_SELF_CLASS_IS_VALID_9;
}

void Database::MysqlConnectorConnection::SetThread()
{
    std::lock_guard lockGuard{ mutex };

    isStop = false;

    thread = std::thread{ &ClassType::WaitThread, this };
}

Database::MysqlConnectorConnection::~MysqlConnectorConnection() noexcept
{
    EXCEPTION_TRY
    {
        Stop();
        Join();
        session.close();
        client.close();
    }
    EXCEPTION_ALL_CATCH(Database)

    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, MysqlConnectorConnection)

void Database::MysqlConnectorConnection::ChangeDatabase(const BasisDatabaseContainer& basisDatabaseContainer)
{
    DATABASE_CLASS_IS_VALID_9;

    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    container.emplace_back(basisDatabaseContainer);

    conditionVariable.notify_one();
}

void Database::MysqlConnectorConnection::Stop()
{
    std::lock_guard lockGuard{ mutex };

    isStop = true;

    conditionVariable.notify_one();
}

void Database::MysqlConnectorConnection::Join()
{
    if (thread.joinable())
    {
        thread.join();
    }
}

void Database::MysqlConnectorConnection::WaitThread()
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

void Database::MysqlConnectorConnection::Execution()
{
    while (!container.empty())
    {
        EXCEPTION_TRY
        {
            const auto basisDatabaseContainer = ExtractNext();

            const auto sql = SqlStatement::GenerateStatement(basisDatabaseContainer);

            session.sql(sql).execute();
        }
        EXCEPTION_ALL_CATCH(Database)
    }
}

Database::BasisDatabaseContainer Database::MysqlConnectorConnection::ExtractNext() noexcept
{
    auto basisDatabaseContainer = container.front();

    container.pop_front();

    return basisDatabaseContainer;
}

Database::BasisDatabaseContainer Database::MysqlConnectorConnection::SelectOne(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    const auto sql = SqlStatement::GenerateSelectOneStatement(fieldNameContainer, basisDatabaseContainer);

    auto result = session.sql(sql).execute();

    BasisDatabaseContainer select{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, basisDatabaseContainer.GetKey() };

    if (result.hasData())
    {
        const auto row = result.fetchOne();

        for (auto index = 0u; index < row.colCount(); ++index)
        {
            select.Modify(GetBasisDatabase(fieldNameContainer.at(index), row[index]));
        }
    }

    return select;
}

Database::MysqlConnectorConnection::ResultContainer Database::MysqlConnectorConnection::SelectAll(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    const auto sql = SqlStatement::GenerateSelectAllStatement(fieldNameContainer, basisDatabaseContainer);

    auto result = session.sql(sql).execute().fetchAll();

    ResultContainer resultContainer{};

    for (const auto& entity : result)
    {
        BasisDatabaseContainer select{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, basisDatabaseContainer.GetKey() };

        for (auto index = 0u; index < entity.colCount(); ++index)
        {
            select.Modify(GetBasisDatabase(fieldNameContainer.at(index), entity[index]));
        }

        resultContainer.emplace_back(select);
    }

    return resultContainer;
}

Database::BasisDatabase Database::MysqlConnectorConnection::GetBasisDatabase(const FieldName& fieldName, const MysqlxValue& rowView)
{
    switch (fieldName.GetDataType())
    {
        case DataType::String:
        {
            const std::string result{ rowView };
            return BasisDatabase{ fieldName.GetFieldName(), result };
        }

        case DataType::Int32:
        case DataType::Int32Count:
        {
            const int64_t result{ rowView };
            return BasisDatabase{ fieldName.GetFieldName(), boost::numeric_cast<int32_t>(result) };
        }

        case DataType::Int64:
        case DataType::Int64Count:
        {
            const int64_t result{ rowView };
            return BasisDatabase{ fieldName.GetFieldName(), result };
        }

        case DataType::Double:
        {
            const double result{ rowView };
            return BasisDatabase{ fieldName.GetFieldName(), result };
        }

        case DataType::Bool:
        {
            const int64_t result{ rowView };
            return BasisDatabase{ fieldName.GetFieldName(), result != 0 };
        }

        default:
            return BasisDatabase{ fieldName.GetFieldName(), ""s };
    }
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR