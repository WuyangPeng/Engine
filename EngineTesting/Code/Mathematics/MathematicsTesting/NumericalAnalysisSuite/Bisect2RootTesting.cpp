///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:00)

#include "Bisect2RootTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect2RootDetail.h"

namespace Mathematics
{
    template class Bisect2Root<float>;
    template class Bisect2Root<double>;
}

Mathematics::Bisect2RootTesting::Bisect2RootTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Bisect2RootTesting)

void Mathematics::Bisect2RootTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Bisect2RootTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionXTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}

void Mathematics::Bisect2RootTesting::HaveSolutionTest()
{
    constexpr double rootX = 9.0;
    constexpr double rootY = 19.0;
    const BisectRootType type = BisectRootType::HaveSolution;

    const Bisect2RootD bisect2Root(rootX, rootY, type);

    ASSERT_APPROXIMATE(bisect2Root.GetXRoot(), rootX, 1e-10);
    ASSERT_APPROXIMATE(bisect2Root.GetYRoot(), rootY, 1e-10);
    ASSERT_EQUAL(bisect2Root.GetBisectRootType(), type);
}

void Mathematics::Bisect2RootTesting::NoSolutionXTest()
{
    const BisectRootType type = BisectRootType::NoSolution;

    const Bisect2RootD bisect2Root;

    ASSERT_EQUAL(bisect2Root.GetBisectRootType(), type);

    MAYBE_UNUSED auto value = bisect2Root.GetXRoot();
}

void Mathematics::Bisect2RootTesting::NoSolutionYTest()
{
    const BisectRootType type = BisectRootType::NoSolution;

    const Bisect2RootD bisect2Root;

    ASSERT_EQUAL(bisect2Root.GetBisectRootType(), type);

    MAYBE_UNUSED auto value = bisect2Root.GetYRoot();
}

void Mathematics::Bisect2RootTesting::UnknownTest()
{
    constexpr float rootX = 19.0f;
    constexpr float rootY = 29.0f;
    const BisectRootType type = BisectRootType::Unknown;

    const Bisect2RootF bisect2Root(rootX, rootY, type);

    ASSERT_EQUAL(bisect2Root.GetBisectRootType(), type);
    ASSERT_APPROXIMATE(bisect2Root.GetXRoot(), rootX, 1e-8f);
    ASSERT_APPROXIMATE(bisect2Root.GetYRoot(), rootY, 1e-8f);
}
