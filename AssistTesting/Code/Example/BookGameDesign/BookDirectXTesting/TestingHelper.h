// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.0.0.1 (2019/09/28 19:50)

#ifndef BOOK_DIRECTX_TESTING_HELPER_H
#define BOOK_DIRECTX_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace BookDirectX
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites(); 

		void AddIntroductionTo3DGameProgrammingWithDirectX90cSuite();

		void AddAdvanced3DGameProgrammingWithDirectX10Suite();

		void AddGameCodingCompleteSuite();

		void AddMultiplayerGameProgrammingSuite();

		void AddBeginningGameProgrammingSuite();

		void AddRealTimeRenderingTricksAndTechniquesInDirectXSuite();

		void AddAdvancedAnimationWithDirectSuite();

		void AddProgrammingRolePlayingGamesWithDirectXSuite();

		void AddRickOfTheWindowsGameProgrammingGuruSuite();

		void AddTricksOfThe3DGameProgrammingGurusSuite();

		void AddGameProgrammingAllInOneSuite();
	
	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // BOOK_DIRECTX_TESTING_HELPER_H