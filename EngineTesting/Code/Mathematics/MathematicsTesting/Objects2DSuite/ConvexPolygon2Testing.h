// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 13:58)

#ifndef MATHEMATICS_OBJECTS2D_SUITE_CONVEX_POLYGON2_TESTING_H
#define MATHEMATICS_OBJECTS2D_SUITE_CONVEX_POLYGON2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
	class ConvexPolygon2Testing : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ConvexPolygon2Testing);

	private:
		void MainTest();
		void ConvexPolygonTest();
	
		virtual void DoRunUnitTest() override;	
	};
}

#endif // MATHEMATICS_OBJECTS2D_SUITE_CONVEX_POLYGON2_TESTING_H