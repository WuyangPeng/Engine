/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:30)

#include "Framework/FrameworkExport.h"

#include "WindowProcessManagerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

Framework::WindowMessageInterfaceSharedPtr Framework::WindowProcessManagerImpl::windowProcessMessage{};

int Framework::WindowProcessManagerImpl::windowMessageIndex{};

Framework::WindowProcessManagerImpl::ClassNameContainerSharedPtr Framework::WindowProcessManagerImpl::GetClassNameContainer()
{
    static auto classNameContainer = std::make_shared<ClassNameContainer>();

    return classNameContainer;
}

Framework::WindowProcessManagerImpl::MessageFunctionPointerContainerSharedPtr Framework::WindowProcessManagerImpl::GetMessageFunctionPointer()
{
    static MessageFunctionPointerContainer messageFunctionPointerContainer{ { System::WindowsMessages::Paint, &WindowMessageInterface::PaintMessage },
                                                                            { System::WindowsMessages::EraseBackground, &WindowMessageInterface::EraseBackgroundMessage },
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

Framework::WindowProcessManagerImpl::WindowMessageContainerSharedPtr Framework::WindowProcessManagerImpl::GetWindowMessageContainer()
{
    static auto windowMessageContainer = std::make_shared<WindowMessageContainer>();

    return windowMessageContainer;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowProcessManagerImpl)

Framework::WindowProcessManagerImpl::WindowProcess Framework::WindowProcessManagerImpl::GetProcess() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return WindowProcessFunction;
}

Framework::WindowProcessManagerImpl::DisplayFunction Framework::WindowProcessManagerImpl::GetFunction() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return Display;
}

bool Framework::WindowProcessManagerImpl::IsClassNameExist(const String& className)
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    const auto classNameContainer = GetClassNameContainer();

    if (const auto iter = classNameContainer->find(className);
        iter != classNameContainer->cend())
    {
        return true;
    }

    return false;
}

bool Framework::WindowProcessManagerImpl::SetNewClassName(const String& className)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (const auto classNameContainer = GetClassNameContainer();
        classNameContainer->insert(className).second)
    {
        return true;
    }

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
        const auto windowMessageContainer = GetWindowMessageContainer();

        windowMessageContainer->emplace(windowMessageIndex++, windowProcessMessage);
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

    const auto windowMessageContainer = GetWindowMessageContainer();

    for (auto iter = windowMessageContainer->begin(); iter != windowMessageContainer->end(); ++iter)
    {
        if (auto nextWindowMessage = iter->second.lock();
            nextWindowMessage != nullptr)
        {
            windowProcessMessage = nextWindowMessage;
            windowMessageContainer->erase(iter);
            break;
        }
    }
}

void Framework::WindowProcessManagerImpl::ClearWindowMessageContainer(const WindowMessageInterfaceSharedPtr& windowMessage)
{
    const auto windowMessageContainer = GetWindowMessageContainer();

    for (auto iter = windowMessageContainer->begin(); iter != windowMessageContainer->end();)
    {
        if (auto nextWindowMessage = iter->second.lock();
            nextWindowMessage == nullptr || nextWindowMessage == windowMessage)
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

void Framework::WindowProcessManagerImpl::SetMainWindowHWnd(WindowsHWnd hWnd)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (windowProcessMessage)
    {
        windowProcessMessage->SetMainWindow(hWnd);
    }
}

Framework::WindowProcessManagerImpl::WindowsHWnd Framework::WindowProcessManagerImpl::GetMainWindowHWnd() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return windowProcessMessage->GetHWnd();
}

Framework::WindowProcessManagerImpl::WindowsLResult SYSTEM_CALL_BACK Framework::WindowProcessManagerImpl::WindowProcessFunction(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam)
{
    EXCEPTION_TRY
    {
        return DoWindowProcessFunction(hWnd, message, wParam, lParam);
    }
    EXCEPTION_ALL_CATCH(Framework)

    return 0;
}

Framework::WindowProcessManagerImpl::WindowsLResult Framework::WindowProcessManagerImpl::DoWindowProcessFunction(WindowsHWnd hWnd, WindowsUInt message, WindowsWParam wParam, WindowsLParam lParam)
{
    const auto messageFunctionPointer = GetMessageFunctionPointer();

    const auto flag = System::UnderlyingCastEnum<System::WindowsMessages>(boost::numeric_cast<int>(message));

    if (const auto iter = messageFunctionPointer->find(flag);
        windowProcessMessage && iter != messageFunctionPointer->cend())
    {
        return ((*windowProcessMessage).*(iter->second))(hWnd, wParam, lParam);
    }

    return DefaultSystemWindowProcess(hWnd, flag, wParam, lParam);
}

void Framework::WindowProcessManagerImpl::Display(WindowsHWnd hWnd, int64_t timeDelta)
{
    if (windowProcessMessage)
    {
        windowProcessMessage->Display(hWnd, timeDelta);
    }
}
