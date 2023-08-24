///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 11:35)

#include "Framework/FrameworkExport.h"

#include "WindowMessageInterface.h"
#include "System/Helper/Tools.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

Framework::WindowMessageInterface::WindowMessageInterface(int64_t delta) noexcept
    : windowsHWnd{ nullptr }, delta{ delta }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowMessageInterface::WindowMessageInterface(int64_t delta, const EnvironmentDirectory& environmentDirectory) noexcept
    : WindowMessageInterface{ delta }
{
    System::UnusedFunction(environmentDirectory);

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

System::WindowsLResult Framework::WindowMessageInterface::CreateMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    // 只保存第一个创建窗口的HWnd
    if (windowsHWnd == nullptr)
    {
        windowsHWnd = hWnd;
    }

    CoreTools::DisableNoexcept();

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::Create, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::SizeMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::Size, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::CloseMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::Close, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::MoveMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::Move, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::CharMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::Char, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::KeyDownMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::KeyDown, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::KeyUpMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::KeyUp, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::LeftButtonDownMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::LButtonDown, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::LeftButtonUpMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::LButtonUp, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::MiddleButtonDownMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::MButtonDown, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::MiddleButtonUpMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::MButtonUp, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::RightButtonDownMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::RButtonDown, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::RightButtonUpMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::RButtonUp, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::MouseMoveMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::MouseMove, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::MouseWheelMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::MouseWheel, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::DestroyMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    // 只收到主窗口销毁时才退出程序。
    if (hWnd == windowsHWnd)
    {
        windowsHWnd = nullptr;

        return System::PostSystemQuitMessage();
    }
    else
    {
        return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::Destroy, wParam, lParam);
    }
}

System::WindowsLResult Framework::WindowMessageInterface::PaintMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::Paint, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageInterface::EraseBackgroundMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    return DefaultSystemWindowProcess(hWnd, System::WindowsMessages::EraseBackground, wParam, lParam);
}

void Framework::WindowMessageInterface::Display(HWnd hWnd, int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    System::UnusedFunction(hWnd, timeDelta);
}

int Framework::WindowMessageInterface::GetTerminateKey() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return WindowApplicationTrait::KeyIdentifiers::keyTerminate;
}

System::WindowsHWnd Framework::WindowMessageInterface::GetHWnd() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return windowsHWnd;
}

void Framework::WindowMessageInterface::SetMainWindow(HWnd hWnd)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowsHWnd == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("窗口还未创建！"))
    }

    // 修改主窗口
    windowsHWnd = hWnd;

    CoreTools::DisableNoexcept();
}

int64_t Framework::WindowMessageInterface::GetDelta() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return delta;
}
