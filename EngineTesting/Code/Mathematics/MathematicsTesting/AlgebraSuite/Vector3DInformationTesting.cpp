///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:42)

#include "Vector3DInformationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3InformationDetail.h"
#include "Mathematics/Algebra/Vector3Tools.h"

#include <random>

namespace Mathematics
{
    template class Vector3Information<float>;
    template class Vector3Information<double>;
}

Mathematics::Vector3InformationTesting::Vector3InformationTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Vector3InformationTesting)

void Mathematics::Vector3InformationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Vector3InformationTesting::MainTest()
{
   // ASSERT_NOT_THROW_EXCEPTION_0(DimensionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AxesAlignBoundingBoxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DirectionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExtremeTest);
}

void Mathematics::Vector3InformationTesting::DimensionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real<double> randomDistribution0{ 0.0001, 0.0002 };
    std::uniform_real<double> randomDistribution1{ -5.0, 5.1 };

    std::vector<Vector3D> vector0;
    std::vector<Vector3D> vector1;
    std::vector<Vector3D> vector2;
    std::vector<Vector3D> vector3;
    const double slope = randomDistribution1(generator);
    const double yCoordinate = randomDistribution1(generator);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D eachVector0(randomDistribution0(generator),
                                   randomDistribution0(generator),
                                   randomDistribution0(generator));

        vector0.push_back(eachVector0);

        const double randomValue = randomDistribution0(generator) * randomDistribution1(generator);

        const Vector3D eachVector1(randomValue, yCoordinate, randomValue * slope);

        vector1.push_back(eachVector1);

        const Vector3D eachVector2(randomDistribution1(generator),
                                   randomDistribution1(generator),
                                   randomDistribution0(generator));

        vector2.push_back(eachVector2);

        const Vector3D eachVector3(randomDistribution1(generator),
                                   randomDistribution1(generator),
                                   randomDistribution1(generator));

        vector3.push_back(eachVector3);
    }

    vector2.emplace_back(20.0, 80.7, randomDistribution0(generator));
    vector2.emplace_back(120.0, 180.7, randomDistribution0(generator));
    vector3.emplace_back(20.0, 80.7, 20.0);
    vector3.emplace_back(120.0, 180.7, -80.0);

    DoubleVector3Information information0(vector0, 0.0001);

    ASSERT_EQUAL(information0.GetDimension(), 0);

    DoubleVector3Information information1(vector1, 0.0001);

    ASSERT_EQUAL(information1.GetDimension(), 1);

    DoubleVector3Information information2(vector2, 0.0001);

    ASSERT_EQUAL(information2.GetDimension(), 2);

    DoubleVector3Information information3(vector3, 0.0001);

    ASSERT_EQUAL(information3.GetDimension(), 3);
}

void Mathematics::Vector3InformationTesting::AxesAlignBoundingBoxTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real<double> randomDistribution{ -100.0f, 100.0f };

    std::vector<Vector3D> vectors;

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D eachVector(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        vectors.push_back(eachVector);
    }

    const auto aabb = Vector3ToolsD::ComputeExtremes(vectors);
    DoubleVector3Information secondInformation(vectors);

    ASSERT_TRUE(Vector3ToolsD::Approximate(aabb.GetMinPoint(), secondInformation.GetAxesAlignBoundingBox().GetMinPoint()));

    ASSERT_TRUE(Vector3ToolsD::Approximate(aabb.GetMaxPoint(), secondInformation.GetAxesAlignBoundingBox().GetMaxPoint()));

    const double xRange = aabb.GetMaxPoint().GetX() - aabb.GetMinPoint().GetX();

    const double yRange = aabb.GetMaxPoint().GetY() - aabb.GetMinPoint().GetY();

    const double zRange = aabb.GetMaxPoint().GetZ() - aabb.GetMinPoint().GetZ();

    if (xRange < yRange && zRange < yRange)
    {
        ASSERT_APPROXIMATE(yRange, secondInformation.GetMaxRange(), 1e-10);
    }
    else if (zRange < xRange)
    {
        ASSERT_APPROXIMATE(xRange, secondInformation.GetMaxRange(), 1e-10);
    }
    else
    {
        ASSERT_APPROXIMATE(zRange, secondInformation.GetMaxRange(), 1e-10);
    }
}

void Mathematics::Vector3InformationTesting::DirectionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real<double> randomDistribution{ -100.0f, 100.0f };

    std::vector<Vector3D> vectors;

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D eachVector(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        vectors.push_back(eachVector);
    }

    DoubleVector3Information information(vectors);

    const auto ptr = information.GetAxesAlignBoundingBox();

    Vector3D minVector = ptr.GetMinPoint();
    Vector3D maxVector = ptr.GetMaxPoint();

    const double xRange = maxVector.GetX() - minVector.GetX();

    const double yRange = maxVector.GetY() - minVector.GetY();

    const double zRange = maxVector.GetZ() - minVector.GetZ();

    if (xRange < yRange && zRange < yRange)
    {
        for (const auto& eachVector : vectors)
        {
            if (MathD::FAbs(eachVector.GetY() - minVector.GetY()) <= 1e-10)
            {
                minVector = eachVector;
                break;
            }
        }

        for (const auto& eachVector : vectors)
        {
            if (MathD::FAbs(eachVector.GetY() - maxVector.GetY()) <= 1e-10)
            {
                maxVector = eachVector;
                break;
            }
        }
    }
    else if (zRange < xRange)
    {
        for (const auto& eachVector : vectors)
        {
            if (MathD::FAbs(eachVector.GetX() - minVector.GetX()) <= 1e-10)
            {
                minVector = eachVector;
                break;
            }
        }

        for (const auto& eachVector : vectors)
        {
            if (MathD::FAbs(eachVector.GetX() - maxVector.GetX()) <= 1e-10)
            {
                maxVector = eachVector;
                break;
            }
        }
    }
    else
    {
        for (const auto& eachVector : vectors)
        {
            if (MathD::FAbs(eachVector.GetZ() - minVector.GetZ()) <= 1e-10)
            {
                minVector = eachVector;
                break;
            }
        }

        for (const auto& eachVector : vectors)
        {
            if (MathD::FAbs(eachVector.GetZ() - maxVector.GetZ()) <= 1e-10)
            {
                maxVector = eachVector;
                break;
            }
        }
    }

    Vector3D directionX = maxVector - minVector;
    directionX.Normalize();

    Vector3D directionY = information.GetPerpendicularExtreme() - information.GetOrigin();
    const double dot = Vector3ToolsD::DotProduct(directionX, directionY);
    directionY -= dot * directionX;
    directionY.Normalize();

    const Vector3D directionZ = Vector3ToolsD::CrossProduct(directionX, directionY);

    ASSERT_TRUE(Vector3ToolsD::Approximate(minVector, information.GetOrigin()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(directionX, information.GetDirectionX()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(directionY, information.GetDirectionY()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(directionZ, information.GetDirectionZ()));
}

void Mathematics::Vector3InformationTesting::ExtremeTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real<double> randomDistribution{ -100.0f, 100.0f };

    std::vector<Vector3D> vectors;

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D eachVector(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        vectors.push_back(eachVector);
    }

    DoubleVector3Information information(vectors);

    const auto ptr = information.GetAxesAlignBoundingBox();

    Vector3D minVector = ptr.GetMinPoint();
    Vector3D maxVector = ptr.GetMaxPoint();

    const double xRange = maxVector.GetX() - minVector.GetX();

    const double yRange = maxVector.GetY() - minVector.GetY();

    const double zRange = maxVector.GetZ() - minVector.GetZ();

    if (xRange < yRange && zRange < yRange)
    {
        for (const auto& eachVector : vectors)
        {
            if (MathD::FAbs(eachVector.GetY() - minVector.GetY()) <= 1e-10)
            {
                minVector = eachVector;
                break;
            }
        }

        for (const auto& eachVector : vectors)
        {
            if (MathD::FAbs(eachVector.GetY() - maxVector.GetY()) <= 1e-10)
            {
                maxVector = eachVector;
                break;
            }
        }
    }
    else if (zRange < xRange)
    {
        for (const auto& eachVector : vectors)
        {
            if (MathD::FAbs(eachVector.GetX() - minVector.GetX()) <= 1e-10)
            {
                minVector = eachVector;
                break;
            }
        }

        for (const auto& eachVector : vectors)
        {
            if (MathD::FAbs(eachVector.GetX() - maxVector.GetX()) <= 1e-10)
            {
                maxVector = eachVector;
                break;
            }
        }
    }
    else
    {
        for (const auto& eachVector : vectors)
        {
            if (MathD::FAbs(eachVector.GetZ() - minVector.GetZ()) <= 1e-10)
            {
                minVector = eachVector;
                break;
            }
        }

        for (const auto& eachVector : vectors)
        {
            if (MathD::FAbs(eachVector.GetZ() - maxVector.GetZ()) <= 1e-10)
            {
                maxVector = eachVector;
                break;
            }
        }
    }

    ASSERT_TRUE(Vector3ToolsD::Approximate(minVector, information.GetMinExtreme()));
    ASSERT_TRUE(Vector3ToolsD::Approximate(maxVector, information.GetMaxExtreme()));

    double maxDistance = 0.0;
    Vector3D perpendicularExtreme;
    for (const auto& eachVector : vectors)
    {
        const Vector3D diff = eachVector - information.GetOrigin();
        const double dot = Vector3ToolsD::DotProduct(information.GetDirectionX(), diff);
        const Vector3D proj = diff - dot * information.GetDirectionX();
        const double distance = Vector3ToolsD::GetLength(proj);

        if (maxDistance < distance)
        {
            maxDistance = distance;
            perpendicularExtreme = eachVector;
        }
    }

    ASSERT_TRUE(Vector3ToolsD::Approximate(perpendicularExtreme, information.GetPerpendicularExtreme()));

    maxDistance = 0.0;
    NumericalValueSymbol maxSign = NumericalValueSymbol::Zero;
    Vector3D tetrahedronExtreme;
    for (const auto& eachVector : vectors)
    {
        const Vector3D diff = eachVector - information.GetOrigin();
        double distance = Vector3ToolsD::DotProduct(information.GetDirectionZ(), diff);
        const NumericalValueSymbol sign = MathD::Sign(distance);
        distance = MathD::FAbs(distance);
        if (maxDistance < distance)
        {
            maxDistance = distance;
            maxSign = sign;
            tetrahedronExtreme = eachVector;
        }
    }

    ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedronExtreme, information.GetTetrahedronExtreme()));
}
