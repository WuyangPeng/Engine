/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 10:59)

#include "LogDefaultMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LogDefaultMacroTesting::LogDefaultMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
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
    LOG_SINGLETON_APPENDER(Info, CoreTools, SYSTEM_TEXT("测试LogMacro，这条日志会写入已配置的日志文件和控制台。"));

    LOG_SINGLETON_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED, SYSTEM_TEXT("测试LogMacro，这条日志会写入已配置的日志文件和控制台。"));
}
