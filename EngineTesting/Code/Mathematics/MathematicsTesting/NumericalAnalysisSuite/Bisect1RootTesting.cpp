///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:00)

#include "Bisect1RootTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect1RootDetail.h"

namespace Mathematics
{
    template class Bisect1Root<float>;
    template class Bisect1Root<double>;
}

Mathematics::Bisect1RootTesting::Bisect1RootTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Bisect1RootTesting)

void Mathematics::Bisect1RootTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Bisect1RootTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}

void Mathematics::Bisect1RootTesting::HaveSolutionTest()
{
    constexpr auto root = 9.0;
    const auto type = BisectRootType::HaveSolution;

    const Bisect1RootD bisect1Root(root, type);

    ASSERT_APPROXIMATE(bisect1Root.GetRoot(), root, 1e-10);
    ASSERT_ENUM_EQUAL(bisect1Root.GetBisect1RootType(), type);
}

void Mathematics::Bisect1RootTesting::NoSolutionTest()
{
    const auto type = BisectRootType::NoSolution;

    const Bisect1RootD bisect1Root;

    ASSERT_ENUM_EQUAL(bisect1Root.GetBisect1RootType(), type);

    MAYBE_UNUSED auto value = bisect1Root.GetRoot();
}

void Mathematics::Bisect1RootTesting::UnknownTest()
{
    constexpr auto root = 19.0f;
    const auto type = BisectRootType::Unknown;

    const Bisect1RootF bisect1Root(root, type);

    ASSERT_ENUM_EQUAL(bisect1Root.GetBisect1RootType(), type);
    ASSERT_APPROXIMATE(bisect1Root.GetRoot(), root, 1e-8f);
}
