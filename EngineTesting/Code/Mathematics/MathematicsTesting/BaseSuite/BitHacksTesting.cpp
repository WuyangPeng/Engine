///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:26)

#include "BitHacksTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/BitHacksDetail.h"

#include <algorithm>
#include <random>

Mathematics::BitHacksTesting::BitHacksTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, BitHacksTesting)

void Mathematics::BitHacksTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::BitHacksTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IsPowerOfTwoTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Log2OfPowerOfTwoTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScaledFloatToIntTest);
}

// IsPowerOfTwo ����
void Mathematics::BitHacksTesting::IsPowerOfTwoTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SignIntIsPowerOfTwoTrueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignIntIsPowerOfTwoTrueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SignIntIsPowerOfTwoFalseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignIntIsPowerOfTwoFalseTest);
}

// IsPowerOfTwo ����
void Mathematics::BitHacksTesting::SignIntIsPowerOfTwoTrueTest()
{
    // ��������
    int value = 1;

    for (int i = 0; i < 31; ++i)
    {
        ASSERT_TRUE(BitHacks::IsPowerOfTwo(value));

        value *= 2;
    }
}

void Mathematics::BitHacksTesting::UnsignIntIsPowerOfTwoTrueTest()
{
    // ��������
    unsigned value = 1;

    for (int i = 0; i < 32; ++i)
    {
        ASSERT_TRUE(BitHacks::IsPowerOfTwo(value));

        value *= 2;
    }
}

void Mathematics::BitHacksTesting::SignIntIsPowerOfTwoFalseTest()
{
    // �̶�ֵ����
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
    // �̶�ֵ����
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(220u));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(341u));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(481u));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(5161u));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(7325u));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(8644u));
    ASSERT_FALSE(BitHacks::IsPowerOfTwo(91281u));
}

// Log2OfPowerOfTwo ����
void Mathematics::BitHacksTesting::Log2OfPowerOfTwoTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FixedValueLog2OfPowerOfTwoTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SignIntLog2OfPowerOfTwoTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UnsignIntLog2OfPowerOfTwoTest);
}

void Mathematics::BitHacksTesting::FixedValueLog2OfPowerOfTwoTest()
{
    // �̶�ֵ����
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(1u), 0u);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(3u), 1u);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(4u), 2u);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(5u), 2u);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(8u), 3u);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(15u), 3u);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(31u), 4u);
    ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(32u), 5u);
}

void Mathematics::BitHacksTesting::SignIntLog2OfPowerOfTwoTest()
{
    // ���ֵ����
    auto max = boost::numeric_cast<int>(pow(2.0, 31) - 1);

    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_int_distribution<> integerRandomDistribution{ 0, max };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = integerRandomDistribution(randomEngine);

        ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(value), boost::numeric_cast<int>(log(boost::numeric_cast<double>(value)) / log(2.0)));
    }
}

void Mathematics::BitHacksTesting::UnsignIntLog2OfPowerOfTwoTest()
{
    // ���ֵ����
    const auto max = boost::numeric_cast<uint32_t>(pow(2.0, 32) - 1);

    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_int_distribution<uint32_t> integerRandomDistribution{ 0, max };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = integerRandomDistribution(randomEngine);

        ASSERT_EQUAL(BitHacks::Log2OfPowerOfTwo(value), boost::numeric_cast<uint32_t>(log(boost::numeric_cast<double>(value)) / log(2.0)));
    }
}

// ScaledFloatToInt����
void Mathematics::BitHacksTesting::ScaledFloatToIntTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ScaledFloatToIntMinTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScaledFloatToIntMaxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScaledFloatToIntRandomTest);
}

void Mathematics::BitHacksTesting::ScaledFloatToIntMinTest()
{
    // ��������
    for (auto power = 0; power < 25; ++power)
    {
        ASSERT_EQUAL(BitHacks::ScaledFloatToInt(0.0f, power), 0);
    }
}

void Mathematics::BitHacksTesting::ScaledFloatToIntMaxTest()
{
    // ��������
    for (auto power = 0; power < 25; ++power)
    {
        auto max = boost::numeric_cast<int>(pow(2.0, power) - 1);
        ASSERT_EQUAL(BitHacks::ScaledFloatToInt(1.0f, power), max);
    }
}

void Mathematics::BitHacksTesting::ScaledFloatToIntRandomTest()
{
    // ���ֵ����
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_int_distribution<uint32_t> integerRandomDistribution{ 0, 24 };
    std::uniform_real_distribution<float> floatRandomDistribution{ 0.0f, 1.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto value = floatRandomDistribution(randomEngine);
        auto power = integerRandomDistribution(randomEngine);

        auto max = boost::numeric_cast<int>(pow(2.0, power) - 1);

        auto scaledValue = boost::numeric_cast<int>(value * (max + 1));

        ASSERT_EQUAL(BitHacks::ScaledFloatToInt(value, power), scaledValue);
    }
}
