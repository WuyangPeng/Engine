// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 13:13)

#include "Query2RationalTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
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

using std::default_random_engine;
using std::swap;
using std::uniform_int;
using std::uniform_real;
using std::vector;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
namespace Mathematics
{
    template class Query2Rational<double>;
    template class Query2Rational<float>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Query2RationalTesting)

void Mathematics::Query2RationalTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VerticesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TriangleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CircumcircleTest);
}

void Mathematics::Query2RationalTesting ::VerticesTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(1, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        int size = secondRandomDistribution(generator);

        for (int m = 0; m < size; ++m)
        {
            vertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        Query2RationalD query(vertices);

        ASSERT_ENUM_EQUAL(query.GetType(), QueryType::Rational);
        ASSERT_EQUAL(query.GetNumVertices(), size);

        for (int m = 0; m < size; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, query.GetVertice(m), vertices[m], 1e-10);
        }
    }
}

void Mathematics::Query2RationalTesting ::LineTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(1, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        int size = secondRandomDistribution(generator);

        for (int m = 0; m < size; ++m)
        {
            vertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        uniform_int<> thirdRandomDistribution(0, size - 1);

        int firstIndex = thirdRandomDistribution(generator);
        int secondIndex = thirdRandomDistribution(generator);
        int thirdIndex = thirdRandomDistribution(generator);

        Query2RationalD query(vertices);

        ASSERT_ENUM_EQUAL(query.ToLine(secondIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
        ASSERT_ENUM_EQUAL(query.ToLine(thirdIndex, secondIndex, thirdIndex), LineQueryType::OnLine);

        if (firstIndex != secondIndex && secondIndex != thirdIndex && firstIndex != thirdIndex)
        {
            Vector2 firstVector = vertices[firstIndex];
            Vector2 secondVector = vertices[secondIndex];
            Vector2 thirdVector = vertices[thirdIndex];

            SignRational<32> x0(firstVector[0] - secondVector[0]);
            SignRational<32> y0(firstVector[1] - secondVector[1]);
            SignRational<32> x1(thirdVector[0] - secondVector[0]);
            SignRational<32> y1(thirdVector[1] - secondVector[1]);

            SignRational<32> dotPerp = QueryDotTools<SignRational<32>>::Det2(x0, y0, x1, y1);

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

void Mathematics::Query2RationalTesting ::TriangleTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(1, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        int size = secondRandomDistribution(generator);

        for (int m = 0; m < size; ++m)
        {
            vertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        uniform_int<> thirdRandomDistribution(0, size - 1);

        int firstIndex = thirdRandomDistribution(generator);
        int secondIndex = thirdRandomDistribution(generator);
        int thirdIndex = thirdRandomDistribution(generator);
        int fourthIndex = thirdRandomDistribution(generator);

        Query2RationalD query(vertices);
        if (query.ToLine(secondIndex, thirdIndex, fourthIndex) == LineQueryType::Right)
        {
            swap(secondIndex, thirdIndex);
        }

        ASSERT_ENUM_EQUAL(query.ToTriangle(secondIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        ASSERT_ENUM_EQUAL(query.ToTriangle(thirdIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        ASSERT_ENUM_EQUAL(query.ToTriangle(fourthIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);

        LineQueryType sign0 = query.ToLine(firstIndex, thirdIndex, fourthIndex);
        LineQueryType sign1 = query.ToLine(firstIndex, secondIndex, fourthIndex);
        LineQueryType sign2 = query.ToLine(firstIndex, secondIndex, thirdIndex);

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

void Mathematics::Query2RationalTesting ::CircumcircleTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(1, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        int size = secondRandomDistribution(generator);

        for (int m = 0; m < size; ++m)
        {
            vertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        uniform_int<> thirdRandomDistribution(0, size - 1);

        int firstIndex = thirdRandomDistribution(generator);
        int secondIndex = thirdRandomDistribution(generator);
        int thirdIndex = thirdRandomDistribution(generator);
        int fourthIndex = thirdRandomDistribution(generator);

        Query2RationalD query(vertices);

        ASSERT_ENUM_EQUAL(query.ToCircumcircle(secondIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
        ASSERT_ENUM_EQUAL(query.ToCircumcircle(thirdIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
        ASSERT_ENUM_EQUAL(query.ToCircumcircle(fourthIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);

        if (firstIndex != secondIndex && secondIndex != thirdIndex &&
            thirdIndex != fourthIndex && fourthIndex != firstIndex &&
            secondIndex != fourthIndex && firstIndex != thirdIndex)
        {
            Vector2 firstVector = vertices[firstIndex];
            Vector2 secondVector = vertices[secondIndex];
            Vector2 thirdVector = vertices[thirdIndex];
            Vector2 fourthVector = vertices[fourthIndex];

            SignRational<32> lhsPlusTestX(secondVector[0] + firstVector[0]);
            SignRational<32> lhsMinusTestX(secondVector[0] - firstVector[0]);
            SignRational<32> lhsPlusTestY(secondVector[1] + firstVector[1]);
            SignRational<32> lhsMinusTestY(secondVector[1] - firstVector[1]);
            SignRational<32> mhsPlusTestX(thirdVector[0] + firstVector[0]);
            SignRational<32> mhsMinusTestX(thirdVector[0] - firstVector[0]);
            SignRational<32> mhsPlusTestY(thirdVector[1] + firstVector[1]);
            SignRational<32> mhsMinusTestY(thirdVector[1] - firstVector[1]);
            SignRational<32> rhsPlusTestX(fourthVector[0] + firstVector[0]);
            SignRational<32> rhsMinusTestX(fourthVector[0] - firstVector[0]);
            SignRational<32> rhsPlusTestY(fourthVector[1] + firstVector[1]);
            SignRational<32> rhsMinusTestY(fourthVector[1] - firstVector[1]);
            SignRational<32> z0 = lhsPlusTestX * lhsMinusTestX + lhsPlusTestY * lhsMinusTestY;
            SignRational<32> z1 = mhsPlusTestX * mhsMinusTestX + mhsPlusTestY * mhsMinusTestY;
            SignRational<32> z2 = rhsPlusTestX * rhsMinusTestX + rhsPlusTestY * rhsMinusTestY;

            SignRational<32> det = QueryDotTools<SignRational<32>>::Det3(lhsMinusTestX, lhsMinusTestY, z0, mhsMinusTestX, mhsMinusTestY, z1, rhsMinusTestX, rhsMinusTestY, z2);

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
