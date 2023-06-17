///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/13 17:26)

#include "WindowMessageLoop1.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

using namespace std::literals;

Framework::WindowMessageLoop1::WindowMessageLoop1(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ instance, commandLine, information, environmentDirectory }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowMessageLoop1)

int Framework::WindowMessageLoop1::EnterMessageLoop()
{
    auto hwnd = GetHwnd();

    System::String className{};
    MAYBE_UNUSED const auto value = System::GetSystemClassName(hwnd, className);

    EnterOldMessageLoop(className);
    EnterNewMessageLoop(className);

    return 0;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)

void Framework::WindowMessageLoop1::DisplayFunction(MAYBE_UNUSED WindowsHWnd hwnd, MAYBE_UNUSED int64_t timeDelta) noexcept
{
}

#include STSTEM_WARNING_POP

void Framework::WindowMessageLoop1::EnterOldMessageLoop(const String& className)
{
    auto instance = System::GetHInstance();

    WindowMessageLoop loop{ nullptr };

    auto windowName = SYSTEM_TEXT("Open Old Message Window"s);

    const WindowSize size{ 800, 600 };
    WindowCreateParameter createParameter{ windowName };
    WindowInstanceParameter instanceParameter{ instance, className };
    WindowCreateHandle create{ instanceParameter, createParameter, size };

    loop.EnterMessageLoop(create.GetHwnd());
}

void Framework::WindowMessageLoop1::EnterNewMessageLoop(const String& className)
{
    auto instance = System::GetHInstance();

    WindowMessageLoop loop{ DisplayFunction };

    auto windowName = SYSTEM_TEXT("Open New Message Window"s);

    const WindowSize size{ 800, 600 };
    WindowCreateParameter createParameter{ windowName };
    WindowInstanceParameter instanceParameter{ instance, className };
    WindowCreateHandle create{ instanceParameter, createParameter, size };

    loop.EnterMessageLoop(create.GetHwnd());
}
