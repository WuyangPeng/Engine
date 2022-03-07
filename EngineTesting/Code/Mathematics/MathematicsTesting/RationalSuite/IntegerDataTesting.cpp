// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.2 (2019/08/26 16:12)

#include "IntegerDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"

#include <boost/utility/binary.hpp>

using std::vector;

namespace Mathematics
{
    template class IntegerData<1>;
    template class IntegerData<2>;
    template class IntegerData<19>;
    template class IntegerData<22>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, IntegerDataTesting)

void Mathematics::IntegerDataTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BitTest);
  //  ASSERT_THROW_EXCEPTION_0(ExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConversionTest);
  //  ASSERT_THROW_EXCEPTION_0(ConversionExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FloatingPointConversionTest);
}

void Mathematics::IntegerDataTesting ::CopyTest()
{
    vector<uint16_t> data{ uint16_t(0xF000), uint16_t(0xF458), uint16_t(0xF789), uint16_t(0x2523) };

    IntegerData<2> firstIntegerData(data);

    for (uint32_t i = 0; i < data.size(); ++i)
    {
        ASSERT_EQUAL(firstIntegerData[i], data[i]);
    }

    IntegerData<2> secondIntegerData(firstIntegerData);

    for (uint32_t i = 0; i < data.size(); ++i)
    {
        ASSERT_EQUAL(secondIntegerData[i], data[i]);
    }

    IntegerData<2> thirdIntegerData;

    for (uint32_t i = 0; i < data.size(); ++i)
    {
        ASSERT_EQUAL(thirdIntegerData[i], 0x0000);
    }

    thirdIntegerData = secondIntegerData;

    for (uint32_t i = 0; i < data.size(); ++i)
    {
        ASSERT_EQUAL(thirdIntegerData[i], data[i]);
    }
}

void Mathematics::IntegerDataTesting ::BitTest()
{
    vector<uint16_t> data{ uint16_t(BOOST_BINARY(11111111 00000000)),  // 最低位
                           uint16_t(BOOST_BINARY(10111111 11111111)),
                           uint16_t(BOOST_BINARY(10000000 11111111)),
                           uint16_t(BOOST_BINARY(10000000 00000001)),
                           uint16_t(BOOST_BINARY(10000111 00000001)),
                           uint16_t(BOOST_BINARY(01111111 11111110)),
                           uint16_t(BOOST_BINARY(01011111 11111110)),
                           uint16_t(BOOST_BINARY(01000000 11111110)),
                           uint16_t(BOOST_BINARY(01000000 00000010)),
                           uint16_t(BOOST_BINARY(00100001 00011100)),
                           uint16_t(BOOST_BINARY(00010001 00011000)),
                           uint16_t(BOOST_BINARY(00001001 00010000)),
                           uint16_t(BOOST_BINARY(00000101 00100000)),
                           uint16_t(BOOST_BINARY(00000011 01000000)),
                           uint16_t(BOOST_BINARY(00000001 10000000)),
                           uint16_t(BOOST_BINARY(00000001 00000000)),
                           uint16_t(BOOST_BINARY(01011010 00000000)),
                           uint16_t(BOOST_BINARY(01011100 00000000)),
                           uint16_t(BOOST_BINARY(00011000 00000000)),
                           uint16_t(BOOST_BINARY(00010000 00000000)),
                           uint16_t(BOOST_BINARY(00110000 00000000)),
                           uint16_t(BOOST_BINARY(01100000 00000000)),
                           uint16_t(BOOST_BINARY(01000000 00000000)),
                           uint16_t(BOOST_BINARY(11111111 00000000)) };  // 最高位

    IntegerData<12> firstIntegerData(data);

    ASSERT_FALSE(firstIntegerData.GetBit(0));
    ASSERT_TRUE(firstIntegerData.GetBit(15));

    ASSERT_TRUE(firstIntegerData.GetBit(boost::numeric_cast<int>(data.size() * 16 - 1)));
    ASSERT_FALSE(firstIntegerData.GetBit(boost::numeric_cast<int>(data.size() * 16 - 1 - 8)));

    firstIntegerData.SetBit(15, false);

    ASSERT_FALSE(firstIntegerData.GetBit(15));
}

void Mathematics::IntegerDataTesting ::ExceptionTest()
{
    vector<uint16_t> data{ uint16_t(0xF000), uint16_t(0xF458), uint16_t(0xF789), uint16_t(0x2523), uint16_t(0x5555) };

    IntegerData<2> integerData(data);
}

void Mathematics::IntegerDataTesting ::ConversionTest()
{
    IntegerData<3> firstIntegerData(uint64_t((0xF000F458F7892523ULL)));

    ASSERT_EQUAL(firstIntegerData[0], uint16_t(0x2523));
    ASSERT_EQUAL(firstIntegerData[1], uint16_t(0xF789));
    ASSERT_EQUAL(firstIntegerData[2], uint16_t(0xF458));
    ASSERT_EQUAL(firstIntegerData[3], uint16_t(0xF000));

    ASSERT_ENUM_EQUAL(firstIntegerData.GetSign(), NumericalValueSymbol::Positive);
    ASSERT_FALSE(firstIntegerData.IsZero());

    IntegerDataAmend<3> firstIntegerDataAmend(firstIntegerData);
    firstIntegerDataAmend.Negative();

    ASSERT_ENUM_EQUAL(firstIntegerData.GetSign(), NumericalValueSymbol::Negative);
    ASSERT_FALSE(firstIntegerData.IsZero());

    firstIntegerData.SetZero();
    ASSERT_TRUE(firstIntegerData.IsZero());
    ASSERT_ENUM_EQUAL(firstIntegerData.GetSign(), NumericalValueSymbol::Positive);

    IntegerData<3> secondIntegerData(uint64_t(0));

    ASSERT_TRUE(secondIntegerData.IsZero());
    ASSERT_ENUM_EQUAL(secondIntegerData.GetSign(), NumericalValueSymbol::Positive);

    IntegerDataAmend<3> secondIntegerDataAmend(secondIntegerData);
    secondIntegerDataAmend.Negative();

    ASSERT_ENUM_EQUAL(secondIntegerData.GetSign(), NumericalValueSymbol::Positive);
    ASSERT_TRUE(secondIntegerData.IsZero());
}

void Mathematics::IntegerDataTesting ::ConversionExceptionTest()
{
    IntegerData<2> firstIntegerData(uint64_t((0xF000F458F7892523LL)));
}

void Mathematics::IntegerDataTesting ::CompareTest()
{
    vector<uint16_t> data{ uint16_t(0xF000), uint16_t(0xF458), uint16_t(0xF789), uint16_t(0x2523) };

    IntegerData<2> firstIntegerData(data);
    IntegerData<2> secondIntegerData(data);

    ASSERT_ENUM_EQUAL(IntegerData<2>::UnsignedDataCompare(firstIntegerData, secondIntegerData), NumericalValueSymbol::Zero);

    ASSERT_TRUE(firstIntegerData == secondIntegerData);
    ASSERT_FALSE(firstIntegerData < secondIntegerData);

    ASSERT_FALSE(firstIntegerData != secondIntegerData);
    ASSERT_TRUE(firstIntegerData <= secondIntegerData);
    ASSERT_FALSE(firstIntegerData > secondIntegerData);
    ASSERT_TRUE(firstIntegerData >= secondIntegerData);

    firstIntegerData[0] = static_cast<uint16_t>(0x0000);

    ASSERT_ENUM_EQUAL(IntegerData<2>::UnsignedDataCompare(firstIntegerData, secondIntegerData), NumericalValueSymbol::Negative);

    ASSERT_FALSE(firstIntegerData == secondIntegerData);
    ASSERT_TRUE(firstIntegerData < secondIntegerData);

    firstIntegerData[0] = static_cast<uint16_t>(0xFFFF);

    ASSERT_ENUM_EQUAL(IntegerData<2>::UnsignedDataCompare(firstIntegerData, secondIntegerData), NumericalValueSymbol::Positive);

    ASSERT_FALSE(firstIntegerData == secondIntegerData);
    ASSERT_FALSE(firstIntegerData < secondIntegerData);

    ASSERT_TRUE(firstIntegerData != secondIntegerData);
    ASSERT_FALSE(firstIntegerData <= secondIntegerData);
    ASSERT_TRUE(firstIntegerData > secondIntegerData);
    ASSERT_TRUE(firstIntegerData >= secondIntegerData);
}

void Mathematics::IntegerDataTesting ::FloatingPointConversionTest()
{
    IntegerData<3> firstIntegerData(3333333.33333f);

    ASSERT_EQUAL(firstIntegerData[0], uint16_t(0xDCD5));
    ASSERT_EQUAL(firstIntegerData[1], uint16_t(0x0032));

    ASSERT_ENUM_EQUAL(firstIntegerData.GetSign(), NumericalValueSymbol::Positive);
    ASSERT_FALSE(firstIntegerData.IsZero());

    IntegerData<3> secondIntegerData(-22223333.011113333f);  // -22223334

    ASSERT_EQUAL(secondIntegerData[0], uint16_t(0xE61A));
    ASSERT_EQUAL(secondIntegerData[1], uint16_t(0xFEAC));

    ASSERT_EQUAL(secondIntegerData[2], uint16_t(0xFFFF));
    ASSERT_EQUAL(secondIntegerData[3], uint16_t(0xFFFF));
    ASSERT_EQUAL(secondIntegerData[4], uint16_t(0xFFFF));
    ASSERT_EQUAL(secondIntegerData[5], uint16_t(0xFFFF));

    ASSERT_ENUM_EQUAL(secondIntegerData.GetSign(), NumericalValueSymbol::Negative);
    ASSERT_FALSE(secondIntegerData.IsZero());

    IntegerData<3> thirdIntegerData(2222222.33333);

    ASSERT_EQUAL(thirdIntegerData[0], uint16_t(0xE88E));
    ASSERT_EQUAL(thirdIntegerData[1], uint16_t(0x0021));

    ASSERT_ENUM_EQUAL(thirdIntegerData.GetSign(), NumericalValueSymbol::Positive);
    ASSERT_FALSE(thirdIntegerData.IsZero());

    IntegerData<3> fourthIntegerData(-22223333.311113333);

    ASSERT_EQUAL(fourthIntegerData[0], uint16_t(0xE61B));
    ASSERT_EQUAL(fourthIntegerData[1], uint16_t(0xFEAC));

    ASSERT_EQUAL(fourthIntegerData[2], uint16_t(0xFFFF));
    ASSERT_EQUAL(fourthIntegerData[3], uint16_t(0xFFFF));
    ASSERT_EQUAL(fourthIntegerData[4], uint16_t(0xFFFF));
    ASSERT_EQUAL(fourthIntegerData[5], uint16_t(0xFFFF));

    ASSERT_ENUM_EQUAL(fourthIntegerData.GetSign(), NumericalValueSymbol::Negative);
    ASSERT_FALSE(fourthIntegerData.IsZero());
}
