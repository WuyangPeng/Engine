///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:30)

#include "LogFileMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LogFileMacroTesting::LogFileMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogFileMacroTesting)

void CoreTools::LogFileMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogFileMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileLogTest);
}

void CoreTools::LogFileMacroTesting::FileLogTest() noexcept
{
    LOG_SINGLETON_FILE_APPENDER(Info, CoreTools, SYSTEM_TEXT("LogMacro"))
        << SYSTEM_TEXT("����LogMacro��������־��д����־�ļ�LogMacro��")
        << CoreTools::LogAppenderIOManageSign::Refresh;

    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;

    LOG_SINGLETON_FILE_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, functionDescribed, SYSTEM_TEXT("LogMacro"))
        << SYSTEM_TEXT("����LogMacro��������־��д����־�ļ�LogMacro��")
        << CoreTools::LogAppenderIOManageSign::Refresh;
}
