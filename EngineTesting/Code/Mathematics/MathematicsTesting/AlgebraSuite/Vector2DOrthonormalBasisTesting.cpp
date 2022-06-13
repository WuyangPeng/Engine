///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:58)

#include "Vector2DOrthonormalBasisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2OrthonormalBasisDetail.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Vector2OrthonormalBasisTesting)

void Mathematics::Vector2OrthonormalBasisTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalBasisTest);
}

void Mathematics::Vector2OrthonormalBasisTesting::OrthonormalBasisTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution{ -10.0, 10.0 };
    const uniform_real<float> secondRandomDistribution{ -10.0f, 10.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 firstVector(firstRandomDistribution(generator), firstRandomDistribution(generator));

        Vector2F secondVector(secondRandomDistribution(generator), secondRandomDistribution(generator));

        const Vector2OrthonormalBasisD firstOrthonormalBasis(firstVector);

        firstVector.Normalize();

        ASSERT_TRUE(Vector2ToolsD::Approximate(firstVector, firstOrthonormalBasis.GetUVector(), 1e-10));

        ASSERT_TRUE(Vector2ToolsD::Approximate(Vector2(firstVector[1], -firstVector[0]), firstOrthonormalBasis.GetVVector(), 1e-10));

        const Vector2OrthonormalBasisF secondOrthonormalBasis(secondVector);

        secondVector.Normalize();

        ASSERT_TRUE(Vector2ToolsF::Approximate(secondVector, secondOrthonormalBasis.GetUVector(), 1e-8f));

        ASSERT_TRUE(Vector2ToolsF::Approximate(Vector2(secondVector[1], -secondVector[0]), secondOrthonormalBasis.GetVVector(), 1e-8f));
    }
}
