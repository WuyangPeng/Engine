// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.2 (2019/08/22 11:36)

#include "Vector2DToolsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2Detail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Vector2ToolsTesting)

void Mathematics::Vector2ToolsTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProductTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PerpTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OtherCalculateTest);
}

void Mathematics::Vector2ToolsTesting ::DistanceTest()
{
    Vector2F firstVector(3.0f, 4.0f);

    ASSERT_APPROXIMATE(Vector2ToolsF::GetLength(firstVector), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(Vector2ToolsF::GetLengthSquared(firstVector), 25.0f, 1e-8f);

    Vector2F secondVector(6.0f, 8.0f);

    ASSERT_APPROXIMATE(Vector2ToolsF::Distance(firstVector, secondVector), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(Vector2ToolsF::DistanceSquared(firstVector, secondVector), 25.0f, 1e-8f);
}

void Mathematics::Vector2ToolsTesting ::ProductTest()
{
    Vector2 firstVector(-4.0, 3.0);
    Vector2 secondVector(8.0, 6.0);

    ASSERT_APPROXIMATE(Vector2ToolsD::DotProduct(firstVector, secondVector), -14.0, 1e-8f);
    ASSERT_APPROXIMATE(Vector2ToolsD::PseudoCrossProduct(firstVector, secondVector), -48.0, 1e-8f);
}

void Mathematics::Vector2ToolsTesting ::ProjectionTest()
{
    default_random_engine generator{};

    uniform_real<double> randomDistribution{ -10.0f, 10.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 firstVector(randomDistribution(generator),
                            randomDistribution(generator));

        Vector2 secondVector(randomDistribution(generator),
                             randomDistribution(generator));

        double moduleSquare = Vector2ToolsD::GetLengthSquared(secondVector);
        Vector2 parallelVector = secondVector * (Vector2ToolsD::DotProduct(firstVector, secondVector) / moduleSquare);

        ASSERT_TRUE(Vector2ToolsD::Approximate(Vector2ToolsD::ParallelVectorLhsToRhs(firstVector, secondVector), parallelVector));

        Vector2 apeakVector = firstVector - parallelVector;

        ASSERT_TRUE(Vector2ToolsD::Approximate(Vector2ToolsD::ApeakVectorLhsToRhs(firstVector, secondVector), apeakVector));

        double angle = MathD::ACos(Vector2ToolsD::DotProduct(firstVector, secondVector) / (Vector2ToolsD::GetLength(firstVector) * Vector2ToolsD::GetLength(secondVector)));

        ASSERT_APPROXIMATE(angle, Vector2ToolsD::GetVectorIncludedAngle(firstVector, secondVector), 1e-10);
    }
}

void Mathematics::Vector2ToolsTesting ::PerpTest()
{
    Vector2F firstVector(3.0f, 4.0f);
    Vector2F perpVector(4.0f, -3.0f);

    ASSERT_TRUE(Vector2ToolsF::Approximate(Vector2ToolsF::GetPerp(firstVector), perpVector));

    perpVector.Normalize();

    ASSERT_TRUE(Vector2ToolsF::Approximate(Vector2ToolsF::GetUnitPerp(firstVector), perpVector));

    float dotPerp = firstVector.GetX() * perpVector.GetY() - firstVector.GetY() * perpVector.GetX();

    ASSERT_APPROXIMATE(Vector2ToolsF::DotPerp(firstVector, perpVector), dotPerp, 1e-8f);
}

void Mathematics::Vector2ToolsTesting ::CompareTest()
{
    Vector2F firstVector(6.0f, 8.0f);
    Vector2F secondVector(7.0f, 5.0f);

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

void Mathematics::Vector2ToolsTesting ::OtherCalculateTest()
{
    default_random_engine generator{};

    uniform_real<double> randomDistribution{ -10.0f, 10.0f };

    const auto testLoopCount = GetTestLoopCount();

    vector<Vector2D> vectors;

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 eachVector(randomDistribution(generator), randomDistribution(generator));

        vectors.push_back(eachVector);
    }

    AxesAlignBoundingBox2D aabb = Vector2ToolsD::ComputeExtremes(vectors);
    Vector2 minVector = aabb.GetMinPoint();
    Vector2 maxVector = aabb.GetMaxPoint();

    for (const auto& eachVector : vectors)
    {
        ASSERT_TRUE(minVector.GetX() <= eachVector.GetX());
        ASSERT_TRUE(minVector.GetY() <= eachVector.GetY());
        ASSERT_TRUE(eachVector.GetX() <= maxVector.GetX());
        ASSERT_TRUE(eachVector.GetY() <= maxVector.GetY());
    }

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 firstVector(randomDistribution(generator), randomDistribution(generator));
        Vector2 secondVector(randomDistribution(generator), randomDistribution(generator));

        Vector2ToolsD::Vector2Orthonormalize orthonormalize = Vector2ToolsD::Orthonormalize(firstVector, secondVector);

        firstVector.Normalize();

        double dot = Vector2ToolsD::DotProduct(firstVector, secondVector);
        secondVector -= firstVector * dot;
        secondVector.Normalize();

        ASSERT_TRUE(Vector2ToolsD::Approximate(firstVector, orthonormalize.GetUVector()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(secondVector, orthonormalize.GetVVector()));

        Vector2 thirdVector(randomDistribution(generator), randomDistribution(generator));

        Vector2OrthonormalBasisD orthonormalBasis = Vector2ToolsD::GenerateOrthonormalBasis(thirdVector);

        thirdVector.Normalize();

        ASSERT_TRUE(Vector2ToolsD::Approximate(thirdVector, orthonormalBasis.GetUVector()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(Vector2ToolsD::GetPerp(thirdVector), orthonormalBasis.GetVVector()));
    }
}
