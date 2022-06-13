///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/27 11:23)

#include "QueryDotToolsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Query/QueryDotToolsDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class QueryDotTools<double>;
    template class QueryDotTools<float>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QueryDotToolsTesting)

void Mathematics::QueryDotToolsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DotTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Det2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Det3Test);
}

void Mathematics::QueryDotToolsTesting::DotTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 firstVector(firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector2 secondVector(firstRandomDistribution(generator), firstRandomDistribution(generator));

        ASSERT_APPROXIMATE(Vector2ToolsD::DotProduct(firstVector, secondVector),
                           QueryDotToolsD::Dot(firstVector[0], firstVector[1], secondVector[0], secondVector[1]), 1e-8f);

        Vector3D thirdVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D fourthVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));

        ASSERT_APPROXIMATE(Vector3ToolsD::DotProduct(thirdVector, fourthVector), QueryDotToolsD::Dot(thirdVector[0], thirdVector[1], thirdVector[2], fourthVector[0], fourthVector[1], fourthVector[2]), 1e-8f);
    }
}

void Mathematics::QueryDotToolsTesting::Det2Test()
{
    default_random_engine generator;
    const uniform_real<float> firstRandomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 firstVector(firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector2 secondVector(firstRandomDistribution(generator), firstRandomDistribution(generator));

        ASSERT_APPROXIMATE(Vector2ToolsD::DotPerp(firstVector, secondVector), QueryDotToolsD::Det2(firstVector[0], firstVector[1], secondVector[0], secondVector[1]), 1e-8f);
    }
}

void Mathematics::QueryDotToolsTesting::Det3Test()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D firstVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D secondVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D thirdVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));

        ASSERT_APPROXIMATE(Vector3ToolsD::ScalarTripleProduct(firstVector, secondVector, thirdVector),
                           QueryDotToolsD::Det3(firstVector[0], firstVector[1], firstVector[2], secondVector[0], secondVector[1], secondVector[2], thirdVector[0], thirdVector[1], thirdVector[2]),
                           1e-8f);

        Vector4D fourthVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector4D fifthVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector4D sixthVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector4D seventhVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));

        const Matrix4D matrix(fourthVector[0], fourthVector[1], fourthVector[2], fourthVector[3],
                              fifthVector[0], fifthVector[1], fifthVector[2], fifthVector[3],
                              sixthVector[0], sixthVector[1], sixthVector[2], sixthVector[3],
                              seventhVector[0], seventhVector[1], seventhVector[2], seventhVector[3]);

        ASSERT_APPROXIMATE(matrix.Determinant(),
                           QueryDotToolsD::Det4(fourthVector[0], fourthVector[1], fourthVector[2], fourthVector[3],
                                                fifthVector[0], fifthVector[1], fifthVector[2], fifthVector[3],
                                                sixthVector[0], sixthVector[1], sixthVector[2], sixthVector[3],
                                                seventhVector[0], seventhVector[1], seventhVector[2], seventhVector[3]),
                           1e-6);
    }
}
