///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	°æ±¾£º0.9.1.2 (2023/07/28 13:36)

#include "WindowMessageLoop1.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
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
    const auto hWnd = GetHWnd();

    System::String className{};

    if (!System::GetSystemClassName(hWnd, className))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("GetSystemClassName Ê§°Ü¡£"));
    }

    EnterOldMessageLoop(className);
    EnterNewMessageLoop(className);

    return 0;
}

void Framework::WindowMessageLoop1::DisplayFunction(WindowsHWnd hWnd, int64_t timeDelta) noexcept
{
    System::UnusedFunction(hWnd, timeDelta);
}

void Framework::WindowMessageLoop1::EnterOldMessageLoop(const String& className)
{
    const auto instance = System::GetHInstance();

    WindowMessageLoop loop{ nullptr };

    const auto windowName = SYSTEM_TEXT("Open Old Message Window"s);

    const WindowSize size{ 800, 600 };
    const WindowCreateParameter createParameter{ windowName };
    const WindowInstanceParameter instanceParameter{ instance, className };
    const WindowCreateHandle create{ instanceParameter, createParameter, size };

    if (!loop.EnterMessageLoop(create.GetHWnd()))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("EnterMessageLoop Ê§°Ü¡£"));
    }
}

void Framework::WindowMessageLoop1::EnterNewMessageLoop(const String& className)
{
    const auto instance = System::GetHInstance();

    WindowMessageLoop loop{ DisplayFunction };

    const auto windowName = SYSTEM_TEXT("Open New Message Window"s);

    const WindowSize size{ 800, 600 };
    const WindowCreateParameter createParameter{ windowName };
    const WindowInstanceParameter instanceParameter{ instance, className };
    const WindowCreateHandle create{ instanceParameter, createParameter, size };

    if (!loop.EnterMessageLoop(create.GetHWnd()))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("EnterMessageLoop Ê§°Ü¡£"));
    }
}
