// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.5 (2020/03/16 18:55)

#ifndef DATABASE_TESTING_SQL_INTERFACE_SUITE_MYSQL_CONNECTOR_SCHEMA_TESTING_H
#define DATABASE_TESTING_SQL_INTERFACE_SUITE_MYSQL_CONNECTOR_SCHEMA_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Database
{
	class MysqlConnectorSchemaTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MysqlConnectorSchemaTesting);

	private:
		void MainTest();

		void SchemaTest();
		void SchemaContainerTest();

		void DoRunUnitTest() override;
	};
}

#endif // DATABASE_TESTING_SQL_INTERFACE_SUITE_MYSQL_CONNECTOR_SCHEMA_TESTING_H