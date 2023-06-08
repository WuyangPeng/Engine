///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/28 15:57)

#include "Cone3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Cone3Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

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
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };
    const uniform_real<double> secondRandomDistribution(0.0, MathD::GetHalfPI());

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D vertex(firstRandomDistribution(generator),
                              firstRandomDistribution(generator),
                              firstRandomDistribution(generator));

        Vector3D axis(firstRandomDistribution(generator),
                      firstRandomDistribution(generator),
                      firstRandomDistribution(generator));

        axis.Normalize();

        const double angle(secondRandomDistribution(generator));

        const double height(MathD::FAbs(firstRandomDistribution(generator)));

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
