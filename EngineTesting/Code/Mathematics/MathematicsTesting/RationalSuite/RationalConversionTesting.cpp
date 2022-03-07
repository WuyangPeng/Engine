// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/26 16:49)

#include "RationalConversionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataAmendDetail.h"
#include "Mathematics/Rational/RationalConversionDetail.h"

#include <limits>
#include <random>

using std::default_random_engine;
using std::numeric_limits;
using std::uniform_int;
using std::uniform_real;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26490)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, RationalConversionTesting)

void Mathematics::RationalConversionTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatingPointTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedIntegerTest);
    ASSERT_THROW_EXCEPTION_0(FloatOverflowTest);
    ASSERT_THROW_EXCEPTION_0(DoubleOverflowTest);
    ASSERT_THROW_EXCEPTION_0(IntegerOverflowTest);
    ASSERT_THROW_EXCEPTION_0(UnsignedIntegerOverflowTest);
}

void Mathematics::RationalConversionTesting ::FloatingPointTest()
{
    default_random_engine generator{};
    uniform_real<float> firstRandomDistribution(-1.0e38f, 1.0e38f);
    uniform_real<double> secondRandomDistribution(static_cast<double>(std::numeric_limits<uint64_t>::min()), static_cast<double>(std::numeric_limits<uint64_t>::max()));

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        float firstValue = firstRandomDistribution(generator);

        SignRational<20> firstRational(firstValue);

        RationalConversion<20, float> firstConversion(firstRational);

        float secondValue = firstConversion.GetValue();

        uint32_t thirdValue = *(reinterpret_cast<const uint32_t*>(&firstValue));
        uint32_t fourthValue = *(reinterpret_cast<const uint32_t*>(&secondValue));

        ASSERT_EQUAL(thirdValue, fourthValue);

        double fifthValue = secondRandomDistribution(generator);

        SignRational<40> secondRational(fifthValue);

        RationalConversion<40, double> secondConversion(secondRational);

        double sixthValue = secondConversion.GetValue();

        uint64_t seventhValue = *(reinterpret_cast<const uint64_t*>(&fifthValue));
        uint64_t eighthValue = *(reinterpret_cast<const uint64_t*>(&sixthValue));

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}

void Mathematics::RationalConversionTesting ::IntegerTest()
{
    default_random_engine generator{};
    uniform_int<int64_t> firstRandomDistribution(-numeric_limits<int64_t>::max(), numeric_limits<int64_t>::max());
    uniform_int<int> secondRandomDistribution(-INT_MAX, INT_MAX);
    uniform_int<int8_t> thirdRandomDistribution(-numeric_limits<int8_t>::max(), numeric_limits<int8_t>::max());

    uniform_int<int16_t> fourthRandomDistribution(-numeric_limits<int16_t>::max(), numeric_limits<int16_t>::max());
    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        int64_t firstValue = firstRandomDistribution(generator);

        SignRational<20> firstIntegerData(firstValue);

        RationalConversion<20, int64_t> firstConversion(firstIntegerData);

        int64_t secondValue = firstConversion.GetValue();

        ASSERT_EQUAL(firstValue, secondValue);

        int8_t thirdValue = thirdRandomDistribution(generator);

        SignRational<20> thirdIntegerData(thirdValue);

        RationalConversion<20, int8_t> thirdConversion(thirdIntegerData);

        int8_t fourthValue = thirdConversion.GetValue();

        ASSERT_EQUAL(thirdValue, fourthValue);

        int fifthValue = secondRandomDistribution(generator);

        SignRational<40> secondIntegerData(fifthValue);

        RationalConversion<40, int> secondConversion(secondIntegerData);

        int sixthValue = secondConversion.GetValue();

        ASSERT_EQUAL(fifthValue, sixthValue);

        int16_t seventhValue = fourthRandomDistribution(generator);

        SignRational<40> fourthIntegerData(seventhValue);

        RationalConversion<40, int16_t> seventhConversion(fourthIntegerData);

        int16_t eighthValue = seventhConversion.GetValue();

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}

void Mathematics::RationalConversionTesting ::UnsignedIntegerTest()
{
    default_random_engine generator{};
    uniform_int<uint64_t> firstRandomDistribution(0, numeric_limits<int64_t>::max());
    uniform_int<uint32_t> secondRandomDistribution(0, INT_MAX);
    uniform_int<uint8_t> thirdRandomDistribution(0, numeric_limits<int8_t>::max());
    uniform_int<uint16_t> fourthRandomDistribution(0, numeric_limits<int16_t>::max());

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        uint64_t firstValue = firstRandomDistribution(generator);

        SignRational<20> firstIntegerData(firstValue);

        RationalConversion<20, uint64_t> firstConversion(firstIntegerData);

        uint64_t secondValue = firstConversion.GetValue();

        ASSERT_EQUAL(firstValue, secondValue);

        uint8_t thirdValue = thirdRandomDistribution(generator);

        SignRational<20> thirdIntegerData(thirdValue);

        RationalConversion<20, uint8_t> thirdConversion(thirdIntegerData);

        uint8_t fourthValue = thirdConversion.GetValue();

        ASSERT_EQUAL(thirdValue, fourthValue);

        uint32_t fifthValue = secondRandomDistribution(generator);

        SignRational<40> secondIntegerData(fifthValue);

        RationalConversion<40, uint32_t> secondConversion(secondIntegerData);

        uint32_t sixthValue = secondConversion.GetValue();

        ASSERT_EQUAL(fifthValue, sixthValue);

        uint16_t seventhValue = fourthRandomDistribution(generator);

        SignRational<40> fourthIntegerData(seventhValue);

        RationalConversion<40, uint16_t> seventhConversion(fourthIntegerData);

        uint16_t eighthValue = seventhConversion.GetValue();

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}

void Mathematics::RationalConversionTesting ::FloatOverflowTest()
{
    Integer<50> firstInteger;
    Integer<50> secondInteger(1);

    firstInteger[48] = static_cast<uint16_t>(0xFFFF);

    SignRational<50> firstRational(firstInteger, secondInteger);

    RationalConversion<50, float> firstConversion(firstRational);

    [[maybe_unused]] auto value = firstConversion.GetValue();
}

void Mathematics::RationalConversionTesting ::DoubleOverflowTest()
{
    Integer<150> firstInteger;
    Integer<150> secondInteger(1);

    firstInteger[148] = static_cast<uint16_t>(0xFFFF);

    SignRational<150> firstRational(firstInteger, secondInteger);

    RationalConversion<150, double> firstConversion(firstRational);

    [[maybe_unused]] auto value = firstConversion.GetValue();
}

void Mathematics::RationalConversionTesting ::IntegerOverflowTest()
{
    int64_t firstValue = (0xFCCCCCFFFULL);

    Integer<150> firstInteger(firstValue);
    Integer<150> secondInteger(1);

    SignRational<150> firstRational(firstInteger, secondInteger);

    RationalConversion<150, int16_t> firstConversion(firstRational);

    [[maybe_unused]] auto value = firstConversion.GetValue();
}

void Mathematics::RationalConversionTesting ::UnsignedIntegerOverflowTest()
{
    uint64_t firstValue = (0xFCCCCCFFFULL);

    Integer<150> firstInteger(firstValue);
    Integer<150> secondInteger(1);

    SignRational<150> firstRational(firstInteger, secondInteger);

    RationalConversion<150, uint16_t> firstConversion(firstRational);

    [[maybe_unused]] auto value = firstConversion.GetValue();
}
