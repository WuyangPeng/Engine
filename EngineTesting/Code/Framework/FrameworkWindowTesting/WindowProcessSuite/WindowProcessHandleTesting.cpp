///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/10 15:45)

#include "WindowProcessHandleTesting.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/WindowProcess/WindowProcessHandleDetail.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

using namespace std::literals;

Framework::WindowProcessHandleTesting::WindowProcessHandleTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowProcessHandleTesting)

void Framework::WindowProcessHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowProcessHandleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ClassNameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(HWndTest);
}

void Framework::WindowProcessHandleTesting::BaseTest()
{
    const EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    WindowProcessInterface process{ System::gMicroseconds / 60, environmentDirectory };

    ASSERT_UNEQUAL_NULL_PTR(process.GetFunction());
    ASSERT_UNEQUAL_NULL_PTR(process.GetProcess());

    ASSERT_TRUE(process.PreCreate());
    ASSERT_TRUE(process.Initialize());
    process.PreIdle();
    process.Terminate();
}

void Framework::WindowProcessHandleTesting::ClassNameTest()
{
    System::String className{};
    ASSERT_TRUE(System::GetSystemClassName(hWnd, className));

    const EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    WindowProcessInterface process{ System::gMicroseconds / 60, environmentDirectory };

    ASSERT_TRUE(process.IsClassNameExist(className));

    const auto newClassName = SYSTEM_TEXT("New Class 2"s);

    ASSERT_TRUE(process.SetNewClassName(newClassName));

    ASSERT_TRUE(process.IsClassNameExist(newClassName));
}

void Framework::WindowProcessHandleTesting::HWndTest()
{
    const EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    WindowProcessInterface process{ System::gMicroseconds / 60, environmentDirectory };

    ASSERT_EQUAL_NULL_PTR(process.GetMainWindowHWnd());
}
