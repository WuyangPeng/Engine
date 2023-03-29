///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/12 16:03)

#include "LogEngineMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LogEngineMacroTesting::LogEngineMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogEngineMacroTesting)

void CoreTools::LogEngineMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogEngineMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EngineLogTest);
}

void CoreTools::LogEngineMacroTesting::EngineLogTest() noexcept
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools, SYSTEM_TEXT("测试LogMacro，这条日志会写入日志文件CoreTools和控制台。"));

    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED, SYSTEM_TEXT("测试LogMacro，这条日志会写入日志文件CoreTools和控制台。"));
}
