// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 10:18)

#ifndef DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_FWD_H
#define DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_FWD_H

namespace mysqlx
{
	inline namespace abi2
	{
		inline namespace r0
		{
			class Session;
			class Schema;
			class Collection;
			class Client;
			class DocResult;
			class DbDoc;
			class RowResult;
			class Row;
			class Table;
		}
	}
}

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
 
#endif // DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_FWD_H
