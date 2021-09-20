// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 18:56)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class MinHeapRecordTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MinHeapRecordTesting);

	private:
		void MainTest();
		void FloatTest();
		void IntegerTest();
		void DoubleTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_TESTING_H