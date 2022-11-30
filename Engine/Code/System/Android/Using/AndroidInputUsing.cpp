///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/22 23:26)

#include "System/SystemExport.h"

#include "AndroidInputUsing.h"
#include "System/Android/Flags/AndroidInputFlags.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"

#ifndef SYSTEM_PLATFORM_ANDROID

System::AndroidInputEvent::AndroidInputEvent() noexcept
    : ClassType{ AndroidInputEventType::Key, AndroidMotionEventAction::Mask }
{
}

System::AndroidInputEvent::AndroidInputEvent(AndroidInputEventType androidInputEventType, AndroidMotionEventAction androidMotionEventAction) noexcept
    : ClassType{ androidInputEventType, AndroidKeyEventAction::Down, AndroidKeyCodes::Unknown, androidMotionEventAction }
{
}

System::AndroidInputEvent::AndroidInputEvent(AndroidInputEventType androidInputEventType, AndroidKeyEventAction androidKeyEventAction, AndroidKeyCodes androidKeyCodes) noexcept
    : ClassType{ androidInputEventType, androidKeyEventAction, androidKeyCodes, AndroidMotionEventAction::Mask }
{
}

System::AndroidInputEvent::AndroidInputEvent(AndroidInputEventType androidInputEventType, AndroidKeyEventAction androidKeyEventAction, AndroidKeyCodes androidKeyCodes, AndroidMotionEventAction androidMotionEventAction) noexcept
    : androidInputEventType{ androidInputEventType },
      androidInputSource{ AndroidInputSource::Unknown },
      androidMeta{ AndroidMeta::None },
      androidKeyEventAction{ androidKeyEventAction },
      androidKeyEventFlag{ AndroidKeyEventFlag::Null },
      androidKeyCodes{ androidKeyCodes },
      androidMotionEventAction{ androidMotionEventAction },
      androidMotionEventFlag{ AndroidMotionEventFlag::WindowIsObscured },
      androidMotionEventButton{ AndroidMotionEventButton::Primary },
      androidMotionEventEdgeFlag{ AndroidMotionEventEdgeFlag::None },
      androidMotionEventToolType{ AndroidMotionEventToolType::Unknown }
{
}

System::AndroidInputEventType System::AndroidInputEvent::GetAndroidInputEventType() const noexcept
{
    return androidInputEventType;
}

void System::AndroidInputEvent::SetAndroidInputEventType(AndroidInputEventType aAndroidInputEventType) noexcept
{
    androidInputEventType = aAndroidInputEventType;
}

System::AndroidInputSource System::AndroidInputEvent::GetAndroidInputSource() const noexcept
{
    return androidInputSource;
}

void System::AndroidInputEvent::SetAndroidInputSource(AndroidInputSource aAndroidInputSource) noexcept
{
    androidInputSource = aAndroidInputSource;
}

System::AndroidMeta System::AndroidInputEvent::GetAndroidMeta() const noexcept
{
    return androidMeta;
}

void System::AndroidInputEvent::SetAndroidMeta(AndroidMeta aAndroidMeta) noexcept
{
    androidMeta = aAndroidMeta;
}

System::AndroidKeyEventAction System::AndroidInputEvent::GetAndroidKeyEventAction() const noexcept
{
    return androidKeyEventAction;
}

void System::AndroidInputEvent::SetAndroidKeyEventAction(AndroidKeyEventAction aAndroidKeyEventAction) noexcept
{
    androidKeyEventAction = aAndroidKeyEventAction;
}

System::AndroidKeyEventFlag System::AndroidInputEvent::GetAndroidKeyEventFlag() const noexcept
{
    return androidKeyEventFlag;
}

void System::AndroidInputEvent::SetAndroidKeyEventFlag(AndroidKeyEventFlag aAndroidKeyEvent) noexcept
{
    androidKeyEventFlag = aAndroidKeyEvent;
}

System::AndroidKeyCodes System::AndroidInputEvent::GetAndroidKeyCodes() const noexcept
{
    return androidKeyCodes;
}

void System::AndroidInputEvent::SetAndroidKeyCodes(AndroidKeyCodes aAndroidKeyCodes) noexcept
{
    androidKeyCodes = aAndroidKeyCodes;
}

System::AndroidMotionEventAction System::AndroidInputEvent::GetAndroidMotionEventAction() const noexcept
{
    return androidMotionEventAction;
}

void System::AndroidInputEvent::SetAndroidMotionEventAction(AndroidMotionEventAction aAndroidMotionEventAction) noexcept
{
    androidMotionEventAction = aAndroidMotionEventAction;
}

System::AndroidMotionEventFlag System::AndroidInputEvent::GetAndroidMotionEventFlag() const noexcept
{
    return androidMotionEventFlag;
}

void System::AndroidInputEvent::SetAndroidMotionEventFlag(AndroidMotionEventFlag aAndroidMotionEvent) noexcept
{
    androidMotionEventFlag = aAndroidMotionEvent;
}

System::AndroidMotionEventButton System::AndroidInputEvent::GetAndroidMotionEventButton() const noexcept
{
    return androidMotionEventButton;
}

void System::AndroidInputEvent::SetAndroidMotionEventButton(AndroidMotionEventButton aAndroidMotionEventButton) noexcept
{
    androidMotionEventButton = aAndroidMotionEventButton;
}

System::AndroidMotionEventEdgeFlag System::AndroidInputEvent::GetAndroidMotionEventEdgeFlag() const noexcept
{
    return androidMotionEventEdgeFlag;
}

void System::AndroidInputEvent::SetAndroidMotionEventEdgeFlag(AndroidMotionEventEdgeFlag aAndroidMotionEventEdge) noexcept
{
    androidMotionEventEdgeFlag = aAndroidMotionEventEdge;
}

System::AndroidMotionEventToolType System::AndroidInputEvent::GetAndroidMotionEventToolType() const noexcept
{
    return androidMotionEventToolType;
}

void System::AndroidInputEvent::SetAndroidMotionEventToolType(AndroidMotionEventToolType aAndroidMotionEventTool) noexcept
{
    androidMotionEventToolType = aAndroidMotionEventTool;
}

System::AndroidInputQueue::AndroidInputQueue() noexcept
    : androidInputEvent{}
{
}

int System::AndroidInputQueue::GetSize() const noexcept
{
    return size;
}

System::AndroidInputEvent* System::AndroidInputQueue::GetCurrentAndroidInputEvent() noexcept
{
    return androidInputEvent.data();
}

#endif  // SYSTEM_PLATFORM_ANDROID