/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 19:29)

#include "System/SystemExport.h"

#include "AndroidInputMotionEventFacade.h"
#include "Flags/AndroidInputFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"

System::AndroidInputMotionEventFacade::AndroidInputMotionEventFacade(const AndroidInputEvent* motionEvent) noexcept
    : motionEvent{ motionEvent }
{
}

System::AndroidMotionEventAction System::AndroidInputMotionEventFacade::GetAction() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return UnderlyingCastEnum<AndroidMotionEventAction>(AMotionEvent_getAction(motionEvent));

#else  // !SYSTEM_PLATFORM_ANDROID

    if (motionEvent != nullptr)
        return motionEvent->GetAndroidMotionEventAction();
    else
        return AndroidMotionEventAction::Mask;

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMotionEventFlag System::AndroidInputMotionEventFacade::GetFlags() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return UnderlyingCastEnum<AndroidMotionEventFlag>(AMotionEvent_getFlags(motionEvent));

#else  // !SYSTEM_PLATFORM_ANDROID

    if (motionEvent != nullptr)
        return motionEvent->GetAndroidMotionEventFlag();
    else
        return AndroidMotionEventFlag::WindowIsObscured;

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMeta System::AndroidInputMotionEventFacade::GetMetaState() noexcept
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

System::AndroidMotionEventButton System::AndroidInputMotionEventFacade::GetButtonState() noexcept
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

System::AndroidMotionEventEdgeFlag System::AndroidInputMotionEventFacade::GetEdgeFlags() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return UnderlyingCastEnum<AndroidMotionEventEdgeFlag>(AMotionEvent_getEdgeFlags(motionEvent));

#else  // !SYSTEM_PLATFORM_ANDROID

    if (motionEvent != nullptr)
        return motionEvent->GetAndroidMotionEventEdgeFlag();
    else
        return AndroidMotionEventEdgeFlag::None;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int64_t System::AndroidInputMotionEventFacade::GetDownTime() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getDownTime(motionEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int64_t System::AndroidInputMotionEventFacade::GetEventTime() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getEventTime(motionEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetXOffset() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getXOffset(motionEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetYOffset() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getYOffset(motionEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetXPrecision() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getXPrecision(motionEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetYPrecision() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getYPrecision(motionEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

size_t System::AndroidInputMotionEventFacade::GetPointerCount() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getPointerCount(motionEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0u;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidInputMotionEventFacade::GetPointerId(size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getPointerId(motionEvent, pointerIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex);

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMotionEventToolType System::AndroidInputMotionEventFacade::GetToolType(size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return UnderlyingCastEnum<AndroidMotionEventToolType>(AMotionEvent_getToolType(motionEvent, pointerIndex));

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex);

    if (motionEvent != nullptr)
        return motionEvent->GetAndroidMotionEventToolType();
    else
        return AndroidMotionEventToolType::Unknown;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetRawX(size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getRawX(motionEvent, pointerIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetRawY(size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getRawY(motionEvent, pointerIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetX(size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getX(motionEvent, pointerIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetY(size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getY(motionEvent, pointerIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetPressure(size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getPressure(motionEvent, pointerIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetSize(size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getSize(motionEvent, pointerIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetTouchMajor(size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getTouchMajor(motionEvent, pointerIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetTouchMinor(size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getTouchMinor(motionEvent, pointerIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetToolMajor(size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getToolMajor(motionEvent, pointerIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetToolMinor(size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getToolMinor(motionEvent, pointerIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetOrientation(size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getOrientation(motionEvent, pointerIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetAxisValue(AndroidMotionEventAxis axis, size_t pointerIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getAxisValue(motionEvent, axis, pointerIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(axis, pointerIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

size_t System::AndroidInputMotionEventFacade::GetHistorySize() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistorySize(motionEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0u;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int64_t System::AndroidInputMotionEventFacade::GetHistoricalEventTime(size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistoricalEventTime(motionEvent, historyIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(historyIndex);

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetHistoricalRawX(size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistoricalRawX(motionEvent, pointerIndex, historyIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex, historyIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetHistoricalRawY(size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistoricalRawY(motionEvent, pointerIndex, historyIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex, historyIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetHistoricalX(size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistoricalX(motionEvent, pointerIndex, historyIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex, historyIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetHistoricalY(size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistoricalY(motionEvent, pointerIndex, historyIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex, historyIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetHistoricalPressure(size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistoricalPressure(motionEvent, pointerIndex, historyIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex, historyIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetHistoricalSize(size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistoricalSize(motionEvent, pointerIndex, historyIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex, historyIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetHistoricalTouchMajor(size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistoricalTouchMajor(motionEvent, pointerIndex, historyIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex, historyIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetHistoricalTouchMinor(size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistoricalTouchMinor(motionEvent, pointerIndex, historyIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex, historyIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetHistoricalToolMajor(size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistoricalToolMajor(motionEvent, pointerIndex, historyIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex, historyIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetHistoricalToolMinor(size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistoricalToolMinor(motionEvent, pointerIndex, historyIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex, historyIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetHistoricalOrientation(size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistoricalOrientation(motionEvent, pointerIndex, historyIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(pointerIndex, historyIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}

float System::AndroidInputMotionEventFacade::GetHistoricalAxisValue(AndroidMotionEventAxis axis, size_t pointerIndex, size_t historyIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AMotionEvent_getHistoricalAxisValue(motionEvent, axis, pointerIndex, historyIndex);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(axis, pointerIndex, historyIndex);

    return 0.0f;

#endif  // SYSTEM_PLATFORM_ANDROID
}
