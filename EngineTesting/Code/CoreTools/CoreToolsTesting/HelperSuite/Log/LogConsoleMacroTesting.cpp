/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 10:59)

#include "LogConsoleMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LogConsoleMacroTesting::LogConsoleMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogConsoleMacroTesting)

void CoreTools::LogConsoleMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogConsoleMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConsoleLogTest);
}

void CoreTools::LogConsoleMacroTesting::ConsoleLogTest() noexcept
{
    LOG_SINGLETON_CONSOLE_APPENDER(Info, CoreTools, SYSTEM_TEXT("测试LogMacro，这条日志会写入控制台。"));

    LOG_SINGLETON_CONSOLE_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED, SYSTEM_TEXT("测试LogMacro，这条日志会写入控制台。"));
}
