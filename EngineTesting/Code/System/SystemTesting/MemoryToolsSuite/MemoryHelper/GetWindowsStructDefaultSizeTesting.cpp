///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/04 21:17)

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
    const auto consoleFontInfoEx = GetWindowsStructDefaultSize<ConsoleFontInfoEx>();

    ASSERT_EQUAL(consoleFontInfoEx.cbSize, sizeof(ConsoleFontInfoEx));
    ASSERT_EQUAL(consoleFontInfoEx.nFont, 0u);
    ASSERT_EQUAL(consoleFontInfoEx.dwFontSize.X, 0);
    ASSERT_EQUAL(consoleFontInfoEx.dwFontSize.Y, 0);
    ASSERT_EQUAL(consoleFontInfoEx.FontFamily, 0u);
    ASSERT_EQUAL(consoleFontInfoEx.FontWeight, 0u);
}
