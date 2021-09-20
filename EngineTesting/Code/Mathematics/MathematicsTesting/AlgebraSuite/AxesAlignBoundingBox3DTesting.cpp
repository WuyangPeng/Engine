// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 13:59)

#include "AxesAlignBoundingBox3DTesting.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox3DDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class AxesAlignBoundingBox3D<float>;
	template class AxesAlignBoundingBox3D<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,AxesAlignBoundingBox3DTesting) 

void Mathematics::AxesAlignBoundingBox3DTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntersectionTest);
}

void Mathematics::AxesAlignBoundingBox3DTesting
	::ConstructionTest()
{	
	FloatVector3D firstVector(3.0f,7.0f,6.0f);
	FloatVector3D secondVector(5.0f,11.0f,17.0f);

	FloatAxesAlignBoundingBox3D firstAABB(firstVector,secondVector);

	ASSERT_TRUE(FloatVector3DTools::Approximate(firstAABB.GetMaxPoint(),FloatVector3D(5.0f,11.0f,17.0f)));
	ASSERT_TRUE(FloatVector3DTools::Approximate(firstAABB.GetMinPoint(),FloatVector3D(3.0f,7.0f,6.0f)));

	DoubleAxesAlignBoundingBox3D secondAABB(firstAABB);

	ASSERT_TRUE(DoubleVector3DTools::Approximate(secondAABB.GetMaxPoint(),DoubleVector3D(5.0,11.0,17.0)));
	ASSERT_TRUE(DoubleVector3DTools::Approximate(secondAABB.GetMinPoint(),DoubleVector3D(3.0,7.0,6.0)));

	FloatAxesAlignBoundingBox3D thirdAABB(3.0f,5.0f,1.0f,7.0f,4.0f,16.0f);

	ASSERT_TRUE(FloatVector3DTools::Approximate(thirdAABB.GetMaxPoint(),FloatVector3D(5.0f,7.0f,16.0f)));
	ASSERT_TRUE(FloatVector3DTools::Approximate(thirdAABB.GetMinPoint(),FloatVector3D(3.0f,1.0f,4.0f)));
												  
}

void Mathematics::AxesAlignBoundingBox3DTesting
	::AccessTest()
{
	default_random_engine randomEngine{};
	uniform_real<float> firstRandomDistribution{ -100.0f,100.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVector3D firstVector(firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine));

		uniform_real<float> secondRandomDistribution(firstVector[0],100.0f);
		uniform_real<float> thirdRandomDistribution(firstVector[1],100.0f);
		uniform_real<float> fourthRandomDistribution(firstVector[2],100.0f);

		FloatVector3D secondVector(secondRandomDistribution(randomEngine),thirdRandomDistribution(randomEngine), fourthRandomDistribution(randomEngine));

		FloatAxesAlignBoundingBox3D firstAABB(firstVector,secondVector);
		
		ASSERT_TRUE(FloatVector3DTools::Approximate(firstAABB.GetMaxPoint(),secondVector));
	    ASSERT_TRUE(FloatVector3DTools::Approximate(firstAABB.GetMinPoint(), firstVector));
		ASSERT_TRUE(FloatVector3DTools::Approximate(firstAABB.GetCenter(),(firstVector + secondVector) / 2.0f));

		ASSERT_APPROXIMATE(firstAABB.GetExtentX(),(secondVector[0] - firstVector[0]) / 2.0f,1e-8f);

		ASSERT_APPROXIMATE(firstAABB.GetExtentY(),(secondVector[1] - firstVector[1]) / 2.0f,1e-8f);

		ASSERT_APPROXIMATE(firstAABB.GetExtentZ(),(secondVector[2] - firstVector[2]) / 2.0f,1e-8f);
	}
}

