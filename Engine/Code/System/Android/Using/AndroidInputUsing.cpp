///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 22:59)

#include "System/SystemExport.h"

#include "AndroidInputUsing.h"

#ifndef SYSTEM_PLATFORM_ANDROID

System::AndroidInputEvent::AndroidInputEvent() noexcept
    : m_AndroidInputEventType{ AndroidInputEventType::Key },
      m_AndroidInputSource{ AndroidInputSource::Keyborad },
      m_AndroidMeta{ AndroidMeta::None },
      m_AndroidKeyEventAction{ AndroidKeyEventAction::Down },
      m_AndroidKeyEventFlag{ AndroidKeyEvent::SoftKeyboard },
      m_AndroidKeyCodes{ AndroidKeyCodes::A },
      m_AndroidMotionEventAction{ AndroidMotionEventAction::Down },
      m_AndroidMotionEventFlag{ AndroidMotionEvent::WindowIsObscured },
      m_AndroidMotionEventButton{ AndroidMotionEventButton::Primary },
      m_AndroidMotionEventEdgeFlag{ AndroidMotionEventEdge::None },
      m_AndroidMotionEventToolType{ AndroidMotionEventTool::Unknown }
{
}

System::AndroidInputEventType System::AndroidInputEvent::GetAndroidInputEventType() const noexcept
{
    return m_AndroidInputEventType;
}

void System::AndroidInputEvent::SetAndroidInputEventType(AndroidInputEventType androidInputEventType) noexcept
{
    m_AndroidInputEventType = androidInputEventType;
}

System::AndroidInputSource System::AndroidInputEvent::GetAndroidInputSource() const noexcept
{
    return m_AndroidInputSource;
}

void System::AndroidInputEvent::SetAndroidInputSource(AndroidInputSource androidInputSource) noexcept
{
    m_AndroidInputSource = androidInputSource;
}

System::AndroidMeta System::AndroidInputEvent::GetAndroidMeta() const noexcept
{
    return m_AndroidMeta;
}

void System::AndroidInputEvent::SetAndroidMeta(AndroidMeta androidMeta) noexcept
{
    m_AndroidMeta = androidMeta;
}

System::AndroidKeyEventAction System::AndroidInputEvent::GetAndroidKeyEventAction() const noexcept
{
    return m_AndroidKeyEventAction;
}

void System::AndroidInputEvent::SetAndroidKeyEventAction(AndroidKeyEventAction androidKeyEventAction) noexcept
{
    m_AndroidKeyEventAction = androidKeyEventAction;
}

System::AndroidKeyEvent System::AndroidInputEvent::GetAndroidKeyEventFlag() const noexcept
{
    return m_AndroidKeyEventFlag;
}

void System::AndroidInputEvent::SetAndroidKeyEventFlag(AndroidKeyEvent androidKeyEvent) noexcept
{
    m_AndroidKeyEventFlag = androidKeyEvent;
}

System::AndroidKeyCodes System::AndroidInputEvent::GetAndroidKeyCodes() const noexcept
{
    return m_AndroidKeyCodes;
}

void System::AndroidInputEvent::SetAndroidKeyCodes(AndroidKeyCodes androidKeyCodes) noexcept
{
    m_AndroidKeyCodes = androidKeyCodes;
}

System::AndroidMotionEventAction System::AndroidInputEvent::GetAndroidMotionEventAction() const noexcept
{
    return m_AndroidMotionEventAction;
}

void System::AndroidInputEvent::SetAndroidMotionEventAction(AndroidMotionEventAction androidMotionEventAction) noexcept
{
    m_AndroidMotionEventAction = androidMotionEventAction;
}

System::AndroidMotionEvent System::AndroidInputEvent::GetAndroidMotionEventFlag() const noexcept
{
    return m_AndroidMotionEventFlag;
}

void System::AndroidInputEvent::SetAndroidMotionEventFlag(AndroidMotionEvent androidMotionEvent) noexcept
{
    m_AndroidMotionEventFlag = androidMotionEvent;
}

System::AndroidMotionEventButton System::AndroidInputEvent::GetAndroidMotionEventButton() const noexcept
{
    return m_AndroidMotionEventButton;
}

void System::AndroidInputEvent::SetAndroidMotionEventButton(AndroidMotionEventButton androidMotionEventButton) noexcept
{
    m_AndroidMotionEventButton = androidMotionEventButton;
}

System::AndroidMotionEventEdge System::AndroidInputEvent::GetAndroidMotionEventEdgeFlag() const noexcept
{
    return m_AndroidMotionEventEdgeFlag;
}

void System::AndroidInputEvent::SetAndroidMotionEventEdgeFlag(AndroidMotionEventEdge androidMotionEventEdge) noexcept
{
    m_AndroidMotionEventEdgeFlag = androidMotionEventEdge;
}

System::AndroidMotionEventTool System::AndroidInputEvent::GetAndroidMotionEventToolType() const noexcept
{
    return m_AndroidMotionEventToolType;
}

void System::AndroidInputEvent::SetAndroidMotionEventToolType(AndroidMotionEventTool androidMotionEventTool) noexcept
{
    m_AndroidMotionEventToolType = androidMotionEventTool;
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