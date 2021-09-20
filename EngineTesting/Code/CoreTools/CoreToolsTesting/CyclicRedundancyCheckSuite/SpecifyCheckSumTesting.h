// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:51)

#ifndef CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SPECIFY_CHECK_SUM_TESTING_H
#define CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SPECIFY_CHECK_SUM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class SpecifyCheckSumTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SpecifyCheckSumTesting);

	private:
		void MainTest();
		void SumTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_CYCLIC_REDUNDANCY_CHECK_SUITE_SPECIFY_CHECK_SUM_TESTING_H
