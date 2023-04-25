///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 21:06)

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
    LOG_SINGLETON_APPENDER(Info, CoreTools, SYSTEM_TEXT("����LogMacro��������־��д�������õ���־�ļ��Ϳ���̨��"));

    LOG_SINGLETON_APPENDER_USE_FUNCTION_DESCRIBED(Info, CoreTools, CORE_TOOLS_FUNCTION_DESCRIBED, SYSTEM_TEXT("����LogMacro��������־��д�������õ���־�ļ��Ϳ���̨��"));
}
