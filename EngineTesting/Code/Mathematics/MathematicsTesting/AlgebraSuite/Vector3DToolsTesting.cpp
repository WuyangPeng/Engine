///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:44)

#include "Vector3DToolsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

#include <random>

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Vector3Tools<float>;
    template class Vector3Tools<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::Vector3ToolsTesting::Vector3ToolsTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Vector3ToolsTesting)

void Mathematics::Vector3ToolsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
    const Vector3F vector0(3.0f, 4.0f, 5.0f);

    ASSERT_APPROXIMATE(Vector3ToolsF::GetLength(vector0), MathF::Sqrt(50.0f), 1e-8f);
    ASSERT_APPROXIMATE(Vector3ToolsF::GetLengthSquared(vector0), 50.0f, 1e-8f);

    const Vector3F vector1(6.0f, 8.0f, 5.0f);

    ASSERT_APPROXIMATE(Vector3ToolsF::Distance(vector0, vector1), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(Vector3ToolsF::DistanceSquared(vector0, vector1), 25.0f, 1e-8f);
}

void Mathematics::Vector3ToolsTesting::ProductTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector3D vector0(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        Vector3D vector1(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        const double dotProduct = vector0[0] * vector1[0] +
                                  vector0[1] * vector1[1] +
                                  vector0[2] * vector1[2];

        ASSERT_APPROXIMATE(Vector3ToolsD::DotProduct(vector0, vector1), dotProduct, 1e-10);

        Vector3D crossProduct(vector0.GetY() * vector1.GetZ() - vector0.GetZ() * vector1.GetY(),
                              vector0.GetZ() * vector1.GetX() - vector0.GetX() * vector1.GetZ(),
                              vector0.GetX() * vector1.GetY() - vector0.GetY() * vector1.GetX());

        ASSERT_TRUE(Vector3ToolsD::Approximate(Vector3ToolsD::CrossProduct(vector0, vector1), crossProduct));

        ASSERT_TRUE(Vector3ToolsD::Approximate(Vector3ToolsD::CrossProductWithReduceMultiplication(vector0, vector1), crossProduct));

        crossProduct.Normalize();

        ASSERT_TRUE(Vector3ToolsD::Approximate(Vector3ToolsD::UnitCrossProduct(vector0, vector1), crossProduct));

        const Vector3D vector2(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        ASSERT_APPROXIMATE(Vector3ToolsD::ScalarTripleProduct(vector0, vector1, vector2),
                           Vector3ToolsD::DotProduct(Vector3ToolsD::CrossProduct(vector0, vector1), vector2), 1e-10);
    }
}

void Mathematics::Vector3ToolsTesting::ProjectionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D vector0(randomDistribution(generator),
                               randomDistribution(generator),
                               randomDistribution(generator));

        const Vector3D vector1(randomDistribution(generator),
                               randomDistribution(generator),
                               randomDistribution(generator));

        const double moduleSquare = Vector3ToolsD::GetLengthSquared(vector1);
        const Vector3D parallelVector = vector1 * (Vector3ToolsD::DotProduct(vector0, vector1) / moduleSquare);

        ASSERT_TRUE(Vector3ToolsD::Approximate(parallelVector, Vector3ToolsD::ParallelVectorLhsToRhs(vector0, vector1)));

        const Vector3D apeakVector = vector0 - parallelVector;

        ASSERT_TRUE(Vector3ToolsD::Approximate(apeakVector, Vector3ToolsD::ApeakVectorLhsToRhs(vector0, vector1)));

        const double angle = MathD::ACos(Vector3ToolsD::DotProduct(vector0, vector1) / (Vector3ToolsD::GetLength(vector0) * Vector3ToolsD::GetLength(vector1)));

        ASSERT_APPROXIMATE(angle, Vector3ToolsD::GetVectorIncludedAngle(vector0, vector1), 1e-10);

        const Vector3D reflectionVector = 2 * Vector3ToolsD::DotProduct(vector1, vector0) * vector1 - vector0;

        ASSERT_TRUE(Vector3ToolsD::Approximate(reflectionVector, Vector3ToolsD::ReflectionVector(vector0, vector1)));

        constexpr double consistencyRatio(0.6);

        const double conphiSquare = Vector3ToolsD::DotProduct(-vector1, vector0) * Vector3ToolsD::DotProduct(-vector1, vector0);
        constexpr double consistencyRatioSquare = consistencyRatio * consistencyRatio;
        const double costheta = 1 / consistencyRatioSquare * MathD::Sqrt(1 - consistencyRatioSquare * (1 - conphiSquare));

        const Vector3D refractionVector = consistencyRatio * vector0 - (costheta + consistencyRatio * Vector3ToolsD::DotProduct(-vector1, vector0)) * vector1;

        ASSERT_TRUE(Vector3ToolsD::Approximate(refractionVector, Vector3ToolsD::RefractionVector(vector0, vector1, consistencyRatio)));
    }
}

