// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.2 (2019/08/22 13:27)

#include "Vector4DToolsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Algebra/Vector4Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Vector4Tools<float>;
    template class Vector4Tools<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Vector4ToolsTesting)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
void Mathematics::Vector4ToolsTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProductTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OtherCalculateTest);
}

void Mathematics::Vector4ToolsTesting ::DistanceTest()
{
    Vector4F firstVector(3.0f, 4.0f, 5.0f, 3.0f);

    ASSERT_APPROXIMATE(Vector4ToolsF::GetLength(firstVector), MathF::Sqrt(59.0f), 1e-8f);
    ASSERT_APPROXIMATE(Vector4ToolsF::GetLengthSquared(firstVector), 59.0f, 1e-8f);

    Vector4F secondVector(6.0f, 8.0f, 5.0f, 3.0f);

    ASSERT_APPROXIMATE(Vector4ToolsF::Distance(firstVector, secondVector), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(Vector4ToolsF::DistanceSquared(firstVector, secondVector), 25.0f, 1e-8f);
}

void Mathematics::Vector4ToolsTesting ::ProductTest()
{
    default_random_engine generator{};

    uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector4D firstVector(randomDistribution(generator),
                                   randomDistribution(generator),
                                   randomDistribution(generator),
                                   randomDistribution(generator));

        Vector4D secondVector(randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator));

        double dotProduct = firstVector[0] * secondVector[0] +
                            firstVector[1] * secondVector[1] +
                            firstVector[2] * secondVector[2] +
                            firstVector[3] * secondVector[3];

        ASSERT_APPROXIMATE(Vector4ToolsD::DotProduct(firstVector, secondVector), dotProduct, 1e-10);
    }
}

void Mathematics::Vector4ToolsTesting ::ProjectionTest()
{
    default_random_engine generator{};

    uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector4D firstVector(randomDistribution(generator),
                                   randomDistribution(generator),
                                   randomDistribution(generator),
                                   randomDistribution(generator));

        Vector4D secondVector(randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator));

        double moduleSquare = Vector4ToolsD::GetLengthSquared(secondVector);
        Vector4D parallelVector = secondVector * (Vector4ToolsD::DotProduct(firstVector, secondVector) / moduleSquare);

        ASSERT_TRUE(Vector4ToolsD::Approximate(parallelVector, Vector4ToolsD::ParallelVectorLhsToRhs(firstVector, secondVector)));

        Vector4D apeakVector = firstVector - parallelVector;

        ASSERT_TRUE(Vector4ToolsD::Approximate(apeakVector, Vector4ToolsD::ApeakVectorLhsToRhs(firstVector, secondVector)));

        double angle = MathD::ACos(Vector4ToolsD::DotProduct(firstVector, secondVector) / (Vector4ToolsD::GetLength(firstVector) * Vector4ToolsD::GetLength(secondVector)));

        ASSERT_APPROXIMATE(angle, Vector4ToolsD::GetVectorIncludedAngle(firstVector, secondVector), 1e-10);
    }
}

void Mathematics::Vector4ToolsTesting ::CompareTest()
{
    Vector4F firstVector(6.0f, 8.0f, 9.0f, 3.0f);
    Vector4F secondVector(7.0f, 5.0f, 19.0f, 32.0f);

    ASSERT_TRUE(Vector4ToolsF::Approximate(firstVector, firstVector));
    ASSERT_TRUE(Vector4ToolsF::Approximate(secondVector, secondVector));
    ASSERT_FALSE(Vector4ToolsF::Approximate(firstVector, secondVector));

    ASSERT_TRUE(firstVector == firstVector);
    ASSERT_FALSE(firstVector == secondVector);
    ASSERT_TRUE(firstVector != secondVector);
    ASSERT_TRUE(firstVector < secondVector);
    ASSERT_TRUE(firstVector <= secondVector);
    ASSERT_FALSE(firstVector > secondVector);
    ASSERT_FALSE(firstVector >= secondVector);

    GetStream() << "�����ǵ�����Ϣ��\n";
    GetStream() << firstVector << '\n';
    GetStream() << secondVector << '\n';
}

void Mathematics::Vector4ToolsTesting ::OtherCalculateTest()
{
    default_random_engine generator{};

    uniform_real<double> randomDistribution{ -100.0, 100.0 };

    vector<Vector4D> vectors;

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector4D eachVector(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        vectors.push_back(eachVector);
    }

    auto aabb = Vector4ToolsD::ComputeExtremes(vectors);
    Vector4D minVector = aabb.GetMinPoint();
    Vector4D maxVector = aabb.GetMaxPoint();

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
