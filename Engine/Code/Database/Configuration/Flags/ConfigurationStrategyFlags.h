//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 20:21)

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
