/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:42)

#ifndef DATABASE_MONGO_WRAPPERS_MONGO_CONNECTION_H
#define DATABASE_MONGO_WRAPPERS_MONGO_CONNECTION_H

#include "Database/DatabaseDll.h"

#include "System/Helper/PragmaWarning/Mongocxx.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <condition_variable>
#include <deque>
#include <mutex>
#include <thread>

#ifdef DATABASE_USE_MONGO

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MongoConnection final
    {
    public:
        using ClassType = MongoConnection;

        using ResultContainer = std::vector<BasisDatabaseManager>;
        using FieldNameContainer = std::vector<DatabaseField>;

    public:
        explicit MongoConnection(ConfigurationStrategy configurationStrategy);
        ~MongoConnection() noexcept;
        MongoConnection(const MongoConnection& rhs) = delete;
        MongoConnection& operator=(const MongoConnection& rhs) = delete;
        MongoConnection(MongoConnection&& rhs) noexcept = delete;
        MongoConnection& operator=(MongoConnection&& rhs) noexcept = delete;

    public:
        CLASS_INVARIANT_DECLARE;

        void ChangeDatabase(const BasisDatabaseManager& basisDatabaseContainer);

        NODISCARD BasisDatabaseManager SelectOne(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer);
        NODISCARD ResultContainer SelectAll(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer);

        void Wait();

    private:
        using Container = std::deque<BasisDatabaseManager>;

    private:
        NODISCARD BasisDatabaseManager ExtractNext() noexcept;

        void WaitThread();
        void Execution();
        void Connect();

        void SetThread();
        void Stop();
        void Join();

        void Init();

        void ExecutionDelete(const BasisDatabaseManager& basisDatabaseContainer, mongocxx::collection& collection);
        void ExecutionInsert(const BasisDatabaseManager& basisDatabaseContainer, mongocxx::collection& collection);
        void ExecutionUpdate(const BasisDatabaseManager& basisDatabaseContainer, mongocxx::collection& collection);

        NODISCARD bsoncxx::builder::basic::document GetKeyDocument(const BasisDatabaseManager& basisDatabaseContainer) const;
        NODISCARD bsoncxx::builder::basic::document GetInsertDocument(const BasisDatabaseManager& basisDatabaseContainer) const;
        NODISCARD bsoncxx::builder::basic::document GetUpdateDocument(const BasisDatabaseManager& basisDatabaseContainer) const;
        NODISCARD bsoncxx::builder::basic::document GetDocument(const BasisDatabaseContainer& objectContainer) const;

        NODISCARD static BasisDatabase GetBasisDatabase(const FieldNameContainer& fieldNameContainer, const bsoncxx::document::element& rowView);
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