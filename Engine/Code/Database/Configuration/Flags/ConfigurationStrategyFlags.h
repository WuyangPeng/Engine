///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 15:54)

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
        MariaDb = 1 << 8,
        Mongo = 1 << 9,
        Redis = 1 << 10,
    };
}

#endif  // DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H
