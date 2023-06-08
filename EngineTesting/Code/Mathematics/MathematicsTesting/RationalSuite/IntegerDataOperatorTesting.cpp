///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 15:01)

#include "IntegerDataOperatorTesting.h"

#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataAmendDetail.h"
#include "Mathematics/Rational/IntegerDataAnalysisDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"
#include "Mathematics/Rational/IntegerDataOperatorDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <boost/utility/binary.hpp>
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::vector;

namespace Mathematics
{
    template class IntegerData<21>;
    template class IntegerData<22>;
    template class IntegerData<29>;
    template class IntegerData<32>;

    template class IntegerDataAnalysis<21>;
    template class IntegerDataAnalysis<22>;
    template class IntegerDataAnalysis<29>;
    template class IntegerDataAnalysis<32>;

    template class IntegerDataAmend<21>;
    template class IntegerDataAmend<22>;
    template class IntegerDataAmend<29>;
    template class IntegerDataAmend<32>;

    template class IntegerDataOperator<21>;
    template class IntegerDataOperator<22>;
    template class IntegerDataOperator<29>;
    template class IntegerDataOperator<32>;
}

Mathematics::IntegerDataOperatorTesting::IntegerDataOperatorTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, IntegerDataOperatorTesting)

void Mathematics::IntegerDataOperatorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::IntegerDataOperatorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AdditionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SubtractionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiplicationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LeftShiftTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DivisionModuloTest);
}

void Mathematics::IntegerDataOperatorTesting::AdditionTest()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(0, INT32_MAX / 2);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(28);
        vector<uint16_t> secondShortVector(28);

        // 最高位为零
        for (auto i = 0; i < 27; ++i)
        {
            firstShortVector.at(i) = secondRandomDistribution(generator);
            secondShortVector.at(i) = secondRandomDistribution(generator);
        }

        const IntegerData<28> firstInteger(firstShortVector);
        const IntegerData<28> secondInteger(secondShortVector);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

        IntegerData<28> thirdInteger = firstInteger;
        IntegerDataOperator<28> thirdIntegerDataOperator{ thirdInteger };
        thirdIntegerDataOperator += secondInteger;

        IntegerData<28> fourthInteger = secondInteger;
        IntegerDataOperator<28> fourthsIntegerDataOperator(fourthInteger);
        fourthsIntegerDataOperator += firstInteger;

#include STSTEM_WARNING_POP

        ASSERT_EQUAL(thirdInteger, fourthInteger);

        thirdIntegerDataOperator -= secondInteger;

        ASSERT_EQUAL(thirdInteger, firstInteger);

        fourthsIntegerDataOperator -= firstInteger;

        ASSERT_EQUAL(fourthInteger, secondInteger);

        auto firstValue = firstRandomDistribution(generator);
        auto secondValue = firstRandomDistribution(generator);

        IntegerData<4> fifthInteger(firstValue);
        const IntegerData<4> sixthInteger(secondValue);
        IntegerDataOperator<4> fifthIntegerDataOperator(fifthInteger);

        fifthIntegerDataOperator += sixthInteger;

        ASSERT_EQUAL(fifthInteger, IntegerData<4>(firstValue + secondValue));

        // 精确测试
        vector<uint16_t> thirdShortVector(10);
        vector<uint16_t> fourthShortVector(10);

        // 最高位为零
        for (auto i = 0; i < 9; ++i)
        {
            thirdShortVector.at(i) = secondRandomDistribution(generator);
            fourthShortVector.at(i) = secondRandomDistribution(generator);
        }

        IntegerData<5> seventhInteger(thirdShortVector);
        IntegerData<5> eighthInteger(fourthShortVector);

        const IntegerDataAnalysis<5> integerDataAnalysis(eighthInteger);

        if (loop % 2 == 1)
        {
            eighthInteger = -integerDataAnalysis;
        }

        IntegerData<5> ninthInteger(seventhInteger);
        IntegerDataOperator<5> seventhIntegerDataOperator(seventhInteger);
        seventhIntegerDataOperator += eighthInteger;

        uint32_t carry = 0;
        for (int i = 0; i < 10; ++i)
        {
            const uint32_t lhsBit = ninthInteger[i];
            const uint32_t rhsBit = eighthInteger[i];
            const uint32_t sum = lhsBit + rhsBit + carry;
            ASSERT_EQUAL(sum & 0x0000FFFF, seventhInteger[i]);
            carry = (sum & 0x00010000) ? 1 : 0;
        }
    }
}

