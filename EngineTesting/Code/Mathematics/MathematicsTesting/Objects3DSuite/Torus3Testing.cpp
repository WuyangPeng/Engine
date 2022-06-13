///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/31 11:38)

#include "Torus3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Objects3D/Torus3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Torus3<float>;
    template class Torus3<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Torus3Testing)

void Mathematics::Torus3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TorusTest);
}

void Mathematics::Torus3Testing::TorusTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution(0.1, 100.0);
    const uniform_real<double> secondRandomDistribution(0.0, 1.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto innerRadius = firstRandomDistribution(generator);

        const uniform_real<double> thirdRandomDistribution(innerRadius, 105.0);

        auto outerRadius = thirdRandomDistribution(generator);

        const Torus3D torus(outerRadius, innerRadius);

        ASSERT_APPROXIMATE(outerRadius, torus.GetOuterRadius(), 1e-10);
        ASSERT_APPROXIMATE(innerRadius, torus.GetInnerRadius(), 1e-10);

        auto t = secondRandomDistribution(generator);
        auto s = secondRandomDistribution(generator);

        auto radius = torus.GetOuterRadius() + torus.GetInnerRadius() * cos(MathD::GetTwoPI() * t);

        auto x = radius * cos(MathD::GetTwoPI() * s);
        auto y = radius * sin(MathD::GetTwoPI() * s);
        auto z = torus.GetInnerRadius() * sin(MathD::GetTwoPI() * t);

        ASSERT_TRUE(Vector3ToolsD::Approximate(Vector3D(x, y, z), torus.GetPosition(s, t)));

        Vector3D normal(x - torus.GetOuterRadius() * cos(MathD::GetTwoPI() * s), y - torus.GetOuterRadius() * sin(MathD::GetTwoPI() * s), z);
        normal.Normalize();

        ASSERT_TRUE(Vector3ToolsD::Approximate(normal, torus.GetNormal(s, t)));

        const auto parameters = torus.GetParameters(Vector3D(x, y, z));

        ASSERT_APPROXIMATE(parameters.GetS(), s, 1e-10);
        ASSERT_APPROXIMATE(parameters.GetT(), t, 1e-10);
    }
}