void Mathematics::AxesAlignBoundingBox3DTesting
	::IntersectionTest()
{
	default_random_engine randomEngine{};
	uniform_real<float> firstRandomDistribution{ -100.0f,100.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVector3D firstVector(firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine));

		uniform_real<float> secondRandomDistribution(firstVector[0],100.0f);
		uniform_real<float> thirdRandomDistribution(firstVector[1],100.0f);
		uniform_real<float> fourthRandomDistribution(firstVector[2],100.0f);

		FloatVector3D secondVector(secondRandomDistribution(randomEngine),thirdRandomDistribution(randomEngine),fourthRandomDistribution(randomEngine));

		FloatVector3D thirdVector(firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine));

		uniform_real<float> fifthRandomDistribution(thirdVector[0],100.0f);
		uniform_real<float> sixthRandomDistribution(thirdVector[1],100.0f);
		uniform_real<float> seventhRandomDistribution(thirdVector[2],100.0f);

		FloatVector3D fourthVector(fifthRandomDistribution(randomEngine),sixthRandomDistribution(randomEngine),seventhRandomDistribution(randomEngine));
		
		FloatAxesAlignBoundingBox3D firstAABB(firstVector,secondVector);
		FloatAxesAlignBoundingBox3D secondAABB(thirdVector,fourthVector);

		if((firstVector[0] <= thirdVector[0] && thirdVector[0] <= secondVector[0]) || (thirdVector[0] <= firstVector[0] && firstVector[0] <= fourthVector[0]))
		{
			ASSERT_TRUE(HasXOverlap(firstAABB,secondAABB));
		}
		else
		{
			ASSERT_FALSE(HasXOverlap(firstAABB,secondAABB));
		}

		if((firstVector[1] <= thirdVector[1] && thirdVector[1] <= secondVector[1]) || (thirdVector[1] <= firstVector[1] && firstVector[1] <= fourthVector[1]))
		{
			ASSERT_TRUE(HasYOverlap(firstAABB,secondAABB));
		}
		else
		{
			ASSERT_FALSE(HasYOverlap(firstAABB,secondAABB));
		}

		if((firstVector[2] <= thirdVector[2] && thirdVector[2] <= secondVector[2]) || (thirdVector[2] <= firstVector[2] && firstVector[2] <= fourthVector[2]))
		{
			ASSERT_TRUE(HasZOverlap(firstAABB,secondAABB));
		}
		else
		{
			ASSERT_FALSE(HasZOverlap(firstAABB,secondAABB));
		}

		if(HasXOverlap(firstAABB,secondAABB) && HasYOverlap(firstAABB,secondAABB) && HasZOverlap(firstAABB,secondAABB))
		{
			ASSERT_TRUE(IsIntersection(firstAABB,secondAABB));
		}
		else
		{
			ASSERT_FALSE(IsIntersection(firstAABB,secondAABB));
		}

		if(IsIntersection(firstAABB,secondAABB))
		{
			FloatAxesAlignBoundingBox3D thirdAABB = FindIntersection(firstAABB,secondAABB);

			ASSERT_TRUE(firstAABB.GetMinPoint()[0] <= thirdAABB.GetMinPoint()[0]);
			ASSERT_TRUE(thirdAABB.GetMaxPoint()[0] <= firstAABB.GetMaxPoint()[0]);
			ASSERT_TRUE(firstAABB.GetMinPoint()[1] <= thirdAABB.GetMinPoint()[1]);
			ASSERT_TRUE(thirdAABB.GetMaxPoint()[1] <= firstAABB.GetMaxPoint()[1]);
			ASSERT_TRUE(firstAABB.GetMinPoint()[2] <= thirdAABB.GetMinPoint()[2]);
			ASSERT_TRUE(thirdAABB.GetMaxPoint()[2] <= firstAABB.GetMaxPoint()[2]);

			ASSERT_TRUE(secondAABB.GetMinPoint()[0] <= thirdAABB.GetMinPoint()[0]);
			ASSERT_TRUE(thirdAABB.GetMaxPoint()[0] <= secondAABB.GetMaxPoint()[0]);
			ASSERT_TRUE(secondAABB.GetMinPoint()[1] <= thirdAABB.GetMinPoint()[1]);
			ASSERT_TRUE(thirdAABB.GetMaxPoint()[1] <= secondAABB.GetMaxPoint()[1]);
			ASSERT_TRUE(secondAABB.GetMinPoint()[2] <= thirdAABB.GetMinPoint()[2]);
			ASSERT_TRUE(thirdAABB.GetMaxPoint()[2] <= secondAABB.GetMaxPoint()[2]);
		}
	}
}

