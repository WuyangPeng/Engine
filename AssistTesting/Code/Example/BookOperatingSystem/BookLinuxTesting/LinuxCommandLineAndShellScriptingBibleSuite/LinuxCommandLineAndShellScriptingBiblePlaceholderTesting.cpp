///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.4 (2021/06/12 13:13)

#include "LinuxCommandLineAndShellScriptingBiblePlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/LinuxCommandLineAndShellScriptingBible/Helper/LinuxCommandLineAndShellScriptingBibleClassInvariantMacro.h"

BookLinux::LinuxCommandLineAndShellScriptingBible::LinuxCommandLineAndShellScriptingBiblePlaceholderTesting::LinuxCommandLineAndShellScriptingBiblePlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    LINUX_COMMAND_LINE_AND_SHELL_SCRIPTING_BIBLE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookLinux::LinuxCommandLineAndShellScriptingBible, LinuxCommandLineAndShellScriptingBiblePlaceholderTesting)

void BookLinux::LinuxCommandLineAndShellScriptingBible::LinuxCommandLineAndShellScriptingBiblePlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookLinux::LinuxCommandLineAndShellScriptingBible::LinuxCommandLineAndShellScriptingBiblePlaceholderTesting::MainTest() noexcept
{
}
