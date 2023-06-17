///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:45)

#include "Vector4DToolsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"

#include <random>

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Vector4Tools<float>;
    template class Vector4Tools<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::Vector4ToolsTesting::Vector4ToolsTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Vector4ToolsTesting)

void Mathematics::Vector4ToolsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Vector4ToolsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProductTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OtherCalculateTest);
}

void Mathematics::Vector4ToolsTesting::DistanceTest()
{
    const Vector4F vector0(3.0f, 4.0f, 5.0f, 3.0f);

    ASSERT_APPROXIMATE(Vector4ToolsF::GetLength(vector0), MathF::Sqrt(59.0f), 1e-8f);
    ASSERT_APPROXIMATE(Vector4ToolsF::GetLengthSquared(vector0), 59.0f, 1e-8f);

    const Vector4F vector1(6.0f, 8.0f, 5.0f, 3.0f);

    ASSERT_APPROXIMATE(Vector4ToolsF::Distance(vector0, vector1), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(Vector4ToolsF::DistanceSquared(vector0, vector1), 25.0f, 1e-8f);
}

void Mathematics::Vector4ToolsTesting::ProductTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    const std::uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector4D vector0(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        Vector4D vector1(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        const double dotProduct = vector0[0] * vector1[0] +
                                  vector0[1] * vector1[1] +
                                  vector0[2] * vector1[2] +
                                  vector0[3] * vector1[3];

        ASSERT_APPROXIMATE(Vector4ToolsD::DotProduct(vector0, vector1), dotProduct, 1e-10);
    }
}

void Mathematics::Vector4ToolsTesting::ProjectionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    const std::uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector4D vector0(randomDistribution(generator),
                               randomDistribution(generator),
                               randomDistribution(generator),
                               randomDistribution(generator));

        const Vector4D vector1(randomDistribution(generator),
                               randomDistribution(generator),
                               randomDistribution(generator),
                               randomDistribution(generator));

        const double moduleSquare = Vector4ToolsD::GetLengthSquared(vector1);
        const Vector4D parallelVector = vector1 * (Vector4ToolsD::DotProduct(vector0, vector1) / moduleSquare);

        ASSERT_TRUE(Vector4ToolsD::Approximate(parallelVector, Vector4ToolsD::ParallelVectorLhsToRhs(vector0, vector1)));

        const Vector4D apeakVector = vector0 - parallelVector;

        ASSERT_TRUE(Vector4ToolsD::Approximate(apeakVector, Vector4ToolsD::ApeakVectorLhsToRhs(vector0, vector1)));

        const double angle = MathD::ACos(Vector4ToolsD::DotProduct(vector0, vector1) / (Vector4ToolsD::GetLength(vector0) * Vector4ToolsD::GetLength(vector1)));

        ASSERT_APPROXIMATE(angle, Vector4ToolsD::GetVectorIncludedAngle(vector0, vector1), 1e-10);
    }
}

void Mathematics::Vector4ToolsTesting::CompareTest()
{
    const Vector4F vector0(6.0f, 8.0f, 9.0f, 3.0f);
    const Vector4F vector1(7.0f, 5.0f, 19.0f, 32.0f);

    ASSERT_TRUE(Vector4ToolsF::Approximate(vector0, vector0));
    ASSERT_TRUE(Vector4ToolsF::Approximate(vector1, vector1));
    ASSERT_FALSE(Vector4ToolsF::Approximate(vector0, vector1));

    ASSERT_TRUE(vector0 == vector0);
    ASSERT_FALSE(vector0 == vector1);
    ASSERT_TRUE(vector0 != vector1);
    ASSERT_TRUE(vector0 < vector1);
    ASSERT_TRUE(vector0 <= vector1);
    ASSERT_FALSE(vector0 > vector1);
    ASSERT_FALSE(vector0 >= vector1);

    GetStream() << "以下是调试信息：\n";
    GetStream() << vector0 << '\n';
    GetStream() << vector1 << '\n';
}

void Mathematics::Vector4ToolsTesting::OtherCalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    const std::uniform_real<double> randomDistribution{ -100.0, 100.0 };

    std::vector<Vector4D> vectors;

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector4D eachVector(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        vectors.push_back(eachVector);
    }

    const auto aabb = Vector4ToolsD::ComputeExtremes(vectors);
    const Vector4D minVector = aabb.GetMinPoint();
    const Vector4D maxVector = aabb.GetMaxPoint();

    for (const auto& eachVector : vectors)
    {
        ASSERT_TRUE(minVector.GetX() <= eachVector.GetX());
        ASSERT_TRUE(minVector.GetY() <= eachVector.GetY());
        ASSERT_TRUE(minVector.GetZ() <= eachVector.GetZ());
        ASSERT_TRUE(minVector.GetW() <= eachVector.GetW());
        ASSERT_TRUE(eachVector.GetX() <= maxVector.GetX());
        ASSERT_TRUE(eachVector.GetY() <= maxVector.GetY());
        ASSERT_TRUE(eachVector.GetZ() <= maxVector.GetZ());
        ASSERT_TRUE(eachVector.GetW() <= maxVector.GetW());
    }
}
