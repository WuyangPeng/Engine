///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/23 15:34)

#include "Database/DatabaseExport.h"

#include "MysqlBoostConnection.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/FieldName.h"
#include "Database/Statement/SqlStatement.h"

using namespace std::literals;

Database::MysqlBoostConnection::MysqlBoostConnection(ConfigurationStrategy configurationStrategy)
    : configurationStrategy{ std::move(configurationStrategy) },
      context{},
      sslContext{ boost::asio::ssl::context::tls_client },
      connection{ context.get_executor(), sslContext },
      container{},
      thread{},
      mutex{},
      conditionVariable{},
      isStop{ false }
{
    Init();

    DATABASE_SELF_CLASS_IS_VALID_9;
}

void Database::MysqlBoostConnection::Init()
{
    try
    {
        Connect();
        SetThread();
    }
    catch (const boost::mysql::error_with_diagnostics& error)
    {
        const auto result = SYSTEM_TEXT("Error: ") +
                            CoreTools::StringConversion::MultiByteConversionStandard(error.what()) +
                            SYSTEM_TEXT("\nServer diagnostics: ") +
                            CoreTools::StringConversion::MultiByteConversionStandard(error.get_diagnostics().server_message()) +
                            SYSTEM_TEXT("\n");

        THROW_EXCEPTION(result)
    }
}

void Database::MysqlBoostConnection::Connect()
{
    boost::asio::ip::tcp::resolver resolver{ context.get_executor() };
    const auto endpoints = resolver.resolve(configurationStrategy.GetIp(), std::to_string(configurationStrategy.GetPort()));

    const boost::mysql::handshake_params params{ configurationStrategy.GetDBUserName(), configurationStrategy.GetDBPassword(), configurationStrategy.GetDBHostName() };

    if (!endpoints.empty())
    {
        connection.connect(*endpoints.begin(), params);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("mysql connection 失败。"))
    }
}

void Database::MysqlBoostConnection::SetThread()
{
    std::lock_guard lockGuard{ mutex };

    isStop = false;

    thread = std::thread{ &ClassType::WaitThread, this };
}

Database::MysqlBoostConnection::~MysqlBoostConnection() noexcept
{
    EXCEPTION_TRY
    {
        Stop();
        Join();
        connection.close();
    }
    EXCEPTION_ALL_CATCH(Database)

    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, MysqlBoostConnection)

void Database::MysqlBoostConnection::ChangeDatabase(const BasisDatabaseContainer& basisDatabaseContainer)
{
    DATABASE_CLASS_IS_VALID_9;

    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    container.emplace_back(basisDatabaseContainer);

    conditionVariable.notify_one();
}

void Database::MysqlBoostConnection::Stop()
{
    std::lock_guard lockGuard{ mutex };

    isStop = true;

    conditionVariable.notify_one();
}

void Database::MysqlBoostConnection::Join()
{
    if (thread.joinable())
    {
        thread.join();
    }
}

void Database::MysqlBoostConnection::WaitThread()
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

void Database::MysqlBoostConnection::Execution()
{
    while (!container.empty())
    {
        EXCEPTION_TRY
        {
            const auto basisDatabaseContainer = ExtractNext();

            boost::mysql::results result{};
            const auto sql = SqlStatement::GenerateStatement(basisDatabaseContainer);

            connection.query(sql, result);
        }
        EXCEPTION_ALL_CATCH(Database)
    }
}

Database::BasisDatabaseContainer Database::MysqlBoostConnection::ExtractNext() noexcept
{
    auto basisDatabaseContainer = container.front();

    container.pop_front();

    return basisDatabaseContainer;
}

Database::BasisDatabaseContainer Database::MysqlBoostConnection::SelectOne(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    boost::mysql::results result{};
    const auto sql = SqlStatement::GenerateSelectOneStatement(fieldNameContainer, basisDatabaseContainer);

    connection.query(sql, result);

    BasisDatabaseContainer select{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, basisDatabaseContainer.GetKey() };

    if (const auto& rows = result.rows();
        !rows.empty())
    {
        auto index = 0;
        for (const auto& value : rows.at(0))
        {
            select.Modify(GetBasisDatabase(fieldNameContainer.at(index), value));

            ++index;
        }
    }

    return select;
}

Database::MysqlBoostConnection::ResultContainer Database::MysqlBoostConnection::SelectAll(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    boost::mysql::results result{};
    const auto sql = SqlStatement::GenerateSelectAllStatement(fieldNameContainer, basisDatabaseContainer);

    connection.query(sql, result);

    ResultContainer resultContainer{};

    for (const auto& entity : result.rows())
    {
        BasisDatabaseContainer select{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, basisDatabaseContainer.GetKey() };

        auto index = 0;
        for (const auto& value : entity)
        {
            select.Modify(GetBasisDatabase(fieldNameContainer.at(index), value));
            ++index;
        }

        resultContainer.emplace_back(select);
    }

    return resultContainer;
}

Database::BasisDatabase Database::MysqlBoostConnection::GetBasisDatabase(const FieldName& fieldName, const boost::mysql::field_view& rowView)
{
    switch (fieldName.GetDataType())
    {
        case DataType::String:
            return BasisDatabase{ fieldName.GetFieldName(), rowView.as_string() };

        case DataType::Int32:
        case DataType::Int32Count:
            return BasisDatabase{ fieldName.GetFieldName(), boost::numeric_cast<int32_t>(rowView.as_int64()) };

        case DataType::Int64:
        case DataType::Int64Count:
            return BasisDatabase{ fieldName.GetFieldName(), rowView.as_int64() };

        case DataType::Double:
            return BasisDatabase{ fieldName.GetFieldName(), rowView.as_double() };

        case DataType::Bool:
            return BasisDatabase{ fieldName.GetFieldName(), rowView.as_int64() != 0 };

        default:
            return BasisDatabase{ fieldName.GetFieldName(), ""s };
    }
}