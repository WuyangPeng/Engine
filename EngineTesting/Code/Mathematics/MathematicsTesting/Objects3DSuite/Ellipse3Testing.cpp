///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:16)

#include "Ellipse3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Ellipse3Detail.h"

#include <random>

namespace Mathematics
{
    template class Ellipse3<float>;
    template class Ellipse3<double>;
}

Mathematics::Ellipse3Testing::Ellipse3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Ellipse3Testing)

void Mathematics::Ellipse3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Ellipse3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EllipseTest);
}

void Mathematics::Ellipse3Testing::EllipseTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D center(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        Vector3D normal(randomDistribution0(generator),
                        randomDistribution0(generator),
                        randomDistribution0(generator));

        Vector3D major(randomDistribution0(generator),
                       randomDistribution0(generator),
                       randomDistribution0(generator));

        Vector3D minor(randomDistribution0(generator),
                       randomDistribution0(generator),
                       randomDistribution0(generator));

        auto majorLength = Vector3ToolsD::GetLength(major);
        auto minorLength = Vector3ToolsD::GetLength(minor);

        normal.Normalize();
        major.Normalize();
        minor.Normalize();

        const auto orthonormalize = Vector3ToolsD::Orthonormalize(major, minor, normal);

        const Ellipse3D ellipse(center, orthonormalize.GetUVector(), orthonormalize.GetVVector(), orthonormalize.GetWVector(), majorLength, minorLength);

        ASSERT_TRUE(Vector3ToolsD::Approximate(center, ellipse.GetCenter()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetUVector(), ellipse.GetNormal()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetVVector(), ellipse.GetMajor()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetWVector(), ellipse.GetMinor()));
        ASSERT_APPROXIMATE(majorLength, ellipse.GetMajorLength(), 1e-10);
        ASSERT_APPROXIMATE(minorLength, ellipse.GetMinorLength(), 1e-10);
    }
}
