// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:02)

#ifndef DATABASE_DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H
#define DATABASE_DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H

#include "System/Helper/EnumMacro.h"

#include <iostream>

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

#endif // DATABASE_DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_FLAGS_H
