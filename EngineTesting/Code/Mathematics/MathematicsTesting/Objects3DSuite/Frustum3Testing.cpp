///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/30 11:27)

#include "Frustum3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Frustum3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class Frustum3<float>;
    template class Frustum3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Frustum3Testing)

void Mathematics::Frustum3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FrustumTest);
}

void Mathematics::Frustum3Testing::FrustumTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution(-10.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector3D origin(firstRandomDistribution(generator),
                              firstRandomDistribution(generator),
                              firstRandomDistribution(generator));

        const Vector3D firstVector(firstRandomDistribution(generator),
                                   firstRandomDistribution(generator),
                                   firstRandomDistribution(generator));

        const Vector3D secondVector(firstRandomDistribution(generator),
                                    firstRandomDistribution(generator),
                                    firstRandomDistribution(generator));

        const Vector3D thirdVector(firstRandomDistribution(generator),
                                   firstRandomDistribution(generator),
                                   firstRandomDistribution(generator));

        auto directionMin = MathD::FAbs(firstRandomDistribution(generator));
        auto directionMax = directionMin + MathD::FAbs(firstRandomDistribution(generator));

        auto upBound = Vector3ToolsD::GetLength(firstVector);
        auto rightBound = Vector3ToolsD::GetLength(secondVector);

        const auto orthonormalize = Vector3ToolsD::Orthonormalize(firstVector, secondVector, thirdVector, 1e-10);

        const Frustum3D frustum(origin, orthonormalize.GetUVector(), orthonormalize.GetVVector(), orthonormalize.GetWVector(), directionMin, directionMax, upBound, rightBound);

        ASSERT_TRUE(Vector3ToolsD::Approximate(origin, frustum.GetOrigin()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetUVector(), frustum.GetDirectionVector()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetVVector(), frustum.GetUpVector()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetWVector(), frustum.GetRightVector()));
        ASSERT_APPROXIMATE(directionMin, frustum.GetDirectionMin(), 1e-10);
        ASSERT_APPROXIMATE(directionMax, frustum.GetDirectionMax(), 1e-10);
        ASSERT_APPROXIMATE(upBound, frustum.GetUpBound(), 1e-10);
        ASSERT_APPROXIMATE(rightBound, frustum.GetRightBound(), 1e-10);

        ASSERT_APPROXIMATE(directionMax / directionMin, frustum.GetDirectionRatio(), 1e-10);
        ASSERT_APPROXIMATE(-2.0 * upBound * directionMax, frustum.GetMTwoUF(), 1e-10);
        ASSERT_APPROXIMATE(-2.0 * rightBound * directionMax, frustum.GetMTwoRF(), 1e-10);

        auto vertex = frustum.ComputeVertices();

        auto directionScaled = frustum.GetDirectionMin() * frustum.GetDirectionVector();
        auto upScaled = frustum.GetUpBound() * frustum.GetUpVector();
        auto rightScaled = frustum.GetRightBound() * frustum.GetRightVector();

        ASSERT_TRUE(Vector3ToolsD::Approximate(directionScaled - upScaled - rightScaled + frustum.GetOrigin(), vertex.at(0)));
        ASSERT_TRUE(Vector3ToolsD::Approximate(directionScaled - upScaled + rightScaled + frustum.GetOrigin(), vertex.at(1)));
        ASSERT_TRUE(Vector3ToolsD::Approximate(directionScaled + upScaled + rightScaled + frustum.GetOrigin(), vertex.at(2)));
        ASSERT_TRUE(Vector3ToolsD::Approximate(directionScaled + upScaled - rightScaled + frustum.GetOrigin(), vertex.at(3)));

        ASSERT_TRUE(Vector3ToolsD::Approximate((vertex.at(0) - frustum.GetOrigin()) * frustum.GetDirectionRatio() + frustum.GetOrigin(), vertex.at(4), 1e-10));
        ASSERT_TRUE(Vector3ToolsD::Approximate((vertex.at(1) - frustum.GetOrigin()) * frustum.GetDirectionRatio() + frustum.GetOrigin(), vertex.at(5), 1e-10));
        ASSERT_TRUE(Vector3ToolsD::Approximate((vertex.at(2) - frustum.GetOrigin()) * frustum.GetDirectionRatio() + frustum.GetOrigin(), vertex.at(6), 1e-10));
        ASSERT_TRUE(Vector3ToolsD::Approximate((vertex.at(3) - frustum.GetOrigin()) * frustum.GetDirectionRatio() + frustum.GetOrigin(), vertex.at(7), 1e-10));
    }
}
