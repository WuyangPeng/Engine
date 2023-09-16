///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/26 15:32)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_MOTION_EVENT_FACADE_H
#define SYSTEM_ANDROID_ANDROID_INPUT_MOTION_EVENT_FACADE_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidInputUsing.h"

namespace System
{
    class SYSTEM_DEFAULT_DECLARE AndroidInputMotionEventFacade final
    {
    public:
        using ClassType = AndroidInputMotionEventFacade;

    public:
        explicit AndroidInputMotionEventFacade(const AndroidInputEvent* motionEvent) noexcept;

        NODISCARD AndroidMotionEventAction GetAction() noexcept;
        NODISCARD AndroidMotionEventFlag GetFlags() noexcept;
        NODISCARD AndroidMeta GetMetaState() noexcept;
        NODISCARD AndroidMotionEventButton GetButtonState() noexcept;
        NODISCARD AndroidMotionEventEdgeFlag GetEdgeFlags() noexcept;
        NODISCARD int64_t GetDownTime() noexcept;
        NODISCARD int64_t GetEventTime() noexcept;
        NODISCARD float GetXOffset() noexcept;
        NODISCARD float GetYOffset() noexcept;
        NODISCARD float GetXPrecision() noexcept;
        NODISCARD float GetYPrecision() noexcept;
        NODISCARD size_t GetPointerCount() noexcept;

        NODISCARD int32_t GetPointerId(size_t pointerIndex) noexcept;
        NODISCARD AndroidMotionEventToolType GetToolType(size_t pointerIndex) noexcept;
        NODISCARD float GetRawX(size_t pointerIndex) noexcept;
        NODISCARD float GetRawY(size_t pointerIndex) noexcept;
        NODISCARD float GetX(size_t pointerIndex) noexcept;
        NODISCARD float GetY(size_t pointerIndex) noexcept;
        NODISCARD float GetPressure(size_t pointerIndex) noexcept;
        NODISCARD float GetSize(size_t pointerIndex) noexcept;
        NODISCARD float GetTouchMajor(size_t pointerIndex) noexcept;
        NODISCARD float GetTouchMinor(size_t pointerIndex) noexcept;
        NODISCARD float GetToolMajor(size_t pointerIndex) noexcept;
        NODISCARD float GetToolMinor(size_t pointerIndex) noexcept;
        NODISCARD float GetOrientation(size_t pointerIndex) noexcept;
        NODISCARD float GetAxisValue(AndroidMotionEventAxis axis, size_t pointerIndex) noexcept;

        NODISCARD size_t GetHistorySize() noexcept;
        NODISCARD int64_t GetHistoricalEventTime(size_t historyIndex) noexcept;
        NODISCARD float GetHistoricalRawX(size_t pointerIndex, size_t historyIndex) noexcept;
        NODISCARD float GetHistoricalRawY(size_t pointerIndex, size_t historyIndex) noexcept;
        NODISCARD float GetHistoricalX(size_t pointerIndex, size_t historyIndex) noexcept;
        NODISCARD float GetHistoricalY(size_t pointerIndex, size_t historyIndex) noexcept;
        NODISCARD float GetHistoricalPressure(size_t pointerIndex, size_t historyIndex) noexcept;
        NODISCARD float GetHistoricalSize(size_t pointerIndex, size_t historyIndex) noexcept;
        NODISCARD float GetHistoricalTouchMajor(size_t pointerIndex, size_t historyIndex) noexcept;
        NODISCARD float GetHistoricalTouchMinor(size_t pointerIndex, size_t historyIndex) noexcept;
        NODISCARD float GetHistoricalToolMajor(size_t pointerIndex, size_t historyIndex) noexcept;
        NODISCARD float GetHistoricalToolMinor(size_t pointerIndex, size_t historyIndex) noexcept;
        NODISCARD float GetHistoricalOrientation(size_t pointerIndex, size_t historyIndex) noexcept;
        NODISCARD float GetHistoricalAxisValue(AndroidMotionEventAxis axis, size_t pointerIndex, size_t historyIndex) noexcept;

    private:
        const AndroidInputEvent* motionEvent;
    };
}

#endif  // SYSTEM_ANDROID_ANDROID_INPUT_MOTION_EVENT_FACADE_H
