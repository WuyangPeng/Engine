/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 12:07)

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
    static_assert(GetRequiredBits<0B111111111111111111111111111111100>::result == 33);
    static_assert(GetRequiredBits<0B1111111111111111111111111111111000>::result == 34);
    static_assert(GetRequiredBits<0B11111111111111111111111111111110000>::result == 35);
    static_assert(GetRequiredBits<0B111111111111111111111111111111100000>::result == 36);
    static_assert(GetRequiredBits<0B1111111111111111111111111111111000000>::result == 37);
    static_assert(GetRequiredBits<0B11111111111111111111111111111110000000>::result == 38);
    static_assert(GetRequiredBits<0B111111111111111111111111111111100000001>::result == 39);
    static_assert(GetRequiredBits<0B1111111111111111111111111111111000000011>::result == 40);

    static_assert(GetRequiredBits<0B11111111111111111111111111111110000000000>::result == 41);
    static_assert(GetRequiredBits<0B111111111111111111111111111111100000000000>::result == 42);
    static_assert(GetRequiredBits<0B1111111111111111111111111111111000000000000>::result == 43);
    static_assert(GetRequiredBits<0B11111111111111111111111111111110000000000000>::result == 44);
    static_assert(GetRequiredBits<0B111111111111111111111111111111100000000000000>::result == 45);
    static_assert(GetRequiredBits<0B1111111111111111111111111111111000000000000000>::result == 46);
    static_assert(GetRequiredBits<0B11111111111111111111111111111110000000000000000>::result == 47);
    static_assert(GetRequiredBits<0B111111111111111111111111111111100000001000000000>::result == 48);
    static_assert(GetRequiredBits<0B1111111111111111111111111111111000000011000000000>::result == 49);
    static_assert(GetRequiredBits<0B11111111111111111111111111111110000000110000000001>::result == 50);

    static_assert(GetRequiredBits<0B111111111111111111111111111111100000000001111111000>::result == 51);
    static_assert(GetRequiredBits<0B1111111111111111111111111111111000000000001111111000>::result == 52);
    static_assert(GetRequiredBits<0B11111111111111111111111111111110000000000001111111000>::result == 53);
    static_assert(GetRequiredBits<0B111111111111111111111111111111100000000000001111111000>::result == 54);
    static_assert(GetRequiredBits<0B1111111111111111111111111111111000000000000001111111000>::result == 55);
    static_assert(GetRequiredBits<0B11111111111111111111111111111110000000000000001111111000>::result == 56);
    static_assert(GetRequiredBits<0B111111111111111111111111111111100000000000000001111111000>::result == 57);
    static_assert(GetRequiredBits<0B1111111111111111111111111111111000000010000000001111111000>::result == 58);
    static_assert(GetRequiredBits<0B11111111111111111111111111111110000000110000000001111111000>::result == 59);
    static_assert(GetRequiredBits<0B111111111111111111111111111111100000001100000000011111111000>::result == 60);

    static_assert(GetRequiredBits<0B1111111111111111111111111111111000000011000000000111111110000>::result == 61);
    static_assert(GetRequiredBits<0B11111111111111111111111111111110000000110000000001111111100010>::result == 62);
    static_assert(GetRequiredBits<0B111111111111111111111111111111100000001100000000011111111000101>::result == 63);
    static_assert(GetRequiredBits<0B1111111111111111111111111111111000000011000000000111111110001011>::result == 64);
}
