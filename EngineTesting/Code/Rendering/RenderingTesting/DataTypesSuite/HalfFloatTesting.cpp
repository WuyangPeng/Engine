///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:58)

#include "HalfFloatTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/DataTypes/HalfFloat.h"

#include <random>

Rendering::HalfFloatTesting::HalfFloatTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, HalfFloatTesting)

void Rendering::HalfFloatTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::HalfFloatTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BigFloatTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SmallFloatTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UInt16Test);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
}

void Rendering::HalfFloatTesting::BigFloatTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> floatRandomDistribution(-32768.0f, 32768.0f);  // 2��15�η�

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const float firstValue = floatRandomDistribution(generator);

        const HalfFloat firstHalfFloat(firstValue);

        const float secondValue = firstHalfFloat.ToFloat();

        // ����ֻ��1/2^10
        ASSERT_APPROXIMATE(firstValue, secondValue, Mathematics::MathF::FAbs(firstValue / 1024.0f));

        const HalfFloat secondHalfFloat(secondValue);

        const float thirdValue = firstHalfFloat.ToFloat();

        ASSERT_APPROXIMATE(thirdValue, secondValue, 1e-8f);

        ASSERT_EQUAL(firstHalfFloat, secondHalfFloat);
        ASSERT_TRUE(Approximate(firstHalfFloat, secondHalfFloat, 1e-8f));
    }
}

void Rendering::HalfFloatTesting::SmallFloatTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> firstFloatRandomDistribution(-1.0f / 32768.0f, 1.0f / 32768.0f);  // 2��-15�η�

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const float firstValue = firstFloatRandomDistribution(generator);

        const HalfFloat firstHalfFloat(firstValue);

        const float secondValue = firstHalfFloat.ToFloat();

        // ����ֻ��1/2^10
        ASSERT_APPROXIMATE(firstValue, secondValue, Mathematics::MathF::FAbs(firstValue * 1024.0f));

        const HalfFloat secondHalfFloat(secondValue);

        const float thirdValue = firstHalfFloat.ToFloat();

        ASSERT_APPROXIMATE(thirdValue, secondValue, 1e-8f);

        ASSERT_EQUAL(firstHalfFloat, secondHalfFloat);
        ASSERT_TRUE(Approximate(firstHalfFloat, secondHalfFloat, 1e-8f));
    }
}

void Rendering::HalfFloatTesting::UInt16Test() noexcept
{
}

void Rendering::HalfFloatTesting::OperatorTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> floatRandomDistribution(-32768.0f, 32768.0f);  // 2��15�η�

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const float firstValue = floatRandomDistribution(generator);

        const HalfFloat firstHalfFloat(firstValue);

        const HalfFloat secondHalfFloat = -firstHalfFloat;

        ASSERT_APPROXIMATE(firstHalfFloat.ToFloat(), -secondHalfFloat.ToFloat(), 1e-8f);
    }
}
