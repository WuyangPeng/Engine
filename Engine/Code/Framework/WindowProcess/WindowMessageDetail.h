///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 13:42)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_DETAIL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_DETAIL_H

#include "VirtualKeysTypes.h"
#include "WindowMessage.h"
#include "Flags/MouseTypes.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "System/Windows/Flags/WindowsMessagesFlags.h"
#include "System/Windows/WindowsCreate.h"
#include "System/Windows/WindowsUser.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/WindowCreate/WindowSize.h"

template <typename MiddleLayer>
Framework::WindowMessage<MiddleLayer>::WindowMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, environmentDirectory }, middleLayer{ std::make_shared<MiddleLayer>(MiddleLayerPlatform::Windows, environmentDirectory) }, accumulative{ delta }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename MiddleLayer>
bool Framework::WindowMessage<MiddleLayer>::IsValid() const noexcept
{
    if (ParentType::IsValid() && middleLayer != nullptr && 0 <= accumulative)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename MiddleLayer>
bool Framework::WindowMessage<MiddleLayer>::PreCreate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return middleLayer->PreCreate();
}

template <typename MiddleLayer>
bool Framework::WindowMessage<MiddleLayer>::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return middleLayer->Initialize();
}

template <typename MiddleLayer>
void Framework::WindowMessage<MiddleLayer>::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    middleLayer->PreIdle();

    return ParentType::PreIdle();
}

template <typename MiddleLayer>
void Framework::WindowMessage<MiddleLayer>::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    middleLayer->Terminate();

    return ParentType::Terminate();
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::CreateMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    middleLayer->Create(Rendering::EnvironmentParameter::Create(hWnd));

    return ParentType::CreateMessage(hWnd, wParam, lParam);
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::SizeMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowSize clientSize{ lParam };

    middleLayer->Resize(boost::numeric_cast<System::WindowsDisplay>(wParam), clientSize);

    return ParentType::SizeMessage(hWnd, wParam, lParam);
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::CloseMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::UnusedFunction(wParam, lParam);

    DoCloseMessage(hWnd);

    return 0;
}

template <typename MiddleLayer>
void Framework::WindowMessage<MiddleLayer>::DoCloseMessage(HWnd hWnd) const
{
    const auto className = GetWindowsClassName(hWnd);

    const auto exitInformation = SYSTEM_TEXT("是否退出") + className + SYSTEM_TEXT("？");

    if (!System::SystemValidateRect(hWnd))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("SystemValidateRect 失败。"));
    }

    if (System::DefaultMessageBox(hWnd, exitInformation, className))
    {
        if (!System::DestroySystemWindow(hWnd))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("DestroySystemWindow 失败。"));
        }
    }
}

template <typename MiddleLayer>
System::String Framework::WindowMessage<MiddleLayer>::GetWindowsClassName(HWnd hWnd) const
{
    if (String name{};
        System::GetWindowTextString(hWnd, name))
    {
        return name;
    }
    else
    {
        return SYSTEM_TEXT("程序");
    }
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::CharMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    // 当Terminate键被按下时退出应用程序。
    if (const auto key = boost::numeric_cast<int>(wParam);
        key == GetTerminateKey())
    {
        if (!SendSystemMessage(hWnd, System::WindowsMessages::Close, 0, 0))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("SendSystemMessage 失败。"));
        }
    }
    else
    {
        // 获取客户端光标的位置。
        const auto point = GetCursorPosition(hWnd);

        middleLayer->KeyDown(key, point);
    }

    System::UnusedFunction(lParam);

    return 0;
}

template <typename MiddleLayer>
Framework::WindowPoint Framework::WindowMessage<MiddleLayer>::GetCursorPosition(HWnd hWnd) const noexcept
{
    System::WindowsPoint point{};
    if (!System::GetCursorClientPos(hWnd, point))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("GetCursorClientPos 失败。"));
    }

    return WindowPoint{ point };
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::MoveMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    middleLayer->Move(WindowPoint{ lParam });

    System::UnusedFunction(hWnd, wParam);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::KeyDownMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto virtualKey = boost::numeric_cast<int>(wParam);

    // 获取客户端光标的位置。
    const auto point = GetCursorPosition(hWnd);

    if (IsSpecialKey(virtualKey))
    {
        middleLayer->SpecialKeyDown(virtualKey, point);
    }

    // KeyDown在CharMessage上监听。

    System::UnusedFunction(lParam);

    return 0;
}

template <typename MiddleLayer>
bool Framework::WindowMessage<MiddleLayer>::IsSpecialKey(int virtualKey) const noexcept
{
    if (const auto windowsKeyCodes = System::UnderlyingCastEnum<System::WindowsKeyCodes>(virtualKey);
        (System::WindowsKeyCodes::F1 <= windowsKeyCodes) && (windowsKeyCodes <= System::WindowsKeyCodes::F12) ||
        (System::WindowsKeyCodes::Prior <= windowsKeyCodes) && (windowsKeyCodes <= System::WindowsKeyCodes::Down) ||
        (windowsKeyCodes == System::WindowsKeyCodes::Insert) ||
        (windowsKeyCodes == System::WindowsKeyCodes::Delete) ||
        (windowsKeyCodes == System::WindowsKeyCodes::Shift) ||
        (windowsKeyCodes == System::WindowsKeyCodes::Control))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::KeyUpMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto virtualKey = boost::numeric_cast<int>(wParam);

    // 获取客户端光标的位置。
    const auto point = GetCursorPosition(hWnd);

    if (IsSpecialKey(virtualKey))
    {
        middleLayer->SpecialKeyUp(virtualKey, point);
    }
    else
    {
        middleLayer->KeyUp(virtualKey, point);
    }

    System::UnusedFunction(lParam);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::LeftButtonDownMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ wParam };

    middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, windowPoint, virtualKeys);

    System::UnusedFunction(hWnd);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::LeftButtonUpMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ wParam };

    middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseUp, windowPoint, virtualKeys);

    System::UnusedFunction(hWnd);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::MiddleButtonDownMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ wParam };

    middleLayer->MouseClick(MouseButtonsTypes::MiddleButton, MouseStateTypes::MouseDown, windowPoint, virtualKeys);

    System::UnusedFunction(hWnd);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::MiddleButtonUpMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ wParam };

    middleLayer->MouseClick(MouseButtonsTypes::MiddleButton, MouseStateTypes::MouseUp, windowPoint, virtualKeys);

    System::UnusedFunction(hWnd);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::RightButtonDownMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ wParam };

    middleLayer->MouseClick(MouseButtonsTypes::RightButton, MouseStateTypes::MouseDown, windowPoint, virtualKeys);

    System::UnusedFunction(hWnd);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::RightButtonUpMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ wParam };

    middleLayer->MouseClick(MouseButtonsTypes::RightButton, MouseStateTypes::MouseUp, windowPoint, virtualKeys);

    System::UnusedFunction(hWnd);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::MouseMoveMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };

    if (const VirtualKeysTypes virtualKeys{ wParam };
        virtualKeys.IsMouseDown())
    {
        middleLayer->Motion(windowPoint, virtualKeys);
    }
    else
    {
        middleLayer->PassiveMotion(windowPoint);
    }

    System::UnusedFunction(hWnd);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::MouseWheelMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ boost::numeric_cast<WParam>(System::GetLowWord(wParam)) };

    middleLayer->MouseWheel(System::GetHighWord(wParam) / System::EnumCastUnderlying(System::WindowsMessages::MouseWheel), windowPoint, virtualKeys);

    System::UnusedFunction(hWnd);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::DestroyMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    middleLayer->Destroy();

    return ParentType::DestroyMessage(hWnd, wParam, lParam);
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::PaintMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    middleLayer->Paint();

    if (!System::SystemValidateRect(hWnd))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("SystemValidateRect 失败。"));
    }

    System::UnusedFunction(wParam, lParam);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::EraseBackgroundMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    System::UnusedFunction(hWnd, wParam, lParam);

    // 这告诉Windows不擦除背景（由OpenGL或DirectX来完成）。
    return 1;
}

template <typename MiddleLayer>
void Framework::WindowMessage<MiddleLayer>::Display(HWnd hWnd, int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    accumulative += timeDelta;

    if (const auto aDelta = GetDelta();
        aDelta == 0)
    {
        middleLayer->PreIdle();
        middleLayer->Idle(accumulative);

        accumulative = 0;
    }
    else if (aDelta <= accumulative)
    {
        const auto remainder = accumulative % aDelta;
        middleLayer->PreIdle();
        middleLayer->Idle(accumulative - remainder);

        accumulative = remainder;
    }

    return ParentType::Display(hWnd, timeDelta);
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_DETAIL_H
