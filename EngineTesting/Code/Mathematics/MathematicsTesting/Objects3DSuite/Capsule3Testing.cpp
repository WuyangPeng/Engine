///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:15)

#include "Capsule3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Capsule3Detail.h"

#include <random>

namespace Mathematics
{
    template class Capsule3<float>;
    template class Capsule3<double>;
}

Mathematics::Capsule3Testing::Capsule3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Capsule3Testing)

void Mathematics::Capsule3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Capsule3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CapsuleTest);
}

void Mathematics::Capsule3Testing::CapsuleTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point0(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const Vector3D point1(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const Segment3D firstSegment(point0, point1);

        const double radius(MathD::FAbs(randomDistribution0(generator)));

        const Capsule3D capsule(firstSegment, radius);

        ASSERT_TRUE(Vector3ToolsD::Approximate(capsule.GetSegment().GetBeginPoint(), firstSegment.GetBeginPoint()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(capsule.GetSegment().GetEndPoint(), firstSegment.GetEndPoint()));
        ASSERT_APPROXIMATE(radius, capsule.GetRadius(), 1e-10);
    }
}
