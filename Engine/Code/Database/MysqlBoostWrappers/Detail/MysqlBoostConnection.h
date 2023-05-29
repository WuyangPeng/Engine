///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/23 15:34)

#ifndef DATABASE_MYSQL_BOOST_WRAPPERS_MYSQL_BOOST_CONNECTION_H
#define DATABASE_MYSQL_BOOST_WRAPPERS_MYSQL_BOOST_CONNECTION_H

#include "Database/DatabaseDll.h"

#include "System/Helper/PragmaWarning/Mysql.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <deque>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MysqlBoostConnection final
    {
    public:
        using ClassType = MysqlBoostConnection;
        using ResultContainer = std::vector<BasisDatabaseManager>;
        using FieldNameContainer = std::vector<DatabaseField>;

    public:
        explicit MysqlBoostConnection(ConfigurationStrategy configurationStrategy);
        ~MysqlBoostConnection() noexcept;
        MysqlBoostConnection(const MysqlBoostConnection& rhs) = delete;
        MysqlBoostConnection& operator=(const MysqlBoostConnection& rhs) = delete;
        MysqlBoostConnection(MysqlBoostConnection&& rhs) noexcept = delete;
        MysqlBoostConnection& operator=(MysqlBoostConnection&& rhs) noexcept = delete;

    public:
        CLASS_INVARIANT_DECLARE;

        void ChangeDatabase(const BasisDatabaseManager& basisDatabaseContainer);

        NODISCARD BasisDatabaseManager SelectOne(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer);
        NODISCARD ResultContainer SelectAll(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer);

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

        NODISCARD static BasisDatabase GetBasisDatabase(const DatabaseField& fieldName, const boost::mysql::field_view& rowView);
        NODISCARD static boost::asio::ssl::context CreateContext();

    private:
        ConfigurationStrategy configurationStrategy;
        boost::asio::io_context context;
        boost::asio::ssl::context sslContext;
        boost::mysql::tcp_ssl_connection connection;

        Container container;
        std::thread thread;
        std::mutex mutex;
        std::condition_variable conditionVariable;
        volatile bool isStop;
    };
}

#endif  // DATABASE_MYSQL_BOOST_WRAPPERS_MYSQL_BOOST_CONNECTION_H