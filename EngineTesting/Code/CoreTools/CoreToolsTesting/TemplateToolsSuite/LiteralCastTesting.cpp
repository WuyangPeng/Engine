/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:36)

#include "LiteralCastTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/LiteralCastDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define LITERAL_CAST_COMPILE_ERROR

#undef LITERAL_CAST_COMPILE_ERROR

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

#ifdef LITERAL_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

    s8 = LiteralCast<int8_t, 1000>();

#endif  // LITERAL_CAST_COMPILE_ERROR

#ifdef LITERAL_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

    s8 = LiteralCast<int8_t, 10000000>();

#endif  // LITERAL_CAST_COMPILE_ERROR

#ifdef LITERAL_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

    s8 = LiteralCast<int8_t, 10000000000000LL>();

#endif  // LITERAL_CAST_COMPILE_ERROR

    s8 = LiteralCast<int8_t, 0U>();
    s8 = LiteralCast<int8_t, 100U>();
    s8 = LiteralCast<int8_t, 127U>();

#ifdef LITERAL_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

    s8 = LiteralCast<int8_t, 128>();

#endif  // LITERAL_CAST_COMPILE_ERROR

    s8 = LiteralCast<int8_t, -128>();

#ifdef LITERAL_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

    s8 = LiteralCast<int8_t, -129>();

#endif  // LITERAL_CAST_COMPILE_ERROR

    uint8_t u8{ LiteralCast<uint8_t, 0>() };

#ifdef LITERAL_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

    u8 = LiteralCast<uint8_t, -1>();

#endif  // LITERAL_CAST_COMPILE_ERROR

    u8 = LiteralCast<uint8_t, 128>();
    u8 = LiteralCast<uint8_t, 255>();

#ifdef LITERAL_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

    u8 = LiteralCast<uint8_t, 256>();

#endif  // LITERAL_CAST_COMPILE_ERROR

    uint32_t u32{ LiteralCast<uint32_t, 0>() };
    u32 = LiteralCast<uint32_t, 100000>();
    u32 = LiteralCast<uint32_t, 1000000000>();

#ifdef LITERAL_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

    u32 = LiteralCast<uint32_t, 10000000000000LL>();

#endif  // LITERAL_CAST_COMPILE_ERROR

#ifdef LITERAL_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

    MAYBE_UNUSED int64_t s64{ LiteralCast<int64_t, 0>() };

#endif  // LITERAL_CAST_COMPILE_ERROR

#ifdef LITERAL_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

    MAYBE_UNUSED uint64_t u64{ LiteralCast<uint64_t, 1>() };

#endif  // LITERAL_CAST_COMPILE_ERROR
}
