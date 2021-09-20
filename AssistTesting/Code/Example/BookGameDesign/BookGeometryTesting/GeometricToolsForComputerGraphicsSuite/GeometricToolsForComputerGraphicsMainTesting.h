// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/06 23:13)

#ifndef BOOK_GEOMETRY_GEOMETRIC_TOOLS_FOR_COMPUTER_GRAPHICS_SUITE_MAIN_TESTING_H
#define BOOK_GEOMETRY_GEOMETRIC_TOOLS_FOR_COMPUTER_GRAPHICS_SUITE_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookGeometry
{
	class GeometricToolsForComputerGraphicsMainTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = GeometricToolsForComputerGraphicsMainTesting;
		using ParentType = UnitTest;

	public:
		explicit GeometricToolsForComputerGraphicsMainTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // BOOK_GEOMETRY_GEOMETRIC_TOOLS_FOR_COMPUTER_GRAPHICS_SUITE_MAIN_TESTING_H
