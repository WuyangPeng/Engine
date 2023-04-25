///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 20:41)

#include "ByteSwapTesting.h"
#include "CoreTools/FileManager/ByteSwap.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ByteSwapTesting::ByteSwapTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ByteSwapTesting)

void CoreTools::ByteSwapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ByteSwapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ByteSwap2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ByteSwap4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ByteSwap8Test);
}

void CoreTools::ByteSwapTesting::ByteSwap2Test() noexcept
{
    static_assert(ByteSwap2(0x1234) == 0x3412);
    static_assert(ByteSwap2(0x5678) == 0x7856);
    static_assert(ByteSwap2(0x9012) == 0x1290);
    static_assert(ByteSwap2(0x3456) == 0x5634);
    static_assert(ByteSwap2(0x7890) == 0x9078);

    static_assert(ByteSwap2(ByteSwap2(0x1234)) == 0x1234);
    static_assert(ByteSwap2(ByteSwap2(0x5678)) == 0x5678);
    static_assert(ByteSwap2(ByteSwap2(0x9012)) == 0x9012);
    static_assert(ByteSwap2(ByteSwap2(0x3456)) == 0x3456);
    static_assert(ByteSwap2(ByteSwap2(0x7890)) == 0x7890);
}

void CoreTools::ByteSwapTesting::ByteSwap4Test() noexcept
{
    static_assert(ByteSwap4(0x12345678) == 0x78563412);
    static_assert(ByteSwap4(0x12907856) == 0x56789012);
    static_assert(ByteSwap4(0x90123456) == 0x56341290);
    static_assert(ByteSwap4(0x34567890) == 0x90785634);
    static_assert(ByteSwap4(0x78901234) == 0x34129078);

    static_assert(ByteSwap4(ByteSwap4(0x12345678)) == 0x12345678);
    static_assert(ByteSwap4(ByteSwap4(0x12907856)) == 0x12907856);
    static_assert(ByteSwap4(ByteSwap4(0x90123456)) == 0x90123456);
    static_assert(ByteSwap4(ByteSwap4(0x34567890)) == 0x34567890);
    static_assert(ByteSwap4(ByteSwap4(0x78901234)) == 0x78901234);
}

void CoreTools::ByteSwapTesting::ByteSwap8Test() noexcept
{
    static_assert(ByteSwap8(0x1234567890123456) == 0x5634129078563412);
    static_assert(ByteSwap8(0x5678901234567890) == 0x9078563412907856);
    static_assert(ByteSwap8(0x9012345678901234) == 0x3412907856341290);
    static_assert(ByteSwap8(0x3456789012345678) == 0x7856341290785634);
    static_assert(ByteSwap8(0x7890123456781234) == 0x3412785634129078);

    static_assert(ByteSwap8(ByteSwap8(0x1234567890123456)) == 0x1234567890123456);
    static_assert(ByteSwap8(ByteSwap8(0x5678901234567890)) == 0x5678901234567890);
    static_assert(ByteSwap8(ByteSwap8(0x9012345678901234)) == 0x9012345678901234);
    static_assert(ByteSwap8(ByteSwap8(0x3456789012345678)) == 0x3456789012345678);
    static_assert(ByteSwap8(ByteSwap8(0x7890123456781234)) == 0x7890123456781234);
}
