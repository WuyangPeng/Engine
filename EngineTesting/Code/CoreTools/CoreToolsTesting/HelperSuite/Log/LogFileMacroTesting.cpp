/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 11:00)

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
    LOG_SINGLETON_FILE_APPENDER(Info, CoreTools, SYSTEM_TEXT("LogMacro"), SYSTEM_TEXT("测试LogMacro，这条日志会写入日志文件LogMacro。"));

    LOG_SINGLETON_FILE_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED, SYSTEM_TEXT("LogMacro"), SYSTEM_TEXT("测试LogMacro，这条日志会写入日志文件LogMacro。"));
}
