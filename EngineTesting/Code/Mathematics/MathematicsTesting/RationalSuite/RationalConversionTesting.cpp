///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:43)

#include "RationalConversionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataAmendDetail.h"
#include "Mathematics/Rational/RationalConversionDetail.h"

#include <gsl/util>
#include <limits>
#include <random>

Mathematics::RationalConversionTesting::RationalConversionTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, RationalConversionTesting)

void Mathematics::RationalConversionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::RationalConversionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatingPointTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedIntegerTest);
    ASSERT_THROW_EXCEPTION_0(FloatOverflowTest);
    ASSERT_THROW_EXCEPTION_0(DoubleOverflowTest);
    ASSERT_THROW_EXCEPTION_0(IntegerOverflowTest);
    ASSERT_THROW_EXCEPTION_0(UnsignedIntegerOverflowTest);
}

void Mathematics::RationalConversionTesting::FloatingPointTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<float> randomDistribution0(-1.0e38f, 1.0e38f);
    const std::uniform_real<double> randomDistribution1(static_cast<double>(std::numeric_limits<uint64_t>::min()), static_cast<double>(std::numeric_limits<uint64_t>::max()));

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);

        const SignRational<20> firstRational(firstValue);

        const RationalConversion<20, float> firstConversion(firstRational);

        auto secondValue = firstConversion.GetValue();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        const auto thirdValue = *(reinterpret_cast<const uint32_t*>(&firstValue));
        const auto fourthValue = *(reinterpret_cast<const uint32_t*>(&secondValue));

        ASSERT_EQUAL(thirdValue, fourthValue);

        auto fifthValue = randomDistribution1(generator);

        const SignRational<40> secondRational(fifthValue);

        const RationalConversion<40, double> secondConversion(secondRational);

        auto sixthValue = secondConversion.GetValue();

        const auto seventhValue = *(reinterpret_cast<const uint64_t*>(&fifthValue));
        const auto eighthValue = *(reinterpret_cast<const uint64_t*>(&sixthValue));

#include SYSTEM_WARNING_POP

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}

void Mathematics::RationalConversionTesting::IntegerTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_int<int64_t> randomDistribution0(-std::numeric_limits<int64_t>::max(), std::numeric_limits<int64_t>::max());
    const std::uniform_int<int> randomDistribution1(-INT_MAX, INT_MAX);
    const std::uniform_int<int8_t> thirdRandomDistribution(-std::numeric_limits<int8_t>::max(), std::numeric_limits<int8_t>::max());

    const std::uniform_int<int16_t> fourthRandomDistribution(-std::numeric_limits<int16_t>::max(), std::numeric_limits<int16_t>::max());
    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);

        const SignRational<20> firstIntegerData(firstValue);

        const RationalConversion<20, int64_t> firstConversion(firstIntegerData);

        const int64_t secondValue = firstConversion.GetValue();

        ASSERT_EQUAL(firstValue, secondValue);

        const int8_t thirdValue = thirdRandomDistribution(generator);

        const SignRational<20> thirdIntegerData(thirdValue);

        const RationalConversion<20, int8_t> thirdConversion(thirdIntegerData);

        const int8_t fourthValue = thirdConversion.GetValue();

        ASSERT_EQUAL(thirdValue, fourthValue);

        const int fifthValue = randomDistribution1(generator);

        const SignRational<40> secondIntegerData(fifthValue);

        const RationalConversion<40, int> secondConversion(secondIntegerData);

        const int sixthValue = secondConversion.GetValue();

        ASSERT_EQUAL(fifthValue, sixthValue);

        const int16_t seventhValue = fourthRandomDistribution(generator);

        const SignRational<40> fourthIntegerData(seventhValue);

        const RationalConversion<40, int16_t> seventhConversion(fourthIntegerData);

        const int16_t eighthValue = seventhConversion.GetValue();

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}

void Mathematics::RationalConversionTesting::UnsignedIntegerTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_int<uint64_t> randomDistribution0(0, std::numeric_limits<int64_t>::max());
    const std::uniform_int<uint32_t> randomDistribution1(0, INT_MAX);
    const std::uniform_int<uint8_t> thirdRandomDistribution(0, std::numeric_limits<int8_t>::max());
    const std::uniform_int<uint16_t> fourthRandomDistribution(0, std::numeric_limits<int16_t>::max());

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const uint64_t firstValue = randomDistribution0(generator);

        const SignRational<20> firstIntegerData(firstValue);

        const RationalConversion<20, uint64_t> firstConversion(firstIntegerData);

        const uint64_t secondValue = firstConversion.GetValue();

        ASSERT_EQUAL(firstValue, secondValue);

        const uint8_t thirdValue = thirdRandomDistribution(generator);

        const SignRational<20> thirdIntegerData(thirdValue);

        const RationalConversion<20, uint8_t> thirdConversion(thirdIntegerData);

        const uint8_t fourthValue = thirdConversion.GetValue();

        ASSERT_EQUAL(thirdValue, fourthValue);

        const uint32_t fifthValue = randomDistribution1(generator);

        const SignRational<40> secondIntegerData(fifthValue);

        const RationalConversion<40, uint32_t> secondConversion(secondIntegerData);

        const uint32_t sixthValue = secondConversion.GetValue();

        ASSERT_EQUAL(fifthValue, sixthValue);

        const uint16_t seventhValue = fourthRandomDistribution(generator);

        const SignRational<40> fourthIntegerData(seventhValue);

        const RationalConversion<40, uint16_t> seventhConversion(fourthIntegerData);

        const uint16_t eighthValue = seventhConversion.GetValue();

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}

void Mathematics::RationalConversionTesting::FloatOverflowTest()
{
    Integer<50> firstInteger;
    const Integer<50> secondInteger(1);

    firstInteger[48] = gsl::narrow_cast<uint16_t>(0xFFFF);

    const SignRational<50> firstRational(firstInteger, secondInteger);

    const RationalConversion<50, float> firstConversion(firstRational);

    MAYBE_UNUSED auto value = firstConversion.GetValue();
}

void Mathematics::RationalConversionTesting::DoubleOverflowTest()
{
    Integer<150> firstInteger;
    const Integer<150> secondInteger(1);

    firstInteger[148] = gsl::narrow_cast<uint16_t>(0xFFFF);

    const SignRational<150> firstRational(firstInteger, secondInteger);

    const RationalConversion<150, double> firstConversion(firstRational);

    MAYBE_UNUSED auto value = firstConversion.GetValue();
}

void Mathematics::RationalConversionTesting::IntegerOverflowTest()
{
    constexpr int64_t firstValue = (0xFCCCCCFFFULL);

    const Integer<150> firstInteger(firstValue);
    const Integer<150> secondInteger(1);

    const SignRational<150> firstRational(firstInteger, secondInteger);

    const RationalConversion<150, int16_t> firstConversion(firstRational);

    MAYBE_UNUSED auto value = firstConversion.GetValue();
}

void Mathematics::RationalConversionTesting::UnsignedIntegerOverflowTest()
{
    constexpr uint64_t firstValue = (0xFCCCCCFFFULL);

    const Integer<150> firstInteger(firstValue);
    const Integer<150> secondInteger(1);

    const SignRational<150> firstRational(firstInteger, secondInteger);

    const RationalConversion<150, uint16_t> firstConversion(firstRational);

    MAYBE_UNUSED auto value = firstConversion.GetValue();
}
