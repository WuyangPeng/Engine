///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 23:01)

#include "Vector3DToolsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Vector3Tools<float>;
    template class Vector3Tools<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Vector3ToolsTesting)

void Mathematics::Vector3ToolsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProductTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConversionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OtherCalculateTest);
}

void Mathematics::Vector3ToolsTesting::DistanceTest()
{
    const Vector3F firstVector(3.0f, 4.0f, 5.0f);

    ASSERT_APPROXIMATE(Vector3ToolsF::GetLength(firstVector), MathF::Sqrt(50.0f), 1e-8f);
    ASSERT_APPROXIMATE(Vector3ToolsF::GetLengthSquared(firstVector), 50.0f, 1e-8f);

    const Vector3F secondVector(6.0f, 8.0f, 5.0f);

    ASSERT_APPROXIMATE(Vector3ToolsF::Distance(firstVector, secondVector), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(Vector3ToolsF::DistanceSquared(firstVector, secondVector), 25.0f, 1e-8f);
}

void Mathematics::Vector3ToolsTesting::ProductTest()
{
    default_random_engine generator{};

    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D firstVector(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        Vector3D secondVector(randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator));

        const double dotProduct = firstVector[0] * secondVector[0] +
                                  firstVector[1] * secondVector[1] +
                                  firstVector[2] * secondVector[2];

        ASSERT_APPROXIMATE(Vector3ToolsD::DotProduct(firstVector, secondVector), dotProduct, 1e-10);

        Vector3D crossProduct(firstVector.GetY() * secondVector.GetZ() - firstVector.GetZ() * secondVector.GetY(),
                              firstVector.GetZ() * secondVector.GetX() - firstVector.GetX() * secondVector.GetZ(),
                              firstVector.GetX() * secondVector.GetY() - firstVector.GetY() * secondVector.GetX());

        ASSERT_TRUE(Vector3ToolsD::Approximate(Vector3ToolsD::CrossProduct(firstVector, secondVector), crossProduct));

        ASSERT_TRUE(Vector3ToolsD::Approximate(Vector3ToolsD::CrossProductWithReduceMultiplication(firstVector, secondVector), crossProduct));

        crossProduct.Normalize();

        ASSERT_TRUE(Vector3ToolsD::Approximate(Vector3ToolsD::UnitCrossProduct(firstVector, secondVector), crossProduct));

        const Vector3D thirdVector(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        ASSERT_APPROXIMATE(Vector3ToolsD::ScalarTripleProduct(firstVector, secondVector, thirdVector),
                           Vector3ToolsD::DotProduct(Vector3ToolsD::CrossProduct(firstVector, secondVector), thirdVector), 1e-10);
    }
}

void Mathematics::Vector3ToolsTesting::ProjectionTest()
{
    default_random_engine generator{};

    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector3D firstVector(randomDistribution(generator),
                                   randomDistribution(generator),
                                   randomDistribution(generator));

        const Vector3D secondVector(randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator));

        const double moduleSquare = Vector3ToolsD::GetLengthSquared(secondVector);
        const Vector3D parallelVector = secondVector * (Vector3ToolsD::DotProduct(firstVector, secondVector) / moduleSquare);

        ASSERT_TRUE(Vector3ToolsD::Approximate(parallelVector, Vector3ToolsD::ParallelVectorLhsToRhs(firstVector, secondVector)));

        const Vector3D apeakVector = firstVector - parallelVector;

        ASSERT_TRUE(Vector3ToolsD::Approximate(apeakVector, Vector3ToolsD::ApeakVectorLhsToRhs(firstVector, secondVector)));

        const double angle = MathD::ACos(Vector3ToolsD::DotProduct(firstVector, secondVector) / (Vector3ToolsD::GetLength(firstVector) * Vector3ToolsD::GetLength(secondVector)));

        ASSERT_APPROXIMATE(angle, Vector3ToolsD::GetVectorIncludedAngle(firstVector, secondVector), 1e-10);

        const Vector3D reflectionVector = 2 * Vector3ToolsD::DotProduct(secondVector, firstVector) * secondVector - firstVector;

        ASSERT_TRUE(Vector3ToolsD::Approximate(reflectionVector, Vector3ToolsD::ReflectionVector(firstVector, secondVector)));

        constexpr double consistencyRatio(0.6);

        const double conphiSquare = Vector3ToolsD::DotProduct(-secondVector, firstVector) * Vector3ToolsD::DotProduct(-secondVector, firstVector);
        constexpr double consistencyRatioSquare = consistencyRatio * consistencyRatio;
        const double costheta = 1 / consistencyRatioSquare * MathD::Sqrt(1 - consistencyRatioSquare * (1 - conphiSquare));

        const Vector3D refractionVector = consistencyRatio * firstVector - (costheta + consistencyRatio * Vector3ToolsD::DotProduct(-secondVector, firstVector)) * secondVector;

        ASSERT_TRUE(Vector3ToolsD::Approximate(refractionVector, Vector3ToolsD::RefractionVector(firstVector, secondVector, consistencyRatio)));
    }
}

