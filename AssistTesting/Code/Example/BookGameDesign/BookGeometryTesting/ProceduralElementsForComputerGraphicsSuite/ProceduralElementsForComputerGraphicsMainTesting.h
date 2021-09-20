// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/06 23:13)

#ifndef BOOK_GEOMETRY_PROCEDURAL_ELEMENTS_FOR_COMPUTER_GRAPHICS_MAIN_TESTING_H
#define BOOK_GEOMETRY_PROCEDURAL_ELEMENTS_FOR_COMPUTER_GRAPHICS_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookGeometry
{
	class ProceduralElementsForComputerGraphicsMainTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = ProceduralElementsForComputerGraphicsMainTesting;
		using ParentType = UnitTest;

	public:
		explicit ProceduralElementsForComputerGraphicsMainTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // BOOK_GEOMETRY_PROCEDURAL_ELEMENTS_FOR_COMPUTER_GRAPHICS_MAIN_TESTING_H
