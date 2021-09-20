// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.3 (2019/09/03 15:03)

#include "ColourDefaultTraitsTesting.h"
#include "Rendering/DataTypes/ColourDefaultTraits.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering,ColourDefaultTraitsTesting) 

void Rendering::ColourDefaultTraitsTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(TraitsTest);
}
 
void Rendering::ColourDefaultTraitsTesting
	::TraitsTest()
{
	ASSERT_EQUAL(ColourDefaultTraits<uint8_t>::sm_MaxValue,255);
	ASSERT_EQUAL(ColourDefaultTraits<uint8_t>::sm_MinValue,0);

	ASSERT_EQUAL(ColourDefaultTraits<uint16_t>::sm_MaxValue,255);
	ASSERT_EQUAL(ColourDefaultTraits<uint16_t>::sm_MinValue,0);

	ASSERT_EQUAL(ColourDefaultTraits<uint32_t>::sm_MaxValue,255);
	ASSERT_EQUAL(ColourDefaultTraits<uint32_t>::sm_MinValue,0);

	ASSERT_EQUAL(ColourDefaultTraits<uint64_t>::sm_MaxValue,255);
	ASSERT_EQUAL(ColourDefaultTraits<uint64_t>::sm_MinValue,0);

	ASSERT_EQUAL(ColourDefaultTraits<int16_t>::sm_MaxValue,255);
	ASSERT_EQUAL(ColourDefaultTraits<int16_t>::sm_MinValue,0);

	ASSERT_EQUAL(ColourDefaultTraits<int>::sm_MaxValue,255);
	ASSERT_EQUAL(ColourDefaultTraits<int>::sm_MinValue,0);

	ASSERT_EQUAL(ColourDefaultTraits<int64_t>::sm_MaxValue,255);
	ASSERT_EQUAL(ColourDefaultTraits<int64_t>::sm_MinValue,0);

	ASSERT_EQUAL(ColourDefaultTraits<float>::sm_MaxValue,1);
	ASSERT_EQUAL(ColourDefaultTraits<float>::sm_MinValue,0);

	ASSERT_EQUAL(ColourDefaultTraits<double>::sm_MaxValue,1);
	ASSERT_EQUAL(ColourDefaultTraits<double>::sm_MinValue,0);

	ASSERT_EQUAL(ColourDefaultTraits<long double>::sm_MaxValue,1);
	ASSERT_EQUAL(ColourDefaultTraits<long double>::sm_MinValue,0);

	// 以下代码不应该通过编译
	// ASSERT_EQUAL(ColourDefaultTraits<int8_t>::sm_MaxValue,255);
	// ASSERT_EQUAL(ColourDefaultTraits<int8_t>::sm_MinValue,0);

	// ASSERT_EQUAL(ColourDefaultTraits<char>::sm_MaxValue,255);
	// ASSERT_EQUAL(ColourDefaultTraits<char>::sm_MinValue,0);

	// ASSERT_EQUAL(ColourDefaultTraits<signed char>::sm_MaxValue,255);
	// ASSERT_EQUAL(ColourDefaultTraits<signed char>::sm_MinValue,0);
}
