///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:30)

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
        << SYSTEM_TEXT("测试LogMacro，这条日志会写入日志文件LogMacro和控制台。")
        << CoreTools::LogAppenderIOManageSign::Refresh;

    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;

    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, functionDescribed, SYSTEM_TEXT("LogMacro"))
        << SYSTEM_TEXT("测试LogMacro，这条日志会写入日志文件LogMacro和控制台。")
        << CoreTools::LogAppenderIOManageSign::Refresh;
}