void Mathematics::IntegerDataOperatorTesting::SubtractionTest()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(0, INT32_MAX / 2);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(26);
        vector<uint16_t> secondShortVector(26);

        // 最高位为零
        for (auto i = 0; i < 25; ++i)
        {
            firstShortVector.at(i) = secondRandomDistribution(generator);
            secondShortVector.at(i) = secondRandomDistribution(generator);
        }

        const IntegerData<13> firstInteger(firstShortVector);
        const IntegerData<13> secondInteger(secondShortVector);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

        IntegerData<13> thirdInteger = firstInteger;
        IntegerDataOperator<13> thirdIntegerDataOperator(thirdInteger);
        thirdIntegerDataOperator -= secondInteger;

#include STSTEM_WARNING_POP

        IntegerData<13> fourthInteger = secondInteger;
        IntegerDataOperator<13> fourthIntegerDataOperator(fourthInteger);
        fourthIntegerDataOperator -= firstInteger;

        const IntegerDataAnalysis<13> fourthIntegerDataAnalysis(fourthInteger);

        ASSERT_EQUAL(thirdInteger, -fourthIntegerDataAnalysis);

        thirdIntegerDataOperator += secondInteger;

        ASSERT_EQUAL(thirdInteger, firstInteger);

        fourthIntegerDataOperator += firstInteger;

        ASSERT_EQUAL(fourthInteger, secondInteger);

        fourthInteger = -fourthIntegerDataAnalysis;
        thirdIntegerDataOperator -= fourthInteger;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

        IntegerData<13> testInteger(firstInteger);
        IntegerDataOperator<13> testIntegerDataOperator(testInteger);
        testIntegerDataOperator += secondInteger;

#include STSTEM_WARNING_POP

        ASSERT_EQUAL(thirdInteger, testInteger);

        auto firstValue = firstRandomDistribution(generator);
        auto secondValue = firstRandomDistribution(generator);

        IntegerData<4> fifthInteger(firstValue);
        const IntegerData<4> sixthInteger(secondValue);

        IntegerDataOperator<4> fifthIntegerDataOperator(fifthInteger);
        fifthIntegerDataOperator -= sixthInteger;

        ASSERT_EQUAL(fifthInteger, IntegerData<4>(firstValue - secondValue));

        // 精确测试
        vector<uint16_t> thirdShortVector(20);
        vector<uint16_t> fourthShortVector(20);

        // 最高位为零
        for (auto i = 0; i < 18; ++i)
        {
            thirdShortVector.at(i) = secondRandomDistribution(generator);
            fourthShortVector.at(i) = secondRandomDistribution(generator);
        }

        IntegerData<10> seventhInteger(thirdShortVector);
        IntegerData<10> eighthInteger(fourthShortVector);

        const IntegerDataAnalysis<10> integerDataAnalysis(eighthInteger);

        if (loop % 2 == 1)
        {
            eighthInteger = -integerDataAnalysis;
        }

        IntegerData<10> ninthInteger(seventhInteger);
        IntegerDataOperator<10> seventhIntegerDataOperator(seventhInteger);
        seventhIntegerDataOperator -= eighthInteger;

        IntegerData<10> eleventhInteger(-integerDataAnalysis);

        uint32_t carry = 0;
        for (auto i = 0; i < 20; ++i)
        {
            const uint32_t lhsBit = ninthInteger[i];
            const uint32_t rhsBit = eleventhInteger[i];
            const uint32_t sum = lhsBit + rhsBit + carry;
            ASSERT_EQUAL(sum & 0x0000FFFF, seventhInteger[i]);
            carry = (sum & 0x00010000) ? 1 : 0;
        }
    }
}

void Mathematics::IntegerDataOperatorTesting::MultiplicationTest()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(0, INT32_MAX / 2);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(40);
        vector<uint16_t> secondShortVector(40);

        // 避免计算溢出
        for (auto i = 0; i < 19; ++i)
        {
            firstShortVector.at(i) = secondRandomDistribution(generator);
            secondShortVector.at(i) = secondRandomDistribution(generator);
        }

        const IntegerData<20> firstInteger(firstShortVector);
        const IntegerData<20> secondInteger(secondShortVector);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

        IntegerData<20> thirdInteger = firstInteger;
        IntegerDataOperator<20> thirdIntegerDataOperator(thirdInteger);
        thirdIntegerDataOperator *= secondInteger;

        IntegerData<20> fourthInteger = secondInteger;
        IntegerDataOperator<20> fourthIntegerDataOperator(fourthInteger);
        fourthIntegerDataOperator *= firstInteger;

