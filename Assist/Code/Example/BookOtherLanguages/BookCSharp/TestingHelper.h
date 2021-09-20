// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.2 (2019/09/29 21:09)

#ifndef BOOK_C_SHARP_TESTING_HELPER_H
#define BOOK_C_SHARP_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace BookCSharp
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites(); 

		void AddBeginningCSharp6ProgrammingWithVisualStudio2015Suite();

		void AddProCSharp2010AndTheNET4PlatformSuite();

		void AddProfessionalCSharp6AndNETCore1Suite();

		void AddEffectiveCSharpSuite();

		void AddMicrosoftVisualCSharp2010StepByStepSuite();

		void AddEssentialCSharp5Suite();
		
		void AddCSharpInDepthSuite();
		
		void AddProgrammingCSharpSuite();

		void AddIllstratedCSharp2012Suite();

		void AddCLRViaCSharpSuite();

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // BOOK_C_SHARP_TESTING_HELPER_H