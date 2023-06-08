///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/02 16:32)

#include "Bisect3RootTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Bisect3RootDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
namespace Mathematics
{
    template class Bisect3Root<float>;
    template class Bisect3Root<double>;
}

Mathematics::Bisect3RootTesting::Bisect3RootTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Bisect3RootTesting)

void Mathematics::Bisect3RootTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Bisect3RootTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionXTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionYTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionZTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}

void Mathematics::Bisect3RootTesting::HaveSolutionTest()
{
    constexpr double rootX = 9.0;
    constexpr double rootY = 19.0;
    constexpr double rootZ = 29.0;
    constexpr BisectRootType type = BisectRootType::HaveSolution;

    const Bisect3RootD bisect3Root(rootX, rootY, rootZ, type);

    ASSERT_APPROXIMATE(bisect3Root.GetXRoot(), rootX, 1e-10);
    ASSERT_APPROXIMATE(bisect3Root.GetYRoot(), rootY, 1e-10);
    ASSERT_APPROXIMATE(bisect3Root.GetZRoot(), rootZ, 1e-10);
    ASSERT_ENUM_EQUAL(bisect3Root.GetBisectRootType(), type);
}

void Mathematics::Bisect3RootTesting::NoSolutionXTest()
{
    const BisectRootType type = BisectRootType::NoSolution;

    const Bisect3RootD bisect3Root;

    ASSERT_ENUM_EQUAL(bisect3Root.GetBisectRootType(), type);

    MAYBE_UNUSED auto value = bisect3Root.GetXRoot();
}

void Mathematics::Bisect3RootTesting::NoSolutionYTest()
{
    const BisectRootType type = BisectRootType::NoSolution;

    const Bisect3RootD bisect3Root;

    ASSERT_ENUM_EQUAL(bisect3Root.GetBisectRootType(), type);

    MAYBE_UNUSED auto value = bisect3Root.GetYRoot();
}

void Mathematics::Bisect3RootTesting::NoSolutionZTest()
{
    const BisectRootType type = BisectRootType::NoSolution;

    const Bisect3RootD bisect3Root;

    ASSERT_ENUM_EQUAL(bisect3Root.GetBisectRootType(), type);

    MAYBE_UNUSED auto value = bisect3Root.GetZRoot();
}

void Mathematics::Bisect3RootTesting::UnknownTest()
{
    constexpr float rootX = 19.0f;
    constexpr float rootY = 29.0f;
    constexpr float rootZ = 39.0f;
    const BisectRootType type = BisectRootType::Unknown;

    const Bisect3RootF bisect3Root(rootX, rootY, rootZ, type);

    ASSERT_ENUM_EQUAL(bisect3Root.GetBisectRootType(), type);
    ASSERT_APPROXIMATE(bisect3Root.GetXRoot(), rootX, 1e-8f);
    ASSERT_APPROXIMATE(bisect3Root.GetYRoot(), rootY, 1e-8f);
    ASSERT_APPROXIMATE(bisect3Root.GetZRoot(), rootZ, 1e-8f);
}
