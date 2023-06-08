///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/07 21:16)

#include "ContBox3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Containment/ContBox3Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

namespace Mathematics
{
    template class ContBox3<float>;
    template class ContBox3<double>;
}

Mathematics::ContBox3Testing::ContBox3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, ContBox3Testing)

void Mathematics::ContBox3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::ContBox3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ContAlignedBoxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ContOrientedBoxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MergeBoxesTest);
}

void Mathematics::ContBox3Testing::ContAlignedBoxTest()
{
    std::default_random_engine generator;
    const std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const std::uniform_int<> secondRandomDistribution(10, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        const Box3D box = ContBox3D::ContAlignedBox(vertices);

        for (int i = 0; i < size; ++i)
        {
            ASSERT_TRUE(ContBox3D::InBox(vertices.at(i), box));
        }
    }
}

void Mathematics::ContBox3Testing::ContOrientedBoxTest()
{
    std::default_random_engine generator;
    const std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const std::uniform_int<> secondRandomDistribution(10, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        const Box3D box = ContBox3D::ContOrientedBox(vertices);

        for (int i = 0; i < size; ++i)
        {
            ASSERT_TRUE(ContBox3D::InBox(vertices.at(i), box));
        }
    }
}

void Mathematics::ContBox3Testing::MergeBoxesTest()
{
    std::default_random_engine generator;
    const std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const std::uniform_int<> secondRandomDistribution(10, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> firstVertices;
        const int firstSize = secondRandomDistribution(generator);

        for (int i = 0; i < firstSize; ++i)
        {
            firstVertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        const Box3D firstBox = ContBox3D::ContAlignedBox(firstVertices);

        std::vector<Vector3D> secondVertices;
        const int secondSize = secondRandomDistribution(generator);

        for (int i = 0; i < secondSize; ++i)
        {
            secondVertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        const Box3D secondBox = ContBox3D::ContOrientedBox(secondVertices);

        const Box3D thirdBox = ContBox3D::MergeBoxes(firstBox, secondBox);

        for (int i = 0; i < firstSize; ++i)
        {
            ASSERT_TRUE(ContBox3D::InBox(firstVertices.at(i), thirdBox));
        }

        for (int i = 0; i < secondSize; ++i)
        {
            ASSERT_TRUE(ContBox3D::InBox(secondVertices.at(i), thirdBox));
        }
    }
}
