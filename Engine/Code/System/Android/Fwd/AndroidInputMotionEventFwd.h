// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:21)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_MOTION_EVENT_FWD_H
#define SYSTEM_ANDROID_ANDROID_INPUT_MOTION_EVENT_FWD_H 

#include "AndroidFlagsFwd.h"

namespace System
{
	AndroidMotionEventAction AndroidMotionEventGetAction(const AndroidInputEvent* motionEvent) noexcept;
	AndroidMotionEvent AndroidMotionEventGetFlags(const AndroidInputEvent* motionEvent) noexcept;
	AndroidMeta  AndroidndroidMotionEventGetMetaState(const AndroidInputEvent* motionEvent) noexcept;
	AndroidMotionEventButton AndroidMotionEventGetButtonState(const AndroidInputEvent* motionEvent) noexcept;
	AndroidMotionEventEdge  AndroidMotionEventGetEdgeFlags(const AndroidInputEvent* motionEvent) noexcept;
	int64_t AndroidMotionEventGetDownTime(const AndroidInputEvent* motionEvent) noexcept;
	int64_t AndroidMotionEventGetEventTime(const AndroidInputEvent* motionEvent) noexcept;
	float AndroidMotionEventGetXOffset(const AndroidInputEvent* motionEvent) noexcept;
	float AndroidMotionEventGetYOffset(const AndroidInputEvent* motionEvent) noexcept;
	float AndroidMotionEventGetXPrecision(const AndroidInputEvent* motionEvent) noexcept;
	float AndroidMotionEventGetYPrecision(const AndroidInputEvent* motionEvent) noexcept;
	size_t AndroidMotionEventGetPointerCount(const AndroidInputEvent* motionEvent) noexcept;
	int AndroidMotionEventGetPointerId(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
	AndroidMotionEventTool AndroidMotionEventGetToolType(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
	float AndroidMotionEventGetRawX(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
	float AndroidMotionEventGetRawY(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
	float AndroidMotionEventGetX(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
	float AndroidMotionEventGetY(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
	float AndroidMotionEventGetPressure(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
	float AndroidMotionEventGetSize(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
	float AndroidMotionEventGetTouchMajor(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
	float AndroidMotionEventGetTouchMinor(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
	float AndroidMotionEventGetToolMajor(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
	float AndroidMotionEventGetToolMinor(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
	float AndroidMotionEventGetOrientation(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept;
	float AndroidMotionEventGetAxisValue(const AndroidInputEvent* motionEvent, AndroidMotionEventAxis axis, size_t pointerIndex) noexcept;
	size_t AndroidMotionEventGetHistorySize(const AndroidInputEvent* motionEvent) noexcept;
	int64_t AndroidMotionEventGetHistoricalEventTime(const AndroidInputEvent* motionEvent, size_t historyIndex) noexcept;
	float AndroidMotionEventGetHistoricalRawX(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
	float AndroidMotionEventGetHistoricalRawY(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
	float AndroidMotionEventGetHistoricalX(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
	float AndroidMotionEventGetHistoricalY(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
	float AndroidMotionEventGetHistoricalPressure(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
	float AndroidMotionEventGetHistoricalSize(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
	float AndroidMotionEventGetHistoricalTouchMajor(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
	float AndroidMotionEventGetHistoricalTouchMinor(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
	float AndroidMotionEventGetHistoricalToolMajor(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
	float AndroidMotionEventGetHistoricalToolMinor(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
	float AndroidMotionEventGetHistoricalOrientation(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept;
	float AndroidMotionEventGetHistoricalAxisValue(const AndroidInputEvent* motionEvent, AndroidMotionEventAxis axis, size_t pointerIndex, size_t historyIndex) noexcept;
}

#endif // SYSTEM_ANDROID_ANDROID_INPUT_MOTION_EVENT_FWD_H