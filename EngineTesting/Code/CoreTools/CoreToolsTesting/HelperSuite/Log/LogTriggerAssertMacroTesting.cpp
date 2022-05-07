///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/14 20:37)

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
        << SYSTEM_TEXT("����LogMacro��������־�ᴥ�����ԣ��밴����ȡ����")
        << LOG_SINGLETON_TRIGGER_ASSERT;
}