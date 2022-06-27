///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 11:04)

#include "MainFunctionTesting.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/FileManager/Directory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::MainFunctionTesting::MainFunctionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MainFunctionTesting)

void Framework::MainFunctionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::MainFunctionTesting::MainTest()
{
    CoreTools::Directory directory{ System::GetEngineeringDirectory() };

    // 宏WINDOWS_MAIN_FUNCTION_WITH_INFORMATION、WINDOWS_MAIN_FUNCTION_USE_PARAMETER、CONSOLE_MAIN_FUNCTION、
    // GLUT_CONSOLE_MAIN_FUNCTION和ANDROID_MAIN_FUNCTION使用工具箱调用，
    // 无法单独运行单元测试。

    ASSERT_NOT_THROW_EXCEPTION_0(WinMainEntryPoint3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WinMainEntryPoint4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(MainEntryPoint2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GlutMainEntryPoint2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidMainEntryPoint2Test);
}

void Framework::MainFunctionTesting::WinMainEntryPoint3Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("WinMainEntryPoint3")));
}

void Framework::MainFunctionTesting::WinMainEntryPoint4Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("WinMainEntryPoint4")));
}

void Framework::MainFunctionTesting::MainEntryPoint2Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("MainEntryPoint2")));
}

void Framework::MainFunctionTesting::GlutMainEntryPoint2Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("GlutMainEntryPoint2")));
}

void Framework::MainFunctionTesting::AndroidMainEntryPoint2Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("AndroidMainEntryPoint2")));
}
