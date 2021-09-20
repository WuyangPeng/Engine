// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 15:34)

#ifndef MATHEMATICS_OBJECTS3D_SUITE_TRIANGLE3_TESTING_H
#define MATHEMATICS_OBJECTS3D_SUITE_TRIANGLE3_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class Triangle3Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Triangle3Testing); 

	private:
		void MainTest();
		void TriangleTest();
	
		virtual void DoRunUnitTest() override; 
	};
}

#endif // MATHEMATICS_OBJECTS3D_SUITE_TRIANGLE3_TESTING_H