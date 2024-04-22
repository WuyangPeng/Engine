///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:22)

#include "Query2FilteredTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Query/Query2FilteredDetail.h"

#include <random>

namespace Mathematics
{
    template class Query2Filtered<double>;
    template class Query2Filtered<float>;
}

Mathematics::Query2FilteredTesting::Query2FilteredTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Query2FilteredTesting)

void Mathematics::Query2FilteredTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Query2FilteredTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VerticesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TriangleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CircumcircleTest);
}

void Mathematics::Query2FilteredTesting::VerticesTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(1, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        auto size = randomDistribution1(generator);

        for (auto m = 0; m < size; ++m)
        {
            vertices.push_back(Vector2(randomDistribution0(generator), randomDistribution0(generator)));
        }

        Query2FilteredD query(vertices, 0.0);

        ASSERT_EQUAL(query.GetType(), QueryType::Filtered);
        ASSERT_EQUAL(query.GetNumVertices(), size);

        for (auto m = 0; m < size; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, query.GetVertex(m), vertices.at(m), 1e-10);
        }
    }
}

void Mathematics::Query2FilteredTesting::LineTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(1, 50);
    std::uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector2D> firstVertices;
        std::vector<Vector2D> secondVertices;
        auto size = randomDistribution1(generator);

        for (auto m = 0; m < size; ++m)
        {
            firstVertices.push_back(Vector2(randomDistribution0(generator), randomDistribution0(generator)));
            secondVertices.push_back(Vector2(thirdRandomDistribution(generator), thirdRandomDistribution(generator)));
        }

        std::uniform_int<> thirdRandomDistribution1(0, size - 1);

        auto firstIndex = thirdRandomDistribution1(generator);
        auto secondIndex = thirdRandomDistribution1(generator);
        auto thirdIndex = thirdRandomDistribution1(generator);

        Query2FilteredD firstQuery(firstVertices, 0.0);

        ASSERT_EQUAL(firstQuery.ToLine(secondIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
        ASSERT_EQUAL(firstQuery.ToLine(thirdIndex, secondIndex, thirdIndex), LineQueryType::OnLine);

        if (firstIndex != secondIndex && secondIndex != thirdIndex && firstIndex != thirdIndex)
        {
            const auto& vector0 = firstVertices.at(firstIndex);
            const auto& vector1 = firstVertices.at(secondIndex);
            const auto& vector2 = firstVertices.at(thirdIndex);

            auto dotPerp = Vector2ToolsD::DotPerp(vector0 - vector1, vector2 - vector1);

            if (0.0 < dotPerp)
            {
                ASSERT_EQUAL(firstQuery.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::Right);
            }
            else if (dotPerp < 0.0)
            {
                ASSERT_EQUAL(firstQuery.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::Left);
            }
            else
            {
                ASSERT_EQUAL(firstQuery.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
            }
        }

        Query2FilteredD secondQuery(secondVertices, 1.0);
        Query2RationalD thirdQuery(secondVertices);

        ASSERT_EQUAL(secondQuery.ToLine(firstIndex, secondIndex, thirdIndex), thirdQuery.ToLine(firstIndex, secondIndex, thirdIndex));
    }
}

void Mathematics::Query2FilteredTesting::TriangleTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(1, 50);
    std::uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector2D> firstVertices;
        std::vector<Vector2D> secondVertices;
        auto size = randomDistribution1(generator);

        for (int m = 0; m < size; ++m)
        {
            firstVertices.push_back(Vector2(randomDistribution0(generator), randomDistribution0(generator)));
            secondVertices.push_back(Vector2(thirdRandomDistribution(generator), thirdRandomDistribution(generator)));
        }

        std::uniform_int<> thirdRandomDistribution1(0, size - 1);

        auto firstIndex = thirdRandomDistribution1(generator);
        auto secondIndex = thirdRandomDistribution1(generator);
        auto thirdIndex = thirdRandomDistribution1(generator);
        auto fourthIndex = thirdRandomDistribution1(generator);

        Query2FilteredD firstQuery(firstVertices, 0.0);
        if (firstQuery.ToLine(secondIndex, thirdIndex, fourthIndex) == LineQueryType::Right)
        {
            std::swap(secondIndex, thirdIndex);
        }

        ASSERT_EQUAL(firstQuery.ToTriangle(secondIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        ASSERT_EQUAL(firstQuery.ToTriangle(thirdIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        ASSERT_EQUAL(firstQuery.ToTriangle(fourthIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);

        const auto sign0 = firstQuery.ToLine(firstIndex, thirdIndex, fourthIndex);
        const auto sign1 = firstQuery.ToLine(firstIndex, secondIndex, fourthIndex);
        const auto sign2 = firstQuery.ToLine(firstIndex, secondIndex, thirdIndex);

        if (sign0 == LineQueryType::Right || sign1 == LineQueryType::Left || sign2 == LineQueryType::Right)
        {
            ASSERT_EQUAL(firstQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::Outside);
        }
        else if (sign0 == LineQueryType::OnLine || sign1 == LineQueryType::OnLine || sign2 == LineQueryType::OnLine)
        {
            ASSERT_EQUAL(firstQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        }
        else
        {
            ASSERT_EQUAL(firstQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::Inside);
        }

        Query2FilteredD secondQuery(secondVertices, 1.0);
        Query2RationalD thirdQuery(secondVertices);

        if (secondQuery.ToLine(secondIndex, thirdIndex, fourthIndex) == LineQueryType::Right)
        {
            std::swap(secondIndex, thirdIndex);
        }

        ASSERT_EQUAL(secondQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), thirdQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex));
    }
}

void Mathematics::Query2FilteredTesting::CircumcircleTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(1, 50);
    const std::uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector2D> firstVertices;
        std::vector<Vector2D> secondVertices;
        auto size = randomDistribution1(generator);

        for (auto m = 0; m < size; ++m)
        {
            firstVertices.push_back(Vector2(randomDistribution0(generator), randomDistribution0(generator)));
            secondVertices.push_back(Vector2(randomDistribution0(generator), randomDistribution0(generator)));
        }

        std::uniform_int<> thirdRandomDistribution1(0, size - 1);

        auto firstIndex = thirdRandomDistribution1(generator);
        auto secondIndex = thirdRandomDistribution1(generator);
        auto thirdIndex = thirdRandomDistribution1(generator);
        auto fourthIndex = thirdRandomDistribution1(generator);

        Query2FilteredD firstQuery(firstVertices, 0.0);

        ASSERT_EQUAL(firstQuery.ToCircumcircle(secondIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
        ASSERT_EQUAL(firstQuery.ToCircumcircle(thirdIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
        ASSERT_EQUAL(firstQuery.ToCircumcircle(fourthIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);

        if (firstIndex != secondIndex && secondIndex != thirdIndex &&
            thirdIndex != fourthIndex && fourthIndex != firstIndex &&
            secondIndex != fourthIndex && firstIndex != thirdIndex)
        {
            const auto& vector0 = firstVertices.at(firstIndex);
            const auto& vector1 = firstVertices.at(secondIndex);
            const auto& vector2 = firstVertices.at(thirdIndex);
            const auto& vector3 = firstVertices.at(fourthIndex);

            auto lhsPlusTest = vector1 + vector0;
            auto lhsMinusTest = vector1 - vector0;
            auto mhsPlusTest = vector2 + vector0;
            auto mhsMinusTest = vector2 - vector0;
            auto rhsPlusTest = vector3 + vector0;
            auto rhsMinusTest = vector3 - vector0;
            auto z0 = Vector2ToolsD::DotProduct(lhsPlusTest, lhsMinusTest);
            auto z1 = Vector2ToolsD::DotProduct(mhsPlusTest, mhsMinusTest);
            auto z2 = Vector2ToolsD::DotProduct(rhsPlusTest, rhsMinusTest);

            const Vector3D vector4(lhsMinusTest[0], lhsMinusTest[1], z0);
            const Vector3D vector5(mhsMinusTest[0], mhsMinusTest[1], z1);
            const Vector3D seventhVector(rhsMinusTest[0], rhsMinusTest[1], z2);

            auto dot = Vector3ToolsD::ScalarTripleProduct(vector4, vector5, seventhVector);
            if (0.0 < dot)
            {
                ASSERT_EQUAL(firstQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::Inside);
            }
            else if (dot < 0.0)
            {
                ASSERT_EQUAL(firstQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::Outside);
            }
            else
            {
                ASSERT_EQUAL(firstQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
            }
        }

        Query2FilteredD secondQuery(secondVertices, 1.0);
        Query2RationalD thirdQuery(secondVertices);

        ASSERT_EQUAL(secondQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), thirdQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex));
    }
}
