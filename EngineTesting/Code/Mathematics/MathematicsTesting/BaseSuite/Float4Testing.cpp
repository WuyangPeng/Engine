// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 13:12)

#include "Float4Testing.h"
#include "Mathematics/Base/Float.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Float4Testing)

void Mathematics::Float4Testing
    ::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyTest);
}
#include SYSTEM_WARNING_DISABLE(26440)

void Mathematics::Float4Testing
	::ConstructorTest()
{
	// πÃ∂®÷µ≤‚ ‘
// 	Float4 firstValue;
// 
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetThirdValue(),0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetFourthValue(),0.0f,1e-8f);
// 
// 	const float fiveValue{ 5.0f };
// 	const float fourthValue{ 4.0f };
// 	const float zeroValue{ 0.0f };
// 	const float twoValue{ 2.0f };
// 	Float4 secondValue{ fiveValue,fourthValue,zeroValue,twoValue };
// 
// 	ASSERT_APPROXIMATE(secondValue.GetFirstValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetSecondValue(),fourthValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetThirdValue(),zeroValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetFourthValue(),twoValue,1e-8f);
// 
// 	const float sixValue{ 6.0f };
// 	const float oneValue{ 1.0f };
// 	const float tenValue{ 10.0f };
// 	const float twelveValue{ 12.0f };
// 
// 	secondValue.SetFirstValue(sixValue);
// 	secondValue.SetSecondValue(oneValue);
// 	secondValue.SetThirdValue(tenValue);
// 	secondValue.SetFourthValue(twelveValue);
// 
// 	ASSERT_APPROXIMATE(secondValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetSecondValue(),oneValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetThirdValue(),tenValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetFourthValue(),twelveValue,1e-8f);
// 
// 	firstValue = secondValue;
// 
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),oneValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetThirdValue(),tenValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetFourthValue(),twelveValue,1e-8f);
// 
// 	Float4 thirdValue{ firstValue };
// 
// 	ASSERT_APPROXIMATE(thirdValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetSecondValue(),oneValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetThirdValue(),tenValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetFourthValue(),twelveValue,1e-8f);
}

void Mathematics::Float4Testing
	::DelayCopyTest()
{
	// πÃ∂®÷µ≤‚ ‘
// 	const float fiveValue{ 5.0f };
// 	const float oneValue{ 1.0f };
// 	const float sixValue{ 6.0f };
// 	const float twoValue{ 2.0f };
// 	const float threeValue{ 3.0f };
// 	const float zeroValue{ 0.0f };
// 	const float twelveValue{ 12.0f };
// 	const float elevenValue{ 11.0f };
// 	Float4 firstValue{ fiveValue,sixValue,threeValue,twelveValue };
// 
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetThirdValue(),threeValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetFourthValue(),twelveValue,1e-8f);
// 
// 	Float4 secondValue{ firstValue };
// 
// 	ASSERT_APPROXIMATE(secondValue.GetFirstValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetSecondValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetThirdValue(),threeValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetFourthValue(),twelveValue,1e-8f);
// 
// 	secondValue.SetFirstValue(oneValue);
// 	secondValue.SetSecondValue(twoValue);
// 	secondValue.SetThirdValue(zeroValue);
// 	secondValue.SetFourthValue(elevenValue);
// 
// 	ASSERT_APPROXIMATE(secondValue.GetFirstValue(),oneValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetSecondValue(),twoValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetThirdValue(),zeroValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetFourthValue(),elevenValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetThirdValue(),threeValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetFourthValue(),twelveValue,1e-8f);
// 
// 	Float4 thirdValue{ sixValue,fiveValue,twelveValue,threeValue };
// 
// 	ASSERT_APPROXIMATE(thirdValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetSecondValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetThirdValue(),twelveValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetFourthValue(),threeValue,1e-8f);
// 
// 	firstValue = thirdValue;
// 	thirdValue.SetFirstValue(twoValue);
// 	thirdValue.SetSecondValue(oneValue);
// 	thirdValue.SetThirdValue(zeroValue);
// 	thirdValue.SetFourthValue(elevenValue);
// 
// 	ASSERT_APPROXIMATE(thirdValue.GetFirstValue(),twoValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetSecondValue(),oneValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetThirdValue(),zeroValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetFourthValue(),elevenValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetThirdValue(),twelveValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetFourthValue(),threeValue,1e-8f);
}

