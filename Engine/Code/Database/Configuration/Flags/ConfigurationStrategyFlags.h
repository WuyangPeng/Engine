///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 16:23)

#ifndef DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H
#define DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H

#include "System/Helper/EnumOperator.h"

namespace Database
{
    enum class WrappersStrategy
    {
        Null = 0,
        Mysql = 1 << 0,
        MysqlConnector = 1 << 1,
        MysqlBoost = 1 << 2,
        SqlServer = 1 << 3,
        SQLite = 1 << 4,
        PostgreSQL = 1 << 5,
        Oracle = 1 << 6,
        FlatFile = 1 << 7,
        MariaDB = 1 << 8,
        Mongo = 1 << 9,
        Redis = 1 << 10,
    };
}

#endif  // DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H
