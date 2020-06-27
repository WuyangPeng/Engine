// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 10:34)

#ifndef DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_USING_H
#define DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_USING_H

#include "Database/DatabaseDll.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/PragmaWarning/MysqlxXdevapi.h"  
 
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

#else // ! DATABASE_USE_MYSQL_CPP_CONNECTOR

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

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif // DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_USING_H
