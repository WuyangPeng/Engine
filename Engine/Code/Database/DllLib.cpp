// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 09:31)

// ���ݿ⣨Database��λ������ĵ����㣬ֻ������������е�System��CoreTools�⣬
// ��ʹ��boost��stlsoft���������ݿ���صĹ��߿⡣
// ��Ҫ��MySQL��SQL Server��һ��ƽ���ļ����ݿ���з�װ��

// ���ݿ��������ģ�飺
// 1.  Macro���꣩
// 2.  Configuration�����ã�
// 3.  SqlInterface��Sql�ӿڣ�
// 4.  Statement����䣩
// 5.  MysqlConnectorWrappers��Mysql Connector ��װ����
// 6.  SqlServerWrappers��Sql Server ��װ����
// 7.  SQLiteWrappers��SQLite ��װ����
// 8.  PostgreSQL��PostgreSQL ��װ����
// 9.  Oracle��Oracle ��װ����
// 10. FlatFileWrappers��ƽ���ļ���װ����

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



 
