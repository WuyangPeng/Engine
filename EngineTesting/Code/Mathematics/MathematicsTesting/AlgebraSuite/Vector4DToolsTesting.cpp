// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.2 (2019/08/22 13:27)

#include "Vector4DToolsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector4DToolsDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Vector4DTools<float>;
    template class Vector4DTools<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Vector4DToolsTesting)

void Mathematics::Vector4DToolsTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProductTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OtherCalculateTest);
}

void Mathematics::Vector4DToolsTesting ::DistanceTest()
{
    FloatVector4D firstVector(3.0f, 4.0f, 5.0f, 3.0f);

    ASSERT_APPROXIMATE(FloatVector4DTools::VectorMagnitude(firstVector), FloatMath::Sqrt(59.0f), 1e-8f);
    ASSERT_APPROXIMATE(FloatVector4DTools::VectorMagnitudeSquared(firstVector), 59.0f, 1e-8f);

    FloatVector4D secondVector(6.0f, 8.0f, 5.0f, 3.0f);

    ASSERT_APPROXIMATE(FloatVector4DTools::Distance(firstVector, secondVector), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(FloatVector4DTools::DistanceSquared(firstVector, secondVector), 25.0f, 1e-8f);
}

void Mathematics::Vector4DToolsTesting ::ProductTest()
{
    default_random_engine generator{};

    uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleVector4D firstVector(randomDistribution(generator),
                                   randomDistribution(generator),
                                   randomDistribution(generator),
                                   randomDistribution(generator));

        DoubleVector4D secondVector(randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator));

        double dotProduct = firstVector[0] * secondVector[0] +
                            firstVector[1] * secondVector[1] +
                            firstVector[2] * secondVector[2] +
                            firstVector[3] * secondVector[3];

        ASSERT_APPROXIMATE(DoubleVector4DTools::DotProduct(firstVector, secondVector), dotProduct, 1e-10);
    }
}

void Mathematics::Vector4DToolsTesting ::ProjectionTest()
{
    default_random_engine generator{};

    uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleVector4D firstVector(randomDistribution(generator),
                                   randomDistribution(generator),
                                   randomDistribution(generator),
                                   randomDistribution(generator));

        DoubleVector4D secondVector(randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator));

        double moduleSquare = DoubleVector4DTools::VectorMagnitudeSquared(secondVector);
        DoubleVector4D parallelVector = secondVector * (DoubleVector4DTools::DotProduct(firstVector, secondVector) / moduleSquare);

        ASSERT_TRUE(DoubleVector4DTools::Approximate(parallelVector, DoubleVector4DTools::ParallelVectorLhsToRhs(firstVector, secondVector)));

        DoubleVector4D apeakVector = firstVector - parallelVector;

        ASSERT_TRUE(DoubleVector4DTools::Approximate(apeakVector, DoubleVector4DTools::ApeakVectorLhsToRhs(firstVector, secondVector)));

        double angle = DoubleMath::ACos(DoubleVector4DTools::DotProduct(firstVector, secondVector) / (DoubleVector4DTools::VectorMagnitude(firstVector) * DoubleVector4DTools::VectorMagnitude(secondVector)));

        ASSERT_APPROXIMATE(angle, DoubleVector4DTools::GetVectorIncludedAngle(firstVector, secondVector), 1e-10);
    }
}

void Mathematics::Vector4DToolsTesting ::CompareTest()
{
    FloatVector4D firstVector(6.0f, 8.0f, 9.0f, 3.0f);
    FloatVector4D secondVector(7.0f, 5.0f, 19.0f, 32.0f);

    ASSERT_TRUE(FloatVector4DTools::Approximate(firstVector, firstVector));
    ASSERT_TRUE(FloatVector4DTools::Approximate(secondVector, secondVector));
    ASSERT_FALSE(FloatVector4DTools::Approximate(firstVector, secondVector));

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

void Mathematics::Vector4DToolsTesting ::OtherCalculateTest()
{
    default_random_engine generator{};

    uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<DoubleVector4D> vectors;

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleVector4D eachVector(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        vectors.push_back(eachVector);
    }

    auto aabb = DoubleVector4DTools::ComputeExtremes(vectors);
    DoubleVector4D minVector = aabb.GetMinPoint();
    DoubleVector4D maxVector = aabb.GetMaxPoint();

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
