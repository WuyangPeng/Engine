// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 14:18)

#include "Query3RationalTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Query/Query3RationalDetail.h"
#include "Mathematics/Query/QuerySortTools.h"
#include "Mathematics/Rational/RationalVectorDetail.h"

#include <random>
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
using std::default_random_engine;
using std::swap;
using std::uniform_int;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class Query3Rational<double>;
    template class Query3Rational<float>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Query3RationalTesting)

void Mathematics::Query3RationalTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VerticesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PlaneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TetrahedronTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CircumspherTest);
}

void Mathematics::Query3RationalTesting ::VerticesTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(1, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        int size = secondRandomDistribution(generator);

        for (int m = 0; m < size; ++m)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        Query3RationalD query(vertices);

        ASSERT_ENUM_EQUAL(query.GetType(), QueryType::Rational);
        ASSERT_EQUAL(query.GetNumVertices(), size);

        for (int m = 0; m < size; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, query.GetVertice(m), vertices[m], 1e-10);
        }
    }
}

void Mathematics::Query3RationalTesting ::PlaneTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(1, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        int size = secondRandomDistribution(generator);

        for (int m = 0; m < size; ++m)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        uniform_int<> thirdRandomDistribution(0, size - 1);

        int firstIndex = thirdRandomDistribution(generator);
        int secondIndex = thirdRandomDistribution(generator);
        int thirdIndex = thirdRandomDistribution(generator);
        int fourthIndex = thirdRandomDistribution(generator);

        Query3RationalD query(vertices);

        ASSERT_ENUM_EQUAL(query.ToPlane(secondIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);
        ASSERT_ENUM_EQUAL(query.ToPlane(thirdIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);
        ASSERT_ENUM_EQUAL(query.ToPlane(fourthIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);

        if (firstIndex != secondIndex && secondIndex != thirdIndex && firstIndex != thirdIndex && thirdIndex != fourthIndex && secondIndex != fourthIndex && firstIndex != fourthIndex)
        {
            Vector3D firstVector = vertices[firstIndex];
            Vector3D secondVector = vertices[secondIndex];
            Vector3D thirdVector = vertices[thirdIndex];
            Vector3D fourthVector = vertices[fourthIndex];

            Matrix3D matrix(firstVector - secondVector, thirdVector - secondVector, fourthVector - secondVector, MatrixMajorFlags::Column);

            double det = matrix.Determinant();

            if (0.0 < det)
            {
                ASSERT_ENUM_EQUAL(query.ToPlane(firstVector, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::PositiveSide);
            }
            else if (det < 0.0)
            {
                ASSERT_ENUM_EQUAL(query.ToPlane(firstVector, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::NegativeSide);
            }
            else
            {
                ASSERT_ENUM_EQUAL(query.ToPlane(firstVector, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);
            }
        }
    }
}

void Mathematics::Query3RationalTesting ::TetrahedronTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(1, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        int size = secondRandomDistribution(generator);

        for (int m = 0; m < size; ++m)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        uniform_int<> thirdRandomDistribution(0, size - 1);

        int firstIndex = thirdRandomDistribution(generator);
        int secondIndex = thirdRandomDistribution(generator);
        int thirdIndex = thirdRandomDistribution(generator);
        int fourthIndex = thirdRandomDistribution(generator);
        int fifthIndex = thirdRandomDistribution(generator);

        Query3RationalD query(vertices);

        if (query.ToPlane(secondIndex, thirdIndex, fourthIndex, fifthIndex) == PlaneQueryType::PositiveSide)
        {
            swap(secondIndex, thirdIndex);
        }

        ASSERT_ENUM_EQUAL(query.ToTetrahedron(secondIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
        ASSERT_ENUM_EQUAL(query.ToTetrahedron(thirdIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
        ASSERT_ENUM_EQUAL(query.ToTetrahedron(fourthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
        ASSERT_ENUM_EQUAL(query.ToTetrahedron(fifthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);

        PlaneQueryType sign0 = query.ToPlane(firstIndex, thirdIndex, fourthIndex, fifthIndex);
        PlaneQueryType sign1 = query.ToPlane(firstIndex, secondIndex, fourthIndex, fifthIndex);
        PlaneQueryType sign2 = query.ToPlane(firstIndex, secondIndex, thirdIndex, fifthIndex);
        PlaneQueryType sign3 = query.ToPlane(firstIndex, secondIndex, thirdIndex, fourthIndex);

        if (sign0 == PlaneQueryType::PositiveSide || sign1 == PlaneQueryType::NegativeSide ||
            sign2 == PlaneQueryType::PositiveSide || sign3 == PlaneQueryType::NegativeSide)
        {
            ASSERT_ENUM_EQUAL(query.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::Outside);
        }
        else if (sign0 == PlaneQueryType::OnPlane || sign1 == PlaneQueryType::OnPlane ||
                 sign2 == PlaneQueryType::OnPlane || sign3 == PlaneQueryType::OnPlane)
        {
            ASSERT_ENUM_EQUAL(query.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
        }
        else
        {
            ASSERT_ENUM_EQUAL(query.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::Inside);
        }
    }
}

void Mathematics::Query3RationalTesting ::CircumspherTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(1, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        int size = secondRandomDistribution(generator);

        for (int k = 0; k < size; ++k)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        uniform_int<> thirdRandomDistribution(0, size - 1);

        int firstIndex = thirdRandomDistribution(generator);
        int secondIndex = thirdRandomDistribution(generator);
        int thirdIndex = thirdRandomDistribution(generator);
        int fourthIndex = thirdRandomDistribution(generator);
        int fifthIndex = thirdRandomDistribution(generator);

        Query3RationalD query(vertices);

        ASSERT_ENUM_EQUAL(query.ToCircumsphere(secondIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
        ASSERT_ENUM_EQUAL(query.ToCircumsphere(thirdIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
        ASSERT_ENUM_EQUAL(query.ToCircumsphere(fourthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
        ASSERT_ENUM_EQUAL(query.ToCircumsphere(fifthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);

        if (firstIndex != secondIndex && secondIndex != thirdIndex &&
            thirdIndex != fourthIndex && fourthIndex != firstIndex &&
            secondIndex != fourthIndex && firstIndex != thirdIndex &&
            fifthIndex != secondIndex && fifthIndex != thirdIndex &&
            fifthIndex != fourthIndex)
        {
            Vector3D firstVector = vertices[firstIndex];
            Vector3D secondVector = vertices[secondIndex];
            Vector3D thirdVector = vertices[thirdIndex];
            Vector3D fourthVector = vertices[fourthIndex];
            Vector3D fifthVector = vertices[fifthIndex];

            Vector4D s0(firstVector - secondVector);
            Vector4D s1(thirdVector - secondVector);
            Vector4D s2(fourthVector - secondVector);
            Vector4D s3(fifthVector - secondVector);

            Vector4D s4(firstVector + secondVector);
            Vector4D s5(thirdVector + secondVector);
            Vector4D s6(fourthVector + secondVector);
            Vector4D s7(fifthVector + secondVector);

            s0[3] = Vector4ToolsD::DotProduct(s0, s4);
            s1[3] = Vector4ToolsD::DotProduct(s1, s5);
            s2[3] = Vector4ToolsD::DotProduct(s2, s6);
            s3[3] = Vector4ToolsD::DotProduct(s3, s7);

            Matrix4D matrix(s0[0], s0[1], s0[2], s0[3], s1[0], s1[1], s1[2], s1[3], s2[0], s2[1], s2[2], s2[3], s3[0], s3[1], s3[2], s3[3]);

            double det = matrix.Determinant();

            if (1.0 <= det)
            {
                ASSERT_ENUM_EQUAL(query.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::Inside);
            }
            else if (det <= -1.0)
            {
                ASSERT_ENUM_EQUAL(query.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::Outside);
            }
            else
            {
                ASSERT_ENUM_EQUAL(query.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
            }
        }
    }
}
