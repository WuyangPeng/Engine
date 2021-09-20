// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 13:46)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_MANAGER_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace CoreTools
{
	class ObjectManagerTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ObjectManagerTesting);

	private:
		void MainTest();
		void SucceedTest();
		void ExceptionTest();
		void InsertTest();
	
		void DoRunUnitTest() override;	
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_MANAGER_TESTING_H
