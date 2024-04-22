///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:01)

#include "BrentsMethodTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodCalculateDetail.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodDetail.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodRootDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

namespace Mathematics
{
    template class BrentsMethod<float, BrentsMethodTesting>;
    template class BrentsMethod<double, BrentsMethodTesting>;
}

Mathematics::BrentsMethodTesting::BrentsMethodTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, BrentsMethodTesting)

void Mathematics::BrentsMethodTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::BrentsMethodTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}

void Mathematics::BrentsMethodTesting::BaseTest()
{
    BrentsMethod<double, BrentsMethodTesting> brentsMethod(FirstSolution, 20, -1e-5, 1e-5, 1e-6, 1e-7, nullptr);

    ASSERT_EQUAL(brentsMethod.GetFunction(), FirstSolution);

    brentsMethod.SetFunction(SecondSolution);
    ASSERT_EQUAL(brentsMethod.GetFunction(), SecondSolution);

    ASSERT_EQUAL(brentsMethod.GetMaxIterations(), 20);

    brentsMethod.SetMaxIterations(10);
    ASSERT_EQUAL(brentsMethod.GetMaxIterations(), 10);

    ASSERT_APPROXIMATE(brentsMethod.GetNegativeFTolerance(), -1e-5, 1e-10);

    brentsMethod.SetNegativeFTolerance(-1e-4);
    ASSERT_APPROXIMATE(brentsMethod.GetNegativeFTolerance(), -1e-4, 1e-10);

    ASSERT_APPROXIMATE(brentsMethod.GetPositiveFTolerance(), 1e-5, 1e-10);

    brentsMethod.SetPositiveFTolerance(1e-4);
    ASSERT_APPROXIMATE(brentsMethod.GetPositiveFTolerance(), 1e-4, 1e-10);

    ASSERT_APPROXIMATE(brentsMethod.GetStepXTolerance(), 1e-6, 1e-10);

    brentsMethod.SetStepXTolerance(1e-8);
    ASSERT_APPROXIMATE(brentsMethod.GetStepXTolerance(), 1e-8, 1e-10);

    ASSERT_APPROXIMATE(brentsMethod.GetConvXTolerance(), 1e-7, 1e-10);

    brentsMethod.SetConvXTolerance(1e-9);
    ASSERT_APPROXIMATE(brentsMethod.GetConvXTolerance(), 1e-9, 1e-10);

    ASSERT_EQUAL_NULL_PTR(brentsMethod.GetUserData());

    brentsMethod.SetUserData(this);
    ASSERT_EQUAL(brentsMethod.GetUserData(), this);

    const double secondSolution = SecondSolution(3.6, this);

    ASSERT_APPROXIMATE(brentsMethod.GetFunctionValue(3.6), secondSolution, 1e-10);
}

void Mathematics::BrentsMethodTesting::HaveSolutionTest()
{
    BrentsMethod<double, BrentsMethodTesting> brentsMethod(SecondSolution, 20, -1e-5, 1e-5, 1e-5, 1e-5, this);

    const BrentsMethodRoot<double> root = brentsMethod.GetRoot(0.0, 10.0);

    ASSERT_APPROXIMATE(SecondSolution(root.GetRoot(), this), 0.0, 1e-5);
    ASSERT_APPROXIMATE(root.GetFunction(), 0.0, 1e-5);
    ASSERT_EQUAL(root.GetBrentsMethodRootType(), BrentsMethodRootType::HaveSolution);
}

void Mathematics::BrentsMethodTesting::NoSolutionTest()
{
    BrentsMethod<double, BrentsMethodTesting> brentsMethod(FirstSolution, 20, -1e-5, 1e-5, 1e-5, 1e-5, this);

    const BrentsMethodRoot<double> root = brentsMethod.GetRoot(10.0, 20.0);

    ASSERT_EQUAL(System::EnumCastUnderlying(root.GetBrentsMethodRootType()), System::EnumCastUnderlying(BisectRootType::NoSolution));
}

void Mathematics::BrentsMethodTesting::UnknownTest()
{
    BrentsMethod<double, BrentsMethodTesting> brentsMethod(SecondSolution, 20, -1e-10, 1e-10, 1e-10, 1e-10, this);

    const BrentsMethodRoot<double> root = brentsMethod.GetRoot(0.0, 10.0);

    ASSERT_EQUAL(System::EnumCastUnderlying(root.GetBrentsMethodRootType()), System::EnumCastUnderlying(BrentsMethodRootType::Unknown));
}

double Mathematics::BrentsMethodTesting::FirstSolution(double input, const BrentsMethodTesting* userData) noexcept
{
    if (userData != nullptr)
        return input * 1.0 - userData->GetUserData() + input * input * input;
    else
        return 0.0;
}

double Mathematics::BrentsMethodTesting::GetUserData() const noexcept
{
    return 3;
}

double Mathematics::BrentsMethodTesting::SecondSolution(double input, const BrentsMethodTesting* userData) noexcept
{
    if (userData != nullptr)
        return input * 1.0 - userData->GetUserData() + input * input;
    else
        return 0.0;
}
