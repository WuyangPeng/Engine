///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:32)

#include "IntegerDataConversionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataConversionDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"

#include <gsl/util>
#include <limits>
#include <random>

Mathematics::IntegerDataConversionTesting::IntegerDataConversionTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, IntegerDataConversionTesting)

void Mathematics::IntegerDataConversionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::IntegerDataConversionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatingPointTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignedIntegerTest);
    ASSERT_THROW_EXCEPTION_0(FloatOverflowTest);
    ASSERT_THROW_EXCEPTION_0(DoubleOverflowTest);
    ASSERT_THROW_EXCEPTION_0(IntegerOverflowTest);
    ASSERT_THROW_EXCEPTION_0(UnsignedIntegerOverflowTest);
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

void Mathematics::IntegerDataConversionTesting::FloatingPointTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution0{ -1.0e38f, 1.0e38f };
    std::uniform_real_distribution<double> randomDistribution1(static_cast<double>(std::numeric_limits<uint64_t>::min()), static_cast<double>(std::numeric_limits<uint64_t>::max()));

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);

        const IntegerData<20> firstIntegerData(firstValue);

        const IntegerDataConversion<20, float> firstConversion(firstIntegerData);

        auto secondValue = firstConversion.GetValue();

        const auto thirdValue = *(reinterpret_cast<const uint32_t*>(&firstValue));
        const auto fourthValue = *(reinterpret_cast<const uint32_t*>(&secondValue));

        ASSERT_EQUAL(thirdValue, fourthValue);

        auto fifthValue = randomDistribution1(generator);

        const IntegerData<40> secondIntegerData(fifthValue);

        const IntegerDataConversion<40, double> secondConversion(secondIntegerData);

        auto sixthValue = secondConversion.GetValue();

        const auto seventhValue = *(reinterpret_cast<const uint64_t*>(&fifthValue));
        const auto eighthValue = *(reinterpret_cast<const uint64_t*>(&sixthValue));

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}

#include SYSTEM_WARNING_POP

void Mathematics::IntegerDataConversionTesting::IntegerTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<int64_t> randomDistribution0(-std::numeric_limits<int64_t>::max(), std::numeric_limits<int64_t>::max());
    std::uniform_int_distribution<int> randomDistribution1(-INT_MAX, INT_MAX);
    std::uniform_int_distribution<int16_t> thirdRandomDistribution(-std::numeric_limits<int8_t>::max(), std::numeric_limits<int8_t>::max());
    std::uniform_int_distribution<int16_t> fourthRandomDistribution(-std::numeric_limits<int16_t>::max(), std::numeric_limits<int16_t>::max());

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);

        const IntegerData<20> firstIntegerData(firstValue);

        const IntegerDataConversion<20, int64_t> firstConversion(firstIntegerData);

        auto secondValue = firstConversion.GetValue();

        ASSERT_EQUAL(firstValue, secondValue);

        auto thirdValue = thirdRandomDistribution(generator);

        const IntegerData<20> thirdIntegerData(thirdValue);

        const IntegerDataConversion<20, int8_t> thirdConversion(thirdIntegerData);

        auto fourthValue = thirdConversion.GetValue();

        ASSERT_EQUAL(thirdValue, fourthValue);

        auto fifthValue = randomDistribution1(generator);

        const IntegerData<40> secondIntegerData(fifthValue);

        const IntegerDataConversion<40, int> secondConversion(secondIntegerData);

        auto sixthValue = secondConversion.GetValue();

        ASSERT_EQUAL(fifthValue, sixthValue);

        auto seventhValue = fourthRandomDistribution(generator);

        const IntegerData<40> fourthIntegerData(seventhValue);

        const IntegerDataConversion<40, int16_t> seventhConversion(fourthIntegerData);

        auto eighthValue = seventhConversion.GetValue();

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}

void Mathematics::IntegerDataConversionTesting::UnsignedIntegerTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<int64_t> randomDistribution0(0, std::numeric_limits<int64_t>::max());
    std::uniform_int_distribution<int> randomDistribution1(0, INT_MAX);
    std::uniform_int_distribution<int16_t> thirdRandomDistribution(0, std::numeric_limits<int8_t>::max());
    std::uniform_int_distribution<int16_t> fourthRandomDistribution(0, std::numeric_limits<int16_t>::max());

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);

        const IntegerData<20> firstIntegerData(firstValue);

        const IntegerDataConversion<20, uint64_t> firstConversion(firstIntegerData);

        auto secondValue = firstConversion.GetValue();

        ASSERT_EQUAL(firstValue, boost::numeric_cast<int64_t>(secondValue));

        auto thirdValue = thirdRandomDistribution(generator);

        const IntegerData<20> thirdIntegerData(thirdValue);

        const IntegerDataConversion<20, uint8_t> thirdConversion(thirdIntegerData);

        auto fourthValue = thirdConversion.GetValue();

        ASSERT_EQUAL(thirdValue, fourthValue);

        auto fifthValue = randomDistribution1(generator);

        const IntegerData<40> secondIntegerData(fifthValue);

        const IntegerDataConversion<40, uint32_t> secondConversion(secondIntegerData);

        auto sixthValue = secondConversion.GetValue();

        ASSERT_EQUAL(fifthValue, boost::numeric_cast<int64_t>(sixthValue));

        auto seventhValue = fourthRandomDistribution(generator);

        const IntegerData<40> fourthIntegerData(seventhValue);

        const IntegerDataConversion<40, uint16_t> seventhConversion(fourthIntegerData);

        auto eighthValue = seventhConversion.GetValue();

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}

void Mathematics::IntegerDataConversionTesting::FloatOverflowTest()
{
    IntegerData<50> firstIntegerData;

    firstIntegerData[48] = gsl::narrow_cast<uint16_t>(0xFFFF);

    const IntegerDataConversion<50, float> firstConversion(firstIntegerData);

    MAYBE_UNUSED auto value = firstConversion.GetValue();
}

void Mathematics::IntegerDataConversionTesting::DoubleOverflowTest()
{
    IntegerData<150> firstIntegerData;

    firstIntegerData[148] = gsl::narrow_cast<uint16_t>(0xFFFF);

    const IntegerDataConversion<150, double> firstConversion(firstIntegerData);

    MAYBE_UNUSED auto value = firstConversion.GetValue();
}

void Mathematics::IntegerDataConversionTesting::IntegerOverflowTest()
{
    constexpr int64_t firstValue = (0xFCCCCCFFFULL);

    const IntegerData<40> firstIntegerData(firstValue);

    const IntegerDataConversion<40, int16_t> firstConversion(firstIntegerData);

    MAYBE_UNUSED auto value = firstConversion.GetValue();
}

void Mathematics::IntegerDataConversionTesting::UnsignedIntegerOverflowTest()
{
    constexpr uint64_t firstValue = (0xFCCCCCFFFULL);

    const IntegerData<40> firstIntegerData(firstValue);

    const IntegerDataConversion<40, uint16_t> firstConversion(firstIntegerData);

    MAYBE_UNUSED auto value = firstConversion.GetValue();
}
