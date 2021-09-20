// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.0.0.1 (2019/09/29 21:40)

#ifndef BOOK_ACTION_SCRIPT_3_TESTING_HELPER_H
#define BOOK_ACTION_SCRIPT_3_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace BookActionScript3
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites(); 		 

		void AddFoundationActionScript3AnimationMakingThingsMoveSuite();

		void AddAdvancedActionScript3AnimationSuite();

		void AddActionScriptForMultiplayerGamesAndVirtualWorldsSuite();

		void AddAdvancedActionScript3WithDesignPatternsSuite();

		void AddAdvancedActionScript3VisualQuickStartGuideSuite();

		void AddActionScript3BibleSuite();

		void AddActionScript3CookbookSuite();
	
	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // BOOK_ACTION_SCRIPT_3_TESTING_HELPER_H