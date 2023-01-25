///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 11:12)

#ifndef DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H
#define DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H

#include "System/Helper/EnumOperator.h"

namespace Database
{
    enum class WrappersStrategy
    {
        Null = 0,
        Mysql = 1,
        MysqlConnector = 2,
        SqlServer = 3,
        SQLite = 4,
        PostgreSQL = 5,
        Oracle = 6,
        FlatFile = 7,
        MariaDB = 8,
        Mongo = 9,
        Redis = 10,
    };
}

#endif  // DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H
