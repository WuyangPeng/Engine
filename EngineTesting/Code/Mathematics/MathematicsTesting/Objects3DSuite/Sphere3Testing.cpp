///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/31 11:24)

#include "Sphere3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Sphere3Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

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
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D center(firstRandomDistribution(generator),
                              firstRandomDistribution(generator),
                              firstRandomDistribution(generator));

        const double radius(MathD::FAbs(firstRandomDistribution(generator)));

        const Sphere3D circle(center, radius);

        ASSERT_TRUE(Vector3ToolsD::Approximate(center, circle.GetCenter()));
        ASSERT_APPROXIMATE(radius, circle.GetRadius(), 1e-10);
    }
}
