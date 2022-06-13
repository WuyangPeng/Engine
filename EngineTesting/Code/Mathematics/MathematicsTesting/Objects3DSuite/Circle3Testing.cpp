///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/28 15:56)

#include "Circle3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Circle3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Circle3<float>;
    template class Circle3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Circle3Testing)

void Mathematics::Circle3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CircleTest);
}

void Mathematics::Circle3Testing::CircleTest()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector3D center(firstRandomDistribution(generator),
                              firstRandomDistribution(generator),
                              firstRandomDistribution(generator));

        const double radius(firstRandomDistribution(generator));

        const Vector3D direction0(firstRandomDistribution(generator),
                                  firstRandomDistribution(generator),
                                  firstRandomDistribution(generator));

        const Vector3D direction1(firstRandomDistribution(generator),
                                  firstRandomDistribution(generator),
                                  firstRandomDistribution(generator));

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
