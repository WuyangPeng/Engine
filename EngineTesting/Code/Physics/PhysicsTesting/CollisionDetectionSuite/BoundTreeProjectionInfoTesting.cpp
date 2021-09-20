// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 16:44)

#include "BoundTreeProjectionInfoTesting.h"
#include "Physics/CollisionDetection/BoundTreeProjectionInfo.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Physics, BoundTreeProjectionInfoTesting) 

void Physics::BoundTreeProjectionInfoTesting
	::MainTest()
{ 
	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}
 
void Physics::BoundTreeProjectionInfoTesting
	::InitTest()
{
	BoundTreeProjectionInfo firstBoundTreeProjectionInfo(5,1.2f);

	ASSERT_EQUAL(firstBoundTreeProjectionInfo.GetTriangle(), 5);
	ASSERT_APPROXIMATE(firstBoundTreeProjectionInfo.GetProjection(), 1.2f, 1e-8f);

	BoundTreeProjectionInfo secondBoundTreeProjectionInfo(1, 2.2f);

	ASSERT_EQUAL(secondBoundTreeProjectionInfo.GetTriangle(), 1);
	ASSERT_APPROXIMATE(secondBoundTreeProjectionInfo.GetProjection(), 2.2f, 1e-8f);

	ASSERT_TRUE(firstBoundTreeProjectionInfo < secondBoundTreeProjectionInfo);
}
 