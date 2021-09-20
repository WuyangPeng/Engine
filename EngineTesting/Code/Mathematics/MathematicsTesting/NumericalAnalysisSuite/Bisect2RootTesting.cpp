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

void Mathematics::Bisect2RootTesting ::HaveSolutionTest()
{
    double rootX = 9.0;
    double rootY = 19.0;
    BisectRootType type = BisectRootType::HaveSolution;

    DoubleBisect2Root bisect2Root(rootX, rootY, type);

    ASSERT_APPROXIMATE(bisect2Root.GetXRoot(), rootX, 1e-10);
    ASSERT_APPROXIMATE(bisect2Root.GetYRoot(), rootY, 1e-10);
    ASSERT_ENUM_EQUAL(bisect2Root.GetBisectRootType(), type);
}

void Mathematics::Bisect2RootTesting ::NoSolutionXTest()
{
    BisectRootType type = BisectRootType::NoSolution;

    DoubleBisect2Root bisect2Root;

    ASSERT_ENUM_EQUAL(bisect2Root.GetBisectRootType(), type);

    [[maybe_unused]] auto value = bisect2Root.GetXRoot();
}

void Mathematics::Bisect2RootTesting ::NoSolutionYTest()
{
    BisectRootType type = BisectRootType::NoSolution;

    DoubleBisect2Root bisect2Root;

    ASSERT_ENUM_EQUAL(bisect2Root.GetBisectRootType(), type);

    [[maybe_unused]] auto value = bisect2Root.GetYRoot();
}

void Mathematics::Bisect2RootTesting ::UnknownTest()
{
    float rootX = 19.0f;
    float rootY = 29.0f;
    BisectRootType type = BisectRootType::Unknown;

    FloatBisect2Root bisect2Root(rootX, rootY, type);

    ASSERT_ENUM_EQUAL(bisect2Root.GetBisectRootType(), type);
    ASSERT_APPROXIMATE(bisect2Root.GetXRoot(), rootX, 1e-8f);
    ASSERT_APPROXIMATE(bisect2Root.GetYRoot(), rootY, 1e-8f);
}
