// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.5 (2020/03/16 18:45)

#ifndef DATABASE_TESTING_SQL_INTERFACE_SUITE_DATABASE_OBJECT_TESTING_H
#define DATABASE_TESTING_SQL_INTERFACE_SUITE_DATABASE_OBJECT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Database
{
	class DatabaseObjectTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(DatabaseObjectTesting);

	private:
		void MainTest();  

		void NullDatabaseObjectTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // DATABASE_TESTING_SQL_INTERFACE_SUITE_DATABASE_OBJECT_TESTING_H