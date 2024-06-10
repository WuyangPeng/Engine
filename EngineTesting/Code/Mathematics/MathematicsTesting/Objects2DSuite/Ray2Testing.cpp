///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:12)

#include "Ray2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/Ray2Detail.h"

#include <random>

namespace Mathematics
{
    template class Ray2<float>;
    template class Ray2<double>;
}

Mathematics::Ray2Testing::Ray2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Ray2Testing)

void Mathematics::Ray2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Ray2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RayTest);
}

void Mathematics::Ray2Testing::RayTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 origin(randomDistribution0(generator), randomDistribution0(generator));

        Vector2 direction(randomDistribution0(generator), randomDistribution0(generator));

        direction.Normalize();

        const Ray2D line(origin, direction);

        ASSERT_TRUE(Vector2ToolsD::Approximate(origin, line.GetOrigin()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(direction, line.GetDirection()));
    }
}
