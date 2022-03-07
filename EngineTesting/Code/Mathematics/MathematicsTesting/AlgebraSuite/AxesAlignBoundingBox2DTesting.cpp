// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 13:55)

#include "AxesAlignBoundingBox2DTesting.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class AxesAlignBoundingBox2<float>;
	template class AxesAlignBoundingBox2<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
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
	Vector2F firstVector{ 3.0f,7.0f };
	Vector2F secondVector{ 5.0f,11.0f };

	AxesAlignBoundingBox2F firstAABB(firstVector,secondVector);

	ASSERT_TRUE(Vector2ToolsF::Approximate(firstAABB.GetMaxPoint(),Vector2F(5.0f,11.0f)));
	ASSERT_TRUE(Vector2ToolsF::Approximate(firstAABB.GetMinPoint(),Vector2F(3.0f,7.0f)));

	AxesAlignBoundingBox2D secondAABB(firstAABB);

	ASSERT_TRUE(Vector2ToolsD::Approximate(secondAABB.GetMaxPoint(),Vector2(5.0,11.0)));
	ASSERT_TRUE(Vector2ToolsD::Approximate(secondAABB.GetMinPoint(),Vector2(3.0,7.0)));

	AxesAlignBoundingBox2F thirdAABB(3.0f,5.0f,1.0f,7.0f);

	ASSERT_TRUE(Vector2ToolsF::Approximate(thirdAABB.GetMaxPoint(),Vector2F(5.0f,7.0f)));
	ASSERT_TRUE(Vector2ToolsF::Approximate(thirdAABB.GetMinPoint(),Vector2F(3.0f,1.0f)));
}

void Mathematics::AxesAlignBoundingBox2DTesting
	::AccessTest()
{
	default_random_engine randomEngine{};
	uniform_real<float> firstRandomDistribution{ -100.0f,100.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector2F firstVector(firstRandomDistribution(randomEngine),firstRandomDistribution(randomEngine));

		uniform_real<float> secondRandomDistribution(firstVector[0],100.0f);
		uniform_real<float> thirdRandomDistribution(firstVector[1],100.0f);

		Vector2F secondVector(secondRandomDistribution(randomEngine),thirdRandomDistribution(randomEngine));

		AxesAlignBoundingBox2F firstAABB(firstVector,secondVector);
		
		ASSERT_TRUE(Vector2ToolsF::Approximate(firstAABB.GetMaxPoint(),secondVector));
	    ASSERT_TRUE(Vector2ToolsF::Approximate(firstAABB.GetMinPoint(),firstVector));
		ASSERT_TRUE(Vector2ToolsF::Approximate(firstAABB.GetCenter(),(firstVector + secondVector) / 2.0f));

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
		Vector2F firstVector(firstRandomDistribution(randomEngine),
			                  firstRandomDistribution(randomEngine));

		uniform_real<float> secondRandomDistribution(firstVector[0],100.0f);
		uniform_real<float> thirdRandomDistribution(firstVector[1],100.0f);

		Vector2F secondVector(secondRandomDistribution(randomEngine),thirdRandomDistribution(randomEngine));

		Vector2F thirdVector(firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine));

		uniform_real<float> fourthRandomDistribution(thirdVector[0],100.0f);
		uniform_real<float> fifthRandomDistribution(thirdVector[1],100.0f);

		Vector2F fourthVector(fourthRandomDistribution(randomEngine),fifthRandomDistribution(randomEngine));
		
		AxesAlignBoundingBox2F firstAABB(firstVector,secondVector);
		AxesAlignBoundingBox2F secondAABB(thirdVector,fourthVector);

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
			AxesAlignBoundingBox2F thirdAABB = FindIntersection(firstAABB,secondAABB);

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

