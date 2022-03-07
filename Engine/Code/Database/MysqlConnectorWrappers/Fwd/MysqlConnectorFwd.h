///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 17:55)

#ifndef DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_FWD_H
#define DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_FWD_H

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

namespace mysqlx
{
    inline namespace abi2
    {
        inline namespace r0
        {
            class Session;
            class Schema;
            class Collection;
            class Client;
            class DocResult;
            class DbDoc;
            class RowResult;
            class Row;
            class Table;
        }
    }
}

namespace Database
{
    using MysqlxSession = mysqlx::abi2::r0::Session;
    using MysqlxSchema = mysqlx::abi2::r0::Schema;
    using MysqlxCollection = mysqlx::abi2::r0::Collection;
    using MysqlxClient = mysqlx::abi2::r0::Client;
    using MysqlxDocResult = mysqlx::abi2::r0::DocResult;
    using MysqlxDbDoc = mysqlx::abi2::r0::DbDoc;
    using MysqlxRowResult = mysqlx::abi2::r0::RowResult;
    using MysqlxRow = mysqlx::abi2::r0::Row;
    using MysqlxTable = mysqlx::abi2::r0::Table;
}

#else  // ! DATABASE_USE_MYSQL_CPP_CONNECTOR

namespace Database
{
    class MysqlxSession;
    class MysqlxSchema;
    class MysqlxCollection;
    class MysqlxClient;
    class MysqlxDocResult;
    class MysqlxDbDoc;
    class MysqlxRowResult;
    class MysqlxRow;
    class MysqlxTable;
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_FWD_H
