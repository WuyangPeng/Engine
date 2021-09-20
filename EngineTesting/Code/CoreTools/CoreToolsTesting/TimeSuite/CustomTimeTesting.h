// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:39)

#ifndef CONCURRENT_TOOLS_TIME_SUITE_CUSTOM_TIME_TESTING_H
#define CONCURRENT_TOOLS_TIME_SUITE_CUSTOM_TIME_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class CustomTimeTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CustomTimeTesting);

	private:
		void MainTest();
		void TimeTest();
		void DescribeTest();

		void DoRunUnitTest() override;
	};
}

#endif // CONCURRENT_TOOLS_TIME_SUITE_CUSTOM_TIME_TESTING_H