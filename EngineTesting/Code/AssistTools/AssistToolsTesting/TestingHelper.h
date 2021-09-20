// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:03)

#ifndef ASSIST_TOOLS_TESTING_HTESTING_HELPER_H
#define ASSIST_TOOLS_TESTING_HTESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace AssistTools
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper);
	
		  int DoRun() override;			

	private:
		void AddSuites();	

		void AddMacroSuite(); 
		void AddGenerateProjectsSuite(); 
		void AddFeaturesImporterSuite(); 
		void AddBmpColorToGraySuite(); 
		void AddBmpToWmtfSuite(); 
		void AddWmfxCompilerSuite(); 

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // ASSIST_TOOLS_TESTING_HTESTING_HELPER_H