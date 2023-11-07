///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:15)

#include "Circle3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Circle3Detail.h"

#include <random>

namespace Mathematics
{
    template class Circle3<float>;
    template class Circle3<double>;
}

Mathematics::Circle3Testing::Circle3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Circle3Testing)

void Mathematics::Circle3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Circle3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CircleTest);
}

void Mathematics::Circle3Testing::CircleTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D center(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const double radius(randomDistribution0(generator));

        const Vector3D direction0(randomDistribution0(generator),
                                  randomDistribution0(generator),
                                  randomDistribution0(generator));

        const Vector3D direction1(randomDistribution0(generator),
                                  randomDistribution0(generator),
                                  randomDistribution0(generator));

        const auto normal = Vector3ToolsD::CrossProduct(direction0, direction1);

        const auto orthonormalize = Vector3ToolsD::Orthonormalize(direction0, direction1, normal);

        const Circle3D circle(center, orthonormalize.GetUVector(), orthonormalize.GetVVector(), orthonormalize.GetWVector(), radius);

        ASSERT_TRUE(Vector3ToolsD::Approximate(center, circle.GetCenter()));
        ASSERT_APPROXIMATE(radius, circle.GetRadius(), 1e-10);

        ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetUVector(), circle.GetDirection0()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetVVector(), circle.GetDirection1()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetWVector(), circle.GetNormal()));
    }
}
