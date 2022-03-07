// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 10:51)

#include "Query2FilteredTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Query/Query2FilteredDetail.h"

#include "Mathematics/Algebra/Vector2Tools.h"
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
    template class Query2Filtered<double>;
    template class Query2Filtered<float>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Query2FilteredTesting)

void Mathematics::Query2FilteredTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VerticesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TriangleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CircumcircleTest);
}

void Mathematics::Query2FilteredTesting ::VerticesTest()
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

        Query2FilteredD query(vertices, 0.0);

        ASSERT_ENUM_EQUAL(query.GetType(), QueryType::Filtered);
        ASSERT_EQUAL(query.GetNumVertices(), size);

        for (int m = 0; m < size; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, query.GetVertice(m), vertices[m], 1e-10);
        }
    }
}

void Mathematics::Query2FilteredTesting ::LineTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(1, 50);
    uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector2D> firstVertices;
        std::vector<Vector2D> secondVertices;
        int size = secondRandomDistribution(generator);

        for (int m = 0; m < size; ++m)
        {
            firstVertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
            secondVertices.push_back(Vector2(thirdRandomDistribution(generator), thirdRandomDistribution(generator)));
        }

        uniform_int<> thirdRandomDistribution1(0, size - 1);

        int firstIndex = thirdRandomDistribution1(generator);
        int secondIndex = thirdRandomDistribution1(generator);
        int thirdIndex = thirdRandomDistribution1(generator);

        Query2FilteredD firstQuery(firstVertices, 0.0);

        ASSERT_ENUM_EQUAL(firstQuery.ToLine(secondIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
        ASSERT_ENUM_EQUAL(firstQuery.ToLine(thirdIndex, secondIndex, thirdIndex), LineQueryType::OnLine);

        if (firstIndex != secondIndex && secondIndex != thirdIndex && firstIndex != thirdIndex)
        {
            Vector2 firstVector = firstVertices[firstIndex];
            Vector2 secondVector = firstVertices[secondIndex];
            Vector2 thirdVector = firstVertices[thirdIndex];

            double dotPerp = Vector2ToolsD::DotPerp(firstVector - secondVector, thirdVector - secondVector);

            if (0.0 < dotPerp)
            {
                ASSERT_ENUM_EQUAL(firstQuery.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::Right);
            }
            else if (dotPerp < 0.0)
            {
                ASSERT_ENUM_EQUAL(firstQuery.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::Left);
            }
            else
            {
                ASSERT_ENUM_EQUAL(firstQuery.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
            }
        }

        Query2FilteredD secondQuery(secondVertices, 1.0);
        Query2RationalD thirdQuery(secondVertices);

        ASSERT_ENUM_EQUAL(secondQuery.ToLine(firstIndex, secondIndex, thirdIndex), thirdQuery.ToLine(firstIndex, secondIndex, thirdIndex));
    }
}

void Mathematics::Query2FilteredTesting ::TriangleTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(1, 50);
    uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector2D> firstVertices;
        std::vector<Vector2D> secondVertices;
        int size = secondRandomDistribution(generator);

        for (int m = 0; m < size; ++m)
        {
            firstVertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
            secondVertices.push_back(Vector2(thirdRandomDistribution(generator), thirdRandomDistribution(generator)));
        }

        uniform_int<> thirdRandomDistribution1(0, size - 1);

        int firstIndex = thirdRandomDistribution1(generator);
        int secondIndex = thirdRandomDistribution1(generator);
        int thirdIndex = thirdRandomDistribution1(generator);
        int fourthIndex = thirdRandomDistribution1(generator);

        Query2FilteredD firstQuery(firstVertices, 0.0);
        if (firstQuery.ToLine(secondIndex, thirdIndex, fourthIndex) == LineQueryType::Right)
        {
            swap(secondIndex, thirdIndex);
        }

        Vector2 firstVector = firstVertices[firstIndex];
        Vector2 secondVector = firstVertices[secondIndex];
        Vector2 thirdVector = firstVertices[thirdIndex];
        Vector2 fourthVector = firstVertices[fourthIndex];

        ASSERT_ENUM_EQUAL(firstQuery.ToTriangle(secondIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        ASSERT_ENUM_EQUAL(firstQuery.ToTriangle(thirdIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        ASSERT_ENUM_EQUAL(firstQuery.ToTriangle(fourthIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);

        LineQueryType sign0 = firstQuery.ToLine(firstIndex, thirdIndex, fourthIndex);
        LineQueryType sign1 = firstQuery.ToLine(firstIndex, secondIndex, fourthIndex);
        LineQueryType sign2 = firstQuery.ToLine(firstIndex, secondIndex, thirdIndex);

        if (sign0 == LineQueryType::Right || sign1 == LineQueryType::Left || sign2 == LineQueryType::Right)
        {
            ASSERT_ENUM_EQUAL(firstQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::Outside);
        }
        else if (sign0 == LineQueryType::OnLine || sign1 == LineQueryType::OnLine || sign2 == LineQueryType::OnLine)
        {
            ASSERT_ENUM_EQUAL(firstQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        }
        else
        {
            ASSERT_ENUM_EQUAL(firstQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::Inside);
        }

        Query2FilteredD secondQuery(secondVertices, 1.0);
        Query2RationalD thirdQuery(secondVertices);

        if (secondQuery.ToLine(secondIndex, thirdIndex, fourthIndex) == LineQueryType::Right)
        {
            swap(secondIndex, thirdIndex);
        }

        ASSERT_ENUM_EQUAL(secondQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex), thirdQuery.ToTriangle(firstIndex, secondIndex, thirdIndex, fourthIndex));
    }
}

void Mathematics::Query2FilteredTesting ::CircumcircleTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(1, 50);
    uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector2D> firstVertices;
        std::vector<Vector2D> secondVertices;
        int size = secondRandomDistribution(generator);

        for (int m = 0; m < size; ++m)
        {
            firstVertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
            secondVertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        uniform_int<> thirdRandomDistribution1(0, size - 1);

        int firstIndex = thirdRandomDistribution1(generator);
        int secondIndex = thirdRandomDistribution1(generator);
        int thirdIndex = thirdRandomDistribution1(generator);
        int fourthIndex = thirdRandomDistribution1(generator);

        Query2FilteredD firstQuery(firstVertices, 0.0);

        ASSERT_ENUM_EQUAL(firstQuery.ToCircumcircle(secondIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
        ASSERT_ENUM_EQUAL(firstQuery.ToCircumcircle(thirdIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
        ASSERT_ENUM_EQUAL(firstQuery.ToCircumcircle(fourthIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);

        if (firstIndex != secondIndex && secondIndex != thirdIndex &&
            thirdIndex != fourthIndex && fourthIndex != firstIndex &&
            secondIndex != fourthIndex && firstIndex != thirdIndex)
        {
            Vector2 firstVector = firstVertices[firstIndex];
            Vector2 secondVector = firstVertices[secondIndex];
            Vector2 thirdVector = firstVertices[thirdIndex];
            Vector2 fourthVector = firstVertices[fourthIndex];

            Vector2 lhsPlusTest = secondVector + firstVector;
            Vector2 lhsMinusTest = secondVector - firstVector;
            Vector2 mhsPlusTest = thirdVector + firstVector;
            Vector2 mhsMinusTest = thirdVector - firstVector;
            Vector2 rhsPlusTest = fourthVector + firstVector;
            Vector2 rhsMinusTest = fourthVector - firstVector;
            double z0 = Vector2ToolsD::DotProduct(lhsPlusTest, lhsMinusTest);
            double z1 = Vector2ToolsD::DotProduct(mhsPlusTest, mhsMinusTest);
            double z2 = Vector2ToolsD::DotProduct(rhsPlusTest, rhsMinusTest);

            Vector3D fifthVector(lhsMinusTest[0], lhsMinusTest[1], z0);
            Vector3D sixthVector(mhsMinusTest[0], mhsMinusTest[1], z1);
            Vector3D seventhVector(rhsMinusTest[0], rhsMinusTest[1], z2);

            double dot = Vector3ToolsD::ScalarTripleProduct(fifthVector, sixthVector, seventhVector);
            if (0.0 < dot)
            {
                ASSERT_ENUM_EQUAL(firstQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::Inside);
            }
            else if (dot < 0.0)
            {
                ASSERT_ENUM_EQUAL(firstQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::Outside);
            }
            else
            {
                ASSERT_ENUM_EQUAL(firstQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
            }
        }

        Query2FilteredD secondQuery(secondVertices, 1.0);
        Query2RationalD thirdQuery(secondVertices);

        ASSERT_ENUM_EQUAL(secondQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), thirdQuery.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex));
    }
}
