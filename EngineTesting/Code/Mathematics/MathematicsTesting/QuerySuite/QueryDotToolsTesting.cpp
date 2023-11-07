///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:28)

#include "QueryDotToolsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Query/QueryDotToolsDetail.h"

#include <random>

namespace Mathematics
{
    template class QueryDotTools<double>;
    template class QueryDotTools<float>;
}

Mathematics::QueryDotToolsTesting::QueryDotToolsTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, QueryDotToolsTesting)

void Mathematics::QueryDotToolsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::QueryDotToolsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DotTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Det2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Det3Test);
}

void Mathematics::QueryDotToolsTesting::DotTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector2 vector0(randomDistribution0(generator), randomDistribution0(generator));
        Vector2 vector1(randomDistribution0(generator), randomDistribution0(generator));

        ASSERT_APPROXIMATE(Vector2ToolsD::DotProduct(vector0, vector1),
                           QueryDotToolsD::Dot(vector0[0], vector0[1], vector1[0], vector1[1]), 1e-8f);

        Vector3D vector2(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector3D vector3(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));

        ASSERT_APPROXIMATE(Vector3ToolsD::DotProduct(vector2, vector3), QueryDotToolsD::Dot(vector2[0], vector2[1], vector2[2], vector3[0], vector3[1], vector3[2]), 1e-8f);
    }
}

void Mathematics::QueryDotToolsTesting::Det2Test()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution0(-100.0f, 100.0f);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector2 vector0(randomDistribution0(generator), randomDistribution0(generator));
        Vector2 vector1(randomDistribution0(generator), randomDistribution0(generator));

        ASSERT_APPROXIMATE(Vector2ToolsF::DotPerp(vector0, vector1), QueryDotToolsF::Det2(vector0[0], vector0[1], vector1[0], vector1[1]), 1e-8f);
    }
}

void Mathematics::QueryDotToolsTesting::Det3Test()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector3D vector0(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector3D vector1(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector3D vector2(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));

        ASSERT_APPROXIMATE(Vector3ToolsD::ScalarTripleProduct(vector0, vector1, vector2),
                           QueryDotToolsD::Det3(vector0[0], vector0[1], vector0[2], vector1[0], vector1[1], vector1[2], vector2[0], vector2[1], vector2[2]),
                           1e-8f);

        Vector4D vector3(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector4D vector4(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector4D vector5(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector4D seventhVector(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));

        const Matrix4D matrix(vector3[0], vector3[1], vector3[2], vector3[3],
                              vector4[0], vector4[1], vector4[2], vector4[3],
                              vector5[0], vector5[1], vector5[2], vector5[3],
                              seventhVector[0], seventhVector[1], seventhVector[2], seventhVector[3]);

        ASSERT_APPROXIMATE(matrix.Determinant(),
                           QueryDotToolsD::Det4(vector3[0], vector3[1], vector3[2], vector3[3],
                                                vector4[0], vector4[1], vector4[2], vector4[3],
                                                vector5[0], vector5[1], vector5[2], vector5[3],
                                                seventhVector[0], seventhVector[1], seventhVector[2], seventhVector[3]),
                           1e-6);
    }
}
