// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 17:51)

#ifndef DATABASE_TESTING_TESTING_HELPER_H
#define DATABASE_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace Imagics
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 
	
		virtual int DoRun() override;			

	private:
                void AddSuites();	

		void AddMacroSuite();
		void AddBinaryOperationsSuite();
		void AddExtractionSuite();
		void AddFiltersSuite();
		void AddImagesSuite();
		void AddRasterDrawingSuite();
		void AddSegmentersSuite();
		void AddOpenCVSuite();

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // DATABASE_TESTING_TESTING_HELPER_H