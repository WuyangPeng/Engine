///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 14:46)

#include "IntegerDataConversionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataConversionDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <gsl/util>
#include <limits>
#include <random>

using std::default_random_engine;
using std::numeric_limits;
using std::uniform_int;
using std::uniform_real;

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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

void Mathematics::IntegerDataConversionTesting::FloatingPointTest()
{
    default_random_engine generator{};
    const uniform_real<float> firstRandomDistribution{ -1.0e38f, 1.0e38f };
    const uniform_real<double> secondRandomDistribution(static_cast<double>(std::numeric_limits<uint64_t>::min()), static_cast<double>(std::numeric_limits<uint64_t>::max()));

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = firstRandomDistribution(generator);

        const IntegerData<20> firstIntegerData(firstValue);

        const IntegerDataConversion<20, float> firstConversion(firstIntegerData);

        auto secondValue = firstConversion.GetValue();

        const auto thirdValue = *(reinterpret_cast<const uint32_t*>(&firstValue));
        const auto fourthValue = *(reinterpret_cast<const uint32_t*>(&secondValue));

        ASSERT_EQUAL(thirdValue, fourthValue);

        auto fifthValue = secondRandomDistribution(generator);

        const IntegerData<40> secondIntegerData(fifthValue);

        const IntegerDataConversion<40, double> secondConversion(secondIntegerData);

        auto sixthValue = secondConversion.GetValue();

        const auto seventhValue = *(reinterpret_cast<const uint64_t*>(&fifthValue));
        const auto eighthValue = *(reinterpret_cast<const uint64_t*>(&sixthValue));

        ASSERT_EQUAL(seventhValue, eighthValue);
    }
}

#include STSTEM_WARNING_POP

void Mathematics::IntegerDataConversionTesting::IntegerTest()
{
    default_random_engine generator{};
    const uniform_int<int64_t> firstRandomDistribution(-numeric_limits<int64_t>::max(), numeric_limits<int64_t>::max());
    const uniform_int<int> secondRandomDistribution(-INT_MAX, INT_MAX);
    const uniform_int<int8_t> thirdRandomDistribution(-numeric_limits<int8_t>::max(), numeric_limits<int8_t>::max());
    const uniform_int<int16_t> fourthRandomDistribution(-numeric_limits<int16_t>::max(), numeric_limits<int16_t>::max());

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = firstRandomDistribution(generator);

        const IntegerData<20> firstIntegerData(firstValue);

        const IntegerDataConversion<20, int64_t> firstConversion(firstIntegerData);

        auto secondValue = firstConversion.GetValue();

        ASSERT_EQUAL(firstValue, secondValue);

        auto thirdValue = thirdRandomDistribution(generator);

        const IntegerData<20> thirdIntegerData(thirdValue);

        const IntegerDataConversion<20, int8_t> thirdConversion(thirdIntegerData);

        auto fourthValue = thirdConversion.GetValue();

        ASSERT_EQUAL(thirdValue, fourthValue);

        auto fifthValue = secondRandomDistribution(generator);

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
    default_random_engine generator{};
    const uniform_int<int64_t> firstRandomDistribution(0, numeric_limits<int64_t>::max());
    const uniform_int<int> secondRandomDistribution(0, INT_MAX);
    const uniform_int<int8_t> thirdRandomDistribution(0, numeric_limits<int8_t>::max());
    const uniform_int<int16_t> fourthRandomDistribution(0, numeric_limits<int16_t>::max());

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = firstRandomDistribution(generator);

        const IntegerData<20> firstIntegerData(firstValue);

        const IntegerDataConversion<20, uint64_t> firstConversion(firstIntegerData);

        auto secondValue = firstConversion.GetValue();

        ASSERT_EQUAL(firstValue, boost::numeric_cast<int64_t>(secondValue));

        auto thirdValue = thirdRandomDistribution(generator);

        const IntegerData<20> thirdIntegerData(thirdValue);

        const IntegerDataConversion<20, uint8_t> thirdConversion(thirdIntegerData);

        auto fourthValue = thirdConversion.GetValue();

        ASSERT_EQUAL(thirdValue, fourthValue);

        auto fifthValue = secondRandomDistribution(generator);

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
