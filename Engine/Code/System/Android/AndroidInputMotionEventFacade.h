/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:19)

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

        NODISCARD AndroidMotionEventAction GetAction() const noexcept;
        NODISCARD AndroidMotionEventFlag GetFlags() const noexcept;
        NODISCARD AndroidMeta GetMetaState() const noexcept;
        NODISCARD AndroidMotionEventButton GetButtonState() const noexcept;
        NODISCARD AndroidMotionEventEdgeFlag GetEdgeFlags() const noexcept;
        NODISCARD int64_t GetDownTime() const noexcept;
        NODISCARD int64_t GetEventTime() const noexcept;
        NODISCARD float GetXOffset() const noexcept;
        NODISCARD float GetYOffset() const noexcept;
        NODISCARD float GetXPrecision() const noexcept;
        NODISCARD float GetYPrecision() const noexcept;
        NODISCARD size_t GetPointerCount() const noexcept;

        NODISCARD int32_t GetPointerId(size_t pointerIndex) const noexcept;
        NODISCARD AndroidMotionEventToolType GetToolType(size_t pointerIndex) const noexcept;
        NODISCARD float GetRawX(size_t pointerIndex) const noexcept;
        NODISCARD float GetRawY(size_t pointerIndex) const noexcept;
        NODISCARD float GetX(size_t pointerIndex) const noexcept;
        NODISCARD float GetY(size_t pointerIndex) const noexcept;
        NODISCARD float GetPressure(size_t pointerIndex) const noexcept;
        NODISCARD float GetSize(size_t pointerIndex) const noexcept;
        NODISCARD float GetTouchMajor(size_t pointerIndex) const noexcept;
        NODISCARD float GetTouchMinor(size_t pointerIndex) const noexcept;
        NODISCARD float GetToolMajor(size_t pointerIndex) const noexcept;
        NODISCARD float GetToolMinor(size_t pointerIndex) const noexcept;
        NODISCARD float GetOrientation(size_t pointerIndex) const noexcept;
        NODISCARD float GetAxisValue(AndroidMotionEventAxis axis, size_t pointerIndex) const noexcept;

        NODISCARD size_t GetHistorySize() const noexcept;
        NODISCARD int64_t GetHistoricalEventTime(size_t historyIndex) const noexcept;
        NODISCARD float GetHistoricalRawX(size_t pointerIndex, size_t historyIndex) const noexcept;
        NODISCARD float GetHistoricalRawY(size_t pointerIndex, size_t historyIndex) const noexcept;
        NODISCARD float GetHistoricalX(size_t pointerIndex, size_t historyIndex) const noexcept;
        NODISCARD float GetHistoricalY(size_t pointerIndex, size_t historyIndex) const noexcept;
        NODISCARD float GetHistoricalPressure(size_t pointerIndex, size_t historyIndex) const noexcept;
        NODISCARD float GetHistoricalSize(size_t pointerIndex, size_t historyIndex) const noexcept;
        NODISCARD float GetHistoricalTouchMajor(size_t pointerIndex, size_t historyIndex) const noexcept;
        NODISCARD float GetHistoricalTouchMinor(size_t pointerIndex, size_t historyIndex) const noexcept;
        NODISCARD float GetHistoricalToolMajor(size_t pointerIndex, size_t historyIndex) const noexcept;
        NODISCARD float GetHistoricalToolMinor(size_t pointerIndex, size_t historyIndex) const noexcept;
        NODISCARD float GetHistoricalOrientation(size_t pointerIndex, size_t historyIndex) const noexcept;
        NODISCARD float GetHistoricalAxisValue(AndroidMotionEventAxis axis, size_t pointerIndex, size_t historyIndex) const noexcept;

    private:
        const AndroidInputEvent* motionEvent;
    };
}

#endif  // SYSTEM_ANDROID_ANDROID_INPUT_MOTION_EVENT_FACADE_H
