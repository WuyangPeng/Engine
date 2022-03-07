// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 14:34)

#include "Bisect1RootTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Bisect1RootDetail.h"

namespace Mathematics
{
    template class Bisect1Root<float>;
    template class Bisect1Root<double>;
}
#include SYSTEM_WARNING_DISABLE(26496)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Bisect1RootTesting)

void Mathematics::Bisect1RootTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}

void Mathematics::Bisect1RootTesting ::HaveSolutionTest()
{
    double root = 9.0;
    BisectRootType type = BisectRootType::HaveSolution;

    Bisect1RootD bisect1Root(root, type);

    ASSERT_APPROXIMATE(bisect1Root.GetRoot(), root, 1e-10);
    ASSERT_ENUM_EQUAL(bisect1Root.GetBisect1RootType(), type);
}

void Mathematics::Bisect1RootTesting ::NoSolutionTest()
{
    BisectRootType type = BisectRootType::NoSolution;

    Bisect1RootD bisect1Root;

    ASSERT_ENUM_EQUAL(bisect1Root.GetBisect1RootType(), type);

    [[maybe_unused]] auto value = bisect1Root.GetRoot();
}

void Mathematics::Bisect1RootTesting ::UnknownTest()
{
    float root = 19.0f;
    BisectRootType type = BisectRootType::Unknown;

    Bisect1RootF bisect1Root(root, type);

    ASSERT_ENUM_EQUAL(bisect1Root.GetBisect1RootType(), type);
    ASSERT_APPROXIMATE(bisect1Root.GetRoot(), root, 1e-8f);
}
