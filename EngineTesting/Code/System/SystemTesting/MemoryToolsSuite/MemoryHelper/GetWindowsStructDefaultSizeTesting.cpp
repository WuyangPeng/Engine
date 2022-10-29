///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/16 19:37)

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
    auto consoleFontInfoEx = GetWindowsStructDefaultSize<ConsoleFontInfoEx>();

    ASSERT_EQUAL(consoleFontInfoEx.cbSize, sizeof(ConsoleFontInfoEx));
    ASSERT_EQUAL(consoleFontInfoEx.nFont, 0u);
    ASSERT_EQUAL(consoleFontInfoEx.dwFontSize.X, 0);
    ASSERT_EQUAL(consoleFontInfoEx.dwFontSize.Y, 0);
    ASSERT_EQUAL(consoleFontInfoEx.FontFamily, 0u);
    ASSERT_EQUAL(consoleFontInfoEx.FontWeight, 0u);
}
