// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/16 10:05)

// ���ݿ⣨Database��λ������ĵ����㣬ֻ������������е�System��CoreTools�⣬
// ��ʹ��boost��stlsoft���������ݿ���صĹ��߿⡣
// ��Ҫ��MySQL��SQL Server��һ��ƽ���ļ����ݿ���з�װ��

// ���ݿ��������ģ�飺
// 1.  Macro���꣩
// 2.  Configuration�����ã�
// 3.  SqlInterface��Sql�ӿڣ�
// 4.  Statement����䣩
// 5.  MysqlWrappers��Mysql ��װ����
// 6.  MysqlConnectorWrappers��Mysql Connector ��װ����
// 7.  SqlServerWrappers��Sql Server ��װ����
// 8.  SQLiteWrappers��SQLite ��װ����
// 9.  PostgreSQL��PostgreSQL ��װ����
// 10. Oracle��Oracle ��װ����
// 11. FlatFileWrappers��ƽ���ļ���װ����

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



 
