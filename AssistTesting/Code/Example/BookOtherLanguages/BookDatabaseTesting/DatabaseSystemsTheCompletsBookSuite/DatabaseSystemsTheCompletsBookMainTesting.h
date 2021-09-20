// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.0 (2020/04/05 13:38)

#ifndef BOOK_DATABASE_DATABASE_SYSTEM_IMPLEMENTATION_SUITE_MAIN_TESTING_H
#define BOOK_DATABASE_DATABASE_SYSTEM_IMPLEMENTATION_SUITE_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookDatabase
{
	class DatabaseSystemsTheCompletsBookMainTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = DatabaseSystemsTheCompletsBookMainTesting;
		using ParentType = UnitTest;

	public:
		explicit DatabaseSystemsTheCompletsBookMainTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // BOOK_DATABASE_DATABASE_SYSTEM_IMPLEMENTATION_SUITE_MAIN_TESTING_H