// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:02)

#include "System/SystemExport.h"

#include "AndroidInputUsing.h"

#ifndef SYSTEM_PLATFORM_ANDROID

System::AndroidInputEvent
	::AndroidInputEvent() noexcept
	:m_AndroidInputEventType{ AndroidInputEventType::Key },
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

System::AndroidInputQueue
	::AndroidInputQueue() noexcept
	:m_AndroidInputEvent{}
{
}

int System::AndroidInputQueue
	::GetSize() const noexcept
{
	return sm_Size;
}

System::AndroidInputEvent* System::AndroidInputQueue
	::GetCurrentAndroidInputEvent() noexcept
{
	return m_AndroidInputEvent.data();
}

#endif // SYSTEM_PLATFORM_ANDROID