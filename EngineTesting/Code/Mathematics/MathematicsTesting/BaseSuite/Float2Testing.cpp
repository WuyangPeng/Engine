// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/19 13:10)

#include "Float2Testing.h"
#include "Mathematics/Base/Float.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Float2Testing)

void Mathematics::Float2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyTest);
}

void Mathematics::Float2Testing
	::ConstructorTest()
{
	// �̶�ֵ����
// 	Float2 firstValue;
// 
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),0.0f,1e-8f);
// 
// 	const float fiveValue{ 5.0f };
// 	const float fourthValue{ 4.0f };
// 	Float2 secondValue{ fiveValue,fourthValue };
// 
// 	ASSERT_APPROXIMATE(secondValue.GetFirstValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetSecondValue(),fourthValue,1e-8f);
// 
// 	const float sixValue{ 6.0f };
// 	const float oneValue{ 1.0f };
// 
// 	secondValue.SetFirstValue(sixValue);
// 	secondValue.SetSecondValue(oneValue);
// 
// 	ASSERT_APPROXIMATE(secondValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetSecondValue(),oneValue,1e-8f);
// 
// 	firstValue = secondValue;
// 
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),oneValue,1e-8f);
// 
// 	Float2 thirdValue{ firstValue };
// 
// 	ASSERT_APPROXIMATE(thirdValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetSecondValue(),oneValue,1e-8f);
}

void Mathematics::Float2Testing
	::DelayCopyTest()
{
	// �̶�ֵ����
// 	const float fiveValue{ 5.0f };
// 	const float oneValue{ 1.0f };
// 	const float sixValue{ 6.0f };
// 	const float twoValue{ 2.0f };
// 	Float2 firstValue{ fiveValue,sixValue };
// 
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),sixValue,1e-8f);
// 
// 	Float2 secondValue{ firstValue };
// 
// 	ASSERT_APPROXIMATE(secondValue.GetFirstValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetSecondValue(),sixValue,1e-8f);
// 
// 	secondValue.SetFirstValue(oneValue);
// 	secondValue.SetSecondValue(twoValue);
// 
// 	ASSERT_APPROXIMATE(secondValue.GetFirstValue(),oneValue,1e-8f);
// 	ASSERT_APPROXIMATE(secondValue.GetSecondValue(),twoValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),fiveValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),sixValue,1e-8f);
// 
// 	Float2 thirdValue{ sixValue,fiveValue };
// 
// 	ASSERT_APPROXIMATE(thirdValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetSecondValue(),fiveValue,1e-8f);
// 
// 	firstValue = thirdValue;
// 	thirdValue.SetFirstValue(twoValue);
// 	thirdValue.SetSecondValue(oneValue);
// 
// 	ASSERT_APPROXIMATE(thirdValue.GetFirstValue(),twoValue,1e-8f);
// 	ASSERT_APPROXIMATE(thirdValue.GetSecondValue(),oneValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetFirstValue(),sixValue,1e-8f);
// 	ASSERT_APPROXIMATE(firstValue.GetSecondValue(),fiveValue,1e-8f);
}

