///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:08)

#include "Database/DatabaseExport.h"

#include "MysqlBoostConnection.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseField.h"
#include "Database/Statement/SqlStatement.h"

using namespace std::literals;

Database::MysqlBoostConnection::MysqlBoostConnection(ConfigurationStrategy configurationStrategy)
    : configurationStrategy{ std::move(configurationStrategy) },
      context{},
      sslContext{ CreateContext() },
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

boost::asio::ssl::context Database::MysqlBoostConnection::CreateContext()
{
    boost::asio::ssl::context context{ boost::asio::ssl::context::tls_client };

    return context;
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

    const auto userName = configurationStrategy.GetDBUserName();
    const auto password = configurationStrategy.GetDBPassword();
    const auto hostName = configurationStrategy.GetDBHostName();

    const boost::mysql::handshake_params params{ userName, password, hostName };

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

void Database::MysqlBoostConnection::ChangeDatabase(const BasisDatabaseManager& basisDatabaseContainer)
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

    } while (!isStop || !container.empty());
}

void Database::MysqlBoostConnection::Execution()
{
    if (!container.empty())
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

Database::BasisDatabaseManager Database::MysqlBoostConnection::ExtractNext() noexcept
{
    auto basisDatabaseContainer = container.front();

    container.pop_front();

    return basisDatabaseContainer;
}

Database::BasisDatabaseManager Database::MysqlBoostConnection::SelectOne(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    std::unique_lock uniqueLock{ mutex };

    boost::mysql::results result{};
    const auto sql = SqlStatement::GenerateSelectOneStatement(fieldNameContainer, basisDatabaseContainer);

    connection.query(sql, result);

    uniqueLock.unlock();

    BasisDatabaseManager select{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, basisDatabaseContainer.GetKey() };

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

Database::MysqlBoostConnection::ResultContainer Database::MysqlBoostConnection::SelectAll(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    std::unique_lock uniqueLock{ mutex };

    boost::mysql::results result{};
    const auto sql = SqlStatement::GenerateSelectAllStatement(fieldNameContainer, basisDatabaseContainer);

    connection.query(sql, result);

    uniqueLock.unlock();

    ResultContainer resultContainer{};

    for (const auto& entity : result.rows())
    {
        BasisDatabaseManager select{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, basisDatabaseContainer.GetKey() };

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

Database::BasisDatabase Database::MysqlBoostConnection::GetBasisDatabase(const DatabaseField& fieldName, const boost::mysql::field_view& rowView)
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

        case DataType::StringArray:
        {
            const std::string column{ rowView.as_string() };
            BasisDatabase::StringArray element{};
            split(element, column, boost::is_any_of("|"), boost::token_compress_off);

            return BasisDatabase{ fieldName.GetFieldName(), element };
        }

        case DataType::Int32Array:
        {
            const std::string column{ rowView.as_string() };
            BasisDatabase::StringArray element{};
            split(element, column, boost::is_any_of("|"), boost::token_compress_off);

            BasisDatabase::Int32Array result{};
            for (const auto& value : element)
            {
                result.emplace_back(boost::lexical_cast<int32_t>(value));
            }
            return BasisDatabase{ fieldName.GetFieldName(), result };
        }

        case DataType::Int64Array:
        {
            const std::string column{ rowView.as_string() };
            BasisDatabase::StringArray element{};
            split(element, column, boost::is_any_of("|"), boost::token_compress_off);

            BasisDatabase::Int64Array result{};
            for (const auto& value : element)
            {
                result.emplace_back(boost::lexical_cast<int64_t>(value));
            }
            return BasisDatabase{ fieldName.GetFieldName(), result };
        }

        case DataType::DoubleArray:
        {
            const std::string column{ rowView.as_string() };
            BasisDatabase::StringArray element{};
            split(element, column, boost::is_any_of("|"), boost::token_compress_off);

            BasisDatabase::DoubleArray result{};
            for (const auto& value : element)
            {
                result.emplace_back(boost::lexical_cast<double>(value));
            }
            return BasisDatabase{ fieldName.GetFieldName(), element };
        }

        default:
            return BasisDatabase{ fieldName.GetFieldName(), ""s };
    }
}

void Database::MysqlBoostConnection::Wait()
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    for (;;)
    {
        std::unique_lock uniqueLock{ mutex };

        if (isStop || container.empty())
        {
            break;
        }
    }
}
