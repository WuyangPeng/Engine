// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/05 18:09)

#ifndef BOOK_UML_APPLYING_UML_AND_PATTERNS_MAIN_TESTING_H
#define BOOK_UML_APPLYING_UML_AND_PATTERNS_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookUML
{
	class ApplyingUMLAndPatternsMainTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = ApplyingUMLAndPatternsMainTesting;
		using ParentType = UnitTest;

	public:
		explicit ApplyingUMLAndPatternsMainTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // BOOK_UML_APPLYING_UML_AND_PATTERNS_MAIN_TESTING_H
