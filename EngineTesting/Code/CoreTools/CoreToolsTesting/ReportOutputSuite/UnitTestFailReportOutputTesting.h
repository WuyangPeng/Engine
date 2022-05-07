// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/06 15:07)

#ifndef CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_FAIL_REPORT_OUTPUT_TESTING_H
#define CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_FAIL_REPORT_OUTPUT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class UnitTestFailReportOutputTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(UnitTestFailReportOutputTesting); 

	private:
		void MainTest();
		void ReportOutputTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_REPORT_OUTPUT_SUITE_UNIT_TEST_FAIL_REPORT_OUTPUT_TESTING_H