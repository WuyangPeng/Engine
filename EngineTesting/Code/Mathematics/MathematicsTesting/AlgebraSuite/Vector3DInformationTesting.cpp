///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:59)

#include "Vector3DInformationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3InformationDetail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

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
    ASSERT_NOT_THROW_EXCEPTION_0(DimensionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AxesAlignBoundingBoxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DirectionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExtremeTest);
}

void Mathematics::Vector3InformationTesting::DimensionTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution{ 0.0001, 0.0002 };
    const uniform_real<double> secondRandomDistribution{ -10.0, 10.0 };

    vector<Vector3D> firstVector;
    vector<Vector3D> secondVector;
    vector<Vector3D> thirdVector;
    vector<Vector3D> fourthVector;
    const double slope = secondRandomDistribution(generator);
    const double yCoordinate = secondRandomDistribution(generator);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D firstEachVector(firstRandomDistribution(generator),
                                       firstRandomDistribution(generator),
                                       firstRandomDistribution(generator));

        firstVector.push_back(firstEachVector);

        const double randomValue = firstRandomDistribution(generator) * secondRandomDistribution(generator);

        const Vector3D secondEachVector(randomValue, yCoordinate, randomValue * slope);

        secondVector.push_back(secondEachVector);

        const Vector3D thirdEachVector(secondRandomDistribution(generator),
                                       secondRandomDistribution(generator),
                                       firstRandomDistribution(generator));

        thirdVector.push_back(thirdEachVector);

        const Vector3D fourthEachVector(secondRandomDistribution(generator),
                                        secondRandomDistribution(generator),
                                        secondRandomDistribution(generator));

        fourthVector.push_back(fourthEachVector);
    }

    thirdVector.push_back(Vector3D(20.0, 80.7, firstRandomDistribution(generator)));
    thirdVector.push_back(Vector3D(120.0, 180.7, firstRandomDistribution(generator)));
    fourthVector.push_back(Vector3D(20.0, 80.7, 20.0));
    fourthVector.push_back(Vector3D(120.0, 180.7, -80.0));

    DoubleVector3Information firstInformation(firstVector, 0.0001);

    ASSERT_EQUAL(firstInformation.GetDimension(), 0);

    DoubleVector3Information secondInformation(secondVector, 0.0001);

    ASSERT_EQUAL(secondInformation.GetDimension(), 1);

    DoubleVector3Information thirdInformation(thirdVector, 0.0001);

    ASSERT_EQUAL(thirdInformation.GetDimension(), 2);

    DoubleVector3Information fourthInformation(fourthVector, 0.0001);

    ASSERT_EQUAL(fourthInformation.GetDimension(), 3);
}

void Mathematics::Vector3InformationTesting::AxesAlignBoundingBoxTest()
{
    default_random_engine generator{};

    const uniform_real<double> randomDistribution{ -100.0f, 100.0f };

    vector<Vector3D> vectors;

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

    ASSERT_TRUE(Vector3ToolsD::Approximate(aabb.GetMinPoint(), secondInformation.GetAABB().GetMinPoint()));

    ASSERT_TRUE(Vector3ToolsD::Approximate(aabb.GetMaxPoint(), secondInformation.GetAABB().GetMaxPoint()));

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
    default_random_engine generator{};

    const uniform_real<double> randomDistribution{ -100.0f, 100.0f };

    vector<Vector3D> vectors;

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D eachVector(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        vectors.push_back(eachVector);
    }

    DoubleVector3Information information(vectors);

    const auto ptr = information.GetAABB();

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
    default_random_engine generator{};

    const uniform_real<double> randomDistribution{ -100.0f, 100.0f };

    vector<Vector3D> vectors;

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D eachVector(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        vectors.push_back(eachVector);
    }

    DoubleVector3Information information(vectors);

    const auto ptr = information.GetAABB();

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
