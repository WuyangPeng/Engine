// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 15:18)

#ifndef CONCURRENT_TOOLS_UNIT_TEST_SUITE_SUITE_TESTING_H
#define CONCURRENT_TOOLS_UNIT_TEST_SUITE_SUITE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class SuiteTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SuiteTesting);

	private:
		void MainTest();
		void NameTest();
		void StreamTest();
		void AddTestTest();
		void AddSuiteTest();
		void TestDataTest();

		void DoRunUnitTest() override;
	};
}

#endif // CONCURRENT_TOOLS_UNIT_TEST_SUITE_SUITE_TESTING_H