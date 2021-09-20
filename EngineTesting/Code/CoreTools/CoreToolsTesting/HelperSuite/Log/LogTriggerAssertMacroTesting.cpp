///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/14 20:37)

#include "LogTriggerAssertMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LogTriggerAssertMacroTesting::LogTriggerAssertMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogTriggerAssertMacroTesting)

void CoreTools::LogTriggerAssertMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogTriggerAssertMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TriggerAssertTest);
}

void CoreTools::LogTriggerAssertMacroTesting::TriggerAssertTest() noexcept
{
    LOG_SINGLETON_APPENDER(Info, CoreTools)
        << SYSTEM_TEXT("测试LogMacro，这条日志会触发断言，请按“否”取消。")
        << LOG_SINGLETON_TRIGGER_ASSERT;
}
