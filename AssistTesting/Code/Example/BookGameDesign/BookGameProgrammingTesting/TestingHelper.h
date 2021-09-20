// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.0.0.1 (2019/09/28 20:16)

#ifndef BOOK_GAME_PROGRAMMING_TESTING_HELPER_H
#define BOOK_GAME_PROGRAMMING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace BookGameProgramming
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites(); 

		void AddGameProgrammingGemsSuite();

		void AddGameProgrammingGems1Suite(Suite& gameProgrammingGemsSuite);

		void AddGameProgrammingGems2Suite(Suite& gameProgrammingGemsSuite);

		void AddGameProgrammingGems3Suite(Suite& gameProgrammingGemsSuite);

		void AddGameProgrammingGems4Suite(Suite& gameProgrammingGemsSuite);

		void AddGameProgrammingGems5Suite(Suite& gameProgrammingGemsSuite);

		void AddGameProgrammingGems6Suite(Suite& gameProgrammingGemsSuite);

		void AddGameProgrammingGems7Suite(Suite& gameProgrammingGemsSuite);

		void AddGameProgrammingPatternsSuite();
	
	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // BOOK_GAME_PROGRAMMING_TESTING_HELPER_H