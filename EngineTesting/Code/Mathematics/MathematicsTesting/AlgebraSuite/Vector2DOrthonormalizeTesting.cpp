///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:58)

#include "Vector2DOrthonormalizeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2OrthonormalizeDetail.h"
#include "Mathematics/Algebra/Vector2Tools.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Vector2Orthonormalize<float>;
    template class Vector2Orthonormalize<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Vector2OrthonormalizeTesting)

void Mathematics::Vector2OrthonormalizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalizeTest);
}

void Mathematics::Vector2OrthonormalizeTesting::OrthonormalizeTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution{ -10.0, 10.0 };
    const uniform_real<float> secondRandomDistribution{ -10.0f, 10.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 firstVector(firstRandomDistribution(generator),
                            firstRandomDistribution(generator));
        Vector2 secondVector(firstRandomDistribution(generator),
                             firstRandomDistribution(generator));

        Vector2F thirdVector(secondRandomDistribution(generator),
                             secondRandomDistribution(generator));
        Vector2F fourthVector(secondRandomDistribution(generator),
                              secondRandomDistribution(generator));

        const Vector2OrthonormalizeD firstOrthonormalize(firstVector, secondVector, 1e-10);

        firstVector.Normalize();
        const double dot0 = Vector2ToolsD::DotProduct(firstVector, secondVector);
        secondVector -= firstVector * dot0;
        secondVector.Normalize();

        ASSERT_TRUE(Vector2ToolsD::Approximate(firstVector, firstOrthonormalize.GetUVector(), 1e-10));

        ASSERT_TRUE(Vector2ToolsD::Approximate(secondVector, firstOrthonormalize.GetVVector(), 1e-10));

        const Vector2OrthonormalizeF secondOrthonormalize(thirdVector, fourthVector, 1e-5f);

        thirdVector.Normalize();
        const float dot1 = Vector2ToolsF::DotProduct(thirdVector, fourthVector);
        fourthVector -= thirdVector * dot1;
        fourthVector.Normalize();

        ASSERT_TRUE(Vector2ToolsF::Approximate(thirdVector, secondOrthonormalize.GetUVector(), 1e-8f));

        ASSERT_TRUE(Vector2ToolsF::Approximate(fourthVector, secondOrthonormalize.GetVVector(), 1e-5f));
    }
}
