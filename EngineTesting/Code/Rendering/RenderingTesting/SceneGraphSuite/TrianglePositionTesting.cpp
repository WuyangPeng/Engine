// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 11:42)

#include "TrianglePositionTesting.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Rendering/SceneGraph/TrianglePosition.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TrianglePositionTesting) 

void Rendering::TrianglePositionTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);	
}

void Rendering::TrianglePositionTesting
	::InitTest()
{
	TrianglePosition triangleIndex(TrianglePosition::APoint(1.0f,5.0f,6.0f), 
		                           TrianglePosition::APoint(11.0f, 15.0f, 16.0f),
								   TrianglePosition::APoint(21.0f, 25.0f, 26.0f));

	ASSERT_TRUE(Approximate(triangleIndex.GetFirstPosition(), 
		                    TrianglePosition::APoint(1.0f, 5.0f, 6.0f),
							1e-8f));
	ASSERT_TRUE(Approximate(triangleIndex.GetSecondPosition(), 
		                    TrianglePosition::APoint(11.0f, 15.0f, 16.0f),
							1e-8f));
	ASSERT_TRUE(Approximate(triangleIndex.GetThirdPosition(), 
		                    TrianglePosition::APoint(21.0f, 25.0f, 26.0f),
							1e-8f));
}

 