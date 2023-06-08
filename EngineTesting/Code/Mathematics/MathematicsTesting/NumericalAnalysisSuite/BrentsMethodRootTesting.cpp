///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/02 16:53)

#include "BrentsMethodRootTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodCalculateDetail.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodDetail.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodRootDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
Mathematics::BrentsMethodRootTesting::BrentsMethodRootTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, BrentsMethodRootTesting)

void Mathematics::BrentsMethodRootTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::BrentsMethodRootTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionRootTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionFunctionTest);
}

void Mathematics::BrentsMethodRootTesting::HaveSolutionTest()
{
    constexpr double root = 9.0;
    constexpr double function = 19.0;
    const BrentsMethodRootType type = BrentsMethodRootType::HaveSolution;

    const BrentsMethodRootD brentsMethodRoot(root, function, type);

    ASSERT_APPROXIMATE(brentsMethodRoot.GetRoot(), root, 1e-10);
    ASSERT_APPROXIMATE(brentsMethodRoot.GetFunction(), function, 1e-10);
    ASSERT_EQUAL(System::EnumCastUnderlying(brentsMethodRoot.GetBrentsMethodRootType()), System::EnumCastUnderlying(type));
}

void Mathematics::BrentsMethodRootTesting::NoSolutionRootTest()
{
    const BrentsMethodRootType type = BrentsMethodRootType::NoSolution;

    const BrentsMethodRootD brentsMethodRoot;

    ASSERT_EQUAL(System::EnumCastUnderlying(brentsMethodRoot.GetBrentsMethodRootType()), System::EnumCastUnderlying(type));

    MAYBE_UNUSED auto value = brentsMethodRoot.GetRoot();
}

void Mathematics::BrentsMethodRootTesting::UnknownTest()
{
    constexpr float root = 19.0f;
    constexpr float function = 29.0f;
    const BrentsMethodRootType type = BrentsMethodRootType::Unknown;

    const BrentsMethodRootD brentsMethodRoot(root, function, type);

    ASSERT_ENUM_EQUAL(brentsMethodRoot.GetBrentsMethodRootType(), type);
    ASSERT_APPROXIMATE(brentsMethodRoot.GetRoot(), root, 1e-8f);
    ASSERT_APPROXIMATE(brentsMethodRoot.GetFunction(), function, 1e-8f);
}

void Mathematics::BrentsMethodRootTesting::NoSolutionFunctionTest()
{
    const BrentsMethodRootType type = BrentsMethodRootType::NoSolution;

    const BrentsMethodRootD brentsMethodRoot;

    ASSERT_ENUM_EQUAL(brentsMethodRoot.GetBrentsMethodRootType(), type);

    MAYBE_UNUSED auto value = brentsMethodRoot.GetFunction();
}
