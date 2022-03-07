// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:10)

#include "Minimize1Testing.h"
#include "Mathematics/NumericalAnalysis/Minimize1Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
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
namespace Mathematics
{
	template class Minimize1<float,Minimize1Testing>;
	template class Minimize1<double,Minimize1Testing>;	
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Minimize1Testing) 

void Mathematics::Minimize1Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(GetMinimumTest);
}

void Mathematics::Minimize1Testing
	::GetMinimumTest()
{
	Minimize1<double,Minimize1Testing> minimize1(Function, 10, 10, this);

	Minimize1DataD result = minimize1.GetMinimum(-100, 100, 20);

	ASSERT_APPROXIMATE(result.GetMinValue(), Function(result.GetMinLocation(), this), 1e-10);

	for (int i = -100; i < 100;++i)
	{
		ASSERT_TRUE(result.GetMinValue() <= Function(i, this));
	}
}

double Mathematics::Minimize1Testing
	::Function(double value, const Minimize1Testing* minimize1Testing)
{
	return value * value * minimize1Testing->GetValue() + value * 5.0 + 3.0;
}

double Mathematics::Minimize1Testing
	::GetValue() const 
{
	return 1.0;
}


