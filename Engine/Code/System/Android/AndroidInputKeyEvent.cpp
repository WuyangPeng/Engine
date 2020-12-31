//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 19:20)

#include "System/SystemExport.h"

#include "AndroidInputKeyEvent.h"
#include "System/Helper/EnumCast.h"

System::AndroidInputEventType System::AndroidInputEventGetType(const AndroidInputEvent* event) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return UnderlyingCastEnum<AndroidInputEventType>(AInputEvent_getType(event));
#else  // !SYSTEM_PLATFORM_ANDROID
    if (event != nullptr)
        return event->GetAndroidInputEventType();
    else
        return AndroidInputEventType::Key;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int System::AndroidInputEventGetDeviceId([[maybe_unused]] const AndroidInputEvent* event) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AInputEvent_getDeviceId(event);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidInputSource System::AndroidInputEventGetSource(const AndroidInputEvent* event) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return UnderlyingCastEnum<AndroidInputSource>(AInputEvent_getSource(event));
#else  // !SYSTEM_PLATFORM_ANDROID
    if (event != nullptr)
        return event->GetAndroidInputSource();
    else
        return AndroidInputSource::Keyborad;
#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidKeyEventAction System::AndroidKeyEventGetAction(const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return UnderlyingCastEnum<AndroidKeyEventAction>(AKeyEvent_getAction(keyEvent));
#else  // !SYSTEM_PLATFORM_ANDROID
    if (keyEvent != nullptr)
        return keyEvent->GetAndroidKeyEventAction();
    else
        return AndroidKeyEventAction::Down;
#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidKeyEvent System::AndroidKeyEventGetFlags(const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return UnderlyingCastEnum<AndroidKeyEvent>(AKeyEvent_getFlags(keyEvent));
#else  // !SYSTEM_PLATFORM_ANDROID
    if (keyEvent != nullptr)
        return keyEvent->GetAndroidKeyEventFlag();
    else
        return AndroidKeyEvent::SoftKeyboard;
#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidKeyCodes System::AndroidKeyEventGetKeyCode(const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return UnderlyingCastEnum<AndroidKeyCodes>(AKeyEvent_getKeyCode(keyEvent));
#else  // !SYSTEM_PLATFORM_ANDROID
    if (keyEvent != nullptr)
        return keyEvent->GetAndroidKeyCodes();
    else
        return AndroidKeyCodes::A;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int System::AndroidKeyEventGetScanCode([[maybe_unused]] const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AKeyEvent_getScanCode(keyEvent);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMeta System::AndroidKeyEventGetMetaState(const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return UnderlyingCastEnum<AndroidMeta>(AKeyEvent_getMetaState(keyEvent));
#else  // !SYSTEM_PLATFORM_ANDROID
    if (keyEvent != nullptr)
        return keyEvent->GetAndroidMeta();
    else
        return AndroidMeta::None;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int System::AndroidKeyEventGetRepeatCount([[maybe_unused]] const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AKeyEvent_getRepeatCount(keyEvent);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 1;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int64_t System::AndroidKeyEventGetDownTime([[maybe_unused]] const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AKeyEvent_getDownTime(keyEvent);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int64_t System::AndroidKeyEventGetEventTime([[maybe_unused]] const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AKeyEvent_getEventTime(keyEvent);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}
