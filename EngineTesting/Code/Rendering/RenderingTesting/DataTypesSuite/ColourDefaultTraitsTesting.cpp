///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/16 16:38)

#include "ColourDefaultTraitsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/DataTypes/ColourDefaultTraits.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ColourDefaultTraitsTesting)

void Rendering::ColourDefaultTraitsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TraitsTest);
}

void Rendering::ColourDefaultTraitsTesting::TraitsTest()
{
    ASSERT_EQUAL(ColourDefaultTraits<uint8_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<uint8_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<uint16_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<uint16_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<uint32_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<uint32_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<uint64_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<uint64_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<int16_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<int16_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<int>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<int>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<int64_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<int64_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<float>::maxValue, 1);
    ASSERT_EQUAL(ColourDefaultTraits<float>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<double>::maxValue, 1);
    ASSERT_EQUAL(ColourDefaultTraits<double>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<long double>::maxValue, 1);
    ASSERT_EQUAL(ColourDefaultTraits<long double>::minValue, 0);

#if 0

    // 以下代码不应该通过编译
    ASSERT_EQUAL(ColourDefaultTraits<int8_t>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<int8_t>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<char>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<char>::minValue, 0);

    ASSERT_EQUAL(ColourDefaultTraits<signed char>::maxValue, 255);
    ASSERT_EQUAL(ColourDefaultTraits<signed char>::minValue, 0);

#endif  // 0
}
