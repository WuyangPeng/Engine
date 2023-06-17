///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:13)

#include "Framework/FrameworkExport.h"

#include "WindowCreateHandleImpl.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

using namespace std::literals;

Framework::WindowCreateHandleImpl::WindowCreateHandleImpl(const WindowInstanceParameter& windowInstanceParameter, const WindowCreateParameter& windowCreateParameter, const WindowSize& size)
    : windowInstanceParameter{ windowInstanceParameter }, windowCreateParameter{ windowCreateParameter }, size{ size }, hwnd{ nullptr }
{
    InitInstance();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
void Framework::WindowCreateHandleImpl::InitInstance()
{
    // 要求窗口有指定的客户区大小。
    System::WindowsRect rect{ 0, 0, size.GetWindowWidth() - 1, size.GetWindowHeight() - 1 };

    if (!System::AdjustSystemWindowRect(&rect, windowCreateParameter.GetStyle()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取窗口大小失败！"s));
    }

    auto windowClassName = windowInstanceParameter.GetWindowClassName();
    auto windowsName = windowCreateParameter.GetWindowsName();

    // 创建应用程序窗口。
    hwnd = System::CreateSystemWindow(windowClassName.c_str(),
                                      windowsName.c_str(),
                                      windowCreateParameter.GetStyle(),
                                      windowCreateParameter.GetLeftTopCorner().GetWindowX(),
                                      windowCreateParameter.GetLeftTopCorner().GetWindowY(),
                                      rect,
                                      windowCreateParameter.GetParent(),
                                      windowCreateParameter.GetMenu(),
                                      windowInstanceParameter.GetHInstance());

    if (hwnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("创建窗口失败！"s));
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowCreateHandleImpl::IsValid() const noexcept
{
    if (hwnd != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Framework::WindowCreateHandleImpl::WindowsHWnd Framework::WindowCreateHandleImpl::GetHwnd() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return hwnd;
}

void Framework::WindowCreateHandleImpl::SetMainWindow()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    WINDOW_PROCESS_MANAGER_SINGLETON.SetMainWindowHwnd(hwnd);
}
