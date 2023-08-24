///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/09 20:45)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_DETAIL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_DETAIL_H

#include "AndroidCallBack.h"
#include "System/Android/AndroidInputEventFacade.h"
#include "System/Android/AndroidInputMotionEventFacade.h"
#include "System/Android/AndroidNativeWindowFacade.h"
#include "System/Android/Flags/AndroidInputFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Rendering/RendererEngine/EnvironmentParameter.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

template <typename MiddleLayer>
Framework::AndroidCallBack<MiddleLayer>::AndroidCallBack(int64_t delta)
    : ParentType{ delta }, middleLayer{ std::make_shared<MiddleLayer>(MiddleLayerPlatform::Android, EnvironmentDirectory{ SYSTEM_TEXT("DefaultEnvironment"), SYSTEM_TEXT("") }) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename MiddleLayer>
bool Framework::AndroidCallBack<MiddleLayer>::IsValid() const noexcept
{
    if (ParentType::IsValid() && middleLayer != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename MiddleLayer>
void Framework::AndroidCallBack<MiddleLayer>::RedrawNeededMessage(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (androidApp != nullptr)
    {
        ParentType::RedrawNeededMessage(androidApp);

        if (!middleLayer->Paint())
        {
            androidApp->SetDestroyRequested(1);
        }
    }
}

template <typename MiddleLayer>
void Framework::AndroidCallBack<MiddleLayer>::ResizedMessage(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (androidApp != nullptr)
    {
        ParentType::ResizedMessage(androidApp);

        if (const auto nativeWindow = androidApp->GetNativeWindow();
            nativeWindow != nullptr)
        {
            System::AndroidNativeWindowFacade androidNativeWindow{ nativeWindow };
            const auto width = androidNativeWindow.GetWidth();
            const auto height = androidNativeWindow.GetHeight();

            if (const WindowSize windowSize{ width, height };
                !middleLayer->Resize(System::WindowsDisplay::AndroidUnDefinition, windowSize))
            {
                androidApp->SetDestroyRequested(1);
            }
        }
    }
}

template <typename MiddleLayer>
void Framework::AndroidCallBack<MiddleLayer>::RectChanged(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (androidApp != nullptr)
    {
        ParentType::RectChanged(androidApp);

        const auto contentRect = androidApp->GetContentRect();
        const auto width = abs(contentRect.GetRight() - contentRect.GetLeft());
        const auto height = abs(contentRect.GetTop() - contentRect.GetBottom());

        if (const WindowSize windowSize{ width, height };
            !middleLayer->Resize(System::WindowsDisplay::AndroidUnDefinition, windowSize))
        {
            androidApp->SetDestroyRequested(1);
        }
    }
}

template <typename MiddleLayer>
void Framework::AndroidCallBack<MiddleLayer>::InitMessage(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (androidApp != nullptr)
    {
        ParentType::InitMessage(androidApp);

        if (!middleLayer->Create(Rendering::EnvironmentParameter::Create()))
        {
            androidApp->SetDestroyRequested(1);
        }
    }
}

template <typename MiddleLayer>
void Framework::AndroidCallBack<MiddleLayer>::TermMessage(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (androidApp != nullptr)
    {
        ParentType::TermMessage(androidApp);

        middleLayer->Destroy();

        androidApp->SetDestroyRequested(1);
    }
}

template <typename MiddleLayer>
void Framework::AndroidCallBack<MiddleLayer>::Display(AndroidApp* androidApp, int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (androidApp != nullptr)
    {
        ParentType::Display(androidApp, timeDelta);

        if (!middleLayer->Idle(timeDelta))
        {
            androidApp->SetDestroyRequested(1);
        }
    }
}

template <typename MiddleLayer>
int Framework::AndroidCallBack<MiddleLayer>::KeyDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (androidApp != nullptr)
    {
        System::AndroidInputEventFacade androidKeyEvent{ androidInputEvent };
        const auto flags = androidKeyEvent.GetFlags();
        const auto keyCode = System::EnumCastUnderlying(androidKeyEvent.GetKeyCode());

        if ((flags & System::AndroidKeyEventFlag::SoftKeyboard) != System::AndroidKeyEventFlag::Null)
        {
            if (!middleLayer->KeyDown(keyCode, WindowPoint{}))
            {
                androidApp->SetDestroyRequested(1);
            }
        }
        else
        {
            if (!middleLayer->SpecialKeyDown(keyCode, WindowPoint{}))
            {
                androidApp->SetDestroyRequested(1);
            }
        }
    }

    return ParentType::KeyDownMessage(androidApp, androidInputEvent);
}

template <typename MiddleLayer>
int Framework::AndroidCallBack<MiddleLayer>::KeyUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (androidApp != nullptr)
    {
        System::AndroidInputEventFacade androidKeyEvent{ androidInputEvent };
        const auto flags = androidKeyEvent.GetFlags();
        const auto keyCode = System::EnumCastUnderlying(androidKeyEvent.GetKeyCode());

        if ((flags & System::AndroidKeyEventFlag::SoftKeyboard) != System::AndroidKeyEventFlag::Null)
        {
            if (!middleLayer->KeyUp(keyCode, WindowPoint{}))
            {
                androidApp->SetDestroyRequested(1);
            }
        }
        else
        {
            if (!middleLayer->SpecialKeyUp(keyCode, WindowPoint{}))
            {
                androidApp->SetDestroyRequested(1);
            }
        }
    }

    return ParentType::KeyUpMessage(androidApp, androidInputEvent);
}

template <typename MiddleLayer>
int Framework::AndroidCallBack<MiddleLayer>::ActionDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (androidApp != nullptr)
    {
        System::AndroidInputMotionEventFacade androidKeyEvent{ androidInputEvent };
        const auto xOffset = boost::numeric_cast<int>(androidKeyEvent.GetXOffset());
        const auto yOffset = boost::numeric_cast<int>(androidKeyEvent.GetYOffset());

        /// 可以通过使用AndroidMotionEventGetMetaState和AndroidMotionEventGetButtonState
        /// 获取VirtualKeysTypes的值，但对于Android而言，没有太多实际的意义。
        if (const WindowPoint windowPoint{ xOffset, yOffset };
            !middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, windowPoint, VirtualKeysTypes{}))
        {
            androidApp->SetDestroyRequested(1);
        }
    }

    return ParentType::ActionDownMessage(androidApp, androidInputEvent);
}

template <typename MiddleLayer>
int Framework::AndroidCallBack<MiddleLayer>::ActionUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (androidApp != nullptr)
    {
        System::AndroidInputMotionEventFacade androidKeyEvent{ androidInputEvent };
        const auto xOffset = boost::numeric_cast<int>(androidKeyEvent.GetXOffset());
        const auto yOffset = boost::numeric_cast<int>(androidKeyEvent.GetYOffset());

        if (const WindowPoint windowPoint{ xOffset, yOffset };
            !middleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseUp, windowPoint, VirtualKeysTypes{}))
        {
            androidApp->SetDestroyRequested(1);
        }
    }

    return ParentType::ActionUpMessage(androidApp, androidInputEvent);
}

template <typename MiddleLayer>
int Framework::AndroidCallBack<MiddleLayer>::ActionMoveMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (androidApp != nullptr)
    {
        System::AndroidInputMotionEventFacade androidKeyEvent{ androidInputEvent };
        const auto xOffset = boost::numeric_cast<int>(androidKeyEvent.GetXOffset());
        const auto yOffset = boost::numeric_cast<int>(androidKeyEvent.GetYOffset());

        if (const WindowPoint windowPoint{ xOffset, yOffset };
            !middleLayer->Motion(windowPoint, VirtualKeysTypes{}))
        {
            androidApp->SetDestroyRequested(1);
        }
    }

    return ParentType::ActionMoveMessage(androidApp, androidInputEvent);
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_DETAIL_H
