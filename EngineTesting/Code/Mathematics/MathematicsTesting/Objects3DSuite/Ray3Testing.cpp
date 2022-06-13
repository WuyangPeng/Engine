///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/31 11:17)

#include "Ray3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Ray3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Ray3<float>;
    template class Ray3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Ray3Testing)

void Mathematics::Ray3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RayTest);
}

void Mathematics::Ray3Testing::RayTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector3D origin(firstRandomDistribution(generator),
                              firstRandomDistribution(generator),
                              firstRandomDistribution(generator));

        Vector3D direction(firstRandomDistribution(generator),
                           firstRandomDistribution(generator),
                           firstRandomDistribution(generator));

        direction.Normalize();

        const Ray3D line(origin, direction);

        ASSERT_TRUE(Vector3ToolsD::Approximate(origin, line.GetOrigin()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(direction, line.GetDirection()));
    }
}
