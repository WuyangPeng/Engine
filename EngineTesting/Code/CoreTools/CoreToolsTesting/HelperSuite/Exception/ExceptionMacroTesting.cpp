///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 16:23)

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
