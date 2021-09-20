// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 19:04)

#include "ScribeCircle2InscribeTesting.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Containment/ScribeCircle2InscribeDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>

namespace Mathematics
{
	template class ScribeCircle2Inscribe<float>;
	template class ScribeCircle2Inscribe<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, ScribeCircle2InscribeTesting) 

void Mathematics::ScribeCircle2InscribeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(InscribeTest);
}

void Mathematics::ScribeCircle2InscribeTesting
	::InscribeTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	std::uniform_int<> secondRandomDistribution(10, 50);

	const auto testLoopCount = GetTestLoopCount();  
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D v0(firstRandomDistribution(generator),firstRandomDistribution(generator));
		DoubleVector2D v1(firstRandomDistribution(generator),firstRandomDistribution(generator));
		DoubleVector2D v2(firstRandomDistribution(generator),firstRandomDistribution(generator));

		ScribeCircle2Inscribed scribeCircle2Inscribed(v0, v1, v2);
		
		if (scribeCircle2Inscribed.IsCircleConstructed())
		{
			DoubleCircle2 circle = scribeCircle2Inscribed.GetCircle2();

			DoubleVector2D v0Diff = circle.GetCenter() - v0;
			DoubleVector2D v1Diff = circle.GetCenter() - v1;
			DoubleVector2D v2Diff = circle.GetCenter() - v2;
			DoubleVector2D v10 = v1 - v0;
			DoubleVector2D v02 = v0 - v2;
			DoubleVector2D v21 = v2 - v1;

			v10.Normalize();
			v02.Normalize();
			v21.Normalize();

			double param10 = DoubleVector2DTools::DotProduct(v10, v0Diff);
			double param02 = DoubleVector2DTools::DotProduct(v02, v2Diff);
			double param21 = DoubleVector2DTools::DotProduct(v21, v1Diff);

			ASSERT_APPROXIMATE(DoubleVector2DTools::VectorMagnitude(v0 + param10 * v10 - circle.GetCenter()),
				               circle.GetRadius(), 1e-10);
			ASSERT_APPROXIMATE(DoubleVector2DTools::VectorMagnitude(v2 + param02 * v02 - circle.GetCenter()),
				               circle.GetRadius(), 1e-10);
			ASSERT_APPROXIMATE(DoubleVector2DTools::VectorMagnitude(v1 + param21 * v21 - circle.GetCenter()),
				               circle.GetRadius(), 1e-10);

		}
	}
}

