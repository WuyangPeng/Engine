// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.0.0.1 (2019/09/29 14:44)

#ifndef BOOK_TEST_DRIVE_TESTING_HELPER_H
#define BOOK_TEST_DRIVE_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace BookTestDrive
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites(); 

		void AddTestDrivenDevelopmentByExampleSuite();

		void AddTestDrivenDevelopmentAPracticalGuideSuite();

		void AddTestDrivenPracticalTDDAndAcceptanceTDDForJaveDevelopersSuite();

		void AddGrowingObjectOrientedSoftwareGuidedByTestsSuite();
	
	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // BOOK_TEST_DRIVE_TESTING_HELPER_H