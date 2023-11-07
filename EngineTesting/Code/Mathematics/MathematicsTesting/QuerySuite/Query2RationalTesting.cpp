///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:23)

#include "Query2RationalTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Query/Query2RationalDetail.h"
#include "Mathematics/Query/QuerySortTools.h"
#include "Mathematics/Rational/RationalVectorDetail.h"

#include <random>

namespace Mathematics
{
    template class Query2Rational<double>;
    template class Query2Rational<float>;
}

Mathematics::Query2RationalTesting::Query2RationalTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Query2RationalTesting)

void Mathematics::Query2RationalTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Query2RationalTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VerticesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TriangleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CircumcircleTest);
}

void Mathematics::Query2RationalTesting::VerticesTest()
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

        Query2RationalD query(vertices);

        ASSERT_ENUM_EQUAL(query.GetType(), QueryType::Rational);
        ASSERT_EQUAL(query.GetNumVertices(), size);

        for (auto m = 0; m < size; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, query.GetVertice(m), vertices.at(m), 1e-10);
        }
    }
}

void Mathematics::Query2RationalTesting::LineTest()
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

        Query2RationalD query(vertices);

        ASSERT_ENUM_EQUAL(query.ToLine(secondIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
        ASSERT_ENUM_EQUAL(query.ToLine(thirdIndex, secondIndex, thirdIndex), LineQueryType::OnLine);

        if (firstIndex != secondIndex && secondIndex != thirdIndex && firstIndex != thirdIndex)
        {
            const Vector2 vector0 = vertices.at(firstIndex);
            const Vector2 vector1 = vertices.at(secondIndex);
            const Vector2 vector2 = vertices.at(thirdIndex);

            const SignRational<32> x0(vector0[0] - vector1[0]);
            const SignRational<32> y0(vector0[1] - vector1[1]);
            const SignRational<32> x1(vector2[0] - vector1[0]);
            const SignRational<32> y1(vector2[1] - vector1[1]);

            const SignRational<32> dotPerp = QueryDotTools<SignRational<32>>::Det2(x0, y0, x1, y1);

            if (SignRational<32>(0) < dotPerp)
            {
                ASSERT_ENUM_EQUAL(query.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::Right);
            }
            else if (dotPerp < SignRational<32>(0))
            {
                ASSERT_ENUM_EQUAL(query.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::Left);
            }
            else
            {
                ASSERT_ENUM_EQUAL(query.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
            }
        }
    }
}

void Mathematics::Query2RationalTesting::TriangleTest()
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

        Query2RationalD query(vertices);
        if (query.ToLine(secondIndex, thirdIndex, fourthIndex) == LineQueryType::Right)
        {
            std::swap(secondIndex, thirdIndex);
        }

        ASSERT_ENUM_EQUAL(query.ToTriangle(secondIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        ASSERT_ENUM_EQUAL(query.ToTriangle(thirdIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        ASSERT_ENUM_EQUAL(query.ToTriangle(fourthIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);

        const LineQueryType sign0 = query.ToLine(firstIndex, thirdIndex, fourthIndex);
        const LineQueryType sign1 = query.ToLine(firstIndex, secondIndex, fourthIndex);
        const LineQueryType sign2 = query.ToLine(firstIndex, secondIndex, thirdIndex);

        if (sign0 == LineQueryType::Right || sign1 == LineQueryType::Left || sign2 == LineQueryType::Right)
        {
            ASSERT_ENUM_EQUAL(query.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::Outside);
        }
        else if (sign0 == LineQueryType::OnLine || sign1 == LineQueryType::OnLine || sign2 == LineQueryType::OnLine)
        {
            ASSERT_ENUM_EQUAL(query.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        }
        else
        {
            ASSERT_ENUM_EQUAL(query.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::Inside);
        }
    }
}

void Mathematics::Query2RationalTesting::CircumcircleTest()
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

        Query2RationalD query(vertices);

        ASSERT_ENUM_EQUAL(query.ToCircumcircle(secondIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
        ASSERT_ENUM_EQUAL(query.ToCircumcircle(thirdIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
        ASSERT_ENUM_EQUAL(query.ToCircumcircle(fourthIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);

        if (firstIndex != secondIndex && secondIndex != thirdIndex &&
            thirdIndex != fourthIndex && fourthIndex != firstIndex &&
            secondIndex != fourthIndex && firstIndex != thirdIndex)
        {
            const Vector2 vector0 = vertices.at(firstIndex);
            const Vector2 vector1 = vertices.at(secondIndex);
            const Vector2 vector2 = vertices.at(thirdIndex);
            const Vector2 vector3 = vertices.at(fourthIndex);

            const SignRational<32> lhsPlusTestX(vector1[0] + vector0[0]);
            const SignRational<32> lhsMinusTestX(vector1[0] - vector0[0]);
            const SignRational<32> lhsPlusTestY(vector1[1] + vector0[1]);
            const SignRational<32> lhsMinusTestY(vector1[1] - vector0[1]);
            const SignRational<32> mhsPlusTestX(vector2[0] + vector0[0]);
            const SignRational<32> mhsMinusTestX(vector2[0] - vector0[0]);
            const SignRational<32> mhsPlusTestY(vector2[1] + vector0[1]);
            const SignRational<32> mhsMinusTestY(vector2[1] - vector0[1]);
            const SignRational<32> rhsPlusTestX(vector3[0] + vector0[0]);
            const SignRational<32> rhsMinusTestX(vector3[0] - vector0[0]);
            const SignRational<32> rhsPlusTestY(vector3[1] + vector0[1]);
            const SignRational<32> rhsMinusTestY(vector3[1] - vector0[1]);
            const SignRational<32> z0 = lhsPlusTestX * lhsMinusTestX + lhsPlusTestY * lhsMinusTestY;
            const SignRational<32> z1 = mhsPlusTestX * mhsMinusTestX + mhsPlusTestY * mhsMinusTestY;
            const SignRational<32> z2 = rhsPlusTestX * rhsMinusTestX + rhsPlusTestY * rhsMinusTestY;

            const SignRational<32> det = QueryDotTools<SignRational<32>>::Det3(lhsMinusTestX, lhsMinusTestY, z0, mhsMinusTestX, mhsMinusTestY, z1, rhsMinusTestX, rhsMinusTestY, z2);

            if (SignRational<32>() < det)
            {
                ASSERT_ENUM_EQUAL(query.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::Inside);
            }
            else if (det < SignRational<32>())
            {
                ASSERT_ENUM_EQUAL(query.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::Outside);
            }
            else
            {
                ASSERT_ENUM_EQUAL(query.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
            }
        }
    }
}
