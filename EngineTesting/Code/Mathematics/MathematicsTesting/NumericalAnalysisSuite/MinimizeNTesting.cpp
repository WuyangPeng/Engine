// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:10)

#include "MinimizeNTesting.h"
#include "Mathematics/NumericalAnalysis/MinimizeNDetail.h"
#include "Mathematics/NumericalAnalysis/Minimize1Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::vector;
using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class MinimizeN<float,MinimizeNTesting>;
	template class MinimizeN<double,MinimizeNTesting>;	
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
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,MinimizeNTesting) 

void Mathematics::MinimizeNTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GetMinimumTest);
}

void Mathematics::MinimizeNTesting
	::GetMinimumTest()
{
	MinimizeN<double,MinimizeNTesting> minimizeN(5,Function, 10, 10, 10,this);

	vector<double> begin{ -10.0,-20.0,-30.0,-40.0,-70.0 };

	vector<double> end{ 10.0,20.0,30.0,40.0,70.0 };

	vector<double> initial{ 0.0,0.0,0.0,0.0,0.0 };

	MinimizeNDataD result = minimizeN.GetMinimum(begin, end, initial);

	ASSERT_APPROXIMATE(result.GetMinValue(), Function(result.GetMinLocation(), this), 1e-10);

	default_random_engine generator;

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		vector<double> value;

		for (auto beginIndex = 0u;beginIndex < begin.size();++beginIndex)
		{
			uniform_int<> integerRandomDistribution(static_cast<int>(begin[beginIndex]),static_cast<int>(end[beginIndex]));

			value.push_back(integerRandomDistribution(generator));
		}

		ASSERT_TRUE(result.GetMinValue() <= Function(value, this));
	}
}

double Mathematics::MinimizeNTesting
	::Function(const vector<double>& value, const MinimizeNTesting* minimize1Testing)
{
	double result = 0.0;

	for (vector<double>::const_iterator iter = value.begin(),
		 end = value.end();iter != end;++iter)
	{
		result += (*iter) * (*iter) * minimize1Testing->GetValue() +  (*iter) * 5.0 + 3.0;
	}

	return result;
}

double Mathematics::MinimizeNTesting
	::GetValue() const 
{
	return 1.0;
}
