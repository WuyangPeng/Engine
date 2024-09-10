///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:15)

#include "Box3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Objects3D/Box3Detail.h"

#include <random>

namespace Mathematics
{
    template class Box3<float>;
    template class Box3<double>;
}

Mathematics::Box3Testing::Box3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Box3Testing)

void Mathematics::Box3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Box3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoxTest);
}

void Mathematics::Box3Testing::BoxTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D center(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const Vector3D firstAxis(randomDistribution0(generator),
                                 randomDistribution0(generator),
                                 randomDistribution0(generator));

        const Vector3D secondAxis(randomDistribution0(generator),
                                  randomDistribution0(generator),
                                  randomDistribution0(generator));

        const Vector3D thirdAxis(randomDistribution0(generator),
                                 randomDistribution0(generator),
                                 randomDistribution0(generator));

        auto firstExtent = Vector3ToolsD::GetLength(firstAxis);
        auto secondExtent = Vector3ToolsD::GetLength(secondAxis);
        auto thirdExtent = Vector3ToolsD::GetLength(thirdAxis);

        Vector3D fourthAxis{ firstAxis };
        Vector3D fifthAxis{ secondAxis };
        Vector3D sixthAxis{ thirdAxis };

        fourthAxis.Normalize();
        fifthAxis.Normalize();
        sixthAxis.Normalize();

        fourthAxis.Normalize();
        fifthAxis.Normalize();
        sixthAxis.Normalize();

        const Box3D box(center, fourthAxis, fifthAxis, sixthAxis, firstExtent, secondExtent, thirdExtent);

        ASSERT_TRUE(Vector3ToolsD::Approximate(box.GetCenter(), center));
        ASSERT_TRUE(Vector3ToolsD::Approximate(box.GetAxis0(), fourthAxis));
        ASSERT_TRUE(Vector3ToolsD::Approximate(box.GetAxis1(), fifthAxis));
        ASSERT_TRUE(Vector3ToolsD::Approximate(box.GetAxis2(), sixthAxis));
        ASSERT_APPROXIMATE(box.GetExtent0(), firstExtent, 1e-10);
        ASSERT_APPROXIMATE(box.GetExtent1(), secondExtent, 1e-10);
        ASSERT_APPROXIMATE(box.GetExtent2(), thirdExtent, 1e-10);

        auto vertex = box.ComputeVertices();

        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(0), center - firstAxis - secondAxis - thirdAxis));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(1), center + firstAxis - secondAxis - thirdAxis));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(2), center + firstAxis + secondAxis - thirdAxis));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(3), center - firstAxis + secondAxis - thirdAxis));

        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(4), center - firstAxis - secondAxis + thirdAxis));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(5), center + firstAxis - secondAxis + thirdAxis));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(6), center + firstAxis + secondAxis + thirdAxis));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertex.at(7), center - firstAxis + secondAxis + thirdAxis));
    }
}
