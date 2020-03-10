// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 13:02)

#include "System/SystemExport.h"

#include "AndroidInputKeyEvent.h"
#include "System/Helper/UnusedMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

System::AndroidInputEventType System
	::AndroidInputEventGetType(const AndroidInputEvent* event) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return UnderlyingCastEnum<AndroidInputEventType>(AInputEvent_getType(event));
#else // !SYSTEM_PLATFORM_ANDROID
	if (event != nullptr)
		return event->m_AndroidInputEventType;
	else
		return AndroidInputEventType::Key;
#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidInputEventGetDeviceId(const AndroidInputEvent* event) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AInputEvent_getDeviceId(event);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(event);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

System::AndroidInputSource System
	::AndroidInputEventGetSource(const AndroidInputEvent* event) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return UnderlyingCastEnum<AndroidInputSource>(AInputEvent_getSource(event));
#else // !SYSTEM_PLATFORM_ANDROID
	if (event != nullptr)
		return event->m_AndroidInputSource;
	else
		return AndroidInputSource::Keyborad;
#endif // SYSTEM_PLATFORM_ANDROID
}

System::AndroidKeyEventAction System
	::AndroidKeyEventGetAction(const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return UnderlyingCastEnum<AndroidKeyEventAction>(AKeyEvent_getAction(keyEvent));
#else // !SYSTEM_PLATFORM_ANDROID
	if (keyEvent != nullptr)
		return keyEvent->m_AndroidKeyEventAction;
	else
		return AndroidKeyEventAction::Down;
#endif // SYSTEM_PLATFORM_ANDROID
}

System::AndroidKeyEvent System
	::AndroidKeyEventGetFlags(const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return UnderlyingCastEnum<AndroidKeyEvent>(AKeyEvent_getFlags(keyEvent));
#else // !SYSTEM_PLATFORM_ANDROID
	if (keyEvent != nullptr)
		return keyEvent->m_AndroidKeyEventFlag;
	else
		return AndroidKeyEvent::SoftKeyboard;
#endif // SYSTEM_PLATFORM_ANDROID
}

System::AndroidKeyCodes System
	::AndroidKeyEventGetKeyCode(const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return UnderlyingCastEnum<AndroidKeyCodes>(AKeyEvent_getKeyCode(keyEvent));
#else // !SYSTEM_PLATFORM_ANDROID
	if (keyEvent != nullptr)
		return keyEvent->m_AndroidKeyCodes;
	else
		return AndroidKeyCodes::A;
#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidKeyEventGetScanCode(const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AKeyEvent_getScanCode(keyEvent);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(keyEvent);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

System::AndroidMeta System
	::AndroidKeyEventGetMetaState(const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return UnderlyingCastEnum<AndroidMeta>(AKeyEvent_getMetaState(keyEvent));
#else // !SYSTEM_PLATFORM_ANDROID
	if (keyEvent != nullptr)
		return keyEvent->m_AndroidMeta;
	else
		return AndroidMeta::None;
#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidKeyEventGetRepeatCount(const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AKeyEvent_getRepeatCount(keyEvent);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(keyEvent);

	return 1;
#endif // SYSTEM_PLATFORM_ANDROID
}

int64_t System
	::AndroidKeyEventGetDownTime(const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AKeyEvent_getDownTime(keyEvent);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(keyEvent);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

int64_t System
	::AndroidKeyEventGetEventTime(const AndroidInputEvent* keyEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AKeyEvent_getEventTime(keyEvent);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(keyEvent);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

