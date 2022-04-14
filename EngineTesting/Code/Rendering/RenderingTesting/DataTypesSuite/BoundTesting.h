// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/03 13:23)

#ifndef RENDERING_DATA_TYPES_SUITE_BOUND_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_BOUND_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
	class BoundTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BoundTesting); 

	private:
		void MainTest();
	    void BaseTest();
	    void GrowToContainTest();
	    void TransformByTest();
	    void ComputeFromDataTest();
	    void LineIntersectionTest();
	    void BoundIntersectionTest();

		void DoRunUnitTest() override; 
	};
}

#endif // RENDERING_DATA_TYPES_SUITE_BOUND_TESTING_H