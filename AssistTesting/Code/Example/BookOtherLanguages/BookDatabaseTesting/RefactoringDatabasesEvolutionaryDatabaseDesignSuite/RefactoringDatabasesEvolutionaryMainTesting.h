// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.0 (2020/04/05 12:03)

#ifndef BOOK_DATABASE_REFACTORING_DATABASES_EVOLUTIONARY_DATABASE_DESIGN_MAIN_TESTING_H
#define BOOK_DATABASE_REFACTORING_DATABASES_EVOLUTIONARY_DATABASE_DESIGN_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookDatabase
{
	class RefactoringDatabasesEvolutionaryMainTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = RefactoringDatabasesEvolutionaryMainTesting;
		using ParentType = UnitTest;

	public:
		explicit RefactoringDatabasesEvolutionaryMainTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // BOOK_DATABASE_REFACTORING_DATABASES_EVOLUTIONARY_DATABASE_DESIGN_MAIN_TESTING_H