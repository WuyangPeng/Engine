///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/07 15:58)

#include "DistanceCircle3Circle3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistanceCircle3Circle3Detail.h"
#include "Mathematics/Objects3D/Circle3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include <random>
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::swap;

namespace Mathematics
{
    template class DistanceCircle3Circle3<float>;
    template class DistanceCircle3Circle3<double>;
}

Mathematics::DistanceCircle3Circle3Testing::DistanceCircle3Circle3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, DistanceCircle3Circle3Testing)

void Mathematics::DistanceCircle3Circle3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::DistanceCircle3Circle3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}

void Mathematics::DistanceCircle3Circle3Testing::BaseTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3F lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3F lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();
        const float lhsRadius(MathF::FAbs(randomDistribution(generator)));
        const Vector3OrthonormalBasisF lhsBasis = Vector3ToolsF::GenerateOrthonormalBasis(lhsDirection);

        const Vector3F rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3F rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();
        const float rhsRadius(MathF::FAbs(randomDistribution(generator)));
        const Vector3OrthonormalBasisF rhsBasis = Vector3ToolsF::GenerateOrthonormalBasis(rhsDirection);

        DistanceCircle3Circle3F distance(Circle3F(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(), lhsBasis.GetWVector(), lhsRadius),
                                         Circle3F(rhsOrigin, rhsBasis.GetUVector(), rhsBasis.GetVVector(), rhsBasis.GetWVector(), rhsRadius));

        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::GetZeroTolerance(), 1e-8f);

        distance.SetDifferenceStep(1e-4f);
        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

        distance.SetMaximumIterations(10);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

        distance.SetZeroThreshold(MathF::epsilon);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::epsilon, 1e-8f);

        using ApproximateFunction = bool (*)(const Circle3F& lhs, const Circle3F& rhs, const float epsilon);
        ApproximateFunction approximate = Approximate<float>;

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetLhsCircle(), Circle3F(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(), lhsBasis.GetWVector(), lhsRadius), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetRhsCircle(), Circle3F(rhsOrigin, rhsBasis.GetUVector(), rhsBasis.GetVVector(), rhsBasis.GetWVector(), rhsRadius), 1e-8f);
    }
}

void Mathematics::DistanceCircle3Circle3Testing::StaticTest() noexcept
{
}

void Mathematics::DistanceCircle3Circle3Testing::DynamicTest() noexcept
{
}

void Mathematics::DistanceCircle3Circle3Testing::DerivativeTest() noexcept
{
}

void Mathematics::DistanceCircle3Circle3Testing::IntervalTest() noexcept
{
}
