/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/13 10:59)

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
    LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools, SYSTEM_TEXT("����LogMacro��������־��д����־�ļ�CoreTools�Ϳ���̨��"));

    LOG_SINGLETON_ENGINE_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED, SYSTEM_TEXT("����LogMacro��������־��д����־�ļ�CoreTools�Ϳ���̨��"));
}
