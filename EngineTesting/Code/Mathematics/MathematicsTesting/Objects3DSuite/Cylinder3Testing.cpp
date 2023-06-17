///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:16)

#include "Cylinder3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Cylinder3Detail.h"

#include <random>

namespace Mathematics
{
    template class Cylinder3<float>;
    template class Cylinder3<double>;
}

Mathematics::Cylinder3Testing::Cylinder3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Cylinder3Testing)

void Mathematics::Cylinder3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Cylinder3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CylinderTest);
}

void Mathematics::Cylinder3Testing::CylinderTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0{ 0.0, 100.0 };
    const std::uniform_real<double> randomDistribution1(0.0, MathD::GetHalfPI());

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D origin(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));

        Vector3D direction(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));

        direction.Normalize();

        const Line3D line(origin, direction);

        const double radius(MathD::FAbs(randomDistribution1(generator)));

        const double height(MathD::FAbs(randomDistribution0(generator)));

        const Cylinder3D cylinder3(line, radius, height);

        ASSERT_TRUE(Vector3ToolsD::Approximate(cylinder3.GetAxis().GetOrigin(), origin));
        ASSERT_TRUE(Vector3ToolsD::Approximate(cylinder3.GetAxis().GetDirection(), direction));
        ASSERT_APPROXIMATE(cylinder3.GetRadius(), radius, 1e-10);
        ASSERT_APPROXIMATE(cylinder3.GetHeight(), height, 1e-10);
    }
}
