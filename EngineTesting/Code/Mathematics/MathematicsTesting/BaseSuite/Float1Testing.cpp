// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 13:08)

#include "Float1Testing.h"
#include "Mathematics/Base/Float.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Float1Testing) 

void Mathematics::Float1Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyTest);
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
void Mathematics::Float1Testing
	::ConstructorTest()
{
	// πÃ∂®÷µ≤‚ ‘
// 	Float1 firstValue;
// 
// 	ASSERT_APPROXIMATE(firstValue.GetValue(),0.0f,1e-8f);
// 
// 	const float fiveValue{ 5.0f };
// 	Float1 secondValue{ fiveValue };
// 
// 	ASSERT_APPROXIMATE(secondValue.GetValue(),fiveValue,1e-8f);
// 
// 	const float sixValue{ 6.0f };
// 
// 	secondValue.SetValue(sixValue);
// 
// 	ASSERT_APPROXIMATE(secondValue.GetValue(),sixValue,1e-8f);
// 
// 	firstValue = secondValue;
// 
// 	ASSERT_APPROXIMATE(firstValue.GetValue(),sixValue,1e-8f);
// 
// 	Float1 thirdValue{ firstValue };
// 
// 	ASSERT_APPROXIMATE(thirdValue.GetValue(),sixValue,1e-8f);
}

void Mathematics::Float1Testing
	::DelayCopyTest()
{
	// πÃ∂®÷µ≤‚ ‘
// 	const float fiveValue{ 5.0f };
// 	const float oneValue{ 1.0f };
// 	const float sixValue{ 6.0f };
// 	Float1 firstValue{ fiveValue };
// 
// 	ASSERT_APPROXIMATE(firstValue.GetValue(),fiveValue,1e-8f);
// 
// 	Float1 secondValue{ firstValue };
// 
// 	ASSERT_APPROXIMATE(secondValue.GetValue(),fiveValue,1e-8f);
// 
// 	secondValue.SetValue(oneValue);
// 
// 	ASSERT_APPROXIMATE(secondValue.GetValue(),oneValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetValue(),fiveValue,1e-8f);
// 
// 	Float1 thirdValue{ sixValue };
// 
// 	ASSERT_APPROXIMATE(thirdValue.GetValue(),sixValue,1e-8f);
// 
// 	firstValue = thirdValue;
// 	thirdValue.SetValue(oneValue);
// 
// 	ASSERT_APPROXIMATE(firstValue.GetValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetValue(),oneValue,1e-8f);
}

