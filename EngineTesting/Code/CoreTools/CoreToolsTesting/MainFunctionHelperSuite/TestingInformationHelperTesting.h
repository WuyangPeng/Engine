// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 17:06)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_TESTING_INFORMATION_HELPER_TESTING_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_TESTING_INFORMATION_HELPER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class TestingInformationHelperTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(TestingInformationHelperTesting);

	private:
		void MainTest();
		void InformationTest();
		void SuiteExceptionTest();
		void TestingExceptionTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_MAIN_FUNCTION_HELPER_SUITE_TESTING_INFORMATION_HELPER_TESTING_H