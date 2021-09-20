///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/20 13:42)

#include "GetRequiredBitsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/GetRequiredBits.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::GetRequiredBitsTesting::GetRequiredBitsTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, GetRequiredBitsTesting)

void CoreTools::GetRequiredBitsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::GetRequiredBitsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BitsTest);
}

void CoreTools::GetRequiredBitsTesting::BitsTest() noexcept
{
    static_assert(GetRequiredBits<0B1>::result == 1);
    static_assert(GetRequiredBits<0B11>::result == 2);
    static_assert(GetRequiredBits<0B111>::result == 3);
    static_assert(GetRequiredBits<0B1111>::result == 4);
    static_assert(GetRequiredBits<0B11111>::result == 5);
    static_assert(GetRequiredBits<0B111111>::result == 6);
    static_assert(GetRequiredBits<0B1111111>::result == 7);
    static_assert(GetRequiredBits<0B11111111>::result == 8);
    static_assert(GetRequiredBits<0B111111111>::result == 9);
    static_assert(GetRequiredBits<0B1111111111>::result == 10);

    static_assert(GetRequiredBits<0B11111111111>::result == 11);
    static_assert(GetRequiredBits<0B111111111111>::result == 12);
    static_assert(GetRequiredBits<0B1111111111111>::result == 13);
    static_assert(GetRequiredBits<0B11111111111111>::result == 14);
    static_assert(GetRequiredBits<0B111111111111111>::result == 15);
    static_assert(GetRequiredBits<0B1111111111111111>::result == 16);
    static_assert(GetRequiredBits<0B11111111111111111>::result == 17);
    static_assert(GetRequiredBits<0B111111111111111111>::result == 18);
    static_assert(GetRequiredBits<0B1111111111111111111>::result == 19);
    static_assert(GetRequiredBits<0B11111111111111111111>::result == 20);

    static_assert(GetRequiredBits<0B111111111111111111111>::result == 21);
    static_assert(GetRequiredBits<0B1111111111111111111111>::result == 22);
    static_assert(GetRequiredBits<0B11111111111111111111111>::result == 23);
    static_assert(GetRequiredBits<0B111111111111111111111111>::result == 24);
    static_assert(GetRequiredBits<0B1111111111111111111111111>::result == 25);
    static_assert(GetRequiredBits<0B11111111111111111111111111>::result == 26);
    static_assert(GetRequiredBits<0B111111111111111111111111111>::result == 27);
    static_assert(GetRequiredBits<0B1111111111111111111111111111>::result == 28);
    static_assert(GetRequiredBits<0B11111111111111111111111111111>::result == 29);
    static_assert(GetRequiredBits<0B111111111111111111111111111111>::result == 30);

    static_assert(GetRequiredBits<0B1111111111111111111111111111111>::result == 31);
}
