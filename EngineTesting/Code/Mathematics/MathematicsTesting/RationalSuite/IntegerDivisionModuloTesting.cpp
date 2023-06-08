///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 15:59)

#include "IntegerDivisionModuloTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/IntegerDivisionModuloDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::vector;

namespace Mathematics
{
    template class IntegerDivisionModulo<5>;
    template class IntegerDivisionModulo<7>;
}

Mathematics::IntegerDivisionModuloTesting::IntegerDivisionModuloTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, IntegerDivisionModuloTesting)

void Mathematics::IntegerDivisionModuloTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::IntegerDivisionModuloTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DenominatorIsLargeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SingleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultipleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Int32Test);
}

void Mathematics::IntegerDivisionModuloTesting::DenominatorIsLargeTest()
{
    default_random_engine generator{};
    const uniform_int<uint16_t> firstRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(66);
        vector<uint16_t> secondShortVector(66);

        // 最高位为零
        for (auto i = 0; i < 60; ++i)
        {
            firstShortVector.at(i) = firstRandomDistribution(generator);
            secondShortVector.at(i) = firstRandomDistribution(generator);
        }

        secondShortVector.at(61) = firstRandomDistribution(generator);

        const IntegerData<33> firstInteger(firstShortVector);
        const IntegerData<33> secondInteger(secondShortVector);

        const IntegerDivisionModulo<33> firstIntegerDivisionModulo(firstInteger, firstInteger);

        ASSERT_EQUAL(firstIntegerDivisionModulo.GetQuotient(), IntegerData<33>(1));
        ASSERT_EQUAL(firstIntegerDivisionModulo.GetRemainder(), IntegerData<33>(0));

        const IntegerDivisionModulo<33> secondIntegerDivisionModulo(firstInteger, secondInteger);

        ASSERT_EQUAL(secondIntegerDivisionModulo.GetQuotient(), IntegerData<33>(0));
        ASSERT_EQUAL(secondIntegerDivisionModulo.GetRemainder(), firstInteger);

        IntegerData<33> thirdInteger = firstInteger;
        IntegerDataAmend<33> thirdIntegerAmend(thirdInteger);
        thirdIntegerAmend.Negative();

        const IntegerDivisionModulo<33> thirdIntegerDivisionModulo(thirdInteger, thirdInteger);

        ASSERT_EQUAL(thirdIntegerDivisionModulo.GetQuotient(), IntegerData<33>(1));
        ASSERT_EQUAL(thirdIntegerDivisionModulo.GetRemainder(), IntegerData<33>(0));

        const IntegerDivisionModulo<33> fourthIntegerDivisionModulo(thirdInteger, secondInteger);

        ASSERT_EQUAL(fourthIntegerDivisionModulo.GetQuotient(), IntegerData<33>(0));
        ASSERT_EQUAL(fourthIntegerDivisionModulo.GetRemainder(), thirdInteger);

        thirdInteger = secondInteger;
        thirdIntegerAmend.Negative();

        const IntegerDivisionModulo<33> fifthIntegerDivisionModulo(firstInteger, thirdInteger);

        ASSERT_EQUAL(fifthIntegerDivisionModulo.GetQuotient(), IntegerData<33>(0));
        ASSERT_EQUAL(fifthIntegerDivisionModulo.GetRemainder(), firstInteger);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

        IntegerData<33> fourthInteger = firstInteger;

#include STSTEM_WARNING_POP

        IntegerDataAmend<33> fourthIntegerAmend(fourthInteger);
        fourthIntegerAmend.Negative();

        const IntegerDivisionModulo<33> sixthIntegerDivisionModulo(fourthInteger, thirdInteger);

        ASSERT_EQUAL(sixthIntegerDivisionModulo.GetQuotient(), IntegerData<33>(0));
        ASSERT_EQUAL(sixthIntegerDivisionModulo.GetRemainder(), fourthInteger);
    }
}

