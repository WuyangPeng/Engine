///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:01)

#include "BrentsMethodCalculateTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodCalculateDetail.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodDetail.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodRootDetail.h"

namespace Mathematics
{
    template class BrentsMethodCalculate<float, BrentsMethodCalculateTesting>;
    template class BrentsMethodCalculate<double, BrentsMethodCalculateTesting>;
    template class BrentsMethod<float, BrentsMethodCalculateTesting>;
    template class BrentsMethod<double, BrentsMethodCalculateTesting>;
}

Mathematics::BrentsMethodCalculateTesting::BrentsMethodCalculateTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, BrentsMethodCalculateTesting)

void Mathematics::BrentsMethodCalculateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::BrentsMethodCalculateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}

void Mathematics::BrentsMethodCalculateTesting::HaveSolutionTest()
{
    const BrentsMethod<double, BrentsMethodCalculateTesting> brentsMethod(Solution, 20, -1e-5, 1e-5, 1e-5, 1e-5, this);

    BrentsMethodCalculate<double, BrentsMethodCalculateTesting> calculate(brentsMethod, 0.0, 10.0);

    const BrentsMethodRoot<double> root = calculate.GetRoot();

    ASSERT_APPROXIMATE(Solution(root.GetRoot(), this), 0.0, 1e-5);
    ASSERT_APPROXIMATE(root.GetFunction(), 0.0, 1e-5);
    ASSERT_EQUAL(root.GetBrentsMethodRootType(), BrentsMethodRootType::HaveSolution);
}

void Mathematics::BrentsMethodCalculateTesting::NoSolutionTest()
{
    const BrentsMethod<double, BrentsMethodCalculateTesting> brentsMethod(Solution, 20, -1e-5, 1e-5, 1e-5, 1e-5, this);

    BrentsMethodCalculate<double, BrentsMethodCalculateTesting> calculate(brentsMethod, 10.0, 20.0);

    const BrentsMethodRoot<double> root = calculate.GetRoot();

    ASSERT_EQUAL(System::EnumCastUnderlying(root.GetBrentsMethodRootType()), System::EnumCastUnderlying(BisectRootType::NoSolution));
}

void Mathematics::BrentsMethodCalculateTesting::UnknownTest()
{
    const BrentsMethod<double, BrentsMethodCalculateTesting> brentsMethod(Solution, 20, -1e-10, 1e-10, 1e-10, 1e-10, this);

    BrentsMethodCalculate<double, BrentsMethodCalculateTesting> calculate(brentsMethod, 0.0, 10.0);

    const BrentsMethodRoot<double> root = calculate.GetRoot();

    ASSERT_EQUAL(System::EnumCastUnderlying(root.GetBrentsMethodRootType()), System::EnumCastUnderlying(BrentsMethodRootType::Unknown));
}

double Mathematics::BrentsMethodCalculateTesting::Solution(double input, const BrentsMethodCalculateTesting* userData) noexcept
{
    if (userData != nullptr)
        return input * 1.0 - userData->GetUserData() + input * input;
    else
        return 0.0;
}

double Mathematics::BrentsMethodCalculateTesting::GetUserData() const noexcept
{
    return MathD::GetValue(2);
}
