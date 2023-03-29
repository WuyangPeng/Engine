///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/12 15:58)

#include "LogFileMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LogFileMacroTesting::LogFileMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
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
    LOG_SINGLETON_FILE_APPENDER(Info, CoreTools, SYSTEM_TEXT("LogMacro"), SYSTEM_TEXT("����LogMacro��������־��д����־�ļ�LogMacro��"));

    LOG_SINGLETON_FILE_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED, SYSTEM_TEXT("LogMacro"), SYSTEM_TEXT("����LogMacro��������־��д����־�ļ�LogMacro��"));
}
