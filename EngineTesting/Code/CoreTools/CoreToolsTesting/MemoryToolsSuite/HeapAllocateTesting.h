// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 10:37)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SUITE_HEAP_ALLOCATE_TESTING_H
#define CORE_TOOLS_MEMORY_TOOLS_SUITE_HEAP_ALLOCATE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class HeapAllocateTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(HeapAllocateTesting);

	private:
		void MainTest();
		void CharTest();
		void DoubleTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_SUITE_HEAP_ALLOCATE_TESTING_H
