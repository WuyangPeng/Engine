///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/23 15:34)

#include "Database/DatabaseExport.h"

#include "MongoConnection.h"
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

#include <string>

using namespace std::literals;

#ifdef DATABASE_USE_MONGO

Database::MongoConnection::MongoConnection(ConfigurationStrategy configurationStrategy)
    : configurationStrategy{ std::move(configurationStrategy) },
      uri{ CreateMongoURI(this->configurationStrategy) },
      connection{ uri },
      database{ connection[this->configurationStrategy.GetDBHostName()] },
      container{},
      thread{},
      mutex{},
      conditionVariable{},
      isStop{ false }
{
    Init();

    DATABASE_SELF_CLASS_IS_VALID_9;
}

void Database::MongoConnection::Init()
{
    Connect();
    SetThread();
}

void Database::MongoConnection::Connect()
{
    if (!database)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Mongo connection 失败。"))
    }
}

void Database::MongoConnection::SetThread()
{
    std::lock_guard lockGuard{ mutex };

    isStop = false;

    thread = std::thread{ &ClassType::WaitThread, this };
}

Database::MongoConnection::~MongoConnection() noexcept
{
    EXCEPTION_TRY
    {
        Stop();
        Join();
    }
    EXCEPTION_ALL_CATCH(Database)

    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, MongoConnection)

void Database::MongoConnection::ChangeDatabase(const BasisDatabaseManager& basisDatabaseContainer)
{
    DATABASE_CLASS_IS_VALID_9;

    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    container.emplace_back(basisDatabaseContainer);

    conditionVariable.notify_one();
}

void Database::MongoConnection::Stop()
{
    std::lock_guard lockGuard{ mutex };

    isStop = true;

    conditionVariable.notify_one();
}

void Database::MongoConnection::Join()
{
    if (thread.joinable())
    {
        thread.join();
    }
}

void Database::MongoConnection::WaitThread()
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

void Database::MongoConnection::Execution()
{
    if (!container.empty())
    {
        EXCEPTION_TRY
        {
            const auto basisDatabaseContainer = ExtractNext();

            auto collection = database[basisDatabaseContainer.GetDatabaseName().data()];

            switch (basisDatabaseContainer.GetChangeType())
            {
                case ChangeType::Insert:
                    ExecutionInsert(basisDatabaseContainer, collection);
                    break;
                case ChangeType::Update:
                    ExecutionUpdate(basisDatabaseContainer, collection);
                    break;
                case ChangeType::Delete:
                    ExecutionDelete(basisDatabaseContainer, collection);
                    break;
                default:
                    break;
            }
        }
        EXCEPTION_ALL_CATCH(Database)
    }
}

void Database::MongoConnection::ExecutionDelete(const BasisDatabaseManager& basisDatabaseContainer, mongocxx::collection& collection)
{
    auto document = GetKeyDocument(basisDatabaseContainer);

    collection.delete_one(document.extract());
}

bsoncxx::builder::basic::document Database::MongoConnection::GetKeyDocument(const BasisDatabaseManager& basisDatabaseContainer) const
{
    return GetDocument(basisDatabaseContainer.GetKey());
}

bsoncxx::builder::basic::document Database::MongoConnection::GetInsertDocument(const BasisDatabaseManager& basisDatabaseContainer) const
{
    return GetDocument(basisDatabaseContainer.GetDatabase());
}

bsoncxx::builder::basic::document Database::MongoConnection::GetDocument(const BasisDatabaseContainer& objectContainer) const
{
    bsoncxx::builder::basic::document document{};

    for (const auto& value : objectContainer)
    {
        std::string fieldName{ value.GetFieldName() };
        switch (value.GetDataType())
        {
            case DataType::String:
                document.append(bsoncxx::builder::basic::kvp(fieldName, value.GetValue<DataType::String>()));
                break;

            case DataType::Int32:
            case DataType::Int32Count:
                document.append(bsoncxx::builder::basic::kvp(fieldName, value.GetValue<DataType::Int32>()));
                break;

            case DataType::Int64:
            case DataType::Int64Count:
                document.append(bsoncxx::builder::basic::kvp(fieldName, value.GetValue<DataType::Int64>()));
                break;

            case DataType::Double:
                document.append(bsoncxx::builder::basic::kvp(fieldName, value.GetValue<DataType::Double>()));
                break;

            case DataType::Bool:
                document.append(bsoncxx::builder::basic::kvp(fieldName, value.GetValue<DataType::Bool>()));
                break;

            case DataType::StringArray:
                document.append(bsoncxx::builder::basic::kvp(fieldName, value.GetArrayStringValue<DataType::StringArray>()));
                break;

            case DataType::Int32Array:
                document.append(bsoncxx::builder::basic::kvp(fieldName, value.GetArrayStringValue<DataType::Int32Array>()));
                break;

            case DataType::Int64Array:
                document.append(bsoncxx::builder::basic::kvp(fieldName, value.GetArrayStringValue<DataType::Int64Array>()));
                break;

            case DataType::DoubleArray:
                document.append(bsoncxx::builder::basic::kvp(fieldName, value.GetArrayStringValue<DataType::DoubleArray>()));
                break;

            default:
                break;
        }
    }

    return document;
}

