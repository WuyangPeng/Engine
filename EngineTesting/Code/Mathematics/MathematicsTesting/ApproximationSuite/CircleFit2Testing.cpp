// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 16:18)

#include "CircleFit2Testing.h"
#include "Mathematics/Approximation/CircleFit2Detail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class CircleFit2<float>;
	template class CircleFit2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, CircleFit2Testing) 

void Mathematics::CircleFit2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::CircleFit2Testing
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(10, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector2D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(DoubleVector2D(firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}
		
		DoubleCircleFit2 firstCircleFit2(vertices,1000,true);
		DoubleCircleFit2 secondCircleFit2(vertices,1000,false);

		DoubleCircle2 firstCircle = firstCircleFit2.GetCircle(); 
		DoubleCircle2 secondCircle = secondCircleFit2.GetCircle();  

		for (int i = 0; i < size; ++i)
		{
			double distance = DoubleVector2DTools::Distance(vertices[i], firstCircle.GetCenter());

			ASSERT_TRUE(distance <= firstCircle.GetRadius() * 2.1);		
			ASSERT_TRUE(distance <= secondCircle.GetRadius() * 2.1);		
		}		
	}
}

