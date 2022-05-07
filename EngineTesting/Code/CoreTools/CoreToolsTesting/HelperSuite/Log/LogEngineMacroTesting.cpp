///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/14 20:37)

#include "LogEngineMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LogEngineMacroTesting::LogEngineMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
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
    LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
        << SYSTEM_TEXT("����LogMacro��������־��д����־�ļ�CoreTools�Ϳ���̨��")
        << CoreTools::LogAppenderIOManageSign::Refresh;

    const auto functionDescribed = CORE_TOOLS_FUNCTION_DESCRIBED;

    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, functionDescribed)
        << SYSTEM_TEXT("����LogMacro��������־��д����־�ļ�CoreTools�Ϳ���̨��")
        << CoreTools::LogAppenderIOManageSign::Refresh;
}