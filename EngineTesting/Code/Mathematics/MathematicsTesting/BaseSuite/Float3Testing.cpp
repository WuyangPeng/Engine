// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 13:11)

#include "Float3Testing.h"
#include "Mathematics/Base/Float.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Float3Testing)

void Mathematics::Float3Testing
    ::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyTest);
}

void Mathematics::Float3Testing
	::ConstructorTest()
{
	// πÃ∂®÷µ≤‚ ‘
// 	Float3 firstValue;
// 
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetThirdValue(),0.0f,1e-8f);
// 
// 	const float fiveValue{ 5.0f };
// 	const float fourthValue{ 4.0f };
// 	const float zeroValue{ 0.0f };
// 	Float3 secondValue{ fiveValue,fourthValue,zeroValue };
// 
// 	ASSERT_APPROXIMATE(secondValue.GetFirstValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetSecondValue(),fourthValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetThirdValue(),zeroValue,1e-8f);
// 
// 	const float sixValue{ 6.0f };
// 	const float oneValue{ 1.0f };
// 	const float tenValue{ 10.0f };
// 
// 	secondValue.SetFirstValue(sixValue);
// 	secondValue.SetSecondValue(oneValue);
// 	secondValue.SetThirdValue(tenValue);
// 
// 	ASSERT_APPROXIMATE(secondValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetSecondValue(),oneValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetThirdValue(),tenValue,1e-8f);
// 
// 	firstValue = secondValue;
// 
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),oneValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetThirdValue(),tenValue,1e-8f);
// 
// 	Float3 thirdValue{ firstValue };
// 
// 	ASSERT_APPROXIMATE(thirdValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetSecondValue(),oneValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetThirdValue(),tenValue,1e-8f);
}

void Mathematics::Float3Testing
::DelayCopyTest()
{
	// πÃ∂®÷µ≤‚ ‘
// 	const float fiveValue{ 5.0f };
// 	const float oneValue{ 1.0f };
// 	const float sixValue{ 6.0f };
// 	const float twoValue{ 2.0f };
// 	const float threeValue{ 3.0f };
// 	const float zeroValue{ 0.0f };
// 	Float3 firstValue{ fiveValue,sixValue,threeValue };
// 
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetThirdValue(),threeValue,1e-8f);
// 
// 	Float3 secondValue{ firstValue };
// 
// 	ASSERT_APPROXIMATE(secondValue.GetFirstValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetSecondValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetThirdValue(),threeValue,1e-8f);
// 
// 	secondValue.SetFirstValue(oneValue);
// 	secondValue.SetSecondValue(twoValue);
// 	secondValue.SetThirdValue(zeroValue);
// 
// 	ASSERT_APPROXIMATE(secondValue.GetFirstValue(),oneValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetSecondValue(),twoValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetThirdValue(),zeroValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetThirdValue(),threeValue,1e-8f);
// 
// 	Float3 thirdValue{ sixValue,fiveValue,threeValue };
// 
// 	ASSERT_APPROXIMATE(thirdValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetSecondValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetThirdValue(),threeValue,1e-8f);
// 
// 	firstValue = thirdValue;
// 	thirdValue.SetFirstValue(twoValue);
// 	thirdValue.SetSecondValue(oneValue);
// 	thirdValue.SetThirdValue(zeroValue);
// 
// 	ASSERT_APPROXIMATE(thirdValue.GetFirstValue(),twoValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetSecondValue(),oneValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetThirdValue(),zeroValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetThirdValue(),threeValue,1e-8f);
}

