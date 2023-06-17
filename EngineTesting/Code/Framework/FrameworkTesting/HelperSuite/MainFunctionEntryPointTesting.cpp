///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 20:18)

#include "MainFunctionEntryPointTesting.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/FileManager/Directory.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Framework::MainFunctionEntryPointTesting::MainFunctionEntryPointTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MainFunctionEntryPointTesting)

void Framework::MainFunctionEntryPointTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::MainFunctionEntryPointTesting::MainTest()
{
    CoreTools::Directory directory{ System::GetEngineeringDirectory() };

    // 入口点函数WinMainEntryPoint、MainEntryPoint、GlutMainEntryPoint和AndroidMainEntryPoint使用工具箱调用，
    // 无法单独运行单元测试。

    ASSERT_NOT_THROW_EXCEPTION_0(WinMainEntryPoint1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(WinMainEntryPoint2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(MainEntryPoint1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(GlutMainEntryPoint1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidMainEntryPoint1Test);
}

void Framework::MainFunctionEntryPointTesting::WinMainEntryPoint1Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("WinMainEntryPoint1")));
}

void Framework::MainFunctionEntryPointTesting::WinMainEntryPoint2Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("WinMainEntryPoint2")));
}

void Framework::MainFunctionEntryPointTesting::MainEntryPoint1Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("MainEntryPoint1")));
}

void Framework::MainFunctionEntryPointTesting::GlutMainEntryPoint1Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("GlutMainEntryPoint1")));
}

void Framework::MainFunctionEntryPointTesting::AndroidMainEntryPoint1Test()
{
    ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("AndroidMainEntryPoint1")));
}
