// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.2 (2020/06/04 13:09)

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
    [[maybe_unused]] const auto value = System::GetSystemClassName(hwnd, className);

    EnterOldMessageLoop(className);
    EnterNewMessageLoop(className);

    return 0;
}

#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26461)
void Framework::WindowMessageLoop1::DisplayFunction([[maybe_unused]] WindowsHWnd hwnd, [[maybe_unused]] int64_t timeDelta) noexcept
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
