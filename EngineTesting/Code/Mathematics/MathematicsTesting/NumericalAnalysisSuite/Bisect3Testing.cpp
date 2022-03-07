// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 15:01)

#include "Bisect3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect3Detail.h"
#include "Mathematics/NumericalAnalysis/Bisect3RootDetail.h"  

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Bisect3Testing)

void Mathematics::Bisect3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoSolutionTest);
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
#include SYSTEM_WARNING_DISABLE(26497)
void Mathematics::Bisect3Testing ::HaveSolutionTest()
{
//     DoubleBisect3 bisect3(FirstEquation, SecondEquation, ThirdEquation, 10, 0.01);
// 
//     DoubleBisect3Root root = bisect3.Bisect(0.9, -0.1, 0.9, 1.1, 0.1, 1.12);
// 
//     ASSERT_APPROXIMATE(FirstEquation(root.GetXRoot(), root.GetYRoot(), root.GetZRoot()), 0.0f, 0.01);
//     ASSERT_APPROXIMATE(SecondEquation(root.GetXRoot(), root.GetYRoot(), root.GetZRoot()), 0.0f, 0.01);
//     ASSERT_APPROXIMATE(ThirdEquation(root.GetXRoot(), root.GetYRoot(), root.GetZRoot()), 0.0f, 0.01);
//     ASSERT_ENUM_EQUAL(root.GetBisectRootType(), BisectRootType::HaveSolution);
}

void Mathematics::Bisect3Testing ::NoSolutionTest()
 {
//     DoubleBisect3 bisect3(FirstEquation, SecondEquation, ThirdEquation, 10, 0.01);
// 
//     DoubleBisect3Root root = bisect3.Bisect(0.8, -0.1, 0.9, 0.9, 0.1, 1.12);
// 
//     ASSERT_ENUM_EQUAL(root.GetBisectRootType(), BisectRootType::NoSolution);
}

void Mathematics::Bisect3Testing ::UnknownTest()
{
//     DoubleBisect3 bisect3(FirstEquation, SecondEquation, ThirdEquation, 2, 0.01);
// 
//     DoubleBisect3Root root = bisect3.Bisect(0.9, -0.1, 0.9, 1.1, 0.1, 1.12);
// 
//     ASSERT_TRUE(0.9 <= root.GetXRoot() && root.GetXRoot() <= 1.1);
//     ASSERT_TRUE(-0.1 <= root.GetYRoot() && root.GetYRoot() <= 0.1);
//     ASSERT_TRUE(0.9 <= root.GetZRoot() && root.GetZRoot() <= 1.12);
// 
//     ASSERT_ENUM_EQUAL(root.GetBisectRootType(), BisectRootType::Unknown);
}

// static
double Mathematics::Bisect3Testing ::FirstEquation(double x, double y, double z)
{
    return 1.0 * x + 1.0 * y - 2.0 * z + 1.0;
}

// static
double Mathematics::Bisect3Testing ::SecondEquation(double x, double y, double z)
{
    return 2.0 * x + 3.0 * y - 1.0 * z - 1.0;
}

double Mathematics::Bisect3Testing ::ThirdEquation(double x, double y, double z)
{
    return 3.0 * x + 1.0 * y - 2.0 * z - 1.0;
}
