///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:37)

#include "IntegerDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"

#include <gsl/util>

namespace Mathematics
{
    template class IntegerData<1>;
    template class IntegerData<2>;
    template class IntegerData<19>;
    template class IntegerData<22>;
}

Mathematics::IntegerDataTesting::IntegerDataTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, IntegerDataTesting)

void Mathematics::IntegerDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::IntegerDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Bit1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ConversionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FloatingPointConversionTest);
}

void Mathematics::IntegerDataTesting::CopyTest()
{
    std::vector<uint16_t> data{ 0xF000, 0xF458, 0xF789, 0x2523 };

    IntegerData<2> firstIntegerData(data);

    for (auto i = 0u; i < data.size(); ++i)
    {
        ASSERT_EQUAL(firstIntegerData[i], data.at(i));
    }

    IntegerData<2> secondIntegerData(firstIntegerData);

    for (auto i = 0u; i < data.size(); ++i)
    {
        ASSERT_EQUAL(secondIntegerData[i], data.at(i));
    }

    IntegerData<2> thirdIntegerData;

    for (auto i = 0u; i < data.size(); ++i)
    {
        ASSERT_EQUAL(thirdIntegerData[i], 0x0000);
    }

    thirdIntegerData = secondIntegerData;

    for (auto i = 0u; i < data.size(); ++i)
    {
        ASSERT_EQUAL(thirdIntegerData[i], data.at(i));
    }
}

void Mathematics::IntegerDataTesting::Bit1Test()
{
    std::vector<uint16_t> data{ 0b11111111'00000000,  // 最低位
                                0b10111111'11111111,
                                0b10000000'11111111,
                                0b10000000'00000001,
                                0b10000111'00000001,
                                0b01111111'11111110,
                                0b01011111'11111110,
                                0b01000000'11111110,
                                0b01000000'00000010,
                                0b00100001'00011100,
                                0b00010001'00011000,
                                0b00001001'00010000,
                                0b00000101'00100000,
                                0b00000011'01000000,
                                0b00000001'10000000,
                                0b00000001'00000000,
                                0b01011010'00000000,
                                0b01011100'00000000,
                                0b00011000'00000000,
                                0b00010000'00000000,
                                0b00110000'00000000,
                                0b01100000'00000000,
                                0b01000000'00000000,
                                0b11111111'00000000 };  // 最高位

    IntegerData<12> firstIntegerData(data);

    ASSERT_FALSE(firstIntegerData.GetBit(0));
    ASSERT_TRUE(firstIntegerData.GetBit(15));

    ASSERT_TRUE(firstIntegerData.GetBit(boost::numeric_cast<int>(data.size() * 16 - 1)));
    ASSERT_FALSE(firstIntegerData.GetBit(boost::numeric_cast<int>(data.size() * 16 - 1 - 8)));

    firstIntegerData.SetBit(15, false);

    ASSERT_FALSE(firstIntegerData.GetBit(15));
}

void Mathematics::IntegerDataTesting::ConversionTest()
{
    IntegerData<3> firstIntegerData(0xF000F458F7892523ULL);

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

    IntegerData<3> secondIntegerData(uint64_t{ 0 });

    ASSERT_TRUE(secondIntegerData.IsZero());
    ASSERT_ENUM_EQUAL(secondIntegerData.GetSign(), NumericalValueSymbol::Positive);

    IntegerDataAmend<3> secondIntegerDataAmend(secondIntegerData);
    secondIntegerDataAmend.Negative();

    ASSERT_ENUM_EQUAL(secondIntegerData.GetSign(), NumericalValueSymbol::Positive);
    ASSERT_TRUE(secondIntegerData.IsZero());
}

void Mathematics::IntegerDataTesting::CompareTest()
{
    std::vector<uint16_t> data{ 0xF000, 0xF458, 0xF789, 0x2523 };

    IntegerData<2> firstIntegerData(data);
    const IntegerData<2> secondIntegerData(data);

    ASSERT_ENUM_EQUAL(IntegerData<2>::UnsignedDataCompare(firstIntegerData, secondIntegerData), NumericalValueSymbol::Zero);

    ASSERT_TRUE(firstIntegerData == secondIntegerData);
    ASSERT_FALSE(firstIntegerData < secondIntegerData);

    ASSERT_FALSE(firstIntegerData != secondIntegerData);
    ASSERT_TRUE(firstIntegerData <= secondIntegerData);
    ASSERT_FALSE(firstIntegerData > secondIntegerData);
    ASSERT_TRUE(firstIntegerData >= secondIntegerData);

    firstIntegerData[0] = gsl::narrow_cast<uint16_t>(0x0000);

    ASSERT_ENUM_EQUAL(IntegerData<2>::UnsignedDataCompare(firstIntegerData, secondIntegerData), NumericalValueSymbol::Negative);

    ASSERT_FALSE(firstIntegerData == secondIntegerData);
    ASSERT_TRUE(firstIntegerData < secondIntegerData);

    firstIntegerData[0] = gsl::narrow_cast<uint16_t>(0xFFFF);

    ASSERT_ENUM_EQUAL(IntegerData<2>::UnsignedDataCompare(firstIntegerData, secondIntegerData), NumericalValueSymbol::Positive);

    ASSERT_FALSE(firstIntegerData == secondIntegerData);
    ASSERT_FALSE(firstIntegerData < secondIntegerData);

    ASSERT_TRUE(firstIntegerData != secondIntegerData);
    ASSERT_FALSE(firstIntegerData <= secondIntegerData);
    ASSERT_TRUE(firstIntegerData > secondIntegerData);
    ASSERT_TRUE(firstIntegerData >= secondIntegerData);
}

void Mathematics::IntegerDataTesting::FloatingPointConversionTest()
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
