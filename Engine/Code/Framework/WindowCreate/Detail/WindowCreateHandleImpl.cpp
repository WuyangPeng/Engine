///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 15:51)

#include "Framework/FrameworkExport.h"

#include "WindowCreateHandleImpl.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/WindowProcess/WindowProcessManager.h"

Framework::WindowCreateHandleImpl::WindowCreateHandleImpl(WindowInstanceParameter windowInstanceParameter, WindowCreateParameter windowCreateParameter, const WindowSize& size)
    : windowInstanceParameter{ std::move(windowInstanceParameter) }, windowCreateParameter{ std::move(windowCreateParameter) }, size{ size }, hWnd{ nullptr }
{
    InitInstance();

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

void Framework::WindowCreateHandleImpl::InitInstance()
{
    // 要求窗口有指定的客户区大小。
    System::WindowsRect rect{ 0, 0, size.GetWindowWidth() - 1, size.GetWindowHeight() - 1 };

    if (!AdjustSystemWindowRect(&rect, windowCreateParameter.GetStyle()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取窗口大小失败！"s))
    }

    const auto windowClassName = windowInstanceParameter.GetWindowClassName();
    const auto windowsName = windowCreateParameter.GetWindowsName();

    // 创建应用程序窗口。
    hWnd = CreateSystemWindow(windowClassName,
                              windowsName,
                              windowCreateParameter.GetStyle(),
                              windowCreateParameter.GetLeftTopCorner().GetWindowX(),
                              windowCreateParameter.GetLeftTopCorner().GetWindowY(),
                              rect,
                              windowCreateParameter.GetParent(),
                              windowCreateParameter.GetMenu(),
                              windowInstanceParameter.GetHInstance());

    if (hWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("创建窗口失败！"s))
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowCreateHandleImpl::IsValid() const noexcept
{
    if (hWnd != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Framework::WindowCreateHandleImpl::WindowsHWnd Framework::WindowCreateHandleImpl::GetHWnd() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return hWnd;
}

void Framework::WindowCreateHandleImpl::SetMainWindow()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    WINDOW_PROCESS_MANAGER_SINGLETON.SetMainWindowHWnd(hWnd);
}
