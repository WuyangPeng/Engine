///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 10:44)

#include "BitHacksTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/BitHacksDetail.h"

#include <algorithm>
#include <random>

using std::default_random_engine;
using std::pow;
using std::uniform_int;
using std::uniform_real;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, BitHacksTesting)

void Mathematics::BitHacksTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IsPowerOfTwoTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Log2OfPowerOfTwoTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScaledFloatToIntTest);
}

// IsPowerOfTwo 测试
void Mathematics::BitHacksTesting::IsPowerOfTwoTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SignIntIsPowerOfTwoTrueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignIntIsPowerOfTwoTrueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SignIntIsPowerOfTwoFalseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignIntIsPowerOfTwoFalseTest);
}

// IsPowerOfTwo 测试
void Mathematics::BitHacksTesting::SignIntIsPowerOfTwoTrueTest()
{
    // 完整测试
    int value = 1;

    for (int i = 0; i < 31; ++i)
    {
        ASSERT_TRUE(BitHacks::IsPowerOfTwo(value));

        value *= 2;
    }
}

void Mathematics::BitHacksTesting::UnsignIntIsPowerOfTwoTrueTest()
{
    // 完整测试
    unsigned value = 1;

    for (int i = 0; i < 32; ++i)
    {
        ASSERT_TRUE(BitHacks::IsPowerOfTwo(value));

        value *= 2;
    }
}

void Mathematics::BitHacksTesting::SignIntIsPowerOfTwoFalseTest()
{
    // 固定值测试
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(20));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(41));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(81));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(161));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(325));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(644));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(1281));
}

void Mathematics::BitHacksTesting::UnsignIntIsPowerOfTwoFalseTest()
{
    // 固定值测试
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(220u));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(341u));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(481u));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(5161u));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(7325u));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(8644u));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(91281u));
}

// Log2OfPowerOfTwo 测试
void Mathematics::BitHacksTesting::Log2OfPowerOfTwoTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FixedValueLog2OfPowerOfTwoTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SignIntLog2OfPowerOfTwoTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignIntLog2OfPowerOfTwoTest);
}

void Mathematics::BitHacksTesting::FixedValueLog2OfPowerOfTwoTest()
{
    // 固定值测试
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(1u), 0u);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(3u), 1u);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(4u), 2u);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(5u), 2u);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(8u), 3u);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(15u), 3u);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(31), 4);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(32u), 5u);
}

void Mathematics::BitHacksTesting::SignIntLog2OfPowerOfTwoTest()
{
    // 随机值测试
    auto max = boost::numeric_cast<int>(pow(2.0, 31) - 1);

    default_random_engine randomEngine{};
    const uniform_int<> integerRandomDistribution{ 0, max };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = integerRandomDistribution(randomEngine);

        ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(value), boost::numeric_cast<int>(log(boost::numeric_cast<double>(value)) / log(2.0)));
    }
}

void Mathematics::BitHacksTesting::UnsignIntLog2OfPowerOfTwoTest()
{
    // 随机值测试
    const auto max = boost::numeric_cast<uint32_t>(pow(2.0, 32) - 1);

    default_random_engine randomEngine{};
    const uniform_int<uint32_t> integerRandomDistribution{ 0, max };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = integerRandomDistribution(randomEngine);

        ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(value), boost::numeric_cast<uint32_t>(log(boost::numeric_cast<double>(value)) / log(2.0)));
    }
}

// ScaledFloatToInt测试
void Mathematics::BitHacksTesting::ScaledFloatToIntTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ScaledFloatToIntMinTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScaledFloatToIntMaxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScaledFloatToIntRandomTest);
}

void Mathematics::BitHacksTesting::ScaledFloatToIntMinTest()
{
    // 完整测试
    for (auto power = 0; power < 25; ++power)
    {
        ASSERT_EQUAL(BitHacks::ScaledFloatToInt(0.0f, power), 0);
    }
}

void Mathematics::BitHacksTesting::ScaledFloatToIntMaxTest()
{
    // 完整测试
    for (auto power = 0; power < 25; ++power)
    {
        auto max = boost::numeric_cast<int>(pow(2.0, power) - 1);
        ASSERT_EQUAL(BitHacks::ScaledFloatToInt(1.0f, power), max);
    }
}

void Mathematics::BitHacksTesting::ScaledFloatToIntRandomTest()
{
    // 随机值测试
    default_random_engine randomEngine{};
    const uniform_int<uint32_t> integerRandomDistribution{ 0, 24 };
    const uniform_real<float> floatRandomDistribution{ 0.0f, 1.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        auto value = floatRandomDistribution(randomEngine);
        auto power = integerRandomDistribution(randomEngine);

        auto max = boost::numeric_cast<int>(pow(2.0, power) - 1);

        auto scaledValue = boost::numeric_cast<int>(value * (max + 1));

        ASSERT_EQUAL(BitHacks::ScaledFloatToInt(value, power), scaledValue);
    }
}
