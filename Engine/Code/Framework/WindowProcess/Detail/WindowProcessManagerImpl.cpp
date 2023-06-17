///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:09)

#include "Framework/FrameworkExport.h"

#include "WindowProcessManagerImpl.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

Framework::WindowMessageInterfaceSharedPtr Framework::WindowProcessManagerImpl::windowProcessMessage{};

int Framework::WindowProcessManagerImpl::windowMessageIndex{};

// static
// private
Framework::WindowProcessManagerImpl::ClassNameContainerSharedPtr Framework::WindowProcessManagerImpl::GetClassNameContainer()
{
    static auto classNameContainer = std::make_shared<ClassNameContainer>();

    return classNameContainer;
}

// static
// private
Framework::WindowProcessManagerImpl::MessageFunctionPointerContainerSharedPtr Framework::WindowProcessManagerImpl::GetMessageFunctionPointer()
{
    static MessageFunctionPointerContainer messageFunctionPointerContainer{ { System::WindowsMessages::Paint, &WindowMessageInterface::PaintMessage },
                                                                            { System::WindowsMessages::EraseBkgnd, &WindowMessageInterface::EraseBackgroundMessage },
                                                                            { System::WindowsMessages::Move, &WindowMessageInterface::MoveMessage },
                                                                            { System::WindowsMessages::Size, &WindowMessageInterface::SizeMessage },
                                                                            { System::WindowsMessages::Char, &WindowMessageInterface::CharMessage },
                                                                            { System::WindowsMessages::KeyDown, &WindowMessageInterface::KeyDownMessage },
                                                                            { System::WindowsMessages::KeyUp, &WindowMessageInterface::KeyUpMessage },
                                                                            { System::WindowsMessages::LButtonDown, &WindowMessageInterface::LeftButtonDownMessage },
                                                                            { System::WindowsMessages::LButtonUp, &WindowMessageInterface::LeftButtonUpMessage },
                                                                            { System::WindowsMessages::MButtonDown, &WindowMessageInterface::MiddleButtonDownMessage },
                                                                            { System::WindowsMessages::MButtonUp, &WindowMessageInterface::MiddleButtonUpMessage },
                                                                            { System::WindowsMessages::RButtonDown, &WindowMessageInterface::RightButtonDownMessage },
                                                                            { System::WindowsMessages::RButtonUp, &WindowMessageInterface::RightButtonUpMessage },
                                                                            { System::WindowsMessages::MouseMove, &WindowMessageInterface::MouseMoveMessage },
                                                                            { System::WindowsMessages::MouseWheel, &WindowMessageInterface::MouseWheelMessage },
                                                                            { System::WindowsMessages::Create, &WindowMessageInterface::CreateMessage },
                                                                            { System::WindowsMessages::Close, &WindowMessageInterface::CloseMessage },
                                                                            { System::WindowsMessages::Destroy, &WindowMessageInterface::DestroyMessage } };

    static auto functionPointer = make_shared<MessageFunctionPointerContainer>(messageFunctionPointerContainer);

    return functionPointer;
}

// static
// private
Framework::WindowProcessManagerImpl::WindowMessageContainerSharedPtr Framework::WindowProcessManagerImpl::GetWindowMessageContainer()
{
    static auto windowMessageContainer = std::make_shared<WindowMessageContainer>();

    return windowMessageContainer;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowProcessManagerImpl)

// static
Framework::WindowProcessManagerImpl::WindowProcess Framework::WindowProcessManagerImpl::GetProcess() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return WindowProc;
}

// static
Framework::WindowProcessManagerImpl::DisplayFunction Framework::WindowProcessManagerImpl::GetFunction() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return Display;
}

// static
bool Framework::WindowProcessManagerImpl::IsClassNameExist(const String& className)
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    auto classNameContainer = GetClassNameContainer();

    const auto iter = classNameContainer->find(className);

    if (iter != classNameContainer->cend())
        return true;

    return false;
}

// static
bool Framework::WindowProcessManagerImpl::SetNewClassName(const String& className)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    auto classNameContainer = GetClassNameContainer();

    if (classNameContainer->insert(className).second)
        return true;
    else
        return false;
}

Framework::ConstWindowMessageInterfaceSharedPtr Framework::WindowProcessManagerImpl::GetWindowMessageInterface() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return windowProcessMessage;
}

void Framework::WindowProcessManagerImpl::SetWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowProcessMessage != nullptr)
    {
        auto windowMessageContainer = GetWindowMessageContainer();

        windowMessageContainer->insert({ windowMessageIndex++, windowProcessMessage });
    }

    windowProcessMessage = windowMessage;
}

void Framework::WindowProcessManagerImpl::ClearWindowMessage(const WindowMessageInterfaceSharedPtr& windowMessage)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowProcessMessage == windowMessage)
    {
        ResetMainWindowMessage();
    }
    else
    {
        ClearWindowMessageContainer(windowMessage);
    }
}

void Framework::WindowProcessManagerImpl::ResetMainWindowMessage()
{
    windowProcessMessage.reset();

    auto windowMessageContainer = GetWindowMessageContainer();

    for (auto iter = windowMessageContainer->begin(); iter != windowMessageContainer->end(); ++iter)
    {
        auto nextWindowMessage = iter->second.lock();
        if (nextWindowMessage != nullptr)
        {
            windowProcessMessage = nextWindowMessage;
            windowMessageContainer->erase(iter);
            break;
        }
    }
}

void Framework::WindowProcessManagerImpl::ClearWindowMessageContainer(const WindowMessageInterfaceSharedPtr& windowMessage)
{
    auto windowMessageContainer = GetWindowMessageContainer();

    for (auto iter = windowMessageContainer->begin(); iter != windowMessageContainer->end();)
    {
        auto nextWindowMessage = iter->second.lock();
        if (nextWindowMessage == nullptr || nextWindowMessage == windowMessage)
        {
            windowMessageContainer->erase(iter++);
        }
        else
        {
            ++iter;
        }
    }
}

bool Framework::WindowProcessManagerImpl::PreCreate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowProcessMessage)
    {
        return windowProcessMessage->PreCreate();
    }
    else
    {
        return false;
    }
}

bool Framework::WindowProcessManagerImpl::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowProcessMessage)
    {
        return windowProcessMessage->Initialize();
    }
    else
    {
        return false;
    }
}

void Framework::WindowProcessManagerImpl::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowProcessMessage)
    {
        return windowProcessMessage->PreIdle();
    }
}

void Framework::WindowProcessManagerImpl::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowProcessMessage)
    {
        windowProcessMessage->Terminate();
    }
}

void Framework::WindowProcessManagerImpl::SetMainWindowHwnd(HWnd hwnd)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowProcessMessage)
    {
        windowProcessMessage->SetMainWindow(hwnd);
    }
}

Framework::WindowProcessManagerImpl::HWnd Framework::WindowProcessManagerImpl::GetMainWindowHwnd() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return windowProcessMessage->GetHwnd();
}

// static
// private
Framework::WindowProcessManagerImpl::LResult SYSTEM_CALL_BACK Framework::WindowProcessManagerImpl::WindowProc(HWnd hwnd, UInt message, WParam wParam, LParam lParam)
{
    EXCEPTION_TRY
    {
        auto messageFunctionPointer = GetMessageFunctionPointer();

        const auto flag = System::UnderlyingCastEnum<System::WindowsMessages>(message);

        const auto iter = messageFunctionPointer->find(flag);

        if (windowProcessMessage && iter != messageFunctionPointer->cend())
        {
            return ((*windowProcessMessage).*(iter->second))(hwnd, wParam, lParam);
        }

        return System::DefaultSystemWindowProcess(hwnd, flag, wParam, lParam);
    }
    EXCEPTION_ALL_CATCH(Framework)

    return 0;
}

// static
// private
void Framework::WindowProcessManagerImpl::Display(HWnd hwnd, int64_t timeDelta)
{
    if (windowProcessMessage)
    {
        windowProcessMessage->Display(hwnd, timeDelta);
    }
}

Framework::WindowProcessManagerImpl::WindowProcessManagerImpl() noexcept
{
}
