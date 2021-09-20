// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 14:33)

#include "QuadraticCircleFit2Testing.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Approximation/QuadraticCircleFit2Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class QuadraticCircleFit2<float>;
	template class QuadraticCircleFit2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QuadraticCircleFit2Testing) 

void Mathematics::QuadraticCircleFit2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::QuadraticCircleFit2Testing
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(3, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector2D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(DoubleVector2D(firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		DoubleQuadraticCircleFit2 quadraticCircleFit2(vertices);

		DoubleVector2D center = quadraticCircleFit2.GetCenter();
		double radius = quadraticCircleFit2.GetRadius();
		double eigenValue = quadraticCircleFit2.GetEigenValue();

		ASSERT_TRUE(0.0 <= eigenValue && eigenValue <= 1.0);
		ASSERT_TRUE(0.0 <= radius);		

		for (int i = 0; i < size; ++i)
		{
			double distance = DoubleVector2DTools::Distance(vertices[i], center);

			if (eigenValue <= DoubleMath::GetZeroTolerance())
			{
				ASSERT_TRUE(distance <= radius + DoubleMath::GetZeroTolerance());
			}
			else if (eigenValue <= 0.5)
			{
				ASSERT_TRUE(distance <= radius * 1.5);
			}
			else if (eigenValue <= 1.0)
			{
				ASSERT_TRUE(distance <= radius * 2.0);
			}			
		}	

	}
}

