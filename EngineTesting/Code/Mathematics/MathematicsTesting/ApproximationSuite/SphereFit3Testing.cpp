///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:20)

#include "SphereFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Approximation/SphereFit3Detail.h"

#include <random>

namespace Mathematics
{
    template class SphereFit3<float>;
    template class SphereFit3<double>;
}

Mathematics::SphereFit3Testing::SphereFit3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, SphereFit3Testing)

void Mathematics::SphereFit3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::SphereFit3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::SphereFit3Testing::FitTest()
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
            vertices.push_back(Vector3D(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator)));
        }

        const SphereFit3D firstSphereFit3(vertices, 2000, true);
        const SphereFit3D secondSphereFit3(vertices, 2000, false);

        const Sphere3D firstCircle = firstSphereFit3.GetSphere();
        const Sphere3D secondCircle = secondSphereFit3.GetSphere();

        for (int i = 0; i < size; ++i)
        {
            const double distance = Vector3ToolsD::Distance(vertices.at(i), firstCircle.GetCenter());

            ASSERT_TRUE(distance <= firstCircle.GetRadius() * 2.1);
            ASSERT_TRUE(distance <= secondCircle.GetRadius() * 2.1);
        }
    }
}
