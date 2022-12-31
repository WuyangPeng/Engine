///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/16 22:25)

#include "FixedSizeTesting.h"
#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FixedSizeTesting::FixedSizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FixedSizeTesting)

void System::FixedSizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FixedSizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerMinCriticalTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntegerMaxCriticalTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Integer64Test);
}

void System::FixedSizeTesting::IntegerSizeTest()
{
    ASSERT_EQUAL(sizeof(int8_t), 1u);
    ASSERT_EQUAL(sizeof(int16_t), 2u);
    ASSERT_EQUAL(sizeof(int32_t), 4u);
    ASSERT_EQUAL(sizeof(int64_t), 8u);

    ASSERT_EQUAL(sizeof(uint8_t), 1u);
    ASSERT_EQUAL(sizeof(uint16_t), 2u);
    ASSERT_EQUAL(sizeof(uint32_t), 4u);
    ASSERT_EQUAL(sizeof(uint64_t), 8u);
}

void System::FixedSizeTesting::IntegerMinCriticalTest()
{
    int8_t minInt8{ INT8_MIN };
    --minInt8;
    ASSERT_EQUAL(minInt8, INT8_MAX);

    uint8_t minUInt8{ 0u };
    --minUInt8;
    ASSERT_EQUAL(minUInt8, UINT8_MAX);

    int16_t minInt16{ INT16_MIN };
    --minInt16;
    ASSERT_EQUAL(minInt16, INT16_MAX);

    uint16_t minUInt16{ 0u };
    --minUInt16;
    ASSERT_EQUAL(minUInt16, UINT16_MAX);

    int32_t minInt32{ INT32_MIN };
    --minInt32;
    ASSERT_EQUAL(minInt32, INT32_MAX);

    uint32_t minUInt32{ 0u };
    --minUInt32;
    ASSERT_EQUAL(minUInt32, UINT32_MAX);

    int64_t minInt64{ INT64_MIN };
    --minInt64;
    ASSERT_EQUAL(minInt64, INT64_MAX);

    uint64_t minUInt64{ 0u };
    --minUInt64;
    ASSERT_EQUAL(minUInt64, UINT64_MAX);
}

void System::FixedSizeTesting::IntegerMaxCriticalTest()
{
    int8_t maxInt8{ INT8_MAX };
    ++maxInt8;
    ASSERT_EQUAL(maxInt8, INT8_MIN);

    uint8_t maxUInt8{ UINT8_MAX };
    ++maxUInt8;
    ASSERT_EQUAL(maxUInt8, 0u);

    int16_t maxInt16{ INT16_MAX };
    ++maxInt16;
    ASSERT_EQUAL(maxInt16, INT16_MIN);

    uint16_t maxUInt16{ UINT16_MAX };
    ++maxUInt16;
    ASSERT_EQUAL(maxUInt16, 0u);

    int32_t maxInt32{ INT32_MAX };
    ++maxInt32;
    ASSERT_EQUAL(maxInt32, INT32_MIN);

    uint32_t maxUInt32{ UINT32_MAX };
    ++maxUInt32;
    ASSERT_EQUAL(maxUInt32, 0u);

    int64_t maxInt64{ INT64_MAX };
    ++maxInt64;
    ASSERT_EQUAL(maxInt64, INT64_MIN);

    uint64_t maxUInt64{ UINT64_MAX };
    ++maxUInt64;
    ASSERT_EQUAL(maxUInt64, 0u);
}

void System::FixedSizeTesting::Integer64Test() noexcept
{
    MAYBE_UNUSED constexpr uint64_t uint64Value{ 0xFFFFFFFFFFFFULL };
    MAYBE_UNUSED constexpr int64_t int64Value{ 0xFFFFFFFFFFFELL };
}
