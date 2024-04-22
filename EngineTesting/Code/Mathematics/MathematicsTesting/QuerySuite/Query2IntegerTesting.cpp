///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:23)

#include "Query2IntegerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Query/Query2IntegerDetail.h"
#include "Mathematics/Query/QuerySortTools.h"

#include <random>

namespace Mathematics
{
    template class Query2Integer<double>;
    template class Query2Integer<float>;
}

Mathematics::Query2IntegerTesting::Query2IntegerTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Query2IntegerTesting)

void Mathematics::Query2IntegerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Query2IntegerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VerticesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TriangleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CircumcircleTest);
}

void Mathematics::Query2IntegerTesting::VerticesTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(1, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        const auto size = randomDistribution1(generator);

        for (auto m = 0; m < size; ++m)
        {
            vertices.push_back(Vector2D(randomDistribution0(generator), randomDistribution0(generator)));
        }

        Query2IntegerD query(vertices);

        ASSERT_EQUAL(query.GetType(), QueryType::Integer);
        ASSERT_EQUAL(query.GetNumVertices(), size);

        for (auto m = 0; m < size; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, query.GetVertex(m), vertices.at(m), 1e-10);
        }
    }
}

void Mathematics::Query2IntegerTesting::LineTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(1, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        const auto size = randomDistribution1(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector2(randomDistribution0(generator), randomDistribution0(generator)));
        }

        std::uniform_int<> thirdRandomDistribution(0, size - 1);

        auto secondIndex = thirdRandomDistribution(generator);
        auto thirdIndex = thirdRandomDistribution(generator);

        Query2IntegerD query(vertices);

        ASSERT_EQUAL(query.ToLine(secondIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
        ASSERT_EQUAL(query.ToLine(thirdIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
    }
}

void Mathematics::Query2IntegerTesting::TriangleTest()
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

        std::uniform_int<> thirdRandomDistribution(0, size - 1);

        auto firstIndex = thirdRandomDistribution(generator);
        auto secondIndex = thirdRandomDistribution(generator);
        auto thirdIndex = thirdRandomDistribution(generator);
        auto fourthIndex = thirdRandomDistribution(generator);

        Query2IntegerD query(vertices);
        if (query.ToLine(secondIndex, thirdIndex, fourthIndex) == LineQueryType::Right)
        {
            std::swap(secondIndex, thirdIndex);
        }

        const Vector2 vector0 = vertices.at(firstIndex);
        const Vector2 vector1 = vertices.at(secondIndex);
        const Vector2 vector2 = vertices.at(thirdIndex);
        const Vector2 vector3 = vertices.at(fourthIndex);

        ASSERT_EQUAL(query.ToTriangle(secondIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        ASSERT_EQUAL(query.ToTriangle(thirdIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        ASSERT_EQUAL(query.ToTriangle(fourthIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);

        const LineQueryType sign0 = query.ToLine(firstIndex, thirdIndex, fourthIndex);
        const LineQueryType sign1 = query.ToLine(firstIndex, secondIndex, fourthIndex);
        const LineQueryType sign2 = query.ToLine(firstIndex, secondIndex, thirdIndex);

        if (sign0 == LineQueryType::Right || sign1 == LineQueryType::Left ||
            sign2 == LineQueryType::Right)
        {
            ASSERT_EQUAL(query.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::Outside);
        }
        else if (sign0 == LineQueryType::OnLine ||
                 sign1 == LineQueryType::OnLine ||
                 sign2 == LineQueryType::OnLine)
        {
            ASSERT_EQUAL(query.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        }
        else
        {
            ASSERT_EQUAL(query.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::Inside);
        }
    }
}

void Mathematics::Query2IntegerTesting::CircumcircleTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(1, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        auto size = randomDistribution1(generator);

        for (auto i = 0; i < size; ++i)
        {
            vertices.push_back(Vector2(randomDistribution0(generator), randomDistribution0(generator)));
        }

        std::uniform_int<> thirdRandomDistribution(0, size - 1);

        auto secondIndex = thirdRandomDistribution(generator);
        auto thirdIndex = thirdRandomDistribution(generator);
        auto fourthIndex = thirdRandomDistribution(generator);

        Query2IntegerD query(vertices);

        ASSERT_EQUAL(query.ToCircumcircle(secondIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
        ASSERT_EQUAL(query.ToCircumcircle(thirdIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
        ASSERT_EQUAL(query.ToCircumcircle(fourthIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
    }
}
