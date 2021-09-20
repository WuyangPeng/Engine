///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/07/11 14:09)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_MOTION_EVENT_H
#define SYSTEM_ANDROID_ANDROID_INPUT_MOTION_EVENT_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidInputUsing.h"

namespace System
{
    NODISCARD AndroidMotionEventAction SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetAction(const AndroidInputEvent* motionEvent) noexcept;
    NODISCARD AndroidMotionEvent SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetFlags(const AndroidInputEvent* motionEvent) noexcept;
    NODISCARD AndroidMeta SYSTEM_DEFAULT_DECLARE AndroidndroidMotionEventGetMetaState(const AndroidInputEvent* motionEvent) noexcept;
    NODISCARD AndroidMotionEventButton SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetButtonState(const AndroidInputEvent* motionEvent) noexcept;
    NODISCARD AndroidMotionEventEdge SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetEdgeFlags(const AndroidInputEvent* motionEvent) noexcept;
    NODISCARD int64_t SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetDownTime(const AndroidInputEvent* motionEvent) noexcept;
    NODISCARD int64_t SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetEventTime(const AndroidInputEvent* motionEvent) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetXOffset(const AndroidInputEvent* motionEvent) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetYOffset(const AndroidInputEvent* motionEvent) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetXPrecision(const AndroidInputEvent* motionEvent) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetYPrecision(const AndroidInputEvent* motionEvent) noexcept;
    NODISCARD size_t SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetPointerCount(const AndroidInputEvent* motionEvent) noexcept;
    NODISCARD int32_t SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetPointerID(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
    NODISCARD AndroidMotionEventTool SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetToolType(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetRawX(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetRawY(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetX(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetY(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetPressure(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetSize(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetTouchMajor(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetTouchMinor(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetToolMajor(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetToolMinor(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetOrientation(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetAxisValue(const AndroidInputEvent* motionEvent, AndroidMotionEventAxis axis, size_t pointerIndex) noexcept;
    NODISCARD size_t SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistorySize(const AndroidInputEvent* motionEvent) noexcept;
    NODISCARD int64_t SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistoricalEventTime(const AndroidInputEvent* motionEvent, size_t historyIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistoricalRawX(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistoricalRawY(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistoricalX(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistoricalY(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistoricalPressure(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistoricalSize(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistoricalTouchMajor(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistoricalTouchMinor(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistoricalToolMajor(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistoricalToolMinor(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistoricalOrientation(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
    NODISCARD float SYSTEM_DEFAULT_DECLARE AndroidMotionEventGetHistoricalAxisValue(const AndroidInputEvent* motionEvent, AndroidMotionEventAxis axis, size_t pointerIndex, size_t historyIndex) noexcept;
}

#endif  // SYSTEM_ANDROID_ANDROID_INPUT_MOTION_EVENT_H
