//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 20:21)

#ifndef DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H
#define DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H

#include "System/Helper/EnumMacro.h"

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
    };
}

#endif  // DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H
