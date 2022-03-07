// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 10:02)

#include "TrapezoidRuleTesting.h"
#include "Mathematics/NumericalAnalysis/TrapezoidRuleDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

namespace Mathematics
{
	template class TrapezoidRule<float,TrapezoidRuleTesting>;
	template class TrapezoidRule<double,TrapezoidRuleTesting>;	
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26429)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,TrapezoidRuleTesting) 

void Mathematics::TrapezoidRuleTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
}

double Mathematics::TrapezoidRuleTesting ::Solution(double input, const TrapezoidRuleTesting* userData) noexcept
{
	return input * userData->GetUserData() - 3;
}

double Mathematics::TrapezoidRuleTesting ::GetUserData() const noexcept
{
	return 5;
}

void Mathematics::TrapezoidRuleTesting
	::ValueTest() 
{
	double end = 3.5;
	double begin = 1.5;
	int numSamples = 10;
	auto temp1 = (end - begin);
	auto temp2 = (numSamples - 1);
	double difference = temp1 / static_cast<double>(temp2);
	double value = 0.5 * (Solution(begin, this) + Solution(end, this));

	for (int i = 1; i <= numSamples - 2; ++i)
	{
		value += Solution(begin + i * difference, this);
	}

	value *= difference;

	TrapezoidRule<double, TrapezoidRuleTesting> trapezoidRule(numSamples, begin, end, Solution, this);

	ASSERT_APPROXIMATE(value, trapezoidRule.GetValue(), 1e-10);
}

