//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 17:21)

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

        [[nodiscard]] AndroidInputEventType GetAndroidInputEventType() const noexcept;
        [[nodiscard]] AndroidInputSource GetAndroidInputSource() const noexcept;
        [[nodiscard]] AndroidMeta GetAndroidMeta() const noexcept;
        [[nodiscard]] AndroidKeyEventAction GetAndroidKeyEventAction() const noexcept;
        [[nodiscard]] AndroidKeyEvent GetAndroidKeyEventFlag() const noexcept;
        [[nodiscard]] AndroidKeyCodes GetAndroidKeyCodes() const noexcept;
        [[nodiscard]] AndroidMotionEventAction GetAndroidMotionEventAction() const noexcept;
        [[nodiscard]] AndroidMotionEvent GetAndroidMotionEventFlag() const noexcept;
        [[nodiscard]] AndroidMotionEventButton GetAndroidMotionEventButton() const noexcept;
        [[nodiscard]] AndroidMotionEventEdge GetAndroidMotionEventEdgeFlag() const noexcept;
        [[nodiscard]] AndroidMotionEventTool GetAndroidMotionEventToolType() const noexcept;

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

        [[nodiscard]] int GetSize() const noexcept;
        [[nodiscard]] AndroidInputEvent* GetCurrentAndroidInputEvent() noexcept;

    private:
        static constexpr auto sm_Size = 5;

    private:
        std::array<AndroidInputEvent, sm_Size> m_AndroidInputEvent;
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_INPUT_TYPEDEF_H