void Mathematics::Vector3ToolsTesting::ConversionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D vector0(randomDistribution(generator),
                               randomDistribution(generator),
                               randomDistribution(generator));

        double delta = Half(vector0.GetZ());

        const Vector3D vector1(vector0.GetX() * delta, vector0.GetY() * delta, vector0.GetZ());

        ASSERT_TRUE(Vector3ToolsD::Approximate(vector1, Vector3ToolsD::FeatheringOutZAxes(vector0, Half)));

        const Vector3D twistZAxesVector = Vector3ToolsD::TwistZAxes(vector0, Half);

        ASSERT_APPROXIMATE(twistZAxesVector.GetZ(), vector0.GetZ(), 1e-10);

        const double testValue = (vector0.GetX() - vector0.GetY()) * (MathD::Sin(delta) + MathD::Cos(delta));

        ASSERT_APPROXIMATE(twistZAxesVector.GetX() + twistZAxesVector.GetY(), testValue, 1e-10);

        const double curvatureRadius = randomDistribution(generator);
        const double bendCenter = randomDistribution(generator);
        const double bendAreaMin = randomDistribution(generator);
        const double bendAreaMax = bendAreaMin + 1000000.0;

        const Vector3D bendYAxesVector = Vector3ToolsD::BendYAxes(vector0, curvatureRadius, bendCenter, bendAreaMin, bendAreaMax);

        ASSERT_APPROXIMATE(bendYAxesVector.GetX(), vector0.GetX(), 1e-10);

        double y = vector0.GetY();

        if (vector0.GetY() <= bendAreaMin)
            y = bendAreaMin;
        else if (vector0.GetY() >= bendAreaMax)
            y = bendAreaMax;

        delta = 1 / curvatureRadius * (y - bendCenter);

        if (bendAreaMin <= vector0.GetY() && vector0.GetY() <= bendAreaMax)
        {
            ASSERT_APPROXIMATE(bendYAxesVector.GetY(), -MathD::Sin(delta) * (vector0.GetZ() - curvatureRadius) + bendCenter, 1e-10);

            ASSERT_APPROXIMATE(bendYAxesVector.GetZ(), -MathD::Cos(delta) * (vector0.GetZ() - curvatureRadius) + bendCenter, 1e-10);
        }
        else if (vector0.GetY() < bendAreaMin)
        {
            ASSERT_APPROXIMATE(bendYAxesVector.GetY(),
                               -MathD::Sin(delta) * (vector0.GetZ() - curvatureRadius) + bendCenter + MathD::Cos(delta) * (vector0.GetY() - bendAreaMin),
                               1e-10);

            ASSERT_APPROXIMATE(bendYAxesVector.GetZ(),
                               -MathD::Cos(delta) * (vector0.GetZ() - curvatureRadius) + bendCenter + MathD::Sin(delta) * (vector0.GetY() - bendAreaMin),
                               1e-10);
        }
        else
        {
            ASSERT_APPROXIMATE(bendYAxesVector.GetY(),
                               (-MathD::Sin(delta) * (vector0.GetZ() - curvatureRadius) + curvatureRadius + MathD::Cos(delta) * (vector0.GetY() - bendAreaMax)),
                               1e-10);

            ASSERT_APPROXIMATE(bendYAxesVector.GetZ(),
                               (-MathD::Cos(delta) * (vector0.GetZ() - curvatureRadius) + curvatureRadius + MathD::Sin(delta) * (vector0.GetY() - bendAreaMax)),
                               1e-10);
        }
    }
}

