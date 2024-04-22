/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 11:00)

#include "LogTriggerAssertMacroTesting.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LogTriggerAssertMacroTesting::LogTriggerAssertMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
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
    LOG_SINGLETON_APPENDER(Info, CoreTools, SYSTEM_TEXT("测试LogMacro，这条日志会触发断言，请按“否”取消。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
}

void CoreTools::LogTriggerAssertMacroTesting::PrintTipsMessage()
{
    GetStream() << "这个测试会触发失败断言，请按否取消。\n";

    System::SystemPause();
}