///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 13:56)
#include "IntegerDataAmendTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataAmendDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"

using std::vector;

namespace Mathematics
{
    template class IntegerData<1>;
    template class IntegerData<2>;
    template class IntegerData<19>;
    template class IntegerData<22>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, IntegerDataAmendTesting)

void Mathematics::IntegerDataAmendTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FromUnsignedIntTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NegativeTest);
}

void Mathematics::IntegerDataAmendTesting::FromUnsignedIntTest()
{
    vector<uint16_t> data{ 0b11111111'11111111,
                           0b10111111'11111111,
                           0b10000000'11111111,
                           0b10000000'00000001,
                           0b10000000'00000000,
                           0b01111111'11111111,
                           0b01011111'11111111,
                           0b01000000'11111111,
                           0b01000000'00000001,
                           0b00100001'00011001,
                           0b00010001'00011001,
                           0b00001001'00011001,
                           0b00000101'00011001,
                           0b00000011'00011001,
                           0b00000001'00011001,
                           0b00000000'10011001,
                           0b00000000'01011001,
                           0b00000000'00111001,
                           0b00000000'00011001,
                           0b00000000'00001001,
                           0b00000000'00000101,
                           0b00000000'00000011,
                           0b00000000'00000010,
                           0b00000000'00000001 };

    IntegerData<12> firstIntegerData(data);
    IntegerDataAmend<12> firstIntegerDataAmend(firstIntegerData);

    firstIntegerDataAmend.FromUnsignedInt(0, 0b00011110'00000001);

    ASSERT_EQUAL(BOOST_BINARY_U(00011110 00000001), firstIntegerData[0]);
}

void Mathematics::IntegerDataAmendTesting::NegativeTest()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26475)

    IntegerData<4> firstIntegerData{ int64_t(0xF000F458F7892523LL) };

#include STSTEM_WARNING_POP

    ASSERT_EQUAL(firstIntegerData[0], uint16_t(0x2523));
    ASSERT_EQUAL(firstIntegerData[1], uint16_t(0xF789));
    ASSERT_EQUAL(firstIntegerData[2], uint16_t(0xF458));
    ASSERT_EQUAL(firstIntegerData[3], uint16_t(0xF000));

    ASSERT_ENUM_EQUAL(firstIntegerData.GetSign(), NumericalValueSymbol::Negative);
    ASSERT_FALSE(firstIntegerData.IsZero());

    IntegerDataAmend<4> firstIntegerDataAmend(firstIntegerData);
    firstIntegerDataAmend.Negative();

    ASSERT_ENUM_EQUAL(firstIntegerData.GetSign(), NumericalValueSymbol::Positive);
    ASSERT_FALSE(firstIntegerData.IsZero());

    IntegerData<5> secondIntegerData{ uint64_t{} };

    ASSERT_TRUE(secondIntegerData.IsZero());
    ASSERT_ENUM_EQUAL(secondIntegerData.GetSign(), NumericalValueSymbol::Positive);

    IntegerDataAmend<5> secondIntegerDataAmend(secondIntegerData);
    secondIntegerDataAmend.Negative();

    ASSERT_ENUM_EQUAL(secondIntegerData.GetSign(), NumericalValueSymbol::Positive);
    ASSERT_TRUE(secondIntegerData.IsZero());
}