#include STSTEM_WARNING_POP

        ASSERT_EQUAL(thirdInteger, fourthInteger);

        const uint64_t firstValue = firstRandomDistribution(generator);
        const uint64_t secondValue = firstRandomDistribution(generator);

        IntegerData<4> fifthInteger(firstValue);
        const IntegerData<4> sixthInteger(secondValue);

        IntegerDataOperator<4> fifthIntegerDataOperator(fifthInteger);
        fifthIntegerDataOperator *= sixthInteger;

        ASSERT_EQUAL(fifthInteger, IntegerData<4>(firstValue * secondValue));
    }
}

void Mathematics::IntegerDataOperatorTesting::LeftShiftTest()
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

        IntegerData<20> firstInteger(firstShortVector);

        if (loop % 2 == 0)
        {
            IntegerDataAmend<20> firstIntegerDataAmend(firstInteger);
            firstIntegerDataAmend.Negative();
        }

        IntegerData<20> secondInteger(firstInteger);

        auto firstValue = firstRandomDistribution(generator);
        IntegerDataOperator<20> secondIntegerDataOperator(secondInteger);

        secondIntegerDataOperator <<= firstValue;

        for (auto i = 0; i < firstValue; ++i)
        {
            ASSERT_FALSE(secondInteger.GetBit(i));
        }

        for (auto i = firstValue; i < 20 * 2 * 16; ++i)
        {
            ASSERT_EQUAL(secondInteger.GetBit(i), firstInteger.GetBit(i - firstValue));
        }
    }
}

void Mathematics::IntegerDataOperatorTesting::RightShiftTest()
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

        IntegerData<20> firstInteger(firstShortVector);

        if (loop % 2 == 0)
        {
            IntegerDataAmend<20> firstIntegerDataAmend(firstInteger);
            firstIntegerDataAmend.Negative();
        }

        IntegerData<20> secondInteger(firstInteger);

        auto firstValue = firstRandomDistribution(generator);
        IntegerDataOperator<20> secondIntegerDataOperator(secondInteger);

        secondIntegerDataOperator >>= firstValue;

        for (auto i = 0; i < firstValue; ++i)
        {
            ASSERT_EQUAL(secondInteger.GetBit(i + firstValue), firstInteger.GetBit(i));
        }

        for (auto i = firstValue; i < 20 * 2 * 16; ++i)
        {
            ASSERT_FALSE(secondInteger.GetBit(i));
        }
    }
}

void Mathematics::IntegerDataOperatorTesting::DivisionModuloTest()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(0, INT16_MAX);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(40);
        vector<uint16_t> secondShortVector(40);

        for (auto i = 0; i < 19; ++i)
        {
            firstShortVector.at(i) = secondRandomDistribution(generator);
            secondShortVector.at(i) = secondRandomDistribution(generator);
        }

        for (auto i = 19; i < 39; ++i)
        {
            firstShortVector.at(i) = secondRandomDistribution(generator);
        }

        const IntegerData<20> firstInteger(firstShortVector);
        const IntegerData<20> secondInteger(secondShortVector);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

        IntegerData<20> thirdInteger = firstInteger;
        IntegerDataOperator<20> thirdIntegerDataOperator(thirdInteger);
        thirdIntegerDataOperator /= secondInteger;

        IntegerData<20> fourthInteger = firstInteger;
        IntegerDataOperator<20> fourthIntegerDataOperator(fourthInteger);
        fourthIntegerDataOperator %= secondInteger;

#include STSTEM_WARNING_POP

        IntegerMultiplication<20> multiplication(thirdInteger, secondInteger);

        const IntegerData<20> fifthInteger = multiplication.GetMultiplication() + fourthInteger;

        ASSERT_EQUAL(fifthInteger, firstInteger);

        auto firstValue = firstRandomDistribution(generator);
        auto secondValue = firstRandomDistribution(generator);

        IntegerData<4> sixthInteger(firstValue);
        const IntegerData<4> seventhInteger(secondValue);

        IntegerDataOperator<4> fifthIntegerDataOperator(sixthInteger);
        fifthIntegerDataOperator /= seventhInteger;

        ASSERT_EQUAL(sixthInteger, IntegerData<4>(firstValue / secondValue));

        IntegerData<4> eighthInteger(firstValue);

        IntegerDataOperator<4> sixthIntegerDataOperator(eighthInteger);
        sixthIntegerDataOperator %= seventhInteger;

        ASSERT_EQUAL(eighthInteger, IntegerData<4>(firstValue % secondValue));
    }
}
