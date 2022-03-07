// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 14:53)

#include "Bisect3RootTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Bisect3RootDetail.h"

namespace Mathematics
{
    template class Bisect3Root<float>;
    template class Bisect3Root<double>;
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
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Bisect3RootTesting)

void Mathematics::Bisect3RootTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionXTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionYTest);
    ASSERT_THROW_EXCEPTION_0(NoSolutionZTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}

void Mathematics::Bisect3RootTesting ::HaveSolutionTest()
{
    double rootX = 9.0;
    double rootY = 19.0;
    double rootZ = 29.0;
    BisectRootType type = BisectRootType::HaveSolution;

    Bisect3RootD bisect3Root(rootX, rootY, rootZ, type);

    ASSERT_APPROXIMATE(bisect3Root.GetXRoot(), rootX, 1e-10);
    ASSERT_APPROXIMATE(bisect3Root.GetYRoot(), rootY, 1e-10);
    ASSERT_APPROXIMATE(bisect3Root.GetZRoot(), rootZ, 1e-10);
    ASSERT_ENUM_EQUAL(bisect3Root.GetBisectRootType(), type);
}

void Mathematics::Bisect3RootTesting ::NoSolutionXTest()
{
    BisectRootType type = BisectRootType::NoSolution;

    Bisect3RootD bisect3Root;

    ASSERT_ENUM_EQUAL(bisect3Root.GetBisectRootType(), type);

    [[maybe_unused]] auto value = bisect3Root.GetXRoot();
}

void Mathematics::Bisect3RootTesting ::NoSolutionYTest()
{
    BisectRootType type = BisectRootType::NoSolution;

    Bisect3RootD bisect3Root;

    ASSERT_ENUM_EQUAL(bisect3Root.GetBisectRootType(), type);

    [[maybe_unused]] auto value = bisect3Root.GetYRoot();
}

void Mathematics::Bisect3RootTesting ::NoSolutionZTest()
{
    BisectRootType type = BisectRootType::NoSolution;

    Bisect3RootD bisect3Root;

    ASSERT_ENUM_EQUAL(bisect3Root.GetBisectRootType(), type);

    [[maybe_unused]] auto value = bisect3Root.GetZRoot();
}

void Mathematics::Bisect3RootTesting ::UnknownTest()
{
    float rootX = 19.0f;
    float rootY = 29.0f;
    float rootZ = 39.0f;
    BisectRootType type = BisectRootType::Unknown;

    Bisect3RootF bisect3Root(rootX, rootY, rootZ, type);

    ASSERT_ENUM_EQUAL(bisect3Root.GetBisectRootType(), type);
    ASSERT_APPROXIMATE(bisect3Root.GetXRoot(), rootX, 1e-8f);
    ASSERT_APPROXIMATE(bisect3Root.GetYRoot(), rootY, 1e-8f);
    ASSERT_APPROXIMATE(bisect3Root.GetZRoot(), rootZ, 1e-8f);
}
