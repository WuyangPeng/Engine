///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:42)

#include "Vector2DToolsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2Detail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

#include <random>

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Vector2Tools<float>;
    template class Vector2Tools<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::Vector2ToolsTesting::Vector2ToolsTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Vector2ToolsTesting)

void Mathematics::Vector2ToolsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Vector2ToolsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProductTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PerpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OtherCalculateTest);
}

void Mathematics::Vector2ToolsTesting::DistanceTest()
{
    const Vector2F vector0(3.0f, 4.0f);

    ASSERT_APPROXIMATE(Vector2ToolsF::GetLength(vector0), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(Vector2ToolsF::GetLengthSquared(vector0), 25.0f, 1e-8f);

    const Vector2F vector1(6.0f, 8.0f);

    ASSERT_APPROXIMATE(Vector2ToolsF::Distance(vector0, vector1), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(Vector2ToolsF::DistanceSquared(vector0, vector1), 25.0f, 1e-8f);
}

void Mathematics::Vector2ToolsTesting::ProductTest()
{
    const Vector2 vector0(-4.0, 3.0);
    const Vector2 vector1(8.0, 6.0);

    ASSERT_APPROXIMATE(Vector2ToolsD::DotProduct(vector0, vector1), -14.0, 1e-8f);
    ASSERT_APPROXIMATE(Vector2ToolsD::PseudoCrossProduct(vector0, vector1), -48.0, 1e-8f);
}

void Mathematics::Vector2ToolsTesting::ProjectionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real_distribution<double> randomDistribution{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 vector0(randomDistribution(generator),
                              randomDistribution(generator));

        const Vector2 vector1(randomDistribution(generator),
                              randomDistribution(generator));

        const double moduleSquare = Vector2ToolsD::GetLengthSquared(vector1);
        const Vector2 parallelVector = vector1 * (Vector2ToolsD::DotProduct(vector0, vector1) / moduleSquare);

        ASSERT_TRUE(Vector2ToolsD::Approximate(Vector2ToolsD::ParallelVectorLhsToRhs(vector0, vector1), parallelVector));

        const Vector2 apeakVector = vector0 - parallelVector;

        ASSERT_TRUE(Vector2ToolsD::Approximate(Vector2ToolsD::ApeakVectorLhsToRhs(vector0, vector1), apeakVector));

        const double angle = MathD::ACos(Vector2ToolsD::DotProduct(vector0, vector1) / (Vector2ToolsD::GetLength(vector0) * Vector2ToolsD::GetLength(vector1)));

        ASSERT_APPROXIMATE(angle, Vector2ToolsD::GetVectorIncludedAngle(vector0, vector1), 1e-10);
    }
}

void Mathematics::Vector2ToolsTesting::PerpTest()
{
    const Vector2F vector0(3.0f, 4.0f);
    Vector2F perpVector(4.0f, -3.0f);

    ASSERT_TRUE(Vector2ToolsF::Approximate(Vector2ToolsF::GetPerp(vector0), perpVector));

    perpVector.Normalize();

    ASSERT_TRUE(Vector2ToolsF::Approximate(Vector2ToolsF::GetUnitPerp(vector0), perpVector));

    const float dotPerp = vector0.GetX() * perpVector.GetY() - vector0.GetY() * perpVector.GetX();

    ASSERT_APPROXIMATE(Vector2ToolsF::DotPerp(vector0, perpVector), dotPerp, 1e-8f);
}

void Mathematics::Vector2ToolsTesting::CompareTest()
{
    const Vector2F vector0(6.0f, 8.0f);
    const Vector2F vector1(7.0f, 5.0f);

    ASSERT_TRUE(Vector2ToolsF::Approximate(vector0, vector0));
    ASSERT_TRUE(Vector2ToolsF::Approximate(vector1, vector1));
    ASSERT_FALSE(Vector2ToolsF::Approximate(vector0, vector1));

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

void Mathematics::Vector2ToolsTesting::OtherCalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real_distribution<double> randomDistribution{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    std::vector<Vector2D> vectors;

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 eachVector(randomDistribution(generator), randomDistribution(generator));

        vectors.push_back(eachVector);
    }

    const AxesAlignBoundingBox2D aabb = Vector2ToolsD::ComputeExtremes(vectors);
    const Vector2 minVector = aabb.GetMinPoint();
    const Vector2 maxVector = aabb.GetMaxPoint();

    for (const auto& eachVector : vectors)
    {
        ASSERT_TRUE(minVector.GetX() <= eachVector.GetX());
        ASSERT_TRUE(minVector.GetY() <= eachVector.GetY());
        ASSERT_TRUE(eachVector.GetX() <= maxVector.GetX());
        ASSERT_TRUE(eachVector.GetY() <= maxVector.GetY());
    }

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector2 vector0(randomDistribution(generator), randomDistribution(generator));
        Vector2 vector1(randomDistribution(generator), randomDistribution(generator));

        const Vector2ToolsD::Vector2OrthonormalizeType orthonormalize = Vector2ToolsD::Orthonormalize(vector0, vector1);

        vector0.Normalize();

        const double dot = Vector2ToolsD::DotProduct(vector0, vector1);
        vector1 -= vector0 * dot;
        vector1.Normalize();

        ASSERT_TRUE(Vector2ToolsD::Approximate(vector0, orthonormalize.GetUVector()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(vector1, orthonormalize.GetVVector()));

        Vector2 vector2(randomDistribution(generator), randomDistribution(generator));

        const Vector2OrthonormalBasisD orthonormalBasis = Vector2ToolsD::GenerateOrthonormalBasis(vector2);

        vector2.Normalize();

        ASSERT_TRUE(Vector2ToolsD::Approximate(vector2, orthonormalBasis.GetUVector()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(Vector2ToolsD::GetPerp(vector2), orthonormalBasis.GetVVector()));
    }
}
