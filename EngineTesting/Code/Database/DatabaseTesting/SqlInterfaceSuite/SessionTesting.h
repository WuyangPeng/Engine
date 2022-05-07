// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.5 (2020/03/16 18:46)

#ifndef DATABASE_TESTING_SQL_INTERFACE_SUITE_SESSION_TESTING_H
#define DATABASE_TESTING_SQL_INTERFACE_SUITE_SESSION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Database
{
	class SessionTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SessionTesting);

	private:
		void MainTest();

		void NullSessionTest();

		void DoRunUnitTest() override;
	};
}

#endif // DATABASE_TESTING_SQL_INTERFACE_SUITE_SESSION_TESTING_H