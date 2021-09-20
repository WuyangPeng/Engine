// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 17:18)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_SUITE_RESOURCE_MANAGER_TESTING_H
#define CORE_TOOLS_RESOURCE_MANAGER_SUITE_RESOURCE_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class ResourceManagerTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ResourceManagerTesting);

	private:
		void MainTest() noexcept; 

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_SUITE_RESOURCE_MANAGER_TESTING_H