/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 18:28)

#include "ConsoleFontSizeTesting.h"
#include "System/Console/ConsoleFont.h"
#include "System/Console/ConsoleHandle.h"
#include "System/Console/Flags/ConsoleHandleFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleFontSizeTesting::ConsoleFontSizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleFontSizeTesting)

void System::ConsoleFontSizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConsoleFontSizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CurrentConsoleFontSizeTest);
}

void System::ConsoleFontSizeTesting::CurrentConsoleFontSizeTest()
{
    const auto consoleHandle = GetStandardHandle(StandardHandle::Output);

    ConsoleFontInfo consoleFontInfo{};
    ASSERT_TRUE(GetCurrentSystemConsoleFont(consoleHandle, false, &consoleFontInfo));

    const auto [x, y] = GetSystemConsoleFontSize(consoleHandle, consoleFontInfo.nFont);

    ASSERT_EQUAL(x, consoleFontInfo.dwFontSize.X);
    ASSERT_EQUAL(y, consoleFontInfo.dwFontSize.Y);

    ASSERT_LESS_EQUAL(0, x);
    ASSERT_LESS(0, y);
}
