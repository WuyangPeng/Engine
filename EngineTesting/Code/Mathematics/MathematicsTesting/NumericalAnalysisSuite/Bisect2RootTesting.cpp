// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 14:41)

#include "Bisect2RootTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Bisect2RootDetail.h"

namespace Mathematics
{
    template class Bisect2Root<float>;
    template class Bisect2Root<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Bisect2RootTesting)

void Mathematics::Bisect2RootTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionXTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}
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
void Mathematics::Bisect2RootTesting ::HaveSolutionTest()
{
    double rootX = 9.0;
    double rootY = 19.0;
    BisectRootType type = BisectRootType::HaveSolution;

    Bisect2RootD bisect2Root(rootX, rootY, type);

    ASSERT_APPROXIMATE(bisect2Root.GetXRoot(), rootX, 1e-10);
    ASSERT_APPROXIMATE(bisect2Root.GetYRoot(), rootY, 1e-10);
    ASSERT_ENUM_EQUAL(bisect2Root.GetBisectRootType(), type);
}

void Mathematics::Bisect2RootTesting ::NoSolutionXTest()
{
    BisectRootType type = BisectRootType::NoSolution;

    Bisect2RootD bisect2Root;

    ASSERT_ENUM_EQUAL(bisect2Root.GetBisectRootType(), type);

    [[maybe_unused]] auto value = bisect2Root.GetXRoot();
}

void Mathematics::Bisect2RootTesting ::NoSolutionYTest()
{
    BisectRootType type = BisectRootType::NoSolution;

    Bisect2RootD bisect2Root;

    ASSERT_ENUM_EQUAL(bisect2Root.GetBisectRootType(), type);

    [[maybe_unused]] auto value = bisect2Root.GetYRoot();
}

void Mathematics::Bisect2RootTesting ::UnknownTest()
{
    float rootX = 19.0f;
    float rootY = 29.0f;
    BisectRootType type = BisectRootType::Unknown;

    Bisect2RootF bisect2Root(rootX, rootY, type);

    ASSERT_ENUM_EQUAL(bisect2Root.GetBisectRootType(), type);
    ASSERT_APPROXIMATE(bisect2Root.GetXRoot(), rootX, 1e-8f);
    ASSERT_APPROXIMATE(bisect2Root.GetYRoot(), rootY, 1e-8f);
}
