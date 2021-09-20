// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/05 18:56)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_ARRAY_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_ARRAY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class MinHeapRecordStoredTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MinHeapRecordStoredTesting);

	private:
		void MainTest();
		void FloatTest();
		void IntegerTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_ARRAY_TESTING_H