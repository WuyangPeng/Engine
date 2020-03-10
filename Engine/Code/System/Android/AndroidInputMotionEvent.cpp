// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:03)

#include "System/SystemExport.h"

#include "AndroidInputMotionEvent.h"
#include "System/Helper/UnusedMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

System::AndroidMotionEventAction System
	::AndroidMotionEventGetAction(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return UnderlyingCastEnum<AndroidMotionEventAction>(AMotionEvent_getAction(motionEvent));
#else // !SYSTEM_PLATFORM_ANDROID
	if (motionEvent != nullptr)
		return motionEvent->m_AndroidMotionEventAction;
	else
		return AndroidMotionEventAction::Down;
#endif // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMotionEvent System
	::AndroidMotionEventGetFlags(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return UnderlyingCastEnum<AndroidMotionEvent>(AMotionEvent_getFlags(motionEvent));
#else // !SYSTEM_PLATFORM_ANDROID
	if (motionEvent != nullptr)
		return motionEvent->m_AndroidMotionEventFlag;
	else
		return AndroidMotionEvent::WindowIsObscured;
#endif // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMeta System
	::AndroidndroidMotionEventGetMetaState(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return UnderlyingCastEnum<AndroidMeta>(AMotionEvent_getMetaState(motionEvent));
#else // !SYSTEM_PLATFORM_ANDROID
	if (motionEvent != nullptr)
		return motionEvent->m_AndroidMeta;
	else
		return AndroidMeta::None;
#endif // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMotionEventButton System
	::AndroidMotionEventGetButtonState(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return UnderlyingCastEnum<AndroidMotionEventButton>(AMotionEvent_getButtonState(motionEvent));
#else // !SYSTEM_PLATFORM_ANDROID
	if (motionEvent != nullptr)
		return motionEvent->m_AndroidMotionEventButton;
	else
		return AndroidMotionEventButton::Primary;
#endif // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMotionEventEdge System
	::AndroidMotionEventGetEdgeFlags(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return UnderlyingCastEnum<AndroidMotionEventEdge>(AMotionEvent_getEdgeFlags(motionEvent));
#else // !SYSTEM_PLATFORM_ANDROID
	if (motionEvent != nullptr)
		return motionEvent->m_AndroidMotionEventEdgeFlag;
	else
		return AndroidMotionEventEdge::None;
#endif // SYSTEM_PLATFORM_ANDROID
}

int64_t System
	::AndroidMotionEventGetDownTime(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getDownTime(motionEvent);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

int64_t System
	::AndroidMotionEventGetEventTime(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getEventTime(motionEvent);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetXOffset(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getXOffset(motionEvent);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetYOffset(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getYOffset(motionEvent);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetXPrecision(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getXPrecision(motionEvent);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetYPrecision(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getYPrecision(motionEvent);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

size_t System
	::AndroidMotionEventGetPointerCount(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getPointerCount(motionEvent);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);

	return 1;
#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidMotionEventGetPointerId(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getPointerId(motionEvent, pointerIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMotionEventTool System
	::AndroidMotionEventGetToolType(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return UnderlyingCastEnum<AndroidMotionEventTool>(AMotionEvent_getToolType(motionEvent, pointerIndex));
#else // !SYSTEM_PLATFORM_ANDROID	
	SYSTEM_UNUSED_ARG(pointerIndex);

	if (motionEvent != nullptr)
		return motionEvent->m_AndroidMotionEventToolType;
	else
		return AndroidMotionEventTool::Unknown;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetRawX(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getRawX(motionEvent, pointerIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetRawY(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getRawY(motionEvent, pointerIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetX(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getX(motionEvent, pointerIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetY(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getY(motionEvent, pointerIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetPressure(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getPressure(motionEvent, pointerIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetSize(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getSize(motionEvent, pointerIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetTouchMajor(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getTouchMajor(motionEvent, pointerIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetTouchMinor(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getTouchMinor(motionEvent, pointerIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetToolMajor(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getToolMajor(motionEvent, pointerIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetToolMinor(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getToolMinor(motionEvent, pointerIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetOrientation(const AndroidInputEvent* motionEvent, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getOrientation(motionEvent, pointerIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetAxisValue(const AndroidInputEvent* motionEvent, AndroidMotionEventAxis axis, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getAxisValue(motionEvent, axis, pointerIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(axis);
	SYSTEM_UNUSED_ARG(pointerIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

size_t System
	::AndroidMotionEventGetHistorySize(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistorySize(motionEvent);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

int64_t System
	::AndroidMotionEventGetHistoricalEventTime(const AndroidInputEvent* motionEvent, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistoricalEventTime(motionEvent, historyIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(historyIndex);
	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetHistoricalRawX(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistoricalRawX(motionEvent, pointerIndex, historyIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);
	SYSTEM_UNUSED_ARG(historyIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetHistoricalRawY(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistoricalRawY(motionEvent, pointerIndex, historyIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);
	SYSTEM_UNUSED_ARG(historyIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetHistoricalX(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistoricalX(motionEvent, pointerIndex, historyIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);
	SYSTEM_UNUSED_ARG(historyIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetHistoricalY(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistoricalY(motionEvent, pointerIndex, historyIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);
	SYSTEM_UNUSED_ARG(historyIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetHistoricalPressure(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistoricalPressure(motionEvent, pointerIndex, historyIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);
	SYSTEM_UNUSED_ARG(historyIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetHistoricalSize(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistoricalSize(motionEvent, pointerIndex, historyIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);
	SYSTEM_UNUSED_ARG(historyIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetHistoricalTouchMajor(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistoricalTouchMajor(motionEvent, pointerIndex, historyIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);
	SYSTEM_UNUSED_ARG(historyIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetHistoricalTouchMinor(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistoricalTouchMinor(motionEvent, pointerIndex, historyIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);
	SYSTEM_UNUSED_ARG(historyIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetHistoricalToolMajor(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistoricalToolMajor(motionEvent, pointerIndex, historyIndex);
#else // !SYSTEM_PLATFORM_ANDROID

	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);
	SYSTEM_UNUSED_ARG(historyIndex);

	return 0.0f;

#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetHistoricalToolMinor(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistoricalToolMinor(motionEvent, pointerIndex, historyIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);
	SYSTEM_UNUSED_ARG(historyIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetHistoricalOrientation(const AndroidInputEvent* motionEvent, size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistoricalOrientation(motionEvent, pointerIndex, historyIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(pointerIndex);
	SYSTEM_UNUSED_ARG(historyIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}

float System
	::AndroidMotionEventGetHistoricalAxisValue(const AndroidInputEvent* motionEvent, AndroidMotionEventAxis axis, size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AMotionEvent_getHistoricalAxisValue(motionEvent, axis, pointerIndex, historyIndex);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(motionEvent);
	SYSTEM_UNUSED_ARG(axis);
	SYSTEM_UNUSED_ARG(pointerIndex);
	SYSTEM_UNUSED_ARG(historyIndex);

	return 0.0f;
#endif // SYSTEM_PLATFORM_ANDROID
}




