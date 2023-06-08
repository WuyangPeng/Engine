///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:56)

#include "Vector2DInformationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2Detail.h"
#include "Mathematics/Algebra/Vector2InformationDetail.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class Vector2Information<float>;
    template class Vector2Information<double>;
}

Mathematics::Vector2InformationTesting::Vector2InformationTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Vector2InformationTesting)

void Mathematics::Vector2InformationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Vector2InformationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DimensionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AxesAlignBoundingBoxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DirectionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExtremeTest);
}

void Mathematics::Vector2InformationTesting::DimensionTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution{ 0.0001, 0.0002 };
    const uniform_real<double> secondRandomDistribution(-10.0, 10.0);

    vector<Vector2D> firstVector;
    vector<Vector2D> secondVector;
    vector<Vector2D> thirdVector;
    const double slope = secondRandomDistribution(generator);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 firstEachVector(firstRandomDistribution(generator), firstRandomDistribution(generator));

        firstVector.push_back(firstEachVector);

        const double randomValue = firstRandomDistribution(generator) * secondRandomDistribution(generator);

        const Vector2 secondEachVector(randomValue, randomValue * slope);

        secondVector.push_back(secondEachVector);

        const Vector2 thirdEachVector(secondRandomDistribution(generator), secondRandomDistribution(generator));

        thirdVector.push_back(thirdEachVector);
    }

    thirdVector.push_back(Vector2(20.0, 80.7));
    thirdVector.push_back(Vector2(120.0, 180.7));

    Vector2InformationD firstInformation(firstVector, 0.0001);

    ASSERT_EQUAL(firstInformation.GetDimension(), 0);

    Vector2InformationD secondInformation(secondVector, 0.0001);

    ASSERT_EQUAL(secondInformation.GetDimension(), 1);

    Vector2InformationD thirdInformation(thirdVector, 0.0001);

    ASSERT_EQUAL(thirdInformation.GetDimension(), 2);
}

void Mathematics::Vector2InformationTesting::AxesAlignBoundingBoxTest()
{
    default_random_engine generator{};

    const uniform_real<double> randomDistribution{ -100.0f, 100.0f };

    vector<Vector2D> vectors;

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vectors.emplace_back(randomDistribution(generator), randomDistribution(generator));
    }

    const auto aabb = Vector2ToolsD::ComputeExtremes(vectors);
    Vector2InformationD secondInformation(vectors);

    ASSERT_TRUE(Vector2ToolsD::Approximate(aabb.GetMinPoint(), secondInformation.GetAABB().GetMinPoint()));

    ASSERT_TRUE(Vector2ToolsD::Approximate(aabb.GetMaxPoint(), secondInformation.GetAABB().GetMaxPoint()));

    const double xRange = aabb.GetMaxPoint().GetX() - aabb.GetMinPoint().GetX();

    const double yRange = aabb.GetMaxPoint().GetY() - aabb.GetMinPoint().GetY();

    if (xRange < yRange)
    {
        ASSERT_APPROXIMATE(yRange, secondInformation.GetMaxRange(), 1e-10);
    }
    else
    {
        ASSERT_APPROXIMATE(xRange, secondInformation.GetMaxRange(), 1e-10);
    }
}

void Mathematics::Vector2InformationTesting::DirectionTest()
{
    default_random_engine generator{};

    const uniform_real<double> randomDistribution{ -100.0f, 100.0f };

    vector<Vector2D> vectors;

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vectors.emplace_back(randomDistribution(generator), randomDistribution(generator));
    }

    Vector2InformationD information(vectors);

    const auto ptr = information.GetAABB();

    Vector2 minVector = ptr.GetMinPoint();
    Vector2 maxVector = ptr.GetMaxPoint();

    const double xRange = maxVector.GetX() - minVector.GetX();

    const double yRange = maxVector.GetY() - minVector.GetY();

    if (xRange < yRange)
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
    else
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

    Vector2 directionX = maxVector - minVector;
    directionX.Normalize();
    const Vector2 directionY = -Vector2ToolsD::GetPerp(directionX);

    ASSERT_TRUE(Vector2ToolsD::Approximate(minVector, information.GetOrigin()));
    ASSERT_TRUE(Vector2ToolsD::Approximate(directionX, information.GetDirectionX()));
    ASSERT_TRUE(Vector2ToolsD::Approximate(directionY, information.GetDirectionY()));
}

void Mathematics::Vector2InformationTesting::ExtremeTest()
{
    default_random_engine generator{};

    const uniform_real<double> randomDistribution{ -100.0f, 100.0f };

    vector<Vector2D> vectors;

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 eachVector(randomDistribution(generator), randomDistribution(generator));

        vectors.push_back(eachVector);
    }

    Vector2InformationD information(vectors);

    const auto ptr = information.GetAABB();

    Vector2 minVector = ptr.GetMinPoint();
    Vector2 maxVector = ptr.GetMaxPoint();

    const double xRange = maxVector.GetX() - minVector.GetX();

    const double yRange = maxVector.GetY() - minVector.GetY();

    if (xRange < yRange)
    {
        for (const auto& eachVector : vectors)
        {
            if (MathD::FAbs(eachVector.GetY() -
                            minVector.GetY()) <= 1e-10)
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
    else
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

    ASSERT_TRUE(Vector2ToolsD::Approximate(minVector, information.GetMinExtreme()));
    ASSERT_TRUE(Vector2ToolsD::Approximate(maxVector, information.GetMaxExtreme()));

    double maxDistance = 0.0;
    NumericalValueSymbol maxSign = NumericalValueSymbol::Zero;
    Vector2D perpendicularExtreme;
    for (const auto& eachVector : vectors)
    {
        const Vector2 diff = eachVector - information.GetOrigin();
        double distance = Vector2ToolsD::DotProduct(information.GetDirectionY(), diff);
        const NumericalValueSymbol sign = MathD::Sign(distance);
        distance = MathD::FAbs(distance);
        if (maxDistance < distance)
        {
            maxDistance = distance;
            maxSign = sign;
            perpendicularExtreme = eachVector;
        }
    }

    ASSERT_TRUE(Vector2ToolsD::Approximate(perpendicularExtreme, information.GetPerpendicularExtreme()));
}