void Mathematics::Vector3ToolsTesting::ConversionTest()
{
    default_random_engine generator{};

    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector3D firstVector(randomDistribution(generator),
                                   randomDistribution(generator),
                                   randomDistribution(generator));

        double delta = Half(firstVector.GetZ());

        const Vector3D secondVector(firstVector.GetX() * delta, firstVector.GetY() * delta, firstVector.GetZ());

        ASSERT_TRUE(Vector3ToolsD::Approximate(secondVector, Vector3ToolsD::FeatheringOutZAxes(firstVector, Half)));

        const Vector3D twistZAxesVector = Vector3ToolsD::TwistZAxes(firstVector, Half);

        ASSERT_APPROXIMATE(twistZAxesVector.GetZ(), firstVector.GetZ(), 1e-10);

        const double testValue = (firstVector.GetX() - firstVector.GetY()) * (MathD::Sin(delta) + MathD::Cos(delta));

        ASSERT_APPROXIMATE(twistZAxesVector.GetX() + twistZAxesVector.GetY(), testValue, 1e-10);

        const double curvatureRadius = randomDistribution(generator);
        const double bendCenter = randomDistribution(generator);
        const double bendAreaMin = randomDistribution(generator);
        const double bendAreaMax = bendAreaMin + 1000000.0;

        const Vector3D bendYAxesVector = Vector3ToolsD::BendYAxes(firstVector, curvatureRadius, bendCenter, bendAreaMin, bendAreaMax);

        ASSERT_APPROXIMATE(bendYAxesVector.GetX(), firstVector.GetX(), 1e-10);

        double y = firstVector.GetY();

        if (firstVector.GetY() <= bendAreaMin)
            y = bendAreaMin;
        else if (firstVector.GetY() >= bendAreaMax)
            y = bendAreaMax;

        delta = 1 / curvatureRadius * (y - bendCenter);

        if (bendAreaMin <= firstVector.GetY() && firstVector.GetY() <= bendAreaMax)
        {
            ASSERT_APPROXIMATE(bendYAxesVector.GetY(), -MathD::Sin(delta) * (firstVector.GetZ() - curvatureRadius) + bendCenter, 1e-10);

            ASSERT_APPROXIMATE(bendYAxesVector.GetZ(), -MathD::Cos(delta) * (firstVector.GetZ() - curvatureRadius) + bendCenter, 1e-10);
        }
        else if (firstVector.GetY() < bendAreaMin)
        {
            ASSERT_APPROXIMATE(bendYAxesVector.GetY(),
                               -MathD::Sin(delta) * (firstVector.GetZ() - curvatureRadius) + bendCenter + MathD::Cos(delta) * (firstVector.GetY() - bendAreaMin),
                               1e-10);

            ASSERT_APPROXIMATE(bendYAxesVector.GetZ(),
                               -MathD::Cos(delta) * (firstVector.GetZ() - curvatureRadius) + bendCenter + MathD::Sin(delta) * (firstVector.GetY() - bendAreaMin),
                               1e-10);
        }
        else
        {
            ASSERT_APPROXIMATE(bendYAxesVector.GetY(),
                               (-MathD::Sin(delta) * (firstVector.GetZ() - curvatureRadius) + curvatureRadius + MathD::Cos(delta) * (firstVector.GetY() - bendAreaMax)),
                               1e-10);

            ASSERT_APPROXIMATE(bendYAxesVector.GetZ(),
                               (-MathD::Cos(delta) * (firstVector.GetZ() - curvatureRadius) + curvatureRadius + MathD::Sin(delta) * (firstVector.GetY() - bendAreaMax)),
                               1e-10);
        }
    }
}

