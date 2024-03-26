/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:17)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_USING_H
#define SYSTEM_ANDROID_ANDROID_INPUT_USING_H

#include "System/SystemDll.h"

#ifdef SYSTEM_PLATFORM_ANDROID

    #include <android/input.h>

#else  // !SYSTEM_PLATFORM_ANDROID

    #include "System/Android/Fwd/AndroidFlagsFwd.h"

    #include <array>

#endif  // SYSTEM_PLATFORM_ANDROID

#ifdef SYSTEM_PLATFORM_ANDROID

namespace System
{
    constexpr auto gAndroidMotionEventActionPointerIndexShift = AMOTION_EVENT_ACTION_POINTER_INDEX_SHIFT;

    using AndroidInputEvent = AInputEvent;
    using AndroidInputQueue = AInputQueue;
}

#else  // SYSTEM_PLATFORM_ANDROID

namespace System
{
    constexpr auto gAndroidMotionEventActionPointerIndexShift = 8;

    class SYSTEM_DEFAULT_DECLARE AndroidInputEvent final
    {
    public:
        using ClassType = AndroidInputEvent;

    public:
        AndroidInputEvent() noexcept;
        AndroidInputEvent(AndroidInputEventType androidInputEventType, AndroidMotionEventAction androidMotionEventAction) noexcept;
        AndroidInputEvent(AndroidInputEventType androidInputEventType, AndroidKeyEventAction androidKeyEventAction, AndroidKeyCodes androidKeyCodes) noexcept;

        NODISCARD AndroidInputEventType GetAndroidInputEventType() const noexcept;
        NODISCARD AndroidInputSource GetAndroidInputSource() const noexcept;
        NODISCARD AndroidMeta GetAndroidMeta() const noexcept;
        NODISCARD AndroidKeyEventAction GetAndroidKeyEventAction() const noexcept;
        NODISCARD AndroidKeyEventFlag GetAndroidKeyEventFlag() const noexcept;
        NODISCARD AndroidKeyCodes GetAndroidKeyCodes() const noexcept;
        NODISCARD AndroidMotionEventAction GetAndroidMotionEventAction() const noexcept;
        NODISCARD AndroidMotionEventFlag GetAndroidMotionEventFlag() const noexcept;
        NODISCARD AndroidMotionEventButton GetAndroidMotionEventButton() const noexcept;
        NODISCARD AndroidMotionEventEdgeFlag GetAndroidMotionEventEdgeFlag() const noexcept;
        NODISCARD AndroidMotionEventToolType GetAndroidMotionEventToolType() const noexcept;

        void SetAndroidInputEventType(AndroidInputEventType aAndroidInputEventType) noexcept;
        void SetAndroidInputSource(AndroidInputSource aAndroidInputSource) noexcept;
        void SetAndroidMeta(AndroidMeta aAndroidMeta) noexcept;
        void SetAndroidKeyEventAction(AndroidKeyEventAction aAndroidKeyEventAction) noexcept;
        void SetAndroidKeyEventFlag(AndroidKeyEventFlag aAndroidKeyEvent) noexcept;
        void SetAndroidKeyCodes(AndroidKeyCodes aAndroidKeyCodes) noexcept;
        void SetAndroidMotionEventAction(AndroidMotionEventAction aAndroidMotionEventAction) noexcept;
        void SetAndroidMotionEventFlag(AndroidMotionEventFlag aAndroidMotionEvent) noexcept;
        void SetAndroidMotionEventButton(AndroidMotionEventButton aAndroidMotionEventButton) noexcept;
        void SetAndroidMotionEventEdgeFlag(AndroidMotionEventEdgeFlag aAndroidMotionEventEdge) noexcept;
        void SetAndroidMotionEventToolType(AndroidMotionEventToolType aAndroidMotionEventTool) noexcept;

    private:
        AndroidInputEvent(AndroidInputEventType androidInputEventType,
                          AndroidKeyEventAction androidKeyEventAction,
                          AndroidKeyCodes androidKeyCodes,
                          AndroidMotionEventAction androidMotionEventAction) noexcept;

    private:
        AndroidInputEventType androidInputEventType;
        AndroidInputSource androidInputSource;
        AndroidMeta androidMeta;
        AndroidKeyEventAction androidKeyEventAction;
        AndroidKeyEventFlag androidKeyEventFlag;
        AndroidKeyCodes androidKeyCodes;
        AndroidMotionEventAction androidMotionEventAction;
        AndroidMotionEventFlag androidMotionEventFlag;
        AndroidMotionEventButton androidMotionEventButton;
        AndroidMotionEventEdgeFlag androidMotionEventEdgeFlag;
        AndroidMotionEventToolType androidMotionEventToolType;
    };

    class SYSTEM_DEFAULT_DECLARE AndroidInputQueue final
    {
    public:
        using ClassType = AndroidInputQueue;

    public:
        AndroidInputQueue() noexcept;

        NODISCARD static int GetSize() noexcept;
        NODISCARD AndroidInputEvent* GetCurrentAndroidInputEvent() noexcept;

    private:
        static constexpr auto size = 5;
        using Container = std::array<AndroidInputEvent, size>;

    private:
        Container androidInputEvent;
    };
}

#endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_ANDROID_ANDROID_INPUT_USING_H
