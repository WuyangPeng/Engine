///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:21)

#include "Sphere3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Sphere3Detail.h"

#include <random>

namespace Mathematics
{
    template class Sphere3<float>;
    template class Sphere3<double>;
}

Mathematics::Sphere3Testing::Sphere3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Sphere3Testing)

void Mathematics::Sphere3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Sphere3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SphereTest);
}

void Mathematics::Sphere3Testing::SphereTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    const std::uniform_real<double> randomDistribution0(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D center(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const double radius(MathD::FAbs(randomDistribution0(generator)));

        const Sphere3D circle(center, radius);

        ASSERT_TRUE(Vector3ToolsD::Approximate(center, circle.GetCenter()));
        ASSERT_APPROXIMATE(radius, circle.GetRadius(), 1e-10);
    }
}
