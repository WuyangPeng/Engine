// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 14:05)

#include "Box2Testing.h"
#include "Mathematics/Objects2D/Box2Detail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::vector;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Box2<float>;
	template class Box2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Box2Testing) 

void Mathematics::Box2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BoxTest);
}

void Mathematics::Box2Testing
	::BoxTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D center(firstRandomDistribution(generator),firstRandomDistribution(generator));

		DoubleVector2D firstAxis(firstRandomDistribution(generator),firstRandomDistribution(generator));

		DoubleVector2D secondAxis(firstRandomDistribution(generator),firstRandomDistribution(generator));

		double firstExtent = DoubleVector2DTools::VectorMagnitude(firstAxis);
		double secondExtent = DoubleVector2DTools::VectorMagnitude(secondAxis);

		DoubleVector2D thirdAxis(firstAxis);
		DoubleVector2D fourthAxis(secondAxis);

		thirdAxis.Normalize();
		fourthAxis.Normalize();

		DoubleBox2 box(center,thirdAxis,fourthAxis,firstExtent,secondExtent);

		ASSERT_TRUE(DoubleVector2DTools::Approximate(box.GetCenter(),center));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(box.GetAxis0(),thirdAxis));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(box.GetAxis1(),fourthAxis));
		ASSERT_APPROXIMATE(box.GetExtent0(),firstExtent,1e-10);
		ASSERT_APPROXIMATE(box.GetExtent1(),secondExtent,1e-10);

		vector<DoubleVector2D> vertex = box.ComputeVertices();

		ASSERT_TRUE(DoubleVector2DTools::Approximate(vertex[0],center - firstAxis - secondAxis));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(vertex[1],center + firstAxis - secondAxis));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(vertex[2],center + firstAxis + secondAxis));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(vertex[3],center - firstAxis + secondAxis));
	}
}

