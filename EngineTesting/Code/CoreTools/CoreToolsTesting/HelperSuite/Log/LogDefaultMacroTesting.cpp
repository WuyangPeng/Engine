///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/14 20:37)

#include "LogDefaultMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LogDefaultMacroTesting::LogDefaultMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogDefaultMacroTesting)

void CoreTools::LogDefaultMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogDefaultMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultLogTest);
}

void CoreTools::LogDefaultMacroTesting::DefaultLogTest() noexcept
{
    LOG_SINGLETON_APPENDER(Info, CoreTools)
        << SYSTEM_TEXT("测试LogMacro，这条日志会写入已配置的日志文件和控制台。")
        << CoreTools::LogAppenderIOManageSign::Refresh;

    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;

    LOG_SINGLETON_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, functionDescribed)
        << SYSTEM_TEXT("测试LogMacro，这条日志会写入已配置的日志文件和控制台。")
        << CoreTools::LogAppenderIOManageSign::Refresh;
}
