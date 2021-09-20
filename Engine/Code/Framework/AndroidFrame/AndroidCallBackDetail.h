// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.3.0.1 (2020/05/21 16:38)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_DETAIL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_DETAIL_H

#include "AndroidCallBack.h"
#include "System/Android/AndroidInputKeyEvent.h"
#include "System/Android/AndroidInputMotionEvent.h"
#include "System/Android/AndroidNativeWindow.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

template <typename MiddleLayer>
Framework::AndroidCallBack<MiddleLayer>::AndroidCallBack(int64_t delta)
    : ParentType{ delta }, m_MiddleLayer{ std::make_shared<MiddleLayer>(MiddleLayerPlatform::Android) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename MiddleLayer>
bool Framework::AndroidCallBack<MiddleLayer>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_MiddleLayer != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename MiddleLayer>
void Framework::AndroidCallBack<MiddleLayer>::RedrawNeededMessage(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::RedrawNeededMessage(androidApp);

    if (!m_MiddleLayer->Paint())
    {
        androidApp->SetDestroyRequested(1);
    }
}

template <typename MiddleLayer>
void Framework::AndroidCallBack<MiddleLayer>::ResizedMessage(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (androidApp != nullptr)
    {
        ParentType::ResizedMessage(androidApp);

        auto nativeWindow = androidApp->GetAndroidNativeWindow();

        if (nativeWindow != nullptr)
        {
            const auto width = System::AndroidNativeWindowGetWidth(nativeWindow);
            const auto height = System::AndroidNativeWindowGetHeight(nativeWindow);

            if (!m_MiddleLayer->Resize(System::WindowsDisplay::AndroidUnDefinition, WindowSize{ width, height }))
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

    ParentType::RectChanged(androidApp);

    const auto contentRect = androidApp->GetContentRect();
    const auto width = abs(contentRect.GetRight() - contentRect.GetLeft());
    const auto height = abs(contentRect.GetTop() - contentRect.GetBottom());

    if (!m_MiddleLayer->Resize(System::WindowsDisplay::AndroidUnDefinition, WindowSize{ width, height }))
    {
        androidApp->SetDestroyRequested(1);
    }
}

template <typename MiddleLayer>
void Framework::AndroidCallBack<MiddleLayer>::InitMessage(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::InitMessage(androidApp);

    if (!m_MiddleLayer->Create())
    {
        androidApp->SetDestroyRequested(1);
    }
}

template <typename MiddleLayer>
void Framework::AndroidCallBack<MiddleLayer>::TermMessage(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (androidApp != nullptr)
    {
        ParentType::TermMessage(androidApp);

        m_MiddleLayer->Destroy();

        androidApp->SetDestroyRequested(1);
    }
}

template <typename MiddleLayer>
void Framework::AndroidCallBack<MiddleLayer>::Display(AndroidApp* androidApp, int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::Display(androidApp, timeDelta);

    if (!m_MiddleLayer->Idle(timeDelta))
    {
        androidApp->SetDestroyRequested(1);
    }
}

template <typename MiddleLayer>
int Framework::AndroidCallBack<MiddleLayer>::KeyDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto flags = System::AndroidKeyEventGetFlags(androidInputEvent);
    const auto keyCode = System::EnumCastUnderlying(System::AndroidKeyEventGetKeyCode(androidInputEvent));

    if ((flags & System::AndroidKeyEvent::SoftKeyboard) != System::AndroidKeyEvent::Null)
    {
        if (!m_MiddleLayer->KeyDown(keyCode, WindowPoint{}))
        {
            androidApp->SetDestroyRequested(1);
        }
    }
    else
    {
        if (!m_MiddleLayer->SpecialKeyDown(keyCode, WindowPoint{}))
        {
            androidApp->SetDestroyRequested(1);
        }
    }

    return ParentType::KeyDownMessage(androidApp, androidInputEvent);
}

template <typename MiddleLayer>
int Framework::AndroidCallBack<MiddleLayer>::KeyUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto flags = System::AndroidKeyEventGetFlags(androidInputEvent);
    const auto keyCode = System::EnumCastUnderlying(System::AndroidKeyEventGetKeyCode(androidInputEvent));

    if ((flags & System::AndroidKeyEvent::SoftKeyboard) != System::AndroidKeyEvent::Null)
    {
        if (!m_MiddleLayer->KeyUp(keyCode, WindowPoint{}))
        {
            androidApp->SetDestroyRequested(1);
        }
    }
    else
    {
        if (!m_MiddleLayer->SpecialKeyUp(keyCode, WindowPoint{}))
        {
            androidApp->SetDestroyRequested(1);
        }
    }

    return ParentType::KeyUpMessage(androidApp, androidInputEvent);
}

template <typename MiddleLayer>
int Framework::AndroidCallBack<MiddleLayer>::ActionDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto xOffset = boost::numeric_cast<int>(System::AndroidMotionEventGetXOffset(androidInputEvent));
    const auto yOffset = boost::numeric_cast<int>(System::AndroidMotionEventGetYOffset(androidInputEvent));

    // 可以通过使用AndroidMotionEventGetMetaState和AndroidMotionEventGetButtonState
    // 获取VirtualKeysTypes的值，但对于Android而言，没有太多实际的意义。
    if (!m_MiddleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseDown, WindowPoint{ xOffset, yOffset }, VirtualKeysTypes{}))
    {
        androidApp->SetDestroyRequested(1);
    }

    return ParentType::ActionDownMessage(androidApp, androidInputEvent);
}

template <typename MiddleLayer>
int Framework::AndroidCallBack<MiddleLayer>::ActionUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto xOffset = boost::numeric_cast<int>(System::AndroidMotionEventGetXOffset(androidInputEvent));
    const auto yOffset = boost::numeric_cast<int>(System::AndroidMotionEventGetYOffset(androidInputEvent));

    if (!m_MiddleLayer->MouseClick(MouseButtonsTypes::LeftButton, MouseStateTypes::MouseUp, WindowPoint{ xOffset, yOffset }, VirtualKeysTypes{}))
    {
        androidApp->SetDestroyRequested(1);
    }

    return ParentType::ActionUpMessage(androidApp, androidInputEvent);
}

template <typename MiddleLayer>
int Framework::AndroidCallBack<MiddleLayer>::ActionMoveMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto xOffset = boost::numeric_cast<int>(System::AndroidMotionEventGetXOffset(androidInputEvent));
    const auto yOffset = boost::numeric_cast<int>(System::AndroidMotionEventGetYOffset(androidInputEvent));

    if (!m_MiddleLayer->Motion(WindowPoint{ xOffset, yOffset }, VirtualKeysTypes{}))
    {
        androidApp->SetDestroyRequested(1);
    }

    return ParentType::ActionMoveMessage(androidApp, androidInputEvent);
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_DETAIL_H
