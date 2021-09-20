// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:48)

#include "DynamicTestIntersector1Testing.h"
#include "Mathematics/Intersection/DynamicTestIntersector1Detail.h"
#include "Mathematics/Intersection/StaticTestIntersector1Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>

using std::swap;

 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DynamicTestIntersector1Testing)

void Mathematics::DynamicTestIntersector1Testing
::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(IntersectorTest);
}

void Mathematics::DynamicTestIntersector1Testing
	::IntersectorTest()
{
	std::default_random_engine generator;
	std::uniform_real<double> randomDistribution(-100.0,100.0);

	const auto testLoopCount = GetTestLoopCount(); 
	
	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		double u0 = randomDistribution(generator);
		double u1 = randomDistribution(generator);
		double v0 = randomDistribution(generator);
		double v1 = randomDistribution(generator);

		if (u1 < u0)
		{
			swap(u0, u1);
		}

		if (v1 < v0)
		{
			swap(v0, v1);
		}

		double tMax = DoubleMath::FAbs(randomDistribution(generator));
		double speedU = randomDistribution(generator);
		double speedV = randomDistribution(generator);

		DynamicTestIntersector1<double> intersector1(u0, u1, v0, v1, tMax, speedU, speedV);

		ASSERT_APPROXIMATE(u0, intersector1.GetU(0), 1e-10);
		ASSERT_APPROXIMATE(u1, intersector1.GetU(1), 1e-10);
		ASSERT_APPROXIMATE(v0, intersector1.GetV(0), 1e-10);
		ASSERT_APPROXIMATE(v1, intersector1.GetV(1), 1e-10);

		if(u0 <= v1 && v0 <= u1)
		{
			ASSERT_TRUE(intersector1.IsIntersection());
			ASSERT_APPROXIMATE(intersector1.GetFirstTime(), 0.0f, 1e-10);

			u0 += (intersector1.GetLastTime() * speedU);
			u1 += (intersector1.GetLastTime() * speedU);
			v0 += (intersector1.GetLastTime() * speedV);
			v1 += (intersector1.GetLastTime() * speedV);

			StaticTestIntersector1<double> staticIntersector1(u0, u1, v0, v1);
			ASSERT_TRUE(staticIntersector1.IsIntersection());

			u0 += (0.01 * speedU);
			u1 += (0.01 * speedU);
			v0 += (0.01 * speedV);
			v1 += (0.01 * speedV);

			StaticTestIntersector1<double> leaveStaticIntersector1(u0, u1, v0, v1);
			ASSERT_FALSE(leaveStaticIntersector1.IsIntersection());
		}
		else if (intersector1.IsIntersection())
		{
			double lastU0 = u0 + intersector1.GetLastTime() * speedU;
			double lastU1 = u1 + intersector1.GetLastTime() * speedU;
			double lastV0 = v0 + intersector1.GetLastTime() * speedV;
			double lastV1 = v1 + intersector1.GetLastTime() * speedV;

			StaticTestIntersector1<double> lastStaticIntersector1(lastU0, lastU1, lastV0, lastV1);

			ASSERT_TRUE(lastStaticIntersector1.IsIntersection());			

			lastU0 += (0.01 * speedU);
			lastU1 += (0.01 * speedU);
			lastV0 += (0.01 * speedV);
			lastV1 += (0.01 * speedV);

			StaticTestIntersector1<double> leaveLastStaticIntersector1(lastU0, lastU1, lastV0, lastV1);
			ASSERT_FALSE(leaveLastStaticIntersector1.IsIntersection());

			double firstU0 = u0 + intersector1.GetFirstTime() * speedU;
			double firstU1 = u1 + intersector1.GetFirstTime() * speedU;
			double firstV0 = v0 + intersector1.GetFirstTime() * speedV;
			double firstV1 = v1 + intersector1.GetFirstTime() * speedV;

			StaticTestIntersector1<double> firstStaticIntersector1(firstU0, firstU1, firstV0, firstV1);

			ASSERT_TRUE(firstStaticIntersector1.IsIntersection());

			firstU0 -= (0.01 * speedU);
			firstU1 -= (0.01 * speedU);
			firstV0 -= (0.01 * speedV);
			firstV1 -= (0.01 * speedV);

			StaticTestIntersector1<double> leaveFirstStaticIntersector1(firstU0, firstU1, firstV0, firstV1);
			ASSERT_FALSE(leaveFirstStaticIntersector1.IsIntersection());
		}
		else
		{
			ASSERT_THROW_EXCEPTION_1(GetFirstTimeException,intersector1);
			ASSERT_THROW_EXCEPTION_1(GetLastTimeException, intersector1);
		}		
	}
}

void Mathematics::DynamicTestIntersector1Testing
	::GetFirstTimeException(const DynamicTestIntersector1<double>& intersector1)
{
    [[maybe_unused]] auto value = intersector1.GetFirstTime();
}

void Mathematics::DynamicTestIntersector1Testing
	::GetLastTimeException(const DynamicTestIntersector1<double>& intersector1)
{
    [[maybe_unused]] auto value = intersector1.GetLastTime();
}

