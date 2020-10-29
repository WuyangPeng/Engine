//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 13:36)

#ifndef DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_USING_H
#define DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_USING_H

#include "Database/DatabaseDll.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

    #include "System/Helper/PragmaWarning/MysqlxXdevapi.h"
    #include "System/Helper/UnicodeUsing.h"

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
    class MysqlxSession
    {
    };

    class MysqlxSchema
    {
    };

    class MysqlxCollection
    {
    };

    class MysqlxClient
    {
    };

    class MysqlxDocResult
    {
    };

    class MysqlxDbDoc
    {
    };

    class MysqlxRowResult
    {
    };

    class MysqlxRow
    {
    };

    class MysqlxTable
    {
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_USING_H