void Database::MongoConnection::ExecutionInsert(const BasisDatabaseManager& basisDatabaseContainer, mongocxx::collection& collection)
{
    auto document = GetInsertDocument(basisDatabaseContainer);

    collection.insert_one(document.extract());
}

bsoncxx::builder::basic::document Database::MongoConnection::GetUpdateDocument(const BasisDatabaseManager& basisDatabaseContainer) const
{
    bsoncxx::builder::basic::document document{};

    for (const auto& value : basisDatabaseContainer.GetDatabase())
    {
        std::string fieldName{ value.GetFieldName() };
        switch (value.GetDataType())
        {
            case DataType::String:
                document.append(bsoncxx::builder::basic::kvp("$set", bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp(fieldName, value.GetValue<DataType::String>()))));
                break;

            case DataType::Int32:
            case DataType::Int32Count:
                document.append(bsoncxx::builder::basic::kvp("$set", bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp(fieldName, value.GetValue<DataType::Int32>()))));
                break;

            case DataType::Int64:
            case DataType::Int64Count:
                document.append(bsoncxx::builder::basic::kvp("$set", bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp(fieldName, value.GetValue<DataType::Int64>()))));
                break;

            case DataType::Double:
                document.append(bsoncxx::builder::basic::kvp("$set", bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp(fieldName, value.GetValue<DataType::Double>()))));
                break;

            case DataType::Bool:
                document.append(bsoncxx::builder::basic::kvp("$set", bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp(fieldName, value.GetValue<DataType::Bool>()))));
                break;

            case DataType::StringArray:
                 document.append(bsoncxx::builder::basic::kvp("$set", bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp(fieldName, value.GetArrayStringValue<DataType::StringArray>()))));
                break;

            case DataType::Int32Array:
                document.append(bsoncxx::builder::basic::kvp("$set", bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp(fieldName, value.GetArrayStringValue<DataType::Int32Array>()))));
                break;
                
            case DataType::Int64Array:
                document.append(bsoncxx::builder::basic::kvp("$set", bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp(fieldName, value.GetArrayStringValue<DataType::Int64Array>()))));
                break;
                
            case DataType::DoubleArray:
                document.append(bsoncxx::builder::basic::kvp("$set", bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp(fieldName, value.GetArrayStringValue<DataType::DoubleArray>()))));
                break;

            default:
                break;
        }
    }

    return document;
}

void Database::MongoConnection::ExecutionUpdate(const BasisDatabaseManager& basisDatabaseContainer, mongocxx::collection& collection)
{
    auto keyDocument = GetKeyDocument(basisDatabaseContainer);
    auto updateDocument = GetUpdateDocument(basisDatabaseContainer);

    collection.update_one(keyDocument.extract(), updateDocument.extract());
}

Database::BasisDatabaseManager Database::MongoConnection::ExtractNext() noexcept
{
    auto basisDatabaseContainer = container.front();

    container.pop_front();

    return basisDatabaseContainer;
}

Database::BasisDatabaseManager Database::MongoConnection::SelectOne(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    std::unique_lock uniqueLock{ mutex };

    auto collection = database[basisDatabaseContainer.GetDatabaseName().data()];

    auto keyDocument = GetKeyDocument(basisDatabaseContainer);

    const auto result = collection.find_one(keyDocument.extract());

    uniqueLock.unlock();

    BasisDatabaseManager select{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, basisDatabaseContainer.GetKey() };

    if (result)
    {
        for (const auto& value : result.value())
        {
            if (const auto basisDatabase = GetBasisDatabase(fieldNameContainer, value);
                basisDatabase.GetDataType() != DataType::Null)
            {
                select.Modify(basisDatabase);
            }
        }
    }

    return select;
}

Database::MongoConnection::ResultContainer Database::MongoConnection::SelectAll(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    std::unique_lock uniqueLock{ mutex };

    auto collection = database[basisDatabaseContainer.GetDatabaseName().data()];

    auto keyDocument = GetKeyDocument(basisDatabaseContainer);

    auto result = collection.find(keyDocument.extract());

    uniqueLock.unlock();

    ResultContainer resultContainer{};

    for (const auto& entity : result)
    {
        BasisDatabaseManager select{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, basisDatabaseContainer.GetKey() };

        for (const auto& value : entity)
        {
            if (const auto basisDatabase = GetBasisDatabase(fieldNameContainer, value);
                basisDatabase.GetDataType() != DataType::Null)
            {
                select.Modify(basisDatabase);
            }
        }

        resultContainer.emplace_back(select);
    }

    return resultContainer;
}

Database::BasisDatabase Database::MongoConnection::GetBasisDatabase(const FieldNameContainer& fieldNameContainer, const bsoncxx::document::element& rowView)
{
    const std::string key{ rowView.key() };
    const auto iter = std::ranges::find_if(fieldNameContainer, [key](const auto& value) {
        return key == value.GetFieldName();
    });

    if (iter == fieldNameContainer.cend())
    {
        return BasisDatabase{ "nullptr" };
    }

    switch (iter->GetDataType())
    {
        case DataType::String:
        {
            const std::string result{ rowView.get_string().value };
            return BasisDatabase{ iter->GetFieldName(), result };
        }

        case DataType::Int32:
        case DataType::Int32Count:
            return BasisDatabase{ iter->GetFieldName(), rowView.get_int32() };

        case DataType::Int64:
        case DataType::Int64Count:
            return BasisDatabase{ iter->GetFieldName(), rowView.get_int64() };

        case DataType::Double:
            return BasisDatabase{ iter->GetFieldName(), rowView.get_double().value };

        case DataType::Bool:
            return BasisDatabase{ iter->GetFieldName(), rowView.get_bool() };

        case DataType::StringArray:
        {
            const std::string column{ rowView.get_string().value };
            BasisDatabase::StringArray element{};
            split(element, column, boost::is_any_of("|"), boost::token_compress_off);

            return BasisDatabase{ iter->GetFieldName(), element };
        }

        case DataType::Int32Array:
        {
            const std::string column{ rowView.get_string().value };
            BasisDatabase::StringArray element{};
            split(element, column, boost::is_any_of("|"), boost::token_compress_off);

            BasisDatabase::Int32Array result{};
            for (const auto& value : element)
            {
                if (!value.empty())
                {
                    result.emplace_back(boost::lexical_cast<int32_t>(value));
                }
            }

            return BasisDatabase{ iter->GetFieldName(), result };
        }

        case DataType::Int64Array:
        {
            const std::string column{ rowView.get_string().value };
            BasisDatabase::StringArray element{};
            split(element, column, boost::is_any_of("|"), boost::token_compress_off);

            BasisDatabase::Int64Array result{};
            for (const auto& value : element)
            {
                if (!value.empty())
                {
                    result.emplace_back(boost::lexical_cast<int64_t>(value));
                }
            }

            return BasisDatabase{ iter->GetFieldName(), result };
        }

        case DataType::DoubleArray:
        {
            const std::string column{ rowView.get_string().value };
            BasisDatabase::StringArray element{};
            split(element, column, boost::is_any_of("|"), boost::token_compress_off);

            BasisDatabase::DoubleArray result{};
            for (const auto& value : element)
            {
                if (!value.empty())
                {
                    result.emplace_back(boost::lexical_cast<double>(value));
                }
            }

            return BasisDatabase{ iter->GetFieldName(), element };
        }

        default:
            return BasisDatabase{ iter->GetFieldName(), ""s };
    }
}

std::string Database::MongoConnection::CreateMongoURI(const ConfigurationStrategy& configurationStrategy)
{
    return "mongodb://" + configurationStrategy.GetDBUserName() + ":" + configurationStrategy.GetDBPassword() + "@" + configurationStrategy.GetIp() + ":" + std::to_string(configurationStrategy.GetPort()) + "/" + configurationStrategy.GetDBHostName();
}

#endif  // DATABASE_USE_MONGO
