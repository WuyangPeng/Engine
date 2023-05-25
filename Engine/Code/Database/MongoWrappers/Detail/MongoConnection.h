///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/23 15:34)

#ifndef DATABASE_MONGO_WRAPPERS_MONGO_CONNECTION_H
#define DATABASE_MONGO_WRAPPERS_MONGO_CONNECTION_H

#include "Database/DatabaseDll.h"

#include "System/Helper/PragmaWarning/Mongocxx.h" 
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <deque>

#ifdef DATABASE_USE_MONGO

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MongoConnection final
    {
    public:
        using ClassType = MongoConnection;
        using ResultContainer = std::vector<BasisDatabaseContainer>;
        using FieldNameContainer = std::vector<FieldName>;

    public:
        explicit MongoConnection(ConfigurationStrategy configurationStrategy);
        ~MongoConnection() noexcept;
        MongoConnection(const MongoConnection& rhs) = delete;
        MongoConnection& operator=(const MongoConnection& rhs) = delete;
        MongoConnection(MongoConnection&& rhs) noexcept = delete;
        MongoConnection& operator=(MongoConnection&& rhs) noexcept = delete;

    public:
        CLASS_INVARIANT_DECLARE;

        void ChangeDatabase(const BasisDatabaseContainer& basisDatabaseContainer);

        NODISCARD BasisDatabaseContainer SelectOne(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer);
        NODISCARD ResultContainer SelectAll(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer);

    private:
        using Container = std::deque<BasisDatabaseContainer>;

    private:
        NODISCARD BasisDatabaseContainer ExtractNext() noexcept;

        void WaitThread();
        void Execution();
        void Connect();

        void SetThread();
        void Stop();
        void Join();

        void Init();

        void ExecutionDelete(const BasisDatabaseContainer& basisDatabaseContainer, mongocxx::collection& collection);
        void ExecutionInsert(const BasisDatabaseContainer& basisDatabaseContainer, mongocxx::collection& collection);
        void ExecutionUpdate(const BasisDatabaseContainer& basisDatabaseContainer, mongocxx::collection& collection);

        NODISCARD bsoncxx::builder::basic::document GetKeyDocument(const BasisDatabaseContainer& basisDatabaseContainer) const;
        NODISCARD bsoncxx::builder::basic::document GetInsertDocument(const BasisDatabaseContainer& basisDatabaseContainer) const;
        NODISCARD bsoncxx::builder::basic::document GetUpdateDocument(const BasisDatabaseContainer& basisDatabaseContainer) const;
        NODISCARD bsoncxx::builder::basic::document GetDocument(const BasisDatabaseContainer::ObjectContainer& objectContainer) const;

        NODISCARD static BasisDatabase GetBasisDatabase(const FieldName& fieldName, const bsoncxx::document::element& rowView);
        NODISCARD static std::string CreateMongoURI(const ConfigurationStrategy& configurationStrategy);

    private:
        ConfigurationStrategy configurationStrategy;
        mongocxx::uri uri;
        mongocxx::client connection;
        mongocxx::database database;

        Container container;
        std::thread thread;
        std::mutex mutex;
        std::condition_variable conditionVariable;
        volatile bool isStop;
    };
}

#endif  // DATABASE_USE_MONGO

#endif  // DATABASE_MONGO_WRAPPERS_MONGO_CONNECTION_H