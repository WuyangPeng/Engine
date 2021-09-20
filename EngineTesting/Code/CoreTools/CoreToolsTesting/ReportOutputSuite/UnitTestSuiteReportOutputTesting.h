// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 15:07)

#ifndef CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_SUITE_REPORT_OUTPUT_TESTING_H
#define CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_SUITE_REPORT_OUTPUT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class UnitTestSuiteReportOutputTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(UnitTestSuiteReportOutputTesting); 

	private:
		void MainTest();	
		void UnitTestSuiteReportOutputEquilongTest();
		void UnitTestSuiteReportOutputTimeTest();
		void UnitTestSuiteReportOutputTestResultTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_SUITE_REPORT_OUTPUT_TESTING_H