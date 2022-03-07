// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 15:04)

#include "BrentsMethodCalculateTesting.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodDetail.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodRootDetail.h"
#include "Mathematics/NumericalAnalysis/BrentsMethodCalculateDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

namespace Mathematics
{
	template class BrentsMethodCalculate<float,BrentsMethodCalculateTesting>;
	template class BrentsMethodCalculate<double,BrentsMethodCalculateTesting>;
	template class BrentsMethod<float,BrentsMethodCalculateTesting>;
	template class BrentsMethod<double,BrentsMethodCalculateTesting>;
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
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,BrentsMethodCalculateTesting) 

void Mathematics::BrentsMethodCalculateTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(HaveSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoSolutionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnknownTest);
}


void Mathematics::BrentsMethodCalculateTesting
	::HaveSolutionTest()
{
	BrentsMethod<double, BrentsMethodCalculateTesting> brentsMethod(Solution, 20, -1e-5, 1e-5, 1e-5, 1e-5, this);

	BrentsMethodCalculate<double, BrentsMethodCalculateTesting> calculate(brentsMethod, 0.0, 10.0);

	BrentsMethodRoot<double> root = calculate.GetRoot();

	ASSERT_APPROXIMATE(Solution(root.GetRoot(), this), 0.0,1e-5);
	ASSERT_APPROXIMATE(root.GetFunction(), 0.0, 1e-5);
	ASSERT_ENUM_EQUAL(root.GetBrentsMethodRootType(), BrentsMethodRootType::HaveSolution);
}

void Mathematics::BrentsMethodCalculateTesting
	::NoSolutionTest()
{
	BrentsMethod<double, BrentsMethodCalculateTesting> brentsMethod(Solution, 20, -1e-5, 1e-5, 1e-5, 1e-5, this);

	BrentsMethodCalculate<double, BrentsMethodCalculateTesting> calculate(brentsMethod, 10.0, 20.0);

	BrentsMethodRoot<double> root = calculate.GetRoot();

	ASSERT_EQUAL(System::EnumCastUnderlying(root.GetBrentsMethodRootType()), System::EnumCastUnderlying(BisectRootType::NoSolution));
}

void Mathematics::BrentsMethodCalculateTesting
	::UnknownTest()
{
    BrentsMethod<double, BrentsMethodCalculateTesting> brentsMethod(Solution, 20, -1e-10, 1e-10, 1e-10, 1e-10, this);

	BrentsMethodCalculate<double, BrentsMethodCalculateTesting> calculate(brentsMethod, 0.0, 10.0);

	BrentsMethodRoot<double> root = calculate.GetRoot();

	ASSERT_EQUAL(System::EnumCastUnderlying(root.GetBrentsMethodRootType()), System::EnumCastUnderlying(BrentsMethodRootType::Unknown));
}

double Mathematics::BrentsMethodCalculateTesting
	::Solution(double input, const BrentsMethodCalculateTesting* userData) 
{
	return input * 1.0 - userData->GetUserData() + input * input;
}

double Mathematics::BrentsMethodCalculateTesting
	::GetUserData() const
{
	return MathD::GetValue(2);
}

