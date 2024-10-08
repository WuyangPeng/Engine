///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:27)

#include "Query3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Query/Query3Detail.h"

#include <random>

namespace Mathematics
{
    template class Query3<double>;
    template class Query3<float>;
}

Mathematics::Query3Testing::Query3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Query3Testing)

void Mathematics::Query3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Query3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VerticesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PlaneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TetrahedronTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CircumspherTest);
}

void Mathematics::Query3Testing::VerticesTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int_distribution<> randomDistribution1(1, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        auto size = randomDistribution1(generator);

        for (auto k = 0; k < size; ++k)
        {
            vertices.push_back(Vector3D(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator)));
        }

        Query3D query(vertices);

        ASSERT_EQUAL(query.GetType(), QueryType::Real);
        ASSERT_EQUAL(query.GetNumVertices(), size);

        for (auto k = 0; k < size; ++k)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, query.GetVertex(k), vertices.at(k), 1e-10);
        }
    }
}

void Mathematics::Query3Testing::PlaneTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int_distribution<> randomDistribution1(1, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        auto size = randomDistribution1(generator);

        for (auto k = 0; k < size; ++k)
        {
            vertices.emplace_back(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        }

        std::uniform_int_distribution<> thirdRandomDistribution(0, size - 1);

        auto firstIndex = thirdRandomDistribution(generator);
        auto secondIndex = thirdRandomDistribution(generator);
        auto thirdIndex = thirdRandomDistribution(generator);
        auto fourthIndex = thirdRandomDistribution(generator);

        Query3D query(vertices);

        ASSERT_EQUAL(query.ToPlane(secondIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);
        ASSERT_EQUAL(query.ToPlane(thirdIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);
        ASSERT_EQUAL(query.ToPlane(fourthIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);

        if (firstIndex != secondIndex && secondIndex != thirdIndex && firstIndex != thirdIndex && thirdIndex != fourthIndex && secondIndex != fourthIndex && firstIndex != fourthIndex)
        {
            QuerySortTools querySortTools(secondIndex, thirdIndex, fourthIndex);

            const auto& vector0 = vertices.at(firstIndex);
            const auto& vector1 = vertices.at(querySortTools.GetValue(0));
            const auto& vector2 = vertices.at(querySortTools.GetValue(1));
            const auto& vector3 = vertices.at(querySortTools.GetValue(2));

            const Matrix3D matrix(vector0 - vector1, vector2 - vector1, vector3 - vector1, MatrixMajorFlags::Column);

            auto det = matrix.Determinant();

            if (querySortTools.GetSymbol() == NumericalValueSymbol::Positive && 0.0 < det)
            {
                ASSERT_EQUAL(query.ToPlane(vector0, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::PositiveSide);
            }
            else if (querySortTools.GetSymbol() == NumericalValueSymbol::Negative && det < 0.0)
            {
                ASSERT_EQUAL(query.ToPlane(vector0, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::PositiveSide);
            }
            else
            {
                ASSERT_EQUAL(query.ToPlane(vector0, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::NegativeSide);
            }
        }
    }
}

void Mathematics::Query3Testing::TetrahedronTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int_distribution<> randomDistribution1(1, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        auto size = randomDistribution1(generator);

        for (auto k = 0; k < size; ++k)
        {
            vertices.emplace_back(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        }

        std::uniform_int_distribution<> thirdRandomDistribution(0, size - 1);

        auto firstIndex = thirdRandomDistribution(generator);
        auto secondIndex = thirdRandomDistribution(generator);
        auto thirdIndex = thirdRandomDistribution(generator);
        auto fourthIndex = thirdRandomDistribution(generator);
        auto fifthIndex = thirdRandomDistribution(generator);

        Query3D query(vertices);

        if (query.ToPlane(secondIndex, thirdIndex, fourthIndex, fifthIndex) == PlaneQueryType::PositiveSide)
        {
            std::swap(secondIndex, thirdIndex);
        }

        ASSERT_EQUAL(query.ToTetrahedron(secondIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
        ASSERT_EQUAL(query.ToTetrahedron(thirdIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
        ASSERT_EQUAL(query.ToTetrahedron(fourthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
        ASSERT_EQUAL(query.ToTetrahedron(fifthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);

        const auto sign0 = query.ToPlane(firstIndex, thirdIndex, fourthIndex, fifthIndex);
        const auto sign1 = query.ToPlane(firstIndex, secondIndex, fourthIndex, fifthIndex);
        const auto sign2 = query.ToPlane(firstIndex, secondIndex, thirdIndex, fifthIndex);
        const auto sign3 = query.ToPlane(firstIndex, secondIndex, thirdIndex, fourthIndex);

        if (sign0 == PlaneQueryType::PositiveSide ||
            sign1 == PlaneQueryType::NegativeSide ||
            sign2 == PlaneQueryType::PositiveSide ||
            sign3 == PlaneQueryType::NegativeSide)
        {
            ASSERT_EQUAL(query.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::Outside);
        }
        else if (sign0 == PlaneQueryType::OnPlane ||
                 sign1 == PlaneQueryType::OnPlane ||
                 sign2 == PlaneQueryType::OnPlane ||
                 sign3 == PlaneQueryType::OnPlane)
        {
            ASSERT_EQUAL(query.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
        }
        else
        {
            ASSERT_EQUAL(query.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::Inside);
        }
    }
}

void Mathematics::Query3Testing::CircumspherTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int_distribution<> randomDistribution1(1, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        auto size = randomDistribution1(generator);

        for (auto k = 0; k < size; ++k)
        {
            vertices.emplace_back(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        }

        std::uniform_int_distribution<> thirdRandomDistribution(0, size - 1);

        auto firstIndex = thirdRandomDistribution(generator);
        auto secondIndex = thirdRandomDistribution(generator);
        auto thirdIndex = thirdRandomDistribution(generator);
        auto fourthIndex = thirdRandomDistribution(generator);
        auto fifthIndex = thirdRandomDistribution(generator);

        Query3D query(vertices);

        ASSERT_EQUAL(query.ToCircumsphere(secondIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
        ASSERT_EQUAL(query.ToCircumsphere(thirdIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
        ASSERT_EQUAL(query.ToCircumsphere(fourthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
        ASSERT_EQUAL(query.ToCircumsphere(fifthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);

        if (firstIndex != secondIndex &&
            secondIndex != thirdIndex &&
            thirdIndex != fourthIndex &&
            fourthIndex != firstIndex &&
            secondIndex != fourthIndex &&
            firstIndex != thirdIndex &&
            fifthIndex != secondIndex &&
            fifthIndex != thirdIndex &&
            fifthIndex != fourthIndex)
        {
            QuerySortTools querySortTools(secondIndex, thirdIndex, fourthIndex, fifthIndex);

            const auto& vector0 = vertices.at(firstIndex);
            const auto& vector1 = vertices.at(querySortTools.GetValue(0));
            const auto& vector2 = vertices.at(querySortTools.GetValue(1));
            const auto& vector3 = vertices.at(querySortTools.GetValue(2));
            const auto& vector4 = vertices.at(querySortTools.GetValue(3));

            Vector4D s0(vector0 - vector1);
            Vector4D s1(vector2 - vector1);
            Vector4D s2(vector3 - vector1);
            Vector4D s3(vector4 - vector1);

            const Vector4D s4(vector0 + vector1);
            const Vector4D s5(vector2 + vector1);
            const Vector4D s6(vector3 + vector1);
            const Vector4D s7(vector4 + vector1);

            s0[3] = Vector4ToolsD::DotProduct(s0, s4);
            s1[3] = Vector4ToolsD::DotProduct(s1, s5);
            s2[3] = Vector4ToolsD::DotProduct(s2, s6);
            s3[3] = Vector4ToolsD::DotProduct(s3, s7);

            const Matrix4D matrix(s0[0], s0[1], s0[2], s0[3], s1[0], s1[1], s1[2], s1[3], s2[0], s2[1], s2[2], s2[3], s3[0], s3[1], s3[2], s3[3]);

            auto det = matrix.Determinant();

            const auto positive = querySortTools.GetSymbol();
            if (positive == NumericalValueSymbol::Negative)
            {
                det = -det;
            }

            if (1.0 <= det)
            {
                ASSERT_EQUAL(query.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::Inside);
            }
            else if (det <= -1.0)
            {
                ASSERT_EQUAL(query.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::Outside);
            }
            else
            {
                ASSERT_EQUAL(query.ToCircumsphere(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
            }
        }
    }
}
