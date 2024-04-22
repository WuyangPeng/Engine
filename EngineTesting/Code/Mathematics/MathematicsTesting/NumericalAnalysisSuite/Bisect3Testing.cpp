///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:01)

#include "Bisect3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect3Detail.h"
#include "Mathematics/NumericalAnalysis/Bisect3RootDetail.h"

Mathematics::Bisect3Testing::Bisect3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Bisect3Testing)

void Mathematics::Bisect3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Bisect3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}

void Mathematics::Bisect3Testing::HaveSolutionTest()
{
    const Bisect3D bisect3(FirstEquation, SecondEquation, ThirdEquation, 10, 0.01);

    const Bisect3RootD root = bisect3.Bisect(0.9, -0.1, 0.9, 1.1, 0.1, 1.12);

    ASSERT_APPROXIMATE(FirstEquation(root.GetXRoot(), root.GetYRoot(), root.GetZRoot()), 0.0f, 0.01);
    ASSERT_APPROXIMATE(SecondEquation(root.GetXRoot(), root.GetYRoot(), root.GetZRoot()), 0.0f, 0.01);
    ASSERT_APPROXIMATE(ThirdEquation(root.GetXRoot(), root.GetYRoot(), root.GetZRoot()), 0.0f, 0.01);
    ASSERT_EQUAL(root.GetBisectRootType(), BisectRootType::HaveSolution);
}

void Mathematics::Bisect3Testing::NoSolutionTest()
{
    const Bisect3D bisect3(FirstEquation, SecondEquation, ThirdEquation, 10, 0.01);

    const Bisect3RootD root = bisect3.Bisect(0.8, -0.1, 0.9, 0.9, 0.1, 1.12);

    ASSERT_EQUAL(root.GetBisectRootType(), BisectRootType::NoSolution);
}

void Mathematics::Bisect3Testing::UnknownTest()
{
    const Bisect3D bisect3(FirstEquation, SecondEquation, ThirdEquation, 2, 0.01);

    const Bisect3RootD root = bisect3.Bisect(0.9, -0.1, 0.9, 1.1, 0.1, 1.12);

    ASSERT_TRUE(0.9 <= root.GetXRoot() && root.GetXRoot() <= 1.1);
    ASSERT_TRUE(-0.1 <= root.GetYRoot() && root.GetYRoot() <= 0.1);
    ASSERT_TRUE(0.9 <= root.GetZRoot() && root.GetZRoot() <= 1.12);

    ASSERT_EQUAL(root.GetBisectRootType(), BisectRootType::Unknown);
}
