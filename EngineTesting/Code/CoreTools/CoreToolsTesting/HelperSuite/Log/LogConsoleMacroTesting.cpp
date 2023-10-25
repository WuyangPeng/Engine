///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 16:03)

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
    LOG_SINGLETON_CONSOLE_APPENDER(Info, CoreTools, SYSTEM_TEXT("����LogMacro��������־��д�����̨��"));

    LOG_SINGLETON_CONSOLE_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED, SYSTEM_TEXT("����LogMacro��������־��д�����̨��"));
}
