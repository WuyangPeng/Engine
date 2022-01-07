///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.4 (2021/06/12 13:13)

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