void Mathematics::IntegerDivisionModuloTesting::SingleTest()
{
    default_random_engine generator{};
    const uniform_int<uint16_t> firstRandomDistribution(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(66);
        vector<uint16_t> secondShortVector(66);

        // 最高位为零
        for (auto i = 0; i < 65; ++i)
        {
            firstShortVector.at(i) = firstRandomDistribution(generator);
        }

        secondShortVector.at(0) = firstRandomDistribution(generator);

        const IntegerData<33> firstInteger(firstShortVector);
        const IntegerData<33> secondInteger(secondShortVector);

        const IntegerDivisionModulo<33> firstIntegerDivisionModulo(firstInteger, secondInteger);

        IntegerMultiplication<33> multiple(secondInteger, firstIntegerDivisionModulo.GetQuotient());

        ASSERT_EQUAL(multiple.GetMultiplication() + firstIntegerDivisionModulo.GetRemainder(), firstInteger);

        IntegerData<33> thirdInteger = firstInteger;
        IntegerDataAmend<33> thirdIntegerAmend(thirdInteger);
        thirdIntegerAmend.Negative();

        const IntegerDivisionModulo<33> secondIntegerDivisionModulo(thirdInteger, secondInteger);
        IntegerMultiplication<33> secondMultiple(secondInteger, secondIntegerDivisionModulo.GetQuotient());

        ASSERT_EQUAL(secondMultiple.GetMultiplication() + secondIntegerDivisionModulo.GetRemainder(), thirdInteger);

        thirdInteger = secondInteger;
        thirdIntegerAmend.Negative();

        const IntegerDivisionModulo<33> thirdIntegerDivisionModulo(firstInteger, thirdInteger);
        IntegerMultiplication<33> thirdMultiple(thirdInteger, thirdIntegerDivisionModulo.GetQuotient());

        ASSERT_EQUAL(thirdMultiple.GetMultiplication() + thirdIntegerDivisionModulo.GetRemainder(), firstInteger);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

        IntegerData<33> fourthInteger = firstInteger;

#include STSTEM_WARNING_POP

        IntegerDataAmend<33> fourthIntegerAmend(fourthInteger);
        fourthIntegerAmend.Negative();

        const IntegerDivisionModulo<33> fourthIntegerDivisionModulo(fourthInteger, thirdInteger);
        IntegerMultiplication<33> fourthMultiple(thirdInteger, fourthIntegerDivisionModulo.GetQuotient());

        ASSERT_EQUAL(fourthMultiple.GetMultiplication() + fourthIntegerDivisionModulo.GetRemainder(), fourthInteger);
    }
}

void Mathematics::IntegerDivisionModuloTesting::MultipleTest()
{
    default_random_engine generator{};
    const uniform_int<uint16_t> firstRandomDistribution(0, UINT16_MAX);
    const uniform_int<> secondRandomDistribution(33, 66);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(68);
        vector<uint16_t> secondShortVector(68);

        const uint32_t secondIndexMax = secondRandomDistribution(generator);

        // 最高位为零
        for (auto i = 0u; i < secondIndexMax; ++i)
        {
            firstShortVector.at(i) = firstRandomDistribution(generator);
            secondShortVector.at(i) = firstRandomDistribution(generator);
        }

        for (auto i = secondIndexMax; i < 67; ++i)
        {
            firstShortVector.at(i) = firstRandomDistribution(generator);
        }

        const IntegerData<34> firstInteger(firstShortVector);
        const IntegerData<34> secondInteger(secondShortVector);

        const IntegerDivisionModulo<34> firstIntegerDivisionModulo(firstInteger, secondInteger);
        IntegerMultiplication<34> firstMultiplication(secondInteger, firstIntegerDivisionModulo.GetQuotient());

        ASSERT_EQUAL(firstMultiplication.GetMultiplication() + firstIntegerDivisionModulo.GetRemainder(), firstInteger);

        IntegerData<34> thirdInteger = firstInteger;
        IntegerDataAmend<34> thirdIntegerAmend(thirdInteger);
        thirdIntegerAmend.Negative();

        const IntegerDivisionModulo<34> secondIntegerDivisionModulo(thirdInteger, secondInteger);
        IntegerMultiplication<34> secondMultiplication(secondInteger, secondIntegerDivisionModulo.GetQuotient());

        ASSERT_EQUAL(secondMultiplication.GetMultiplication() + secondIntegerDivisionModulo.GetRemainder(), thirdInteger);

        thirdInteger = secondInteger;
        thirdIntegerAmend.Negative();

        const IntegerDivisionModulo<34> thirdIntegerDivisionModulo(firstInteger, thirdInteger);
        IntegerMultiplication<34> thirdMultiplication(thirdInteger, thirdIntegerDivisionModulo.GetQuotient());

        ASSERT_EQUAL(thirdMultiplication.GetMultiplication() + thirdIntegerDivisionModulo.GetRemainder(), firstInteger);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

        IntegerData<34> fourthInteger = firstInteger;

#include STSTEM_WARNING_POP

        IntegerDataAmend<34> fourthIntegerDataAmend(fourthInteger);
        fourthIntegerDataAmend.Negative();

        const IntegerDivisionModulo<34> fourthIntegerDivisionModulo(fourthInteger, thirdInteger);
        IntegerMultiplication<34> fourthMultiplication(thirdInteger, fourthIntegerDivisionModulo.GetQuotient());

        ASSERT_EQUAL(fourthMultiplication.GetMultiplication() + fourthIntegerDivisionModulo.GetRemainder(), fourthInteger);
    }
}

void Mathematics::IntegerDivisionModuloTesting::Int32Test()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(INT32_MIN, UINT32_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const auto firstValue = firstRandomDistribution(generator);
        const auto secondValue = firstRandomDistribution(generator);

        const auto quotientValue = firstValue / secondValue;

        const auto remainderValue = firstValue % secondValue;

        const IntegerDivisionModulo<21> firstIntegerDivisionModulo = IntegerDivisionModulo<21>(IntegerData<21>(firstValue), IntegerData<21>(secondValue));

        ASSERT_EQUAL(IntegerData<21>(quotientValue), firstIntegerDivisionModulo.GetQuotient());
        ASSERT_EQUAL(IntegerData<21>(remainderValue), firstIntegerDivisionModulo.GetRemainder());
    }
}
