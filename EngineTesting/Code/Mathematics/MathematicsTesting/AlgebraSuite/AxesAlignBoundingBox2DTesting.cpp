// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 13:55)

#include "AxesAlignBoundingBox2DTesting.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2DDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class AxesAlignBoundingBox2D<float>;
	template class AxesAlignBoundingBox2D<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,AxesAlignBoundingBox2DTesting) 

void Mathematics::AxesAlignBoundingBox2DTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(IntersectionTest);
}

void Mathematics::AxesAlignBoundingBox2DTesting
	::ConstructionTest()
{
	FloatVector2D firstVector{ 3.0f,7.0f };
	FloatVector2D secondVector{ 5.0f,11.0f };

	FloatAxesAlignBoundingBox2D firstAABB(firstVector,secondVector);

	ASSERT_TRUE(FloatVector2DTools::Approximate(firstAABB.GetMaxPoint(),FloatVector2D(5.0f,11.0f)));
	ASSERT_TRUE(FloatVector2DTools::Approximate(firstAABB.GetMinPoint(),FloatVector2D(3.0f,7.0f)));

	DoubleAxesAlignBoundingBox2D secondAABB(firstAABB);

	ASSERT_TRUE(DoubleVector2DTools::Approximate(secondAABB.GetMaxPoint(),DoubleVector2D(5.0,11.0)));
	ASSERT_TRUE(DoubleVector2DTools::Approximate(secondAABB.GetMinPoint(),DoubleVector2D(3.0,7.0)));

	FloatAxesAlignBoundingBox2D thirdAABB(3.0f,5.0f,1.0f,7.0f);

	ASSERT_TRUE(FloatVector2DTools::Approximate(thirdAABB.GetMaxPoint(),FloatVector2D(5.0f,7.0f)));
	ASSERT_TRUE(FloatVector2DTools::Approximate(thirdAABB.GetMinPoint(),FloatVector2D(3.0f,1.0f)));
}

void Mathematics::AxesAlignBoundingBox2DTesting
	::AccessTest()
{
	default_random_engine randomEngine{};
	uniform_real<float> firstRandomDistribution{ -100.0f,100.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVector2D firstVector(firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine));

		uniform_real<float> secondRandomDistribution(firstVector[0],100.0f);
		uniform_real<float> thirdRandomDistribution(firstVector[1],100.0f);

		FloatVector2D secondVector(secondRandomDistribution(randomEngine),thirdRandomDistribution(randomEngine));

		FloatAxesAlignBoundingBox2D firstAABB(firstVector,secondVector);
		
		ASSERT_TRUE(FloatVector2DTools::Approximate(firstAABB.GetMaxPoint(),secondVector));
	    ASSERT_TRUE(FloatVector2DTools::Approximate(firstAABB.GetMinPoint(),firstVector));
		ASSERT_TRUE(FloatVector2DTools::Approximate(firstAABB.GetCenter(),(firstVector + secondVector) / 2.0f));

		ASSERT_APPROXIMATE(firstAABB.GetExtentX(),(secondVector[0] - firstVector[0]) / 2.0f, 1e-8f);

		ASSERT_APPROXIMATE(firstAABB.GetExtentY(),(secondVector[1] - firstVector[1]) / 2.0f,1e-8f);
	}
}

void Mathematics::AxesAlignBoundingBox2DTesting
	::IntersectionTest()
{
	default_random_engine randomEngine{};
	uniform_real<float> firstRandomDistribution{ -100.0f,100.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVector2D firstVector(firstRandomDistribution(randomEngine),
			                  firstRandomDistribution(randomEngine));

		uniform_real<float> secondRandomDistribution(firstVector[0],100.0f);
		uniform_real<float> thirdRandomDistribution(firstVector[1],100.0f);

		FloatVector2D secondVector(secondRandomDistribution(randomEngine),thirdRandomDistribution(randomEngine));

		FloatVector2D thirdVector(firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine));

		uniform_real<float> fourthRandomDistribution(thirdVector[0],100.0f);
		uniform_real<float> fifthRandomDistribution(thirdVector[1],100.0f);

		FloatVector2D fourthVector(fourthRandomDistribution(randomEngine),fifthRandomDistribution(randomEngine));
		
		FloatAxesAlignBoundingBox2D firstAABB(firstVector,secondVector);
		FloatAxesAlignBoundingBox2D secondAABB(thirdVector,fourthVector);

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

		if(HasXOverlap(firstAABB,secondAABB) && HasYOverlap(firstAABB,secondAABB))
		{
			ASSERT_TRUE(IsIntersection(firstAABB,secondAABB));
		}
		else
		{
			ASSERT_FALSE(IsIntersection(firstAABB,secondAABB));
		}

		if(IsIntersection(firstAABB,secondAABB))
		{
			FloatAxesAlignBoundingBox2D thirdAABB = FindIntersection(firstAABB,secondAABB);

			ASSERT_TRUE(firstAABB.GetMinPoint()[0] <= thirdAABB.GetMinPoint()[0]);
			ASSERT_TRUE(thirdAABB.GetMaxPoint()[0] <= firstAABB.GetMaxPoint()[0]);
			ASSERT_TRUE(firstAABB.GetMinPoint()[1] <= thirdAABB.GetMinPoint()[1]);
			ASSERT_TRUE(thirdAABB.GetMaxPoint()[1] <= firstAABB.GetMaxPoint()[1]);

			ASSERT_TRUE(secondAABB.GetMinPoint()[0] <= thirdAABB.GetMinPoint()[0]);
			ASSERT_TRUE(thirdAABB.GetMaxPoint()[0] <= secondAABB.GetMaxPoint()[0]);
			ASSERT_TRUE(secondAABB.GetMinPoint()[1] <= thirdAABB.GetMinPoint()[1]);
			ASSERT_TRUE(thirdAABB.GetMaxPoint()[1] <= secondAABB.GetMaxPoint()[1]);
		}
	}
}

