/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:16)

#include "GetWindowsStructDefaultSizeTesting.h"
#include "System/Console/Using/ConsoleFontUsing.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetWindowsStructDefaultSizeTesting::GetWindowsStructDefaultSizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetWindowsStructDefaultSizeTesting)

void System::GetWindowsStructDefaultSizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetWindowsStructDefaultSizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetWindowsStructDefaultSizeTest);
}

void System::GetWindowsStructDefaultSizeTesting::GetWindowsStructDefaultSizeTest()
{
    constexpr auto consoleFontInfoEx = GetWindowsStructDefaultSize<ConsoleFontInfoEx>();

    ASSERT_EQUAL(consoleFontInfoEx.cbSize, sizeof(ConsoleFontInfoEx));
    ASSERT_EQUAL(consoleFontInfoEx.nFont, 0u);
    ASSERT_EQUAL(consoleFontInfoEx.dwFontSize.X, 0);
    ASSERT_EQUAL(consoleFontInfoEx.dwFontSize.Y, 0);
    ASSERT_EQUAL(consoleFontInfoEx.FontFamily, 0u);
    ASSERT_EQUAL(consoleFontInfoEx.FontWeight, 0u);
}
