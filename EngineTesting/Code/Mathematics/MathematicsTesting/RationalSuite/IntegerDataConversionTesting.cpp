// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/23 13:59)

#include "IntegerDataConversionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataConversionDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"

#include <limits>
#include <random>

using std::default_random_engine;
using std::numeric_limits;
using std::uniform_int;
using std::uniform_real;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, IntegerDataConversionTesting)

void Mathematics::IntegerDataConversionTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatingPointTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedIntegerTest);
    ASSERT_THROW_EXCEPTION_0(FloatOverflowTest);
    ASSERT_THROW_EXCEPTION_0(DoubleOverflowTest);
    ASSERT_THROW_EXCEPTION_0(IntegerOverflowTest);
    ASSERT_THROW_EXCEPTION_0(UnsignedIntegerOverflowTest);
}

void Mathematics::IntegerDataConversionTesting ::FloatingPointTest()
{
    default_random_engine generator{};
    uniform_real<float> firstRandomDistribution{ -1.0e38f, 1.0e38f };
    uniform_real<double> secondRandomDistribution(static_cast<double>(std::numeric_limits<uint64_t>::min()), static_cast<double>(std::numeric_limits<uint64_t>::max()));

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        float firstValue = firstRandomDistribution(generator);

        IntegerData<20> firstIntegerData(firstValue);

        IntegerDataConversion<20, float> firstConversion(firstIntegerData);

        float secondValue = firstConversion.GetValue();

        uint32_t thirdValue = *(reinterpret_cast<const uint32_t*>(&firstValue));
        uint32_t fourthValue = *(reinterpret_cast<const uint32_t*>(&secondValue));

        ASSERT_EQUAL(thirdValue, fourthValue);

        double fifthValue = secondRandomDistribution(generator);

        IntegerData<40> secondIntegerData(fifthValue);

        IntegerDataConversion<40, double> secondConversion(secondIntegerData);

        double sixthValue = secondConversion.GetValue();

        uint64_t seventhValue = *(reinterpret_cast<const uint64_t*>(&fifthValue));
        uint64_t eighthValue = *(reinterpret_cast<const uint64_t*>(&sixthValue));

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}

void Mathematics::IntegerDataConversionTesting ::IntegerTest()
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

        IntegerData<20> firstIntegerData(firstValue);

        IntegerDataConversion<20, int64_t> firstConversion(firstIntegerData);

        int64_t secondValue = firstConversion.GetValue();

        ASSERT_EQUAL(firstValue, secondValue);

        int8_t thirdValue = thirdRandomDistribution(generator);

        IntegerData<20> thirdIntegerData(thirdValue);

        IntegerDataConversion<20, int8_t> thirdConversion(thirdIntegerData);

        int8_t fourthValue = thirdConversion.GetValue();

        ASSERT_EQUAL(thirdValue, fourthValue);

        int fifthValue = secondRandomDistribution(generator);

        IntegerData<40> secondIntegerData(fifthValue);

        IntegerDataConversion<40, int> secondConversion(secondIntegerData);

        int sixthValue = secondConversion.GetValue();

        ASSERT_EQUAL(fifthValue, sixthValue);

        int16_t seventhValue = fourthRandomDistribution(generator);

        IntegerData<40> fourthIntegerData(seventhValue);

        IntegerDataConversion<40, int16_t> seventhConversion(fourthIntegerData);

        int16_t eighthValue = seventhConversion.GetValue();

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}

void Mathematics::IntegerDataConversionTesting ::UnsignedIntegerTest()
{
    default_random_engine generator{};
    uniform_int<int64_t> firstRandomDistribution(0, numeric_limits<int64_t>::max());
    uniform_int<int> secondRandomDistribution(0, INT_MAX);
    uniform_int<int8_t> thirdRandomDistribution(0, numeric_limits<int8_t>::max());
    uniform_int<int16_t> fourthRandomDistribution(0, numeric_limits<int16_t>::max());

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        uint64_t firstValue = firstRandomDistribution(generator);

        IntegerData<20> firstIntegerData(firstValue);

        IntegerDataConversion<20, uint64_t> firstConversion(firstIntegerData);

        uint64_t secondValue = firstConversion.GetValue();

        ASSERT_EQUAL(firstValue, secondValue);

        uint8_t thirdValue = thirdRandomDistribution(generator);

        IntegerData<20> thirdIntegerData(thirdValue);

        IntegerDataConversion<20, uint8_t> thirdConversion(thirdIntegerData);

        uint8_t fourthValue = thirdConversion.GetValue();

        ASSERT_EQUAL(thirdValue, fourthValue);

        uint32_t fifthValue = secondRandomDistribution(generator);

        IntegerData<40> secondIntegerData(fifthValue);

        IntegerDataConversion<40, uint32_t> secondConversion(secondIntegerData);

        uint32_t sixthValue = secondConversion.GetValue();

        ASSERT_EQUAL(fifthValue, sixthValue);

        uint16_t seventhValue = fourthRandomDistribution(generator);

        IntegerData<40> fourthIntegerData(seventhValue);

        IntegerDataConversion<40, uint16_t> seventhConversion(fourthIntegerData);

        uint16_t eighthValue = seventhConversion.GetValue();

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}

void Mathematics::IntegerDataConversionTesting ::FloatOverflowTest()
{
    IntegerData<50> firstIntegerData;

    firstIntegerData[48] = static_cast<uint16_t>(0xFFFF);

    IntegerDataConversion<50, float> firstConversion(firstIntegerData);

    [[maybe_unused]] auto value = firstConversion.GetValue();
}

void Mathematics::IntegerDataConversionTesting ::DoubleOverflowTest()
{
    IntegerData<150> firstIntegerData;

    firstIntegerData[148] = static_cast<uint16_t>(0xFFFF);

    IntegerDataConversion<150, double> firstConversion(firstIntegerData);

    [[maybe_unused]] auto value = firstConversion.GetValue();
}

void Mathematics::IntegerDataConversionTesting ::IntegerOverflowTest()
{
    int64_t firstValue = (0xFCCCCCFFFULL);

    IntegerData<40> firstIntegerData(firstValue);

    IntegerDataConversion<40, int16_t> firstConversion(firstIntegerData);

    [[maybe_unused]] auto value = firstConversion.GetValue();
}

void Mathematics::IntegerDataConversionTesting ::UnsignedIntegerOverflowTest()
{
    uint64_t firstValue = (0xFCCCCCFFFULL);

    IntegerData<40> firstIntegerData(firstValue);

    IntegerDataConversion<40, uint16_t> firstConversion(firstIntegerData);

    [[maybe_unused]] auto value = firstConversion.GetValue();
}
