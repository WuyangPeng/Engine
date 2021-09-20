// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.0 (2020/04/04 22:22)

#ifndef BOOK_DATABASE_A_FIRST_COURSE_IN_DATABASE_SYSTEMS_MAIN_TESTING_H
#define BOOK_DATABASE_A_FIRST_COURSE_IN_DATABASE_SYSTEMS_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookDatabase
{
	class AFirstCourseInDatabaseSystemsMainTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = AFirstCourseInDatabaseSystemsMainTesting;
		using ParentType = UnitTest;

	public:
		explicit AFirstCourseInDatabaseSystemsMainTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // BOOK_DATABASE_A_FIRST_COURSE_IN_DATABASE_SYSTEMS_MAIN_TESTING_H