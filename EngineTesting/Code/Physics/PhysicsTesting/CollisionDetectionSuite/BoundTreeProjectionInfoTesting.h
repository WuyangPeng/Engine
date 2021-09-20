// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 16:39)

#ifndef PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_PROJECTION_INFO_TESTING_H
#define PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_PROJECTION_INFO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Physics
{
	class BoundTreeProjectionInfoTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BoundTreeProjectionInfoTesting); 

	private:
		void MainTest();
	    void InitTest();
	
		virtual void DoRunUnitTest() override;
	};
}

#endif // PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_PROJECTION_INFO_TESTING_H