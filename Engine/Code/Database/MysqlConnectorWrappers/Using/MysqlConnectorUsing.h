///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 14:19)

#ifndef DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_USING_H
#define DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_USING_H

#include "Database/DatabaseDll.h"

#include "System/Helper/PragmaWarning/MysqlxXdevapi.h"
#include "System/Helper/UnicodeUsing.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

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
    using MysqlxValue = mysqlx::abi2::r0::Value;

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

    class MysqlxValue
    {
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_USING_H
