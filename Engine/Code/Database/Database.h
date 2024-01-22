/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:29)

#ifndef DATABASE_H
#define DATABASE_H

#include "Configuration/Configuration.h"
#include "DatabaseInterface/DatabaseInterface.h"
#include "FlatFileWrappers/FlatFileWrappers.h"
#include "Helper/Helper.h"
#include "MariaDBWrappers/MariaDBWrappers.h"
#include "MongoWrappers/MongoWrappers.h"
#include "MysqlBoostWrappers/MysqlBoostWrappers.h"
#include "MysqlConnectorWrappers/MysqlConnectorWrappers.h"
#include "MysqlWrappers/MysqlWrappers.h"
#include "OracleWrappers/OracleWrappers.h"
#include "PostgreSqlWrappers/PostgreSqlWrappers.h"
#include "RedisWrappers/RedisWrappers.h"
#include "SQLiteWrappers/SQLiteWrappers.h"
#include "SqlServerWrappers/SqlServerWrappers.h"
#include "Statement/Statement.h"

#endif  // DATABASE_H