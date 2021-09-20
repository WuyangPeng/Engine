// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 18:55)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_INDEX_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_INDEX_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class MinHeapRecordIndexTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MinHeapRecordIndexTesting);

	private:
		void MainTest();
		void IndexTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_DATA_TYPES_SUITE_MIN_HEAP_RECORD_INDEX_TESTING_H