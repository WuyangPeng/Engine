///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:20)

#include "Ray3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Ray3Detail.h"

#include <random>

namespace Mathematics
{
    template class Ray3<float>;
    template class Ray3<double>;
}

Mathematics::Ray3Testing::Ray3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Ray3Testing)

void Mathematics::Ray3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Ray3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RayTest);
}

void Mathematics::Ray3Testing::RayTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real<double> randomDistribution0(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D origin(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        Vector3D direction(randomDistribution0(generator),
                           randomDistribution0(generator),
                           randomDistribution0(generator));

        direction.Normalize();

        const Ray3D line(origin, direction);

        ASSERT_TRUE(Vector3ToolsD::Approximate(origin, line.GetOrigin()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(direction, line.GetDirection()));
    }
}
