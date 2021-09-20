// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/05 18:09)

#ifndef BOOK_GEOMETRY_3D_MATH_PRIMER_FOR_GRAPHICS_AND_GAME_DEVELOPMENT_CODE_TESTING_H
#define BOOK_GEOMETRY_3D_MATH_PRIMER_FOR_GRAPHICS_AND_GAME_DEVELOPMENT_CODE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookGeometry
{
	class ThreeDMathPrimerForGraphicsAndGameDevelopmentCodeTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = ThreeDMathPrimerForGraphicsAndGameDevelopmentCodeTesting;
		using ParentType = UnitTest;

	public:
		explicit ThreeDMathPrimerForGraphicsAndGameDevelopmentCodeTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // BOOK_GEOMETRY_3D_MATH_PRIMER_FOR_GRAPHICS_AND_GAME_DEVELOPMENT_CODE_TESTING_H
