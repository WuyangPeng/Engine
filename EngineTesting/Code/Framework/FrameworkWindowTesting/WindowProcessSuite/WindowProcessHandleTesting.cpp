///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 14:00)

#include "WindowProcessHandleTesting.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/WindowProcess/WindowProcessHandleDetail.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

using std::const_pointer_cast;
using namespace std::literals;

namespace Framework
{
    using TestingType = WindowProcessInterface;
}

Framework::WindowProcessHandleTesting::WindowProcessHandleTesting(const OStreamShared& stream, HWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
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
    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    TestingType process{ System::g_Microseconds / 60, environmentDirectory };

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
    MAYBE_UNUSED const auto value = System::GetSystemClassName(hwnd, className);

    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    TestingType process{ System::g_Microseconds / 60, environmentDirectory };

    ASSERT_TRUE(process.IsClassNameExist(className));

    auto newClassName = SYSTEM_TEXT("New Class 2"s);

    ASSERT_TRUE(process.SetNewClassName(newClassName));

    ASSERT_TRUE(process.IsClassNameExist(newClassName));
}

void Framework::WindowProcessHandleTesting::HWndTest()
{
    EnvironmentDirectory environmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"s), SYSTEM_TEXT(""s) };
    TestingType process{ System::g_Microseconds / 60, environmentDirectory };

    ASSERT_EQUAL_NULL_PTR(process.GetMainWindowHwnd());
}
