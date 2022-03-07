// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 17:06)

#ifndef MATHEMATICS_ALGEBRA_SUITE_BARYCENTRIC_COORDINATES_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_BARYCENTRIC_COORDINATES_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class BarycentricCoordinatesTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BarycentricCoordinatesTesting); 

	private:
		void MainTest();
		void BarycentricCoordinates3DTest();
		void BarycentricCoordinates4DTest();

		void DoRunUnitTest() override;		
	};
}

#endif // MATHEMATICS_ALGEBRA_SUITE_BARYCENTRIC_COORDINATES_TESTING_H