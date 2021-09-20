///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.3 (2021/05/23 23:10)

#include "WindowsSystemProgrammingCodeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookOperatingSystem/WindowsSystemProgramming/Code/CodeMain.h"
#include "Example/BookOperatingSystem/WindowsSystemProgramming/Helper/WindowsSystemProgrammingClassInvariantMacro.h"

namespace BookWindowsAPI
{
    using TestingType = WindowsSystemProgramming::CodeMain;
}

BookWindowsAPI::WindowsSystemProgrammingCodeTesting::WindowsSystemProgrammingCodeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    WINDOWS_SYSTEM_PROGRAMMING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookWindowsAPI, WindowsSystemProgrammingCodeTesting)

void BookWindowsAPI::WindowsSystemProgrammingCodeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookWindowsAPI::WindowsSystemProgrammingCodeTesting::MainTest()
{
    TestingType codeMain{};

    ASSERT_TRUE(codeMain.Main());
    ASSERT_TRUE(codeMain.ExecuteChapter1());
}
