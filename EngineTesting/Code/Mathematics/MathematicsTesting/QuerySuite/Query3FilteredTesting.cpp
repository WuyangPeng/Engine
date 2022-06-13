///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/27 10:57)

#include "Query3FilteredTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Query/Query3FilteredDetail.h"

#include <random>

using std::default_random_engine;
using std::swap;
using std::uniform_int;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class Query3Filtered<double>;
    template class Query3Filtered<float>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Query3FilteredTesting)

void Mathematics::Query3FilteredTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VerticesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PlaneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TetrahedronTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CircumspherTest);
}

void Mathematics::Query3FilteredTesting::VerticesTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const uniform_int<> secondRandomDistribution(1, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const auto size = secondRandomDistribution(generator);

        for (auto m = 0; m < size; ++m)
        {
            vertices.emplace_back(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        }

        Query3FilteredD query(vertices, 0.0);

        ASSERT_ENUM_EQUAL(query.GetType(), QueryType::Filtered);
        ASSERT_EQUAL(query.GetNumVertices(), size);

        for (auto m = 0; m < size; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, query.GetVertice(m), vertices.at(m), 1e-10);
        }
    }
}

void Mathematics::Query3FilteredTesting::PlaneTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const uniform_int<> secondRandomDistribution(1, 50);
    const uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> firstVertices;
        std::vector<Vector3D> secondVertices;
        auto size = secondRandomDistribution(generator);

        for (auto m = 0; m < size; ++m)
        {
            firstVertices.emplace_back(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
            secondVertices.emplace_back(thirdRandomDistribution(generator), thirdRandomDistribution(generator), thirdRandomDistribution(generator));
        }

        const uniform_int<> thirdRandomDistribution1(0, size - 1);

        const auto firstIndex = thirdRandomDistribution1(generator);
        const auto secondIndex = thirdRandomDistribution1(generator);
        const auto thirdIndex = thirdRandomDistribution1(generator);
        const auto fourthIndex = thirdRandomDistribution1(generator);

        Query3FilteredD firstQuery(firstVertices, 0.0);

        ASSERT_ENUM_EQUAL(firstQuery.ToPlane(secondIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);
        ASSERT_ENUM_EQUAL(firstQuery.ToPlane(thirdIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);
        ASSERT_ENUM_EQUAL(firstQuery.ToPlane(fourthIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);

        if (firstIndex != secondIndex && secondIndex != thirdIndex && firstIndex != thirdIndex && thirdIndex != fourthIndex && secondIndex != fourthIndex && firstIndex != fourthIndex)
        {
            const auto& firstVector = firstVertices.at(firstIndex);
            const auto& secondVector = firstVertices.at(secondIndex);
            const auto& thirdVector = firstVertices.at(thirdIndex);
            const auto& fourthVector = firstVertices.at(fourthIndex);

            const Matrix3D matrix(firstVector - secondVector, thirdVector - secondVector, fourthVector - secondVector, MatrixMajorFlags::Column);

            const auto det = matrix.Determinant();

            if (0.0 < det)
            {
                ASSERT_ENUM_EQUAL(firstQuery.ToPlane(firstVector, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::PositiveSide);
            }
            else if (det < 0.0)
            {
                ASSERT_ENUM_EQUAL(firstQuery.ToPlane(firstVector, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::NegativeSide);
            }
            else
            {
                ASSERT_ENUM_EQUAL(firstQuery.ToPlane(firstVector, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);
            }
        }

        Query3FilteredD secondQuery(secondVertices, 1.0);
        Query3RationalD thirdQuery(secondVertices);

        ASSERT_ENUM_EQUAL(secondQuery.ToPlane(firstIndex, secondIndex, thirdIndex, fourthIndex), thirdQuery.ToPlane(firstIndex, secondIndex, thirdIndex, fourthIndex));
    }
}

void Mathematics::Query3FilteredTesting::TetrahedronTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const uniform_int<> secondRandomDistribution(1, 50);
    const uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> firstVertices;
        std::vector<Vector3D> secondVertices;
        auto size = secondRandomDistribution(generator);

        for (auto m = 0; m < size; ++m)
        {
            firstVertices.emplace_back(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
            secondVertices.emplace_back(thirdRandomDistribution(generator), thirdRandomDistribution(generator), thirdRandomDistribution(generator));
        }

        const uniform_int<> thirdRandomDistribution1(0, size - 1);

        const auto firstIndex = thirdRandomDistribution1(generator);
        auto secondIndex = thirdRandomDistribution1(generator);
        auto thirdIndex = thirdRandomDistribution1(generator);
        const auto fourthIndex = thirdRandomDistribution1(generator);
        const auto fifthIndex = thirdRandomDistribution1(generator);

        Query3FilteredD firstQuery(firstVertices, 0.0);

        if (firstQuery.ToPlane(secondIndex, thirdIndex, fourthIndex, fifthIndex) == PlaneQueryType::PositiveSide)
        {
            swap(secondIndex, thirdIndex);
        }

        ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(secondIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
        ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(thirdIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
        ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(fourthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
        ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(fifthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);

        const auto sign0 = firstQuery.ToPlane(firstIndex, thirdIndex, fourthIndex, fifthIndex);
        const auto sign1 = firstQuery.ToPlane(firstIndex, secondIndex, fourthIndex, fifthIndex);
        const auto sign2 = firstQuery.ToPlane(firstIndex, secondIndex, thirdIndex, fifthIndex);
        const auto sign3 = firstQuery.ToPlane(firstIndex, secondIndex, thirdIndex, fourthIndex);

        if (sign0 == PlaneQueryType::PositiveSide || sign1 == PlaneQueryType::NegativeSide ||
            sign2 == PlaneQueryType::PositiveSide || sign3 == PlaneQueryType::NegativeSide)
        {
            ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::Outside);
        }
        else if (sign0 == PlaneQueryType::OnPlane || sign1 == PlaneQueryType::OnPlane || sign2 == PlaneQueryType::OnPlane || sign3 == PlaneQueryType::OnPlane)
        {
            ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
        }
        else
        {
            ASSERT_ENUM_EQUAL(firstQuery.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::Inside);
        }

        Query3FilteredD secondQuery(secondVertices, 1.0);
        Query3RationalD thirdQuery(secondVertices);

        if (secondQuery.ToPlane(secondIndex, thirdIndex, fourthIndex, fifthIndex) == PlaneQueryType::PositiveSide)
        {
            swap(secondIndex, thirdIndex);
        }

        ASSERT_ENUM_EQUAL(secondQuery.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), thirdQuery.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex));
    }
}

void Mathematics::Query3FilteredTesting::CircumspherTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const uniform_int<> secondRandomDistribution(1, 50);
    const uniform_real<double> thirdRandomDistribution(-1.0, 1.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> firstVertices;
        std::vector<Vector3D> secondVertices;
        auto size = secondRandomDistribution(generator);

        for (auto m = 0; m < size; ++m)
        {
            firstVertices.emplace_back(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
            secondVertices.emplace_back(thirdRandomDistribution(generator), thirdRandomDistribution(generator), thirdRandomDistribution(generator));
        }

        const uniform_int<> thirdRandomDistribution1(0, size - 1);

        auto firstIndex = thirdRandomDistribution1(generator);
        auto secondIndex = thirdRandomDistribution1(generator);
        auto thirdIndex = thirdRandomDistribution1(generator);
        auto fourthIndex = thirdRandomDistribution1(generator);
        auto fifthIndex = thirdRandomDistribution1(generator);

        Query3FilteredD firstQuery(firstVertices, 0.0);

        ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(secondIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
        ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(thirdIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
        ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(fourthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
        ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(fifthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);

        if (firstIndex != secondIndex && secondIndex != thirdIndex &&
            thirdIndex != fourthIndex && fourthIndex != firstIndex &&
            secondIndex != fourthIndex && firstIndex != thirdIndex &&
            fifthIndex != secondIndex && fifthIndex != thirdIndex &&
            fifthIndex != fourthIndex && firstIndex != fifthIndex)
        {
            const auto& firstVector = firstVertices.at(firstIndex);
            const auto& secondVector = firstVertices.at(secondIndex);
            const auto& thirdVector = firstVertices.at(thirdIndex);
            const auto& fourthVector = firstVertices.at(fourthIndex);
            const auto& fifthVector = firstVertices.at(fifthIndex);

            Vector4D s0(firstVector - secondVector);
            Vector4D s1(thirdVector - secondVector);
            Vector4D s2(fourthVector - secondVector);
            Vector4D s3(fifthVector - secondVector);

            const Vector4D s4(firstVector + secondVector);
            const Vector4D s5(thirdVector + secondVector);
            const Vector4D s6(fourthVector + secondVector);
            const Vector4D s7(fifthVector + secondVector);

            s0[3] = Vector4ToolsD::DotProduct(s0, s4);
            s1[3] = Vector4ToolsD::DotProduct(s1, s5);
            s2[3] = Vector4ToolsD::DotProduct(s2, s6);
            s3[3] = Vector4ToolsD::DotProduct(s3, s7);

            const Matrix4D matrix(s0[0], s0[1], s0[2], s0[3], s1[0], s1[1], s1[2], s1[3], s2[0], s2[1], s2[2], s2[3], s3[0], s3[1], s3[2], s3[3]);

            auto det = matrix.Determinant();

            if (0.0 < det)
            {
                ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::Inside);
            }
            else if (det < 0.0)
            {
                ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::Outside);
            }
            else
            {
                ASSERT_ENUM_EQUAL(firstQuery.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
            }
        }

        Query3FilteredD secondQuery(secondVertices, 1.0);
        Query3RationalD thirdQuery(secondVertices);

        ASSERT_ENUM_EQUAL(secondQuery.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), thirdQuery.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex));
    }
}