// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 17:18)

#ifndef CORE_TOOLS_RESOURCE_MANAGER_SUITE_COMMON_DATA_RESOURCE_TESTING_H
#define CORE_TOOLS_RESOURCE_MANAGER_SUITE_COMMON_DATA_RESOURCE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class CommonDataResourceTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CommonDataResourceTesting);

	private:
		void MainTest() noexcept;
		 

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_RESOURCE_MANAGER_SUITE_COMMON_DATA_RESOURCE_TESTING_H