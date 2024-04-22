///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:00)

#include "Bisect1Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/Bisect1Detail.h"

namespace Mathematics
{
    template class Bisect1<float>;
    template class Bisect1<double>;
}

Mathematics::Bisect1Testing::Bisect1Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Bisect1Testing)

void Mathematics::Bisect1Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Bisect1Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}

void Mathematics::Bisect1Testing::HaveSolutionTest()
{
    Bisect1D bisect1(FirstEquation, 200);

    const Bisect1RootD root = bisect1.Bisect(0.0, 1.0);

    ASSERT_APPROXIMATE(FirstEquation(root.GetRoot()), 0.0, 1e-8);

    ASSERT_EQUAL(root.GetBisect1RootType(), BisectRootType::HaveSolution);
}

void Mathematics::Bisect1Testing::NoSolutionTest()
{
    Bisect1F bisect1(SecondEquation, 20);

    const Bisect1RootF root = bisect1.Bisect(-1.0, 0.0);

    ASSERT_EQUAL(root.GetBisect1RootType(), BisectRootType::NoSolution);
}

void Mathematics::Bisect1Testing::UnknownTest()
{
    Bisect1D bisect1(FirstEquation, 20);

    const Bisect1RootD root = bisect1.Bisect(0.0, 1.0);

    ASSERT_TRUE(0.0 <= root.GetRoot());
    ASSERT_TRUE(root.GetRoot() <= 1.0);

    ASSERT_EQUAL(root.GetBisect1RootType(), BisectRootType::Unknown);
}
