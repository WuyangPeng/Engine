//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 19:20)

#include "System/SystemExport.h"

#include "AndroidInputMotionEvent.h"
#include "System/Helper/EnumCast.h"

System::AndroidMotionEventAction System::AndroidMotionEventGetAction(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return UnderlyingCastEnum<AndroidMotionEventAction>(AMotionEvent_getAction(motionEvent));
#else  // !SYSTEM_PLATFORM_ANDROID
    if (motionEvent != nullptr)
        return motionEvent->GetAndroidMotionEventAction();
    else
        return AndroidMotionEventAction::Down;
#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMotionEvent System::AndroidMotionEventGetFlags(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return UnderlyingCastEnum<AndroidMotionEvent>(AMotionEvent_getFlags(motionEvent));
#else  // !SYSTEM_PLATFORM_ANDROID
    if (motionEvent != nullptr)
        return motionEvent->GetAndroidMotionEventFlag();
    else
        return AndroidMotionEvent::WindowIsObscured;
#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMeta System::AndroidndroidMotionEventGetMetaState(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return UnderlyingCastEnum<AndroidMeta>(AMotionEvent_getMetaState(motionEvent));
#else  // !SYSTEM_PLATFORM_ANDROID
    if (motionEvent != nullptr)
        return motionEvent->GetAndroidMeta();
    else
        return AndroidMeta::None;
#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMotionEventButton System::AndroidMotionEventGetButtonState(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return UnderlyingCastEnum<AndroidMotionEventButton>(AMotionEvent_getButtonState(motionEvent));
#else  // !SYSTEM_PLATFORM_ANDROID
    if (motionEvent != nullptr)
        return motionEvent->GetAndroidMotionEventButton();
    else
        return AndroidMotionEventButton::Primary;
#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMotionEventEdge System::AndroidMotionEventGetEdgeFlags(const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return UnderlyingCastEnum<AndroidMotionEventEdge>(AMotionEvent_getEdgeFlags(motionEvent));
#else  // !SYSTEM_PLATFORM_ANDROID
    if (motionEvent != nullptr)
        return motionEvent->GetAndroidMotionEventEdgeFlag();
    else
        return AndroidMotionEventEdge::None;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int64_t System::AndroidMotionEventGetDownTime([[maybe_unused]] const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getDownTime(motionEvent);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int64_t System::AndroidMotionEventGetEventTime([[maybe_unused]] const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getEventTime(motionEvent);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetXOffset([[maybe_unused]] const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getXOffset(motionEvent);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetYOffset([[maybe_unused]] const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getYOffset(motionEvent);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetXPrecision([[maybe_unused]] const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getXPrecision(motionEvent);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetYPrecision([[maybe_unused]] const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getYPrecision(motionEvent);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

size_t System::AndroidMotionEventGetPointerCount([[maybe_unused]] const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getPointerCount(motionEvent);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 1;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int System::AndroidMotionEventGetPointerId([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getPointerId(motionEvent, pointerIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMotionEventTool System::AndroidMotionEventGetToolType(const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return UnderlyingCastEnum<AndroidMotionEventTool>(AMotionEvent_getToolType(motionEvent, pointerIndex));
#else  // !SYSTEM_PLATFORM_ANDROID

    if (motionEvent != nullptr)
        return motionEvent->GetAndroidMotionEventToolType();
    else
        return AndroidMotionEventTool::Unknown;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetRawX([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getRawX(motionEvent, pointerIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetRawY([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getRawY(motionEvent, pointerIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetX([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getX(motionEvent, pointerIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetY([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getY(motionEvent, pointerIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetPressure([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getPressure(motionEvent, pointerIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetSize([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getSize(motionEvent, pointerIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetTouchMajor([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getTouchMajor(motionEvent, pointerIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetTouchMinor([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getTouchMinor(motionEvent, pointerIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetToolMajor([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getToolMajor(motionEvent, pointerIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetToolMinor([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getToolMinor(motionEvent, pointerIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetOrientation([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getOrientation(motionEvent, pointerIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetAxisValue([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] AndroidMotionEventAxis axis, [[maybe_unused]] size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getAxisValue(motionEvent, axis, pointerIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

size_t System::AndroidMotionEventGetHistorySize([[maybe_unused]] const AndroidInputEvent* motionEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistorySize(motionEvent);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int64_t System::AndroidMotionEventGetHistoricalEventTime([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistoricalEventTime(motionEvent, historyIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetHistoricalRawX([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex, [[maybe_unused]] size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistoricalRawX(motionEvent, pointerIndex, historyIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetHistoricalRawY([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex, [[maybe_unused]] size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistoricalRawY(motionEvent, pointerIndex, historyIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetHistoricalX([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex, [[maybe_unused]] size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistoricalX(motionEvent, pointerIndex, historyIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetHistoricalY([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex, [[maybe_unused]] size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistoricalY(motionEvent, pointerIndex, historyIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetHistoricalPressure([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex, [[maybe_unused]] size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistoricalPressure(motionEvent, pointerIndex, historyIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetHistoricalSize([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex, [[maybe_unused]] size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistoricalSize(motionEvent, pointerIndex, historyIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetHistoricalTouchMajor([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex, [[maybe_unused]] size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistoricalTouchMajor(motionEvent, pointerIndex, historyIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetHistoricalTouchMinor([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex, [[maybe_unused]] size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistoricalTouchMinor(motionEvent, pointerIndex, historyIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetHistoricalToolMajor([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex, [[maybe_unused]] size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistoricalToolMajor(motionEvent, pointerIndex, historyIndex);
#else  // !SYSTEM_PLATFORM_ANDROID

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetHistoricalToolMinor([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex, [[maybe_unused]] size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistoricalToolMinor(motionEvent, pointerIndex, historyIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetHistoricalOrientation([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] size_t pointerIndex, [[maybe_unused]] size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistoricalOrientation(motionEvent, pointerIndex, historyIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidMotionEventGetHistoricalAxisValue([[maybe_unused]] const AndroidInputEvent* motionEvent, [[maybe_unused]] AndroidMotionEventAxis axis, [[maybe_unused]] size_t pointerIndex, [[maybe_unused]] size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AMotionEvent_getHistoricalAxisValue(motionEvent, axis, pointerIndex, historyIndex);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0.0f;
#endif  // SYSTEM_PLATFORM_ANDROID
}
