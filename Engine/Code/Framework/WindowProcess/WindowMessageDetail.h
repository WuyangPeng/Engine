///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:10)

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
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/WindowCreate/WindowSize.h"

template <typename MiddleLayer>
Framework::WindowMessage<MiddleLayer>::WindowMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, environmentDirectory }, middleLayer{ MiddleLayerType::CreateMiddleLayer(MiddleLayerPlatform::Windows, environmentDirectory) }, accumulative{ delta }
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
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::CreateMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    middleLayer->Create(Rendering::EnvironmentParameter::Create(hwnd));

    return ParentType::CreateMessage(hwnd, wParam, lParam);
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::SizeMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowSize clientSize{ lParam };

    middleLayer->Resize(boost::numeric_cast<System::WindowsDisplay>(wParam), clientSize);

    return ParentType::SizeMessage(hwnd, wParam, lParam);
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::CloseMessage(HWnd hwnd, [[maybe_unused]] WParam wParam, [[maybe_unused]] LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    DoCloseMessage(hwnd);

    return 0;
}

// private
template <typename MiddleLayer>
void Framework::WindowMessage<MiddleLayer>::DoCloseMessage(HWnd hwnd) const
{
    using namespace std::literals;

    auto className = GetWindowsClassName(hwnd);

    auto exitInformation = SYSTEM_TEXT("是否退出"s) + className + SYSTEM_TEXT("？"s);

    auto result = System::SystemValidateRect(hwnd);

    if (System::DefaultMessageBox(hwnd, exitInformation, className))
    {
        result = System::DestroySystemWindow(hwnd);
    }
}

// private
template <typename MiddleLayer>
System::String Framework::WindowMessage<MiddleLayer>::GetWindowsClassName(HWnd hwnd) const
{
    String name{};

    if (System::GetWindowTextString(hwnd, name))
        return name;
    else
        return SYSTEM_TEXT("程序");
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::CharMessage(HWnd hwnd, WParam wParam, [[maybe_unused]] LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto key = boost::numeric_cast<int>(wParam);

    // 当Terminate键被按下时退出应用程序。
    if (key == GetTerminateKey())
    {
        MAYBE_UNUSED const auto result = System::SendSystemMessage(hwnd, System::WindowsMessages::Close, 0, 0);
    }
    else
    {
        // 获取客户端光标的位置。
        const auto point = GetCursorPosition(hwnd);

        middleLayer->KeyDown(key, point);
    }

    return 0;
}

// private
template <typename MiddleLayer>
Framework::WindowPoint Framework::WindowMessage<MiddleLayer>::GetCursorPosition(HWnd hwnd) const noexcept
{
    System::WindowsPoint point{};
    MAYBE_UNUSED const auto result = System::GetCursorClientPos(hwnd, point);

    return WindowPoint{ point };
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::MoveMessage([[maybe_unused]] HWnd hwnd, [[maybe_unused]] WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    middleLayer->Move(WindowPoint{ lParam });

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::KeyDownMessage(HWnd hwnd, WParam wParam, [[maybe_unused]] LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto virtualKey = boost::numeric_cast<int>(wParam);

    // 获取客户端光标的位置。
    const auto point = GetCursorPosition(hwnd);

    if (IsSpecialKey(virtualKey))
    {
        middleLayer->SpecialKeyDown(virtualKey, point);
    }

    // KeyDown在CharMessage上监听。

    return 0;
}

// private
template <typename MiddleLayer>
bool Framework::WindowMessage<MiddleLayer>::IsSpecialKey(int virtualKey) const noexcept
{
    auto windowsKeyCodes = System::UnderlyingCastEnum<System::WindowsKeyCodes>(virtualKey);

    if ((System::WindowsKeyCodes::F1 <= windowsKeyCodes) && (windowsKeyCodes <= System::WindowsKeyCodes::F12) ||
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
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::KeyUpMessage(HWnd hwnd, WParam wParam, [[maybe_unused]] LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto virtualKey = boost::numeric_cast<int>(wParam);

    // 获取客户端光标的位置。
    const auto point = GetCursorPosition(hwnd);

    if (IsSpecialKey(virtualKey))
    {
        middleLayer->SpecialKeyUp(virtualKey, point);
    }
    else
    {
        middleLayer->KeyUp(virtualKey, point);
    }

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::LeftButtonDownMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ wParam };

    middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, windowPoint, virtualKeys);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::LeftButtonUpMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ wParam };

    middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseUp, windowPoint, virtualKeys);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::MiddleButtonDownMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ wParam };

    middleLayer->MouseClick(MouseButtonsTypes::MiddleButton, MouseStateTypes::MouseDown, windowPoint, virtualKeys);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::MiddleButtonUpMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ wParam };

    middleLayer->MouseClick(MouseButtonsTypes::MiddleButton, MouseStateTypes::MouseUp, windowPoint, virtualKeys);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::RightButtonDownMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ wParam };

    middleLayer->MouseClick(MouseButtonsTypes::RightButton, MouseStateTypes::MouseDown, windowPoint, virtualKeys);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::RightButtonUpMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ wParam };

    middleLayer->MouseClick(MouseButtonsTypes::RightButton, MouseStateTypes::MouseUp, windowPoint, virtualKeys);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::MouseMoveMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ wParam };

    if (virtualKeys.IsMouseDown())
    {
        middleLayer->Motion(windowPoint, virtualKeys);
    }
    else
    {
        middleLayer->PassiveMotion(windowPoint);
    }

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::MouseWheelMessage([[maybe_unused]] HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const WindowPoint windowPoint{ lParam };
    const VirtualKeysTypes virtualKeys{ boost::numeric_cast<WParam>(System::GetLowWord(wParam)) };

    middleLayer->MouseWheel(System::GetHighWord(wParam) / System::EnumCastUnderlying(System::WindowsMessages::MouseWheel), windowPoint, virtualKeys);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::DestroyMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    middleLayer->Destroy();

    return ParentType::DestroyMessage(hwnd, wParam, lParam);
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::PaintMessage([[maybe_unused]] HWnd hwnd, [[maybe_unused]] WParam wParam, [[maybe_unused]] LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    middleLayer->Paint();

    MAYBE_UNUSED const auto result = System::SystemValidateRect(hwnd);

    return 0;
}

template <typename MiddleLayer>
System::WindowsLResult Framework::WindowMessage<MiddleLayer>::EraseBackgroundMessage([[maybe_unused]] HWnd hwnd, [[maybe_unused]] WParam wParam, [[maybe_unused]] LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    // 这告诉Windows不擦除背景（由OpenGL或DirectX来完成）。

    return 1;
}

template <typename MiddleLayer>
void Framework::WindowMessage<MiddleLayer>::Display(HWnd hwnd, int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    accumulative += timeDelta;

    const auto aDelta = GetDelta();

    if (aDelta == 0)
    {
        middleLayer->Idle(accumulative);

        accumulative = 0;
    }
    else if (aDelta <= accumulative)
    {
        const auto remainder = accumulative % aDelta;
        middleLayer->Idle(accumulative - remainder);

        accumulative = remainder;
    }

    return ParentType::Display(hwnd, timeDelta);
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_DETAIL_H
