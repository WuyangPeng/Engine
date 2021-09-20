// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.3 (2020/04/28 0:07)

#ifndef BOOK_CODE_TESTING__HELPER_H
#define BOOK_CODE_TESTING__HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace BookCode
{
	class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		using ClassType = TestingHelper;
		using ParentType = CMainFunctionTestingHelper;

	public:
		TestingHelper(int argc, char** argv);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void InitSuite();

		void AddCodeCompleteSuite();
		void AddCleanCodeSuite();
		void AddCodeQualitySuite();
		void AddCodeReadingSuite();
		void AddTheCleanCoderSuite();
		void AddCodeCraftSuite();

		void AddBeautifulCodeSuite();
		void AddTheArtOfReadableCodeSuite();
		void AddWorkingEffectivelyWithLegacyCodeSuite();
		void AddDreamingInCodeSuite();
		void AddIMWrightsHardCodeSuite();
		void AddProgrammingBeyondPracticesSuite();
	};
}

#endif // BOOK_CODE_TESTING__HELPER_H