///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/14 20:37)

#include "LogFileAndConsoleMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LogFileAndConsoleMacroTesting::LogFileAndConsoleMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogFileAndConsoleMacroTesting)

void CoreTools::LogFileAndConsoleMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogFileAndConsoleMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileAndConsoleLogTest);
}

void CoreTools::LogFileAndConsoleMacroTesting::FileAndConsoleLogTest() noexcept
{
    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Info, CoreTools, SYSTEM_TEXT("LogMacro"))
        << SYSTEM_TEXT("����LogMacro��������־��д����־�ļ�LogMacro�Ϳ���̨��")
        << CoreTools::LogAppenderIOManageSign::Refresh;

    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;

    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, functionDescribed, SYSTEM_TEXT("LogMacro"))
        << SYSTEM_TEXT("����LogMacro��������־��д����־�ļ�LogMacro�Ϳ���̨��")
        << CoreTools::LogAppenderIOManageSign::Refresh;
}
