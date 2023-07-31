///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 14:24)

#ifndef DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_CONNECTION_H
#define DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_CONNECTION_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

#include <deque>

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MysqlConnectorConnection final
    {
    public:
        using ClassType = MysqlConnectorConnection;
        using ResultContainer = std::vector<BasisDatabaseManager>;
        using FieldNameContainer = std::vector<DatabaseField>;

    public:
        explicit MysqlConnectorConnection(ConfigurationStrategy configurationStrategy);
        ~MysqlConnectorConnection() noexcept;
        MysqlConnectorConnection(const MysqlConnectorConnection& rhs) = delete;
        MysqlConnectorConnection& operator=(const MysqlConnectorConnection& rhs) = delete;
        MysqlConnectorConnection(MysqlConnectorConnection&& rhs) noexcept = delete;
        MysqlConnectorConnection& operator=(MysqlConnectorConnection&& rhs) noexcept = delete;

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

        void SetThread();
        void Stop();
        void Join();

        NODISCARD static BasisDatabase GetBasisDatabase(const DatabaseField& fieldName, const MysqlxValue& rowView);

    private:
        ConfigurationStrategy configurationStrategy;
        MysqlxClient client;
        MysqlxSession session;

        Container container;
        std::thread thread;
        std::mutex mutex;
        std::condition_variable conditionVariable;
        volatile bool isStop;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_CONNECTION_H