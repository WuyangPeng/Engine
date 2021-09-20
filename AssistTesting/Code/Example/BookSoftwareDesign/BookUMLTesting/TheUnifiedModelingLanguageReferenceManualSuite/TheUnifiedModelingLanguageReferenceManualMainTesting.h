// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/05 18:09)

#ifndef BOOK_UML_THE_UNIFIED_MODELING_LANGUAGE_REFERENCE_MANUAL_MAIN_TESTING_H
#define BOOK_UML_THE_UNIFIED_MODELING_LANGUAGE_REFERENCE_MANUAL_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookUML
{
	class TheUnifiedModelingLanguageReferenceManualMainTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = TheUnifiedModelingLanguageReferenceManualMainTesting;
		using ParentType = UnitTest;

	public:
		explicit TheUnifiedModelingLanguageReferenceManualMainTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // BOOK_UML_THE_UNIFIED_MODELING_LANGUAGE_REFERENCE_MANUAL_MAIN_TESTING_H
