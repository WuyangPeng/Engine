///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:34)

#include "LiteralCastTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/LiteralCastDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LiteralCastTesting::LiteralCastTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LiteralCastTesting)

void CoreTools::LiteralCastTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LiteralCastTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CastTest);
}

void CoreTools::LiteralCastTesting::CastTest() noexcept
{
    int8_t s8{ LiteralCast<int8_t, 0>() };
    s8 = LiteralCast<int8_t, 100>();

#if 0  // 这里应该产生编译错误。

    s8 = LiteralCast<int8_t, 1000>();

#endif  // 0

#if 0  // 这里应该产生编译错误。

    s8 = LiteralCast<int8_t, 10000000>();

#endif  // 0

#if 0  // 这里应该产生编译错误。

    s8 = LiteralCast<int8_t, 10000000000000LL>();

#endif  // 0

    s8 = LiteralCast<int8_t, 0U>();
    s8 = LiteralCast<int8_t, 100U>();
    s8 = LiteralCast<int8_t, 127U>();

#if 0  // 这里应该产生编译错误。

    s8 = LiteralCast<int8_t, 128>();

#endif  // 0

    s8 = LiteralCast<int8_t, -128>();

#if 0  // 这里应该产生编译错误。

    s8 = LiteralCast<int8_t, -129>();

#endif  // 0

    uint8_t u8{ LiteralCast<uint8_t, 0>() };

#if 0  // 这里应该产生编译错误。

    u8 = LiteralCast<uint8_t, -1>();

#endif  // 0

    u8 = LiteralCast<uint8_t, 128>();
    u8 = LiteralCast<uint8_t, 255>();

#if 0  // 这里应该产生编译错误。

    u8 = LiteralCast<uint8_t, 256>();

#endif  // 0

    uint32_t u32{ LiteralCast<uint32_t, 0>() };
    u32 = LiteralCast<uint32_t, 100000>();
    u32 = LiteralCast<uint32_t, 1000000000>();

#if 0  // 这里应该产生编译错误。

    u32 = LiteralCast<uint32_t, 10000000000000LL>();

#endif  // 0

#if 0  // 这里应该产生编译错误。

    MAYBE_UNUSED int64_t s64{ LiteralCast<int64_t, 0>() };

#endif  // 0

#if 0  // 这里应该产生编译错误。

    MAYBE_UNUSED uint64_t u64{ LiteralCast<uint64_t, 1>() };

#endif  // 0
}