void Mathematics::Vector3ToolsTesting::CompareTest()
{
    const Vector3F vector0(6.0f, 8.0f, 9.0f);
    const Vector3F vector1(7.0f, 5.0f, 19.0f);

    ASSERT_TRUE(Vector3ToolsF::Approximate(vector0, vector0));
    ASSERT_TRUE(Vector3ToolsF::Approximate(vector1, vector1));
    ASSERT_FALSE(Vector3ToolsF::Approximate(vector0, vector1));

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

void Mathematics::Vector3ToolsTesting::OtherCalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    std::vector<Vector3D> vectors;

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
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

    Vector3D vector0(randomDistribution(generator),
                     randomDistribution(generator),
                     randomDistribution(generator));
    Vector3D vector1(randomDistribution(generator),
                     randomDistribution(generator),
                     randomDistribution(generator));

    Vector3D vector2(randomDistribution(generator),
                     randomDistribution(generator),
                     randomDistribution(generator));

    vectors.clear();
    vectors.push_back(vector0);
    vectors.push_back(vector1);
    vectors.push_back(vector2);

    const Vector3ToolsD::Vector3Orthonormalize firstOrthonormalize = Vector3ToolsD::Orthonormalize(vector0, vector1, vector2);

    const Vector3ToolsD::Vector3Orthonormalize secondOrthonormaliz = Vector3ToolsD::Orthonormalize(vectors);

    vector0.Normalize();
    double dot0 = Vector3ToolsD::DotProduct(vector0, vector1);
    vector1 -= dot0 * vector0;
    vector1.Normalize();

    const double dot1 = Vector3ToolsD::DotProduct(vector1, vector2);
    dot0 = Vector3ToolsD::DotProduct(vector0, vector2);
    vector2 -= dot0 * vector0 + dot1 * vector1;
    vector2.Normalize();

    ASSERT_TRUE(Vector3ToolsD::Approximate(vector0, firstOrthonormalize.GetUVector()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(vector1, firstOrthonormalize.GetVVector()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(vector2, firstOrthonormalize.GetWVector()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(vector0, secondOrthonormaliz.GetUVector()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(vector1, secondOrthonormaliz.GetVVector()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(vector2, secondOrthonormaliz.GetWVector()));

    Vector3D vector3(randomDistribution(generator),
                     randomDistribution(generator),
                     randomDistribution(generator));

    const Vector3OrthonormalBasisD firstOrthonormalBasis = Vector3ToolsD::GenerateOrthonormalBasis(vector3);

    vector3.Normalize();

    const Vector3OrthonormalBasisD secondOrthonormalBasis = Vector3ToolsD::GenerateComplementBasis(vector3);

    ASSERT_TRUE(Vector3ToolsD::Approximate(vector3, firstOrthonormalBasis.GetWVector()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(vector3, firstOrthonormalBasis.GetWVector()));

    ASSERT_TRUE(Vector3ToolsD::Approximate(firstOrthonormalBasis.GetUVector(), secondOrthonormalBasis.GetUVector()));

    ASSERT_TRUE(Vector3ToolsD::Approximate(firstOrthonormalBasis.GetVVector(), secondOrthonormalBasis.GetVVector()));

    ASSERT_TRUE(Vector3ToolsD::Approximate(firstOrthonormalBasis.GetWVector(),
                                           Vector3ToolsD::CrossProduct(secondOrthonormalBasis.GetUVector(), firstOrthonormalBasis.GetVVector())));

    ASSERT_TRUE(Vector3ToolsD::Approximate(firstOrthonormalBasis.GetUVector(),
                                           Vector3ToolsD::CrossProduct(firstOrthonormalBasis.GetVVector(), secondOrthonormalBasis.GetWVector())));

    ASSERT_TRUE(Vector3ToolsD::Approximate(secondOrthonormalBasis.GetVVector(),
                                           Vector3ToolsD::CrossProduct(firstOrthonormalBasis.GetWVector(), firstOrthonormalBasis.GetUVector())));
}
