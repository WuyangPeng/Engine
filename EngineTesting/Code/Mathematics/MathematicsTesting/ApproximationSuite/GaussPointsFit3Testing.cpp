///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:15)

#include "GaussPointsFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/GaussPointsFit3Detail.h"

#include <random>

namespace Mathematics
{
    template class GaussPointsFit3<float>;
    template class GaussPointsFit3<double>;
}

Mathematics::GaussPointsFit3Testing::GaussPointsFit3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, GaussPointsFit3Testing)

void Mathematics::GaussPointsFit3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::GaussPointsFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::GaussPointsFit3Testing::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int_distribution<> randomDistribution1(10, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        const int size = randomDistribution1(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.emplace_back(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        }

        const GaussPointsFit3<double> gaussPointsFit2d(vertices);

        const Box3D box = gaussPointsFit2d.GetBox3();

        for (int i = 0; i < size; ++i)
        {
            const double distanceSquared = Vector3ToolsD::DistanceSquared(box.GetCenter(), vertices.at(i));
            const double maxDistanceSquared = box.GetExtent0() * box.GetExtent0() + box.GetExtent1() * box.GetExtent1() + box.GetExtent2() * box.GetExtent2();

            ASSERT_TRUE(distanceSquared <= maxDistanceSquared);
        }
    }
}
