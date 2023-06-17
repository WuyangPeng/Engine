///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:15)

#include "Cone3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Cone3Detail.h"

#include <random>

namespace Mathematics
{
    template class Cone3<float>;
    template class Cone3<double>;
}

Mathematics::Cone3Testing::Cone3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Cone3Testing)

void Mathematics::Cone3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Cone3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConeTest);
}

void Mathematics::Cone3Testing::ConeTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0{ -100.0, 100.0 };
    const std::uniform_real<double> randomDistribution1(0.0, MathD::GetHalfPI());

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D vertex(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        Vector3D axis(randomDistribution0(generator),
                      randomDistribution0(generator),
                      randomDistribution0(generator));

        axis.Normalize();

        const double angle(randomDistribution1(generator));

        const double height(MathD::FAbs(randomDistribution0(generator)));

        const Cone3D cone(vertex, axis, angle, height);

        ASSERT_TRUE(Vector3ToolsD::Approximate(cone.GetVertex(), vertex));
        ASSERT_TRUE(Vector3ToolsD::Approximate(cone.GetAxis(), axis));
        ASSERT_APPROXIMATE(MathD::Cos(angle), cone.GetCosAngle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::Sin(angle), cone.GetSinAngle(), 1e-10);
        ASSERT_APPROXIMATE(height, cone.GetHeight(), 1e-10);

        const Cone3D secondCone(MathD::Cos(angle), MathD::Sin(angle), height, vertex, axis);

        ASSERT_TRUE(Vector3ToolsD::Approximate(secondCone.GetVertex(), vertex));
        ASSERT_TRUE(Vector3ToolsD::Approximate(secondCone.GetAxis(), axis));
        ASSERT_APPROXIMATE(MathD::Cos(angle), secondCone.GetCosAngle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::Sin(angle), secondCone.GetSinAngle(), 1e-10);
        ASSERT_APPROXIMATE(height, secondCone.GetHeight(), 1e-10);
    }
}
