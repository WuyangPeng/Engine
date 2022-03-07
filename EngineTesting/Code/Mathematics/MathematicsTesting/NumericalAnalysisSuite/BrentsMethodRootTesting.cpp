// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 15:05)

#include "BrentsMethodRootTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodCalculateDetail.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodDetail.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodRootDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, BrentsMethodRootTesting)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26481)
void Mathematics::BrentsMethodRootTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionRootTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionFunctionTest);
}

void Mathematics::BrentsMethodRootTesting ::HaveSolutionTest()
{
    double root = 9.0;
    double function = 19.0;
    BrentsMethodRootType type = BrentsMethodRootType::HaveSolution;

    BrentsMethodRootD brentsMethodRoot(root, function, type);

    ASSERT_APPROXIMATE(brentsMethodRoot.GetRoot(), root, 1e-10);
    ASSERT_APPROXIMATE(brentsMethodRoot.GetFunction(), function, 1e-10);
    ASSERT_EQUAL(System::EnumCastUnderlying(brentsMethodRoot.GetBrentsMethodRootType()), System::EnumCastUnderlying(type));
}

void Mathematics::BrentsMethodRootTesting ::NoSolutionRootTest()
{
    BrentsMethodRootType type = BrentsMethodRootType::NoSolution;

    BrentsMethodRootD brentsMethodRoot;

    ASSERT_EQUAL(System::EnumCastUnderlying(brentsMethodRoot.GetBrentsMethodRootType()), System::EnumCastUnderlying(type));

    [[maybe_unused]] auto value = brentsMethodRoot.GetRoot();
}

void Mathematics::BrentsMethodRootTesting ::UnknownTest()
{
    float root = 19.0f;
    float function = 29.0f;
    BrentsMethodRootType type = BrentsMethodRootType::Unknown;

    BrentsMethodRootD brentsMethodRoot(root, function, type);

    ASSERT_ENUM_EQUAL(brentsMethodRoot.GetBrentsMethodRootType(), type);
    ASSERT_APPROXIMATE(brentsMethodRoot.GetRoot(), root, 1e-8f);
    ASSERT_APPROXIMATE(brentsMethodRoot.GetFunction(), function, 1e-8f);
}

void Mathematics::BrentsMethodRootTesting ::NoSolutionFunctionTest()
{
    BrentsMethodRootType type = BrentsMethodRootType::NoSolution;

    BrentsMethodRootD brentsMethodRoot;

    ASSERT_ENUM_EQUAL(brentsMethodRoot.GetBrentsMethodRootType(), type);

   [[maybe_unused]] auto value = brentsMethodRoot.GetFunction();
}
