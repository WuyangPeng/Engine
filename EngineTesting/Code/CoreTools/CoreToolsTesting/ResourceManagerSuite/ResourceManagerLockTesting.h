// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 17:18)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_SUITE_RESOURCE_MANAGER_LOCK_TESTING_H
#define CORE_TOOLS_RESOURCE_MANAGER_SUITE_RESOURCE_MANAGER_LOCK_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class ResourceManagerLockTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ResourceManagerLockTesting);

	private:
		void MainTest();
            void LockTest() noexcept;

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_SUITE_RESOURCE_MANAGER_LOCK_TESTING_H