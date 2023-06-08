///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 16:28)

#include "IntegerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class Integer<5>;
    template class Integer<7>;
}

Mathematics::IntegerTesting::IntegerTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, IntegerTesting)

void Mathematics::IntegerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::IntegerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UtilitiesTest);
}

// Construction测试
void Mathematics::IntegerTesting::ConstructionTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PositiveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NegativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ZeroTest);
}

void Mathematics::IntegerTesting::PositiveTest()
{
    default_random_engine generator{};
    const uniform_int<uint32_t> firstRandomDistribution(0, INT32_MAX);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = firstRandomDistribution(generator);

        Integer<4> firstInteger(firstValue);
        uint32_t lower = firstInteger[0];
        uint32_t high = firstInteger[1];

        ASSERT_EQUAL((lower | (high << 16)), firstValue);

        Integer<9> secondInteger(firstValue);
        lower = secondInteger[0];
        high = secondInteger[1];

        ASSERT_EQUAL((lower | (high << 16)), firstValue);

        Integer<21> thirdInteger(firstValue);
        lower = thirdInteger[0];
        high = thirdInteger[1];

        ASSERT_EQUAL((lower | (high << 16)), firstValue);

        thirdInteger *= thirdInteger;
        thirdInteger *= thirdInteger;

        const Integer<21> fourthInteger(thirdInteger);

        ASSERT_EQUAL(fourthInteger, thirdInteger);

        Integer<9> fifthInteger;

        ASSERT_EQUAL(fifthInteger, Integer<9>(0));

        fifthInteger = secondInteger;

        ASSERT_EQUAL(fifthInteger, secondInteger);

        vector<uint16_t> shortVector(30);

        for (int i = 0; i < 30; ++i)
        {
            shortVector.at(i) = secondRandomDistribution(generator);
        }

        Integer<15> sixthInteger(shortVector);

        for (int i = 0; i < 30; ++i)
        {
            ASSERT_EQUAL(sixthInteger[i], 0x0000FFFF & static_cast<uint16_t>(shortVector.at(i)));
        }
    }
}

void Mathematics::IntegerTesting::NegativeTest()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(-INT32_MAX, 0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = firstRandomDistribution(generator);

        Integer<6> firstInteger(firstValue);
        auto lower = firstInteger[0];
        auto high = firstInteger[1];

        ASSERT_EQUAL(static_cast<int>(lower | (high << 16)), firstValue);

        Integer<19> secondInteger(firstValue);
        lower = secondInteger[0];
        high = secondInteger[1];

        ASSERT_EQUAL(static_cast<int>(lower | (high << 16)), firstValue);

        Integer<90> thirdInteger(firstValue);
        lower = thirdInteger[0];
        high = thirdInteger[1];

        ASSERT_EQUAL(static_cast<int>(lower | (high << 16)), firstValue);

        thirdInteger *= thirdInteger;
        thirdInteger *= thirdInteger;
        thirdInteger *= thirdInteger;

        const Integer<90> fourthInteger(thirdInteger);

        ASSERT_EQUAL(fourthInteger, thirdInteger);

        Integer<19> fifthInteger;

        ASSERT_EQUAL(fifthInteger, Integer<19>(0));

        fifthInteger = secondInteger;

        ASSERT_EQUAL(fifthInteger, secondInteger);
    }
}

void Mathematics::IntegerTesting::ZeroTest()
{
    Integer<26> firstInteger(0);

    ASSERT_EQUAL(firstInteger[0], 0u);
    ASSERT_EQUAL(firstInteger[1], 0u);

    Integer<7> secondInteger(0);

    ASSERT_EQUAL(secondInteger[0], 0u);
    ASSERT_EQUAL(secondInteger[1], 0u);

    Integer<30> thirdInteger(0);

    ASSERT_EQUAL(thirdInteger[0], 0u);
    ASSERT_EQUAL(thirdInteger[1], 0u);
}

// Calculate测试
void Mathematics::IntegerTesting::CalculateTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReverseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AbsoluteValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AddTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MinusTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiplyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DivideTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LeftShiftTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RightShiftTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SignTest);
}

void Mathematics::IntegerTesting::ReverseTest()
{
    default_random_engine generator{};
    const uniform_int<uint16_t> firstRandomDistribution(0, UINT16_MAX);
    const uniform_int<uint32_t> secondRandomDistribution(0, INT32_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> shortVector(26);

        // 最高位为零
        for (auto i = 0; i < 24; ++i)
        {
            shortVector.at(i) = firstRandomDistribution(generator);
        }

        const Integer<13> firstInteger(shortVector);
        Integer<13> secondInteger = -firstInteger;

        ASSERT_EQUAL(firstInteger, -secondInteger);

        secondInteger = -secondInteger;

        ASSERT_EQUAL(firstInteger, secondInteger);

        const int firstValue = secondRandomDistribution(generator);

        Integer<4> thirdInteger(firstValue);
        thirdInteger = -thirdInteger;
        ASSERT_EQUAL(thirdInteger, Integer<4>(-firstValue));
    }
}

void Mathematics::IntegerTesting::AbsoluteValueTest()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(-INT32_MAX, INT32_MAX);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> shortVector(22);

        // 最高位为零
        for (auto i = 0; i < 20; ++i)
        {
            shortVector.at(i) = secondRandomDistribution(generator);
        }

        const Integer<11> firstInteger(shortVector);
        Integer<11> secondInteger = firstInteger.GetAbsoluteValue();

        ASSERT_EQUAL(firstInteger, secondInteger);

        const Integer<11> thirdInteger = -firstInteger;
        secondInteger = thirdInteger.GetAbsoluteValue();

        ASSERT_EQUAL(thirdInteger, -secondInteger);

        auto firstValue = firstRandomDistribution(generator);

        const Integer<4> fourthInteger(firstValue);
        const Integer<4> fifthInteger = fourthInteger.GetAbsoluteValue();
        ASSERT_EQUAL(fifthInteger, Integer<4>(abs(firstValue)));
    }
}

void Mathematics::IntegerTesting::AddTest()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(0, INT32_MAX / 2);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(88);
        vector<uint16_t> secondShortVector(88);

        // 最高位为零
        for (auto i = 0; i < 86; ++i)
        {
            firstShortVector.at(i) = secondRandomDistribution(generator);
            secondShortVector.at(i) = secondRandomDistribution(generator);
        }

        const Integer<44> firstInteger(firstShortVector);
        const Integer<44> secondInteger(secondShortVector);

        Integer<44> thirdInteger = firstInteger + secondInteger;
        Integer<44> fourthInteger = secondInteger + firstInteger;

        ASSERT_EQUAL(thirdInteger, fourthInteger);

        thirdInteger -= secondInteger;

        ASSERT_EQUAL(thirdInteger, firstInteger);

        fourthInteger -= firstInteger;

        ASSERT_EQUAL(fourthInteger, secondInteger);

        fourthInteger = -fourthInteger;
        thirdInteger += fourthInteger;

        ASSERT_EQUAL(thirdInteger, firstInteger - secondInteger);

        const uint32_t firstValue = firstRandomDistribution(generator);
        const uint32_t secondValue = firstRandomDistribution(generator);

        Integer<4> fifthInteger(firstValue);
        const Integer<4> sixthInteger(secondValue);

        fifthInteger += sixthInteger;

        ASSERT_EQUAL(fifthInteger, Integer<4>(firstValue + secondValue));

        // 精确测试
        vector<uint16_t> thirdShortVector(20);
        vector<uint16_t> fourthShortVector(20);

        // 最高位为零
        for (auto i = 0; i < 18; ++i)
        {
            thirdShortVector.at(i) = secondRandomDistribution(generator);
            fourthShortVector.at(i) = secondRandomDistribution(generator);
        }

        Integer<10> seventhInteger(thirdShortVector);
        Integer<10> eighthInteger(fourthShortVector);

        if (loop % 2 == 1)
        {
            eighthInteger = -eighthInteger;
        }

        Integer<10> ninthInteger(seventhInteger);
        seventhInteger += eighthInteger;

        uint32_t carry = 0;
        for (auto i = 0; i < 20; ++i)
        {
            const uint32_t lhsBit = ninthInteger[i];
            const uint32_t rhsBit = eighthInteger[i];
            const uint32_t sum = lhsBit + rhsBit + carry;
            ASSERT_EQUAL(sum & 0x0000FFFF, seventhInteger[i]);
            carry = (sum & 0x00010000) ? 1 : 0;
        }
    }
}

void Mathematics::IntegerTesting::MinusTest()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(0, INT32_MAX / 2);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(66);
        vector<uint16_t> secondShortVector(66);

        // 最高位为零
        for (auto i = 0; i < 64; ++i)
        {
            firstShortVector.at(i) = secondRandomDistribution(generator);
            secondShortVector.at(i) = secondRandomDistribution(generator);
        }

        const Integer<33> firstInteger(firstShortVector);
        const Integer<33> secondInteger(secondShortVector);

        Integer<33> thirdInteger = firstInteger - secondInteger;
        Integer<33> fourthInteger = secondInteger - firstInteger;

        ASSERT_EQUAL(thirdInteger, -fourthInteger);

        thirdInteger += secondInteger;

        ASSERT_EQUAL(thirdInteger, firstInteger);

        fourthInteger += firstInteger;

        ASSERT_EQUAL(fourthInteger, secondInteger);

        fourthInteger = -fourthInteger;
        thirdInteger -= fourthInteger;

        ASSERT_EQUAL(thirdInteger, firstInteger + secondInteger);

        auto firstValue = firstRandomDistribution(generator);
        auto secondValue = firstRandomDistribution(generator);

        Integer<4> fifthInteger(firstValue);
        const Integer<4> sixthInteger(secondValue);

        fifthInteger -= sixthInteger;

        ASSERT_EQUAL(fifthInteger, Integer<4>(firstValue - secondValue));

        // 精确测试
        vector<uint16_t> thirdShortVector(20);
        vector<uint16_t> fourthShortVector(20);

        // 最高位为零
        for (int i = 0; i < 18; ++i)
        {
            thirdShortVector.at(i) = secondRandomDistribution(generator);
            fourthShortVector.at(i) = secondRandomDistribution(generator);
        }

        Integer<10> seventhInteger(thirdShortVector);
        Integer<10> eighthInteger(fourthShortVector);

        if (loop % 2 == 1)
        {
            eighthInteger = -eighthInteger;
        }

        Integer<10> ninthInteger(seventhInteger);
        seventhInteger -= eighthInteger;
        Integer<10> eleventhInteger(-eighthInteger);

        uint32_t carry = 0;
        for (uint32_t i = 0; i < 20; ++i)
        {
            const uint32_t lhsBit = ninthInteger[i];
            const uint32_t rhsBit = eleventhInteger[i];
            const uint32_t sum = lhsBit + rhsBit + carry;
            ASSERT_EQUAL(sum & 0x0000FFFF, seventhInteger[i]);
            carry = (sum & 0x00010000) ? 1 : 0;
        }
    }
}

void Mathematics::IntegerTesting::MultiplyTest()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(0, INT16_MAX);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(40);
        vector<uint16_t> secondShortVector(40);

        // 避免计算溢出
        for (uint32_t i = 0; i < 19; ++i)
        {
            firstShortVector.at(i) = secondRandomDistribution(generator);
            secondShortVector.at(i) = secondRandomDistribution(generator);
        }

        const Integer<20> firstInteger(firstShortVector);
        const Integer<20> secondInteger(secondShortVector);

        Integer<20> thirdInteger = firstInteger * secondInteger;
        Integer<20> fourthInteger = secondInteger * firstInteger;

        ASSERT_EQUAL(thirdInteger, fourthInteger);

        ASSERT_EQUAL(thirdInteger % firstInteger, Integer<20>(0));

        thirdInteger /= secondInteger;

        ASSERT_EQUAL(thirdInteger, firstInteger);

        ASSERT_EQUAL(fourthInteger % secondInteger, Integer<20>(0));

        fourthInteger /= firstInteger;

        ASSERT_EQUAL(fourthInteger, secondInteger);

        fourthInteger = -fourthInteger;

        thirdInteger *= fourthInteger;

        ASSERT_EQUAL(thirdInteger, -firstInteger * secondInteger);

        const uint32_t firstValue = firstRandomDistribution(generator);
        const uint32_t secondValue = firstRandomDistribution(generator);

        Integer<4> fifthInteger(firstValue);
        const Integer<4> sixthInteger(secondValue);

        fifthInteger *= sixthInteger;

        ASSERT_EQUAL(fifthInteger, Integer<4>(firstValue * secondValue));
    }
}

void Mathematics::IntegerTesting::DivideTest()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(0, INT16_MAX);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(40);
        vector<uint16_t> secondShortVector(40);

        for (auto i = 0; i < 39; ++i)
        {
            firstShortVector.at(i) = secondRandomDistribution(generator);
            secondShortVector.at(i) = secondRandomDistribution(generator);
        }

        const Integer<20> firstInteger(firstShortVector);
        const Integer<20> secondInteger(secondShortVector);

        const Integer<20> thirdInteger = firstInteger / secondInteger;
        const Integer<20> fourthInteger = secondInteger / firstInteger;
        Integer<20> fifthInteger = firstInteger % secondInteger;
        Integer<20> sixthInteger = secondInteger % firstInteger;

        ASSERT_EQUAL(thirdInteger * secondInteger + fifthInteger, firstInteger);
        ASSERT_EQUAL(fourthInteger * firstInteger + sixthInteger, secondInteger);

        fifthInteger = -firstInteger;

        fifthInteger /= secondInteger;

        sixthInteger = -firstInteger;

        sixthInteger %= secondInteger;

        ASSERT_EQUAL(fifthInteger * secondInteger + sixthInteger, -firstInteger);

        const uint32_t firstValue = firstRandomDistribution(generator);
        const uint32_t secondValue = firstRandomDistribution(generator);

        const Integer<4> seventhInteger(firstValue);
        const Integer<4> eighthInteger(secondValue);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

        Integer<4> ninthInteger(seventhInteger);
        Integer<4> tenthInteger(seventhInteger);

        ninthInteger /= eighthInteger;
        tenthInteger %= eighthInteger;

#include STSTEM_WARNING_POP

        ASSERT_EQUAL(ninthInteger, Integer<4>(firstValue / secondValue));
        ASSERT_EQUAL(tenthInteger, Integer<4>(firstValue % secondValue));
    }
}

void Mathematics::IntegerTesting::LeftShiftTest()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(0, 16 * 20);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(40);

        for (auto i = 0; i < 39; ++i)
        {
            firstShortVector.at(i) = secondRandomDistribution(generator);
        }

        Integer<20> firstInteger(firstShortVector);

        if (loop % 2 == 0)
            firstInteger = -firstInteger;

        Integer<20> secondInteger(firstInteger);

        auto firstValue = firstRandomDistribution(generator);

        secondInteger <<= firstValue;

        Integer<40> thirdInteger(1);
        for (auto i = 0; i < firstValue; ++i)
        {
            thirdInteger *= Integer<40>(2);
        }

        Integer<40> fourthInteger;
        for (auto i = 0; i < 20; ++i)
        {
            fourthInteger[i] = firstInteger[i];
        }

        fourthInteger *= thirdInteger;

        for (auto i = 0; i < 20; ++i)
        {
            ASSERT_EQUAL(fourthInteger[i], secondInteger[i]);
        }
    }
}

void Mathematics::IntegerTesting::RightShiftTest()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(0, 16 * 20);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(40);

        for (auto i = 0; i < 38; ++i)
        {
            firstShortVector.at(i) = secondRandomDistribution(generator);
        }

        Integer<20> firstInteger(firstShortVector);

        if (loop % 2 == 0)
            firstInteger = -firstInteger;

        Integer<20> secondInteger(firstInteger);

        auto firstValue = firstRandomDistribution(generator);

        secondInteger >>= firstValue;

        Integer<20> thirdInteger(1);
        for (int i = 0; i < firstValue; ++i)
        {
            thirdInteger *= Integer<20>(2);
        }

        Integer<20> fourthInteger(firstInteger);

        fourthInteger /= thirdInteger;

        // -1右移后依然是-1，除以2则为0。
        // 两者的值相差1
        if (fourthInteger.GetSign() == NumericalValueSymbol::Negative)
        {
            fourthInteger -= Integer<20>(1);
        }

        ASSERT_EQUAL(fourthInteger, secondInteger);
    }
}

void Mathematics::IntegerTesting::SignTest()
{
    default_random_engine generator{};
    const uniform_int<uint16_t> firstRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(40);

        firstShortVector.at(39) = firstRandomDistribution(generator);

        Integer<20> firstInteger(firstShortVector);

        if (static_cast<uint16_t>(firstInteger[39]) & 0x8000)
        {
            ASSERT_ENUM_EQUAL(firstInteger.GetSign(), NumericalValueSymbol::Negative);
        }
        else
        {
            ASSERT_ENUM_EQUAL(firstInteger.GetSign(), NumericalValueSymbol::Positive);
        }
    }
}

// Compare测试
void Mathematics::IntegerTesting::CompareTest()
{
    default_random_engine generator{};
    const uniform_int<uint16_t> firstRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(40);
        vector<uint16_t> secondShortVector(40);

        for (auto i = 0; i < 40; ++i)
        {
            firstShortVector.at(i) = firstRandomDistribution(generator);
            secondShortVector.at(i) = firstRandomDistribution(generator);
        }

        Integer<20> firstInteger(firstShortVector);
        Integer<20> secondInteger(secondShortVector);

        ASSERT_TRUE(firstInteger == firstInteger);
        ASSERT_FALSE(firstInteger == secondInteger);
        ASSERT_FALSE(secondInteger != secondInteger);
        ASSERT_TRUE(firstInteger != secondInteger);

        const NumericalValueSymbol firstSymbol = firstInteger.GetSign();
        const NumericalValueSymbol secondSymbol = secondInteger.GetSign();

        if (firstSymbol == NumericalValueSymbol::Positive)
        {
            if (secondSymbol == NumericalValueSymbol::Positive)
            {
                if (firstInteger.GetLeadingBit() < secondInteger.GetLeadingBit())
                {
                    ASSERT_TRUE(firstInteger < secondInteger);
                    ASSERT_TRUE(firstInteger <= secondInteger);
                    ASSERT_FALSE(firstInteger > secondInteger);
                    ASSERT_FALSE(firstInteger >= secondInteger);
                }
                else if (secondInteger.GetLeadingBit() < firstInteger.GetLeadingBit())
                {
                    ASSERT_FALSE(firstInteger < secondInteger);
                    ASSERT_FALSE(firstInteger <= secondInteger);
                    ASSERT_TRUE(firstInteger > secondInteger);
                    ASSERT_TRUE(firstInteger >= secondInteger);
                }
                else
                {
                    const auto leadingBlock = firstInteger.GetLeadingBlock();

                    for (int i = leadingBlock; 0 <= i; --i)
                    {
                        if (firstInteger[i] < secondInteger[i])
                        {
                            ASSERT_TRUE(firstInteger < secondInteger);
                            ASSERT_TRUE(firstInteger <= secondInteger);
                            ASSERT_FALSE(firstInteger > secondInteger);
                            ASSERT_FALSE(firstInteger >= secondInteger);
                            break;
                        }
                        else if (secondInteger[i] < firstInteger[i])
                        {
                            ASSERT_FALSE(firstInteger < secondInteger);
                            ASSERT_FALSE(firstInteger <= secondInteger);
                            ASSERT_TRUE(firstInteger > secondInteger);
                            ASSERT_TRUE(firstInteger >= secondInteger);
                            break;
                        }
                    }
                }
            }
            else
            {
                ASSERT_FALSE(firstInteger < secondInteger);
                ASSERT_FALSE(firstInteger <= secondInteger);
                ASSERT_TRUE(firstInteger > secondInteger);
                ASSERT_TRUE(firstInteger >= secondInteger);
            }
        }
        else
        {
            if (secondSymbol == NumericalValueSymbol::Positive)
            {
                ASSERT_TRUE(firstInteger < secondInteger);
                ASSERT_TRUE(firstInteger <= secondInteger);
                ASSERT_FALSE(firstInteger > secondInteger);
                ASSERT_FALSE(firstInteger >= secondInteger);
            }
            else
            {
                if (firstInteger.GetLeadingBit() < secondInteger.GetLeadingBit())
                {
                    ASSERT_TRUE(firstInteger < secondInteger);
                    ASSERT_TRUE(firstInteger <= secondInteger);
                    ASSERT_FALSE(firstInteger > secondInteger);
                    ASSERT_FALSE(firstInteger >= secondInteger);
                }
                else if (secondInteger.GetLeadingBit() < firstInteger.GetLeadingBit())
                {
                    ASSERT_FALSE(firstInteger < secondInteger);
                    ASSERT_FALSE(firstInteger <= secondInteger);
                    ASSERT_TRUE(firstInteger > secondInteger);
                    ASSERT_TRUE(firstInteger >= secondInteger);
                }
                else
                {
                    const auto leadingBlock = firstInteger.GetLeadingBlock();

                    for (int i = leadingBlock; 0 <= i; --i)
                    {
                        if (firstInteger[i] < secondInteger[i])
                        {
                            ASSERT_TRUE(firstInteger < secondInteger);
                            ASSERT_TRUE(firstInteger <= secondInteger);
                            ASSERT_FALSE(firstInteger > secondInteger);
                            ASSERT_FALSE(firstInteger >= secondInteger);
                            break;
                        }
                        else if (secondInteger[i] < firstInteger[i])
                        {
                            ASSERT_FALSE(firstInteger < secondInteger);
                            ASSERT_FALSE(firstInteger <= secondInteger);
                            ASSERT_TRUE(firstInteger > secondInteger);
                            ASSERT_TRUE(firstInteger >= secondInteger);
                            break;
                        }
                    }
                }
            }
        }
    }
}

// Utilities测试
void Mathematics::IntegerTesting::UtilitiesTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BlockTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConversionTest);
}

void Mathematics::IntegerTesting::BlockTest()
{
    default_random_engine generator{};
    const uniform_int<uint16_t> firstRandomDistribution(0, 39);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(40);

        auto firstValue = firstRandomDistribution(generator);
        auto secondValue = firstRandomDistribution(generator);

        if (firstValue < secondValue)
        {
            auto thirdValue = firstValue;
            firstValue = secondValue;
            secondValue = thirdValue;
        }

        if (firstValue == secondValue)
        {
            firstValue = secondValue + 1;
        }

        for (auto i = secondValue; i < firstValue; ++i)
        {
            firstShortVector.at(i) = secondRandomDistribution(generator);
        }

        Integer<20> firstInteger(firstShortVector);

        ASSERT_EQUAL(firstValue - 1, firstInteger.GetLeadingBlock());
        ASSERT_EQUAL(secondValue, firstInteger.GetTrailingBlock());

        for (auto i = secondValue; i < firstValue; ++i)
        {
            firstInteger.SetBit(i * 16, false);
            firstInteger.SetBit(i * 16 + 15, false);

            if (firstInteger[i] != 0)
            {
                ASSERT_TRUE(firstInteger.GetLeadingBit(i) <= 14);
                ASSERT_TRUE(1 <= firstInteger.GetTrailingBit(i));
            }
        }

        ASSERT_TRUE(firstInteger.GetLeadingBit() <= 14 + (firstValue - 1) * 16);
        ASSERT_TRUE(1 + secondValue * 16 <= firstInteger.GetTrailingBit());
    }
}

void Mathematics::IntegerTesting::BitTest()
{
    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Integer<20> firstInteger;

        for (auto i = 0; i < 20 * 16; ++i)
        {
            ASSERT_FALSE(firstInteger.GetBit(i));

            firstInteger.SetBit(i, true);

            ASSERT_TRUE(firstInteger.GetBit(i));
        }
    }
}

void Mathematics::IntegerTesting::ConversionTest()
{
    default_random_engine generator{};
    const uniform_real<float> firstRandomDistribution(-1.0e38f, 1.0e38f);
    const uniform_real<double> secondRandomDistribution(static_cast<double>(std::numeric_limits<uint64_t>::min()), static_cast<double>(std::numeric_limits<uint64_t>::max()));

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = firstRandomDistribution(generator);

        const Integer<20> firstIntegerData(firstValue);

        auto secondValue = firstIntegerData.GetValue<float>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        const auto thirdValue = *(reinterpret_cast<const uint32_t*>(&firstValue));
        const auto fourthValue = *(reinterpret_cast<const uint32_t*>(&secondValue));

        ASSERT_EQUAL(thirdValue, fourthValue);

        auto fifthValue = secondRandomDistribution(generator);

        const Integer<40> secondIntegerData(fifthValue);

        auto sixthValue = secondIntegerData.GetValue<double>();

        const auto seventhValue = *(reinterpret_cast<const uint64_t*>(&fifthValue));
        const auto eighthValue = *(reinterpret_cast<const uint64_t*>(&sixthValue));

#include STSTEM_WARNING_POP

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}
