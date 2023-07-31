///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:09)

#include "Framework/FrameworkExport.h"

#include "WindowMessageInterface.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

Framework::WindowMessageInterface::WindowMessageInterface(int64_t delta) noexcept
    : windowsHwnd{ nullptr }, delta{ delta }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowMessageInterface::WindowMessageInterface(int64_t delta, MAYBE_UNUSED const EnvironmentDirectory& environmentDirectory) noexcept
    : WindowMessageInterface{ delta }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowMessageInterface)

bool Framework::WindowMessageInterface::PreCreate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::WindowMessageInterface::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

void Framework::WindowMessageInterface::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

void Framework::WindowMessageInterface::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

System::WindowsLResult Framework::WindowMessageInterface::CreateMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    // 只保存第一个创建窗口的HWnd
    if (windowsHwnd == nullptr)
    {
        windowsHwnd = hwnd;
    }

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::Create, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::SizeMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::Size, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::CloseMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::Close, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::MoveMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::Move, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::CharMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::Char, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::KeyDownMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::KeyDown, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::KeyUpMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::KeyUp, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::LeftButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::LButtonDown, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::LeftButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::LButtonUp, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::MiddleButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::MButtonDown, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::MiddleButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::MButtonUp, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::RightButtonDownMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::RButtonDown, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::RightButtonUpMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::RButtonUp, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::MouseMoveMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::MouseMove, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::MouseWheelMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::MouseWheel, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::DestroyMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    // 只收到主窗口销毁时才退出程序。
    if (hwnd == windowsHwnd)
    {
        windowsHwnd = nullptr;

        return System::PostSystemQuitMessage();
    }
    else
    {
        return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::Destroy, wParam, lParam);
    }
}

System::WindowsLResult Framework::WindowMessageInterface::PaintMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::Paint, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::EraseBackgroundMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();

    return System::DefaultSystemWindowProcess(hwnd, System::WindowsMessages::EraseBackground, wParam, lParam);
}

void Framework::WindowMessageInterface::Display([[maybe_unused]] HWnd hwnd, [[maybe_unused]] int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    CoreTools::DisableNoexcept();
}

int Framework::WindowMessageInterface::GetTerminateKey() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return WindowApplicationTrait::KeyIdentifiers::keyTerminate;
}

System::WindowsHWnd Framework::WindowMessageInterface::GetHwnd() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return windowsHwnd;
}

void Framework::WindowMessageInterface::SetMainWindow(HWnd hwnd)
{
    FRAMEWORK_CLASS_IS_VALID_9;
    FRAMEWORK_ASSERTION_2(windowsHwnd != nullptr, "窗口还未创建！");

    // 修改主窗口
    windowsHwnd = hwnd;

    CoreTools::DisableNoexcept();
}

int64_t Framework::WindowMessageInterface::GetDelta() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return delta;
}
