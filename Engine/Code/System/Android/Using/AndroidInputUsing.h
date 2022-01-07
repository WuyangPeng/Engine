///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 22:53)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_TYPEDEF_H
#define SYSTEM_ANDROID_ANDROID_INPUT_TYPEDEF_H

#include "System/SystemDll.h"

#ifdef SYSTEM_PLATFORM_ANDROID

    #include <android/input.h>

namespace System
{
    using AndroidInputEvent = AInputEvent;
    using AndroidInputQueue = AInputQueue;

    constexpr auto g_AndroidMotionEventActionPointerIndexShift = AMOTION_EVENT_ACTION_POINTER_INDEX_SHIFT;
}

#else  // SYSTEM_PLATFORM_ANDROID

    #include "System/Android/Flags/AndroidInputFlags.h"

    #include <array>

namespace System
{
    constexpr auto g_AndroidMotionEventActionPointerIndexShift = 8;

    class SYSTEM_DEFAULT_DECLARE AndroidInputEvent final
    {
    public:
        using ClassType = AndroidInputEvent;

    public:
        AndroidInputEvent() noexcept;

        NODISCARD AndroidInputEventType GetAndroidInputEventType() const noexcept;
        NODISCARD AndroidInputSource GetAndroidInputSource() const noexcept;
        NODISCARD AndroidMeta GetAndroidMeta() const noexcept;
        NODISCARD AndroidKeyEventAction GetAndroidKeyEventAction() const noexcept;
        NODISCARD AndroidKeyEvent GetAndroidKeyEventFlag() const noexcept;
        NODISCARD AndroidKeyCodes GetAndroidKeyCodes() const noexcept;
        NODISCARD AndroidMotionEventAction GetAndroidMotionEventAction() const noexcept;
        NODISCARD AndroidMotionEvent GetAndroidMotionEventFlag() const noexcept;
        NODISCARD AndroidMotionEventButton GetAndroidMotionEventButton() const noexcept;
        NODISCARD AndroidMotionEventEdge GetAndroidMotionEventEdgeFlag() const noexcept;
        NODISCARD AndroidMotionEventTool GetAndroidMotionEventToolType() const noexcept;

        void SetAndroidInputEventType(AndroidInputEventType androidInputEventType) noexcept;
        void SetAndroidInputSource(AndroidInputSource androidInputSource) noexcept;
        void SetAndroidMeta(AndroidMeta androidMeta) noexcept;
        void SetAndroidKeyEventAction(AndroidKeyEventAction androidKeyEventAction) noexcept;
        void SetAndroidKeyEventFlag(AndroidKeyEvent androidKeyEvent) noexcept;
        void SetAndroidKeyCodes(AndroidKeyCodes androidKeyCodes) noexcept;
        void SetAndroidMotionEventAction(AndroidMotionEventAction androidMotionEventAction) noexcept;
        void SetAndroidMotionEventFlag(AndroidMotionEvent androidMotionEvent) noexcept;
        void SetAndroidMotionEventButton(AndroidMotionEventButton androidMotionEventButton) noexcept;
        void SetAndroidMotionEventEdgeFlag(AndroidMotionEventEdge androidMotionEventEdge) noexcept;
        void SetAndroidMotionEventToolType(AndroidMotionEventTool androidMotionEventTool) noexcept;

    private:
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

    class SYSTEM_DEFAULT_DECLARE AndroidInputQueue final
    {
    public:
        using ClassType = AndroidInputQueue;

    public:
        AndroidInputQueue() noexcept;

        NODISCARD int GetSize() const noexcept;
        NODISCARD AndroidInputEvent* GetCurrentAndroidInputEvent() noexcept;

    private:
        static constexpr auto size = 5;

    private:
        std::array<AndroidInputEvent, size> androidInputEvent;
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_INPUT_TYPEDEF_H