void Mathematics::Vector3ToolsTesting::CompareTest()
{
    const Vector3F firstVector(6.0f, 8.0f, 9.0f);
    const Vector3F secondVector(7.0f, 5.0f, 19.0f);

    ASSERT_TRUE(Vector3ToolsF::Approximate(firstVector, firstVector));
    ASSERT_TRUE(Vector3ToolsF::Approximate(secondVector, secondVector));
    ASSERT_FALSE(Vector3ToolsF::Approximate(firstVector, secondVector));

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

void Mathematics::Vector3ToolsTesting::OtherCalculateTest()
{
    default_random_engine generator{};

    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    vector<Vector3D> vectors;

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector3D eachVector(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        vectors.push_back(eachVector);
    }

    const AxesAlignBoundingBox3D aabb = Vector3ToolsD::ComputeExtremes(vectors);
    const Vector3D minVector = aabb.GetMinPoint();
    const Vector3D maxVector = aabb.GetMaxPoint();

    for (const auto& eachVector : vectors)
    {
        ASSERT_TRUE(minVector.GetX() <= eachVector.GetX());
        ASSERT_TRUE(minVector.GetY() <= eachVector.GetY());
        ASSERT_TRUE(minVector.GetZ() <= eachVector.GetZ());
        ASSERT_TRUE(eachVector.GetX() <= maxVector.GetX());
        ASSERT_TRUE(eachVector.GetY() <= maxVector.GetY());
        ASSERT_TRUE(eachVector.GetZ() <= maxVector.GetZ());
    }

    Vector3D firstVector(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));
    Vector3D secondVector(randomDistribution(generator),
                          randomDistribution(generator),
                          randomDistribution(generator));

    Vector3D thirdVector(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

    vectors.clear();
    vectors.push_back(firstVector);
    vectors.push_back(secondVector);
    vectors.push_back(thirdVector);

    const Vector3ToolsD::Vector3Orthonormalize firstOrthonormalize = Vector3ToolsD::Orthonormalize(firstVector, secondVector, thirdVector);

    const Vector3ToolsD::Vector3Orthonormalize secondOrthonormaliz = Vector3ToolsD::Orthonormalize(vectors);

    firstVector.Normalize();
    double dot0 = Vector3ToolsD::DotProduct(firstVector, secondVector);
    secondVector -= dot0 * firstVector;
    secondVector.Normalize();

    const double dot1 = Vector3ToolsD::DotProduct(secondVector, thirdVector);
    dot0 = Vector3ToolsD::DotProduct(firstVector, thirdVector);
    thirdVector -= dot0 * firstVector + dot1 * secondVector;
    thirdVector.Normalize();

    ASSERT_TRUE(Vector3ToolsD::Approximate(firstVector, firstOrthonormalize.GetUVector()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(secondVector, firstOrthonormalize.GetVVector()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(thirdVector, firstOrthonormalize.GetWVector()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(firstVector, secondOrthonormaliz.GetUVector()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(secondVector, secondOrthonormaliz.GetVVector()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(thirdVector, secondOrthonormaliz.GetWVector()));

    Vector3D fourthVector(randomDistribution(generator),
                          randomDistribution(generator),
                          randomDistribution(generator));

    const Vector3OrthonormalBasisD firstOrthonormalBasis = Vector3ToolsD::GenerateOrthonormalBasis(fourthVector);

    fourthVector.Normalize();

    const Vector3OrthonormalBasisD secondOrthonormalBasis = Vector3ToolsD::GenerateComplementBasis(fourthVector);

    ASSERT_TRUE(Vector3ToolsD::Approximate(fourthVector, firstOrthonormalBasis.GetWVector()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(fourthVector, firstOrthonormalBasis.GetWVector()));

    ASSERT_TRUE(Vector3ToolsD::Approximate(firstOrthonormalBasis.GetUVector(), secondOrthonormalBasis.GetUVector()));

    ASSERT_TRUE(Vector3ToolsD::Approximate(firstOrthonormalBasis.GetVVector(), secondOrthonormalBasis.GetVVector()));

    ASSERT_TRUE(Vector3ToolsD::Approximate(firstOrthonormalBasis.GetWVector(),
                                           Vector3ToolsD::CrossProduct(secondOrthonormalBasis.GetUVector(), firstOrthonormalBasis.GetVVector())));

    ASSERT_TRUE(Vector3ToolsD::Approximate(firstOrthonormalBasis.GetUVector(),
                                           Vector3ToolsD::CrossProduct(firstOrthonormalBasis.GetVVector(), secondOrthonormalBasis.GetWVector())));

    ASSERT_TRUE(Vector3ToolsD::Approximate(secondOrthonormalBasis.GetVVector(),
                                           Vector3ToolsD::CrossProduct(firstOrthonormalBasis.GetWVector(), firstOrthonormalBasis.GetUVector())));
}
