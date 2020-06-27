// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/16 10:05)

// 数据库（Database）位于引擎的第三层，只允许调用引擎中的System、CoreTools库，
// 并使用boost、stlsoft和其他数据库相关的工具库。
// 主要对MySQL、SQL Server和一个平面文件数据库进行封装。

// 数据库包含以下模块：
// 1.  Macro（宏）
// 2.  Configuration（配置）
// 3.  SqlInterface（Sql接口）
// 4.  Statement（语句）
// 5.  MysqlWrappers（Mysql 包装器）
// 6.  MysqlConnectorWrappers（Mysql Connector 包装器）
// 7.  SqlServerWrappers（Sql Server 包装器）
// 8.  SQLiteWrappers（SQLite 包装器）
// 9.  PostgreSQL（PostgreSQL 包装器）
// 10. Oracle（Oracle 包装器）
// 11. FlatFileWrappers（平面文件包装器）

#include "Database/DatabaseExport.h"

#include "Database/Database.h"

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_DATABASE_STATIC

	#include "DllLib.h"

#else // BUILDING_DATABASE_STATIC

	namespace Database
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_DATABASE_STATIC



 
