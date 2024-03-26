/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 17:34)

#include "FixedSizeTestingDetail.h"
#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FixedSizeTesting::FixedSizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

void System::FixedSizeTesting::IntegerSizeTest() const noexcept
{
    static_assert(sizeof(int8_t) == 1u);
    static_assert(sizeof(int16_t) == 2u);
    static_assert(sizeof(int32_t) == 4u);
    static_assert(sizeof(int64_t) == 8u);

    static_assert(sizeof(uint8_t) == 1u);
    static_assert(sizeof(uint16_t) == 2u);
    static_assert(sizeof(uint32_t) == 4u);
    static_assert(sizeof(uint64_t) == 8u);
}

void System::FixedSizeTesting::IntegerMinCriticalTest()
{
    DoIntegerMinCriticalTest<int8_t>(INT8_MIN, INT8_MAX);
    DoIntegerMinCriticalTest<uint8_t>(0u, UINT8_MAX);
    DoIntegerMinCriticalTest<int16_t>(INT16_MIN, INT16_MAX);
    DoIntegerMinCriticalTest<uint16_t>(0u, UINT16_MAX);
    DoIntegerMinCriticalTest<int32_t>(INT32_MIN, INT32_MAX);
    DoIntegerMinCriticalTest<uint32_t>(0u, UINT32_MAX);
    DoIntegerMinCriticalTest<int64_t>(INT64_MIN, INT64_MAX);
    DoIntegerMinCriticalTest<uint64_t>(0u, UINT64_MAX);
}

void System::FixedSizeTesting::IntegerMaxCriticalTest()
{
    DoIntegerMaxCriticalTest<int8_t>(INT8_MAX, INT8_MIN);
    DoIntegerMaxCriticalTest<uint8_t>(UINT8_MAX, 0u);
    DoIntegerMaxCriticalTest<int16_t>(INT16_MAX, INT16_MIN);
    DoIntegerMaxCriticalTest<uint16_t>(UINT16_MAX, 0u);
    DoIntegerMaxCriticalTest<int32_t>(INT32_MAX, INT32_MIN);
    DoIntegerMaxCriticalTest<uint32_t>(UINT32_MAX, 0u);
    DoIntegerMaxCriticalTest<int64_t>(INT64_MAX, INT64_MIN);
    DoIntegerMaxCriticalTest<uint64_t>(UINT64_MAX, 0u);
}

void System::FixedSizeTesting::Integer64Test() const noexcept
{
    MAYBE_UNUSED constexpr uint64_t uint64Value{ 0xFFFFFFFFFFFFULL };
    MAYBE_UNUSED constexpr int64_t int64Value{ 0xFFFFFFFFFFFELL };
}
