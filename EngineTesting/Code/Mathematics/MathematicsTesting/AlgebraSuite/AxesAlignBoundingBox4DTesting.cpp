// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 14:08)

#include "AxesAlignBoundingBox4DTesting.h"
#include "Mathematics/Algebra/Vector4DDetail.h"
#include "Mathematics/Algebra/Vector4DToolsDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox4DDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

namespace Mathematics
{
	template class AxesAlignBoundingBox4D<float>;
	template class AxesAlignBoundingBox4D<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,AxesAlignBoundingBox4DTesting) 

void Mathematics::AxesAlignBoundingBox4DTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
}

void Mathematics::AxesAlignBoundingBox4DTesting
	::ConstructionTest()
{	
	FloatVector4D firstVector(3.0f,7.0f,6.0f,6.0f);
	FloatVector4D secondVector(5.0f,11.0f,17.0f,12.0f);

	FloatAxesAlignBoundingBox4D firstAABB(firstVector,secondVector);

	ASSERT_TRUE(FloatVector4DTools::Approximate(firstAABB.GetMaxPoint(),FloatVector4D(5.0f,11.0f,17.0f,12.0f)));
	ASSERT_TRUE(FloatVector4DTools::Approximate(firstAABB.GetMinPoint(),FloatVector4D(3.0f,7.0f,6.0f,6.0f)));

	DoubleAxesAlignBoundingBox4D secondAABB(firstAABB);

	ASSERT_TRUE(DoubleVector4DTools::Approximate(secondAABB.GetMaxPoint(),DoubleVector4D(5.0,11.0,17.0,12.0)));
	ASSERT_TRUE(DoubleVector4DTools::Approximate(secondAABB.GetMinPoint(),DoubleVector4D(3.0,7.0,6.0,6.0)));												  
}


