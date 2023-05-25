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
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"
#include "Database/DatabaseInterface/FieldName.h"
#include "Database/Statement/SqlStatement.h"

using namespace std::literals;

#ifdef DATABASE_USE_MONGO

Database::MongoConnection::MongoConnection(ConfigurationStrategy configurationStrategy)
    : configurationStrategy{ std::move(configurationStrategy) },
      uri{ CreateMongoURI(this->configurationStrategy) },
      connection{ uri },
      database{ connection[configurationStrategy.GetDBHostName()] },
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

void Database::MongoConnection::ChangeDatabase(const BasisDatabaseContainer& basisDatabaseContainer)
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

    } while (!isStop);
}

void Database::MongoConnection::Execution()
{
    while (!container.empty())
    {
        EXCEPTION_TRY
        {
            const auto basisDatabaseContainer = ExtractNext();

            auto collection = database[basisDatabaseContainer.GetDatabaseName()];

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

void Database::MongoConnection::ExecutionDelete(const BasisDatabaseContainer& basisDatabaseContainer, mongocxx::collection& collection)
{
    auto document = GetKeyDocument(basisDatabaseContainer);

    collection.delete_one(document.extract());
}

bsoncxx::builder::basic::document Database::MongoConnection::GetKeyDocument(const BasisDatabaseContainer& basisDatabaseContainer) const
{
    return GetDocument(basisDatabaseContainer.GetKey());
}

bsoncxx::builder::basic::document Database::MongoConnection::GetInsertDocument(const BasisDatabaseContainer& basisDatabaseContainer) const
{
    return GetDocument(basisDatabaseContainer.GetContainer());
}

bsoncxx::builder::basic::document Database::MongoConnection::GetDocument(const BasisDatabaseContainer::ObjectContainer& objectContainer) const
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

            default:
                break;
        }
    }

    return document;
}

void Database::MongoConnection::ExecutionInsert(const BasisDatabaseContainer& basisDatabaseContainer, mongocxx::collection& collection)
{
    auto document = GetInsertDocument(basisDatabaseContainer);

    collection.insert_one(document.extract());
}

bsoncxx::builder::basic::document Database::MongoConnection::GetUpdateDocument(const BasisDatabaseContainer& basisDatabaseContainer) const
{
    bsoncxx::builder::basic::document document{};

    for (const auto& value : basisDatabaseContainer.GetContainer())
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

            default:
                break;
        }
    }

    return document;
}

void Database::MongoConnection::ExecutionUpdate(const BasisDatabaseContainer& basisDatabaseContainer, mongocxx::collection& collection)
{
    auto keyDocument = GetKeyDocument(basisDatabaseContainer);
    auto updateDocument = GetUpdateDocument(basisDatabaseContainer);

    collection.update_one(keyDocument.extract(), updateDocument.extract());
}

Database::BasisDatabaseContainer Database::MongoConnection::ExtractNext() noexcept
{
    auto basisDatabaseContainer = container.front();

    container.pop_front();

    return basisDatabaseContainer;
}

Database::BasisDatabaseContainer Database::MongoConnection::SelectOne(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    auto collection = database[basisDatabaseContainer.GetDatabaseName()];

    auto keyDocument = GetKeyDocument(basisDatabaseContainer);

    const auto result = collection.find_one(keyDocument.extract());

    BasisDatabaseContainer select{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, basisDatabaseContainer.GetKey() };

    if (result)
    {
        auto index = 0;
        for (const auto& value : result.value())
        {
            select.Modify(GetBasisDatabase(fieldNameContainer.at(index), value));

            ++index;
        }
    }

    return select;
}

Database::MongoConnection::ResultContainer Database::MongoConnection::SelectAll(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    auto collection = database[basisDatabaseContainer.GetDatabaseName()];

    auto keyDocument = GetKeyDocument(basisDatabaseContainer);

    auto result = collection.find(keyDocument.extract());

    ResultContainer resultContainer{};

    for (const auto& entity : result)
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

Database::BasisDatabase Database::MongoConnection::GetBasisDatabase(const FieldName& fieldName, const bsoncxx::document::element& rowView)
{
    switch (fieldName.GetDataType())
    {
        case DataType::String:
        {
            const std::string result{ rowView.get_string().value };
            return BasisDatabase{ fieldName.GetFieldName(), result };
        }

        case DataType::Int32:
        case DataType::Int32Count:
            return BasisDatabase{ fieldName.GetFieldName(), rowView.get_int32() };

        case DataType::Int64:
        case DataType::Int64Count:
            return BasisDatabase{ fieldName.GetFieldName(), rowView.get_int64() };

        case DataType::Double:
            return BasisDatabase{ fieldName.GetFieldName(), rowView.get_double().value };

        case DataType::Bool:
            return BasisDatabase{ fieldName.GetFieldName(), rowView.get_bool() };

        default:
            return BasisDatabase{ fieldName.GetFieldName(), ""s };
    }
}

std::string Database::MongoConnection::CreateMongoURI(const ConfigurationStrategy& configurationStrategy)
{
    return "mongodb://" + configurationStrategy.GetIp() + ":" + std::to_string(configurationStrategy.GetPort()) + "?" + configurationStrategy.GetDBUserName() + "=" + configurationStrategy.GetDBPassword();
}

#endif  // DATABASE_USE_MONGO
