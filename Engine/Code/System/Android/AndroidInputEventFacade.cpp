/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:19)

#include "System/SystemExport.h"

#include "AndroidInputEventFacade.h"
#include "Flags/AndroidInputFlags.h"
#include "Flags/AndroidKeyCodesFlags.h"
#include "System/Helper/EnumCast.h"

System::AndroidInputEventFacade::AndroidInputEventFacade(const AndroidInputEvent* androidInputEvent) noexcept
    : androidInputEvent{ androidInputEvent }
{
}

System::AndroidInputEventType System::AndroidInputEventFacade::GetType() const noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return UnderlyingCastEnum<AndroidInputEventType>(AInputEvent_getType(androidInputEvent));

#else  // !SYSTEM_PLATFORM_ANDROID

    if (androidInputEvent != nullptr)
        return androidInputEvent->GetAndroidInputEventType();
    else
        return AndroidInputEventType::Key;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidInputEventFacade::GetDeviceId() const noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AInputEvent_getDeviceId(androidInputEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidInputSource System::AndroidInputEventFacade::GetSource() const noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return UnderlyingCastEnum<AndroidInputSource>(AInputEvent_getSource(androidInputEvent));

#else  // !SYSTEM_PLATFORM_ANDROID

    if (androidInputEvent != nullptr)
        return androidInputEvent->GetAndroidInputSource();
    else
        return AndroidInputSource::Unknown;

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidKeyEventAction System::AndroidInputEventFacade::GetAction() const noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return UnderlyingCastEnum<AndroidKeyEventAction>(AKeyEvent_getAction(androidInputEvent));

#else  // !SYSTEM_PLATFORM_ANDROID

    if (androidInputEvent != nullptr)
        return androidInputEvent->GetAndroidKeyEventAction();
    else
        return AndroidKeyEventAction::Down;

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidKeyEventFlag System::AndroidInputEventFacade::GetFlags() const noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return UnderlyingCastEnum<AndroidKeyEventFlag>(AKeyEvent_getFlags(androidInputEvent));

#else  // !SYSTEM_PLATFORM_ANDROID

    if (androidInputEvent != nullptr)
        return androidInputEvent->GetAndroidKeyEventFlag();
    else
        return AndroidKeyEventFlag::Null;

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidKeyCodes System::AndroidInputEventFacade::GetKeyCode() const noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return UnderlyingCastEnum<AndroidKeyCodes>(AKeyEvent_getKeyCode(androidInputEvent));

#else  // !SYSTEM_PLATFORM_ANDROID

    if (androidInputEvent != nullptr)
        return androidInputEvent->GetAndroidKeyCodes();
    else
        return AndroidKeyCodes::Unknown;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidInputEventFacade::GetScanCode() const noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AKeyEvent_getScanCode(androidInputEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMeta System::AndroidInputEventFacade::GetMetaState() const noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return UnderlyingCastEnum<AndroidMeta>(AKeyEvent_getMetaState(androidInputEvent));

#else  // !SYSTEM_PLATFORM_ANDROID

    if (androidInputEvent != nullptr)
        return androidInputEvent->GetAndroidMeta();
    else
        return AndroidMeta::None;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidInputEventFacade::GetRepeatCount() const noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AKeyEvent_getRepeatCount(androidInputEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int64_t System::AndroidInputEventFacade::GetDownTime() const noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AKeyEvent_getDownTime(androidInputEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int64_t System::AndroidInputEventFacade::GetEventTime() const noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AKeyEvent_getEventTime(androidInputEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}
