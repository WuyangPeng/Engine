///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:25)

#include "ExceptionMacroTesting.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ExceptionMacroTesting::ExceptionMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ExceptionMacroTesting)

void CoreTools::ExceptionMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ExceptionMacroTesting::MainTest()
{
    ASSERT_THROW_EXCEPTION_0(ThrowErrorTest);
    ASSERT_THROW_EXCEPTION_0(ThrowWindowsErrorTest);
    ASSERT_THROW_EXCEPTION_0(ThrowComErrorTest);
}

void CoreTools::ExceptionMacroTesting::ThrowErrorTest()
{
    THROW_EXCEPTION(SYSTEM_TEXT("��������׳��쳣��"));
}

void CoreTools::ExceptionMacroTesting::ThrowWindowsErrorTest()
{
    THROW_WINDOWS_EXCEPTION;
}

void CoreTools::ExceptionMacroTesting::ThrowComErrorTest()
{
    THROW_LAST_ERROR_EXCEPTION(System::WindowError::EUnexpected, SYSTEM_TEXT("��������׳�COM�쳣��"));
}
