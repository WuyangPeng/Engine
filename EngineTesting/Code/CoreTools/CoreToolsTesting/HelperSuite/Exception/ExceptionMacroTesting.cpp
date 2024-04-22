/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 11:41)

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
    ASSERT_NOT_THROW_EXCEPTION_0(AssertFailThrowExceptionSuccessTest);
    ASSERT_THROW_EXCEPTION_0(AssertFailThrowExceptionFailTest);
}

void CoreTools::ExceptionMacroTesting::ThrowErrorTest()
{
    THROW_EXCEPTION(SYSTEM_TEXT("这里测试抛出异常。"))
}

void CoreTools::ExceptionMacroTesting::ThrowWindowsErrorTest()
{
    THROW_WINDOWS_EXCEPTION;
}

void CoreTools::ExceptionMacroTesting::ThrowComErrorTest()
{
    THROW_LAST_ERROR_EXCEPTION(System::WindowError::EUnexpected, SYSTEM_TEXT("这里测试抛出COM异常。"))
}

void CoreTools::ExceptionMacroTesting::AssertFailThrowExceptionSuccessTest()
{
    ASSERT_FAIL_THROW_EXCEPTION(true, SYSTEM_TEXT("这里测试抛出异常。"));
}

void CoreTools::ExceptionMacroTesting::AssertFailThrowExceptionFailTest()
{
    ASSERT_FAIL_THROW_EXCEPTION(false, SYSTEM_TEXT("这里测试抛出异常。"));
}
