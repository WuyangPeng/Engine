// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:25)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_TYPEDEF_H
#define SYSTEM_ANDROID_ANDROID_INPUT_TYPEDEF_H

#include "System/SystemDll.h"

#ifdef SYSTEM_PLATFORM_ANDROID

#include <android/input.h>

namespace System
{
	using AndroidInputEvent = AInputEvent;
	using AndroidInputQueue = AInputQueue;

	constexpr int g_AndroidMotionEventActionPointerIndexShift{ AMOTION_EVENT_ACTION_POINTER_INDEX_SHIFT };
}

#else // SYSTEM_PLATFORM_ANDROID

#include "System/Android/Flags/AndroidInputFlags.h"

#include <array>

namespace System
{
	constexpr auto g_AndroidMotionEventActionPointerIndexShift = 8;

	struct SYSTEM_DEFAULT_DECLARE AndroidInputEvent
	{
	public:
		using ClassType = AndroidInputEvent;

	public:
		AndroidInputEvent() noexcept;

	public:
		AndroidInputEventType m_AndroidInputEventType;
		AndroidInputSource m_AndroidInputSource;
		AndroidMeta m_AndroidMeta;
		AndroidKeyEventAction m_AndroidKeyEventAction;
		AndroidKeyEvent m_AndroidKeyEventFlag;
		AndroidKeyCodes m_AndroidKeyCodes;
		AndroidMotionEventAction m_AndroidMotionEventAction;
		AndroidMotionEvent m_AndroidMotionEventFlag;
		AndroidMotionEventButton m_AndroidMotionEventButton;
		AndroidMotionEventEdge m_AndroidMotionEventEdgeFlag;
		AndroidMotionEventTool m_AndroidMotionEventToolType;
	};

	struct SYSTEM_DEFAULT_DECLARE AndroidInputQueue
	{
	public:
		using ClassType = AndroidInputQueue;

	public:
		AndroidInputQueue() noexcept;

		AndroidInputQueue(const AndroidInputQueue&) = delete;
		AndroidInputQueue& operator=(const AndroidInputQueue&) = delete;

		int GetSize() const noexcept;
		AndroidInputEvent* GetCurrentAndroidInputEvent() noexcept;

	private:
		static constexpr auto sm_Size = 5;

	private:
		std::array<AndroidInputEvent, sm_Size> m_AndroidInputEvent;
	};
}

#endif // SYSTEM_PLATFORM_ANDROID

#endif // SYSTEM_ANDROID_ANDROID_INPUT_TYPEDEF_H
