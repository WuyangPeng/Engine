// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.2 (2019/08/28 13:16)

#include "Query2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Query/Query2Detail.h"

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
    template class Query2<double>;
    template class Query2<float>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Query2Testing)

void Mathematics::Query2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VerticesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TriangleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CircumcircleTest);
}

void Mathematics::Query2Testing ::VerticesTest()
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

        Query2D query(vertices);

        ASSERT_ENUM_EQUAL(query.GetType(), QueryType::Real);
        ASSERT_EQUAL(query.GetNumVertices(), size);

        for (int m = 0; m < size; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, query.GetVertice(m), vertices[m], 1e-10);
        }
    }
}

void Mathematics::Query2Testing ::LineTest()
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

        Query2D query(vertices);

        ASSERT_ENUM_EQUAL(query.ToLine(secondIndex, secondIndex, thirdIndex), LineQueryType::OnLine);
        ASSERT_ENUM_EQUAL(query.ToLine(thirdIndex, secondIndex, thirdIndex), LineQueryType::OnLine);

        if (firstIndex != secondIndex && secondIndex != thirdIndex && firstIndex != thirdIndex)
        {
            QuerySortTools querySortTools(secondIndex, thirdIndex);

            Vector2 firstVector = vertices[firstIndex];
            Vector2 secondVector = vertices[querySortTools.GetValue(0)];
            Vector2 thirdVector = vertices[querySortTools.GetValue(1)];

            double dotPerp = Vector2ToolsD::DotPerp(firstVector - secondVector, thirdVector - secondVector);

            if (querySortTools.GetSymbol() == NumericalValueSymbol::Positive && 0.0 < dotPerp)
            {
                ASSERT_ENUM_EQUAL(query.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::Right);
            }
            else if (querySortTools.GetSymbol() == NumericalValueSymbol::Negative && dotPerp < 0.0)
            {
                ASSERT_ENUM_EQUAL(query.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::Right);
            }
            else
            {
                ASSERT_ENUM_EQUAL(query.ToLine(firstIndex, secondIndex, thirdIndex), LineQueryType::Left);
            }
        }
    }
}

void Mathematics::Query2Testing ::TriangleTest()
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

        Query2D query(vertices);
        if (query.ToLine(secondIndex, thirdIndex, fourthIndex) == LineQueryType::Right)
        {
            swap(secondIndex, thirdIndex);
        }

        Vector2 firstVector = vertices[firstIndex];
        Vector2 secondVector = vertices[secondIndex];
        Vector2 thirdVector = vertices[thirdIndex];
        Vector2 fourthVector = vertices[fourthIndex];

        ASSERT_ENUM_EQUAL(query.ToTriangle(secondIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        ASSERT_ENUM_EQUAL(query.ToTriangle(thirdIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);
        ASSERT_ENUM_EQUAL(query.ToTriangle(fourthIndex, secondIndex, thirdIndex, fourthIndex), TriangleQueryType::OnTriangle);

        LineQueryType sign0 = query.ToLine(firstIndex, thirdIndex, fourthIndex);
        LineQueryType sign1 = query.ToLine(firstIndex, secondIndex, fourthIndex);
        LineQueryType sign2 = query.ToLine(firstIndex, secondIndex, thirdIndex);

        if (sign0 == LineQueryType::Right || sign1 == LineQueryType::Left ||
            sign2 == LineQueryType::Right)
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

void Mathematics::Query2Testing ::CircumcircleTest()
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

        Query2D query(vertices);

        ASSERT_ENUM_EQUAL(query.ToCircumcircle(secondIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
        ASSERT_ENUM_EQUAL(query.ToCircumcircle(thirdIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);
        ASSERT_ENUM_EQUAL(query.ToCircumcircle(fourthIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::OnCircumcircle);

        if (firstIndex != secondIndex && secondIndex != thirdIndex &&
            thirdIndex != fourthIndex && fourthIndex != firstIndex &&
            secondIndex != fourthIndex && firstIndex != thirdIndex)
        {
            QuerySortTools querySortTools(secondIndex, thirdIndex, fourthIndex);

            Vector2 firstVector = vertices[firstIndex];
            Vector2 secondVector = vertices[querySortTools.GetValue(0)];
            Vector2 thirdVector = vertices[querySortTools.GetValue(1)];
            Vector2 fourthVector = vertices[querySortTools.GetValue(2)];

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
            if (querySortTools.GetSymbol() == NumericalValueSymbol::Positive && 0.0 < dot)
            {
                ASSERT_ENUM_EQUAL(query.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::Inside);
            }
            else if (querySortTools.GetSymbol() == NumericalValueSymbol::Negative && dot < 0.0)
            {
                ASSERT_ENUM_EQUAL(query.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::Inside);
            }
            else
            {
                ASSERT_ENUM_EQUAL(query.ToCircumcircle(firstIndex, secondIndex, thirdIndex, fourthIndex), CircumcircleQueryType::Outside);
            }
        }
    }
}