///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:30)

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
