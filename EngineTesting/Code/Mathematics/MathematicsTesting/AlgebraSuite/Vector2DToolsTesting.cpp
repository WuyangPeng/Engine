///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:59)

#include "Vector2DToolsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2Detail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

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
    const Vector2F firstVector(3.0f, 4.0f);

    ASSERT_APPROXIMATE(Vector2ToolsF::GetLength(firstVector), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(Vector2ToolsF::GetLengthSquared(firstVector), 25.0f, 1e-8f);

    const Vector2F secondVector(6.0f, 8.0f);

    ASSERT_APPROXIMATE(Vector2ToolsF::Distance(firstVector, secondVector), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(Vector2ToolsF::DistanceSquared(firstVector, secondVector), 25.0f, 1e-8f);
}

void Mathematics::Vector2ToolsTesting::ProductTest()
{
    const Vector2 firstVector(-4.0, 3.0);
    const Vector2 secondVector(8.0, 6.0);

    ASSERT_APPROXIMATE(Vector2ToolsD::DotProduct(firstVector, secondVector), -14.0, 1e-8f);
    ASSERT_APPROXIMATE(Vector2ToolsD::PseudoCrossProduct(firstVector, secondVector), -48.0, 1e-8f);
}

void Mathematics::Vector2ToolsTesting::ProjectionTest()
{
    default_random_engine generator{};

    const uniform_real<double> randomDistribution{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 firstVector(randomDistribution(generator),
                                  randomDistribution(generator));

        const Vector2 secondVector(randomDistribution(generator),
                                   randomDistribution(generator));

        const double moduleSquare = Vector2ToolsD::GetLengthSquared(secondVector);
        const Vector2 parallelVector = secondVector * (Vector2ToolsD::DotProduct(firstVector, secondVector) / moduleSquare);

        ASSERT_TRUE(Vector2ToolsD::Approximate(Vector2ToolsD::ParallelVectorLhsToRhs(firstVector, secondVector), parallelVector));

        const Vector2 apeakVector = firstVector - parallelVector;

        ASSERT_TRUE(Vector2ToolsD::Approximate(Vector2ToolsD::ApeakVectorLhsToRhs(firstVector, secondVector), apeakVector));

        const double angle = MathD::ACos(Vector2ToolsD::DotProduct(firstVector, secondVector) / (Vector2ToolsD::GetLength(firstVector) * Vector2ToolsD::GetLength(secondVector)));

        ASSERT_APPROXIMATE(angle, Vector2ToolsD::GetVectorIncludedAngle(firstVector, secondVector), 1e-10);
    }
}

void Mathematics::Vector2ToolsTesting::PerpTest()
{
    const Vector2F firstVector(3.0f, 4.0f);
    Vector2F perpVector(4.0f, -3.0f);

    ASSERT_TRUE(Vector2ToolsF::Approximate(Vector2ToolsF::GetPerp(firstVector), perpVector));

    perpVector.Normalize();

    ASSERT_TRUE(Vector2ToolsF::Approximate(Vector2ToolsF::GetUnitPerp(firstVector), perpVector));

    const float dotPerp = firstVector.GetX() * perpVector.GetY() - firstVector.GetY() * perpVector.GetX();

    ASSERT_APPROXIMATE(Vector2ToolsF::DotPerp(firstVector, perpVector), dotPerp, 1e-8f);
}

void Mathematics::Vector2ToolsTesting::CompareTest()
{
    const Vector2F firstVector(6.0f, 8.0f);
    const Vector2F secondVector(7.0f, 5.0f);

    ASSERT_TRUE(Vector2ToolsF::Approximate(firstVector, firstVector));
    ASSERT_TRUE(Vector2ToolsF::Approximate(secondVector, secondVector));
    ASSERT_FALSE(Vector2ToolsF::Approximate(firstVector, secondVector));

    ASSERT_TRUE(firstVector == firstVector);
    ASSERT_FALSE(firstVector == secondVector);
    ASSERT_TRUE(firstVector != secondVector);
    ASSERT_TRUE(firstVector < secondVector);
    ASSERT_TRUE(firstVector <= secondVector);
    ASSERT_FALSE(firstVector > secondVector);
    ASSERT_FALSE(firstVector >= secondVector);

    GetStream() << "以下是调试信息：\n";
    GetStream() << firstVector << '\n';
    GetStream() << secondVector << '\n';
}

void Mathematics::Vector2ToolsTesting::OtherCalculateTest()
{
    default_random_engine generator{};

    const uniform_real<double> randomDistribution{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    vector<Vector2D> vectors;

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
        Vector2 firstVector(randomDistribution(generator), randomDistribution(generator));
        Vector2 secondVector(randomDistribution(generator), randomDistribution(generator));

        const Vector2ToolsD::Vector2Orthonormalize orthonormalize = Vector2ToolsD::Orthonormalize(firstVector, secondVector);

        firstVector.Normalize();

        const double dot = Vector2ToolsD::DotProduct(firstVector, secondVector);
        secondVector -= firstVector * dot;
        secondVector.Normalize();

        ASSERT_TRUE(Vector2ToolsD::Approximate(firstVector, orthonormalize.GetUVector()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(secondVector, orthonormalize.GetVVector()));

        Vector2 thirdVector(randomDistribution(generator), randomDistribution(generator));

        const Vector2OrthonormalBasisD orthonormalBasis = Vector2ToolsD::GenerateOrthonormalBasis(thirdVector);

        thirdVector.Normalize();

        ASSERT_TRUE(Vector2ToolsD::Approximate(thirdVector, orthonormalBasis.GetUVector()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(Vector2ToolsD::GetPerp(thirdVector), orthonormalBasis.GetVVector()));
    }
}
