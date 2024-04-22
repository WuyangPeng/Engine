///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:25)

#include "Query3Int64Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
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
#include "Mathematics/Query/Query3Int64Detail.h"
#include "Mathematics/Query/QuerySortTools.h"

#include <random>

namespace Mathematics
{
    template class Query3Int64<double>;
    template class Query3Int64<float>;
}

Mathematics::Query3Int64Testing::Query3Int64Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Query3Int64Testing)

void Mathematics::Query3Int64Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Query3Int64Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VerticesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PlaneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TetrahedronTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CircumspherTest);
}

void Mathematics::Query3Int64Testing::VerticesTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(1, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        auto size = randomDistribution1(generator);

        for (auto m = 0; m < size; ++m)
        {
            vertices.emplace_back(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        }

        Query3Int64D query(vertices);

        ASSERT_EQUAL(query.GetType(), QueryType::Int64);
        ASSERT_EQUAL(query.GetNumVertices(), size);

        for (auto m = 0; m < size; ++m)
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, query.GetVertex(m), vertices.at(m), 1e-10);
        }
    }
}

void Mathematics::Query3Int64Testing::PlaneTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(1, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        auto size = randomDistribution1(generator);

        for (auto m = 0; m < size; ++m)
        {
            vertices.emplace_back(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        }

        std::uniform_int<> thirdRandomDistribution(0, size - 1);

        auto secondIndex = thirdRandomDistribution(generator);
        auto thirdIndex = thirdRandomDistribution(generator);
        auto fourthIndex = thirdRandomDistribution(generator);

        Query3Int64D query(vertices);

        ASSERT_EQUAL(query.ToPlane(secondIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);
        ASSERT_EQUAL(query.ToPlane(thirdIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);
        ASSERT_EQUAL(query.ToPlane(fourthIndex, secondIndex, thirdIndex, fourthIndex), PlaneQueryType::OnPlane);
    }
}

void Mathematics::Query3Int64Testing::TetrahedronTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(1, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        auto size = randomDistribution1(generator);

        for (auto m = 0; m < size; ++m)
        {
            vertices.emplace_back(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        }

        std::uniform_int<> thirdRandomDistribution(0, size - 1);

        auto firstIndex = thirdRandomDistribution(generator);
        auto secondIndex = thirdRandomDistribution(generator);
        auto thirdIndex = thirdRandomDistribution(generator);
        auto fourthIndex = thirdRandomDistribution(generator);
        auto fifthIndex = thirdRandomDistribution(generator);

        Query3Int64D query(vertices);

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

        if (sign0 == PlaneQueryType::PositiveSide || sign1 == PlaneQueryType::NegativeSide ||
            sign2 == PlaneQueryType::PositiveSide || sign3 == PlaneQueryType::NegativeSide)
        {
            ASSERT_EQUAL(query.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::Outside);
        }
        else if (sign0 == PlaneQueryType::OnPlane || sign1 == PlaneQueryType::OnPlane ||
                 sign2 == PlaneQueryType::OnPlane || sign3 == PlaneQueryType::OnPlane)
        {
            ASSERT_EQUAL(query.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::OnTetrahedron);
        }
        else
        {
            ASSERT_EQUAL(query.ToTetrahedron(firstIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), TetrahedronQueryType::Inside);
        }
    }
}

void Mathematics::Query3Int64Testing::CircumspherTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int<> randomDistribution1(1, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        auto size = randomDistribution1(generator);

        for (auto i = 0; i < size; ++i)
        {
            vertices.emplace_back(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        }

        std::uniform_int<> thirdRandomDistribution(0, size - 1);

        auto secondIndex = thirdRandomDistribution(generator);
        auto thirdIndex = thirdRandomDistribution(generator);
        auto fourthIndex = thirdRandomDistribution(generator);
        auto fifthIndex = thirdRandomDistribution(generator);

        Query3Int64D query(vertices);

        ASSERT_EQUAL(query.ToCircumsphere(secondIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
        ASSERT_EQUAL(query.ToCircumsphere(thirdIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
        ASSERT_EQUAL(query.ToCircumsphere(fourthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
        ASSERT_EQUAL(query.ToCircumsphere(fifthIndex, secondIndex, thirdIndex, fourthIndex, fifthIndex), CircumsphereQueryType::OnCircumsphere);
    }
}
