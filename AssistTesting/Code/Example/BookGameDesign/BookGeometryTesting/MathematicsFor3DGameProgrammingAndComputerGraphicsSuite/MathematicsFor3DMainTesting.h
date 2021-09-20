// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/06 23:13)

#ifndef BOOK_GEOMETRY_MATHEMATICS_FOR_3D_GAME_PROGRAMMING_AND_COMPUTER_GRAPHICS_MAIN_TESTING_H
#define BOOK_GEOMETRY_MATHEMATICS_FOR_3D_GAME_PROGRAMMING_AND_COMPUTER_GRAPHICS_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookGeometry
{
	class MathematicsFor3DMainTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = MathematicsFor3DMainTesting;
		using ParentType = UnitTest;

	public:
		explicit MathematicsFor3DMainTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // BOOK_GEOMETRY_MATHEMATICS_FOR_3D_GAME_PROGRAMMING_AND_COMPUTER_GRAPHICS_MAIN_TESTING_H
