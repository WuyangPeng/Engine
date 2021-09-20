// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.3 (2020/04/28 0:04)

#ifndef BOOK_CODE_THE_CLEAN_CODER_MAIN_TESTING_H
#define BOOK_CODE_THE_CLEAN_CODER_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookCode
{
	class TheCleanCoderMainTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = TheCleanCoderMainTesting;
		using ParentType = UnitTest;

	public:
		explicit TheCleanCoderMainTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // BOOK_CODE_THE_CLEAN_CODER_MAIN_TESTING_H
