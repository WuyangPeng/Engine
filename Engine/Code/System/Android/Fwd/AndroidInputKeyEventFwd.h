// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:21)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_KEY_EVENT_FWD_H
#define SYSTEM_ANDROID_ANDROID_INPUT_KEY_EVENT_FWD_H 

#include "AndroidFlagsFwd.h"
#include "System/Android/Using/AndroidInputUsing.h"

namespace System
{
	AndroidInputEventType AndroidInputEventGetType(const AndroidInputEvent* event) noexcept;
	int AndroidInputEventGetDeviceId(const AndroidInputEvent* event) noexcept;
	AndroidInputSource AndroidInputEventGetSource(const AndroidInputEvent* event) noexcept;
	AndroidKeyEventAction AndroidKeyEventGetAction(const AndroidInputEvent* keyEvent) noexcept;
	AndroidKeyEvent AndroidKeyEventGetFlags(const AndroidInputEvent* keyEvent) noexcept;
	AndroidKeyCodes AndroidKeyEventGetKeyCode(const AndroidInputEvent* keyEvent) noexcept;
	int AndroidKeyEventGetScanCode(const AndroidInputEvent* keyEvent) noexcept;
	AndroidMeta AndroidKeyEventGetMetaState(const AndroidInputEvent* keyEvent) noexcept;
	int AndroidKeyEventGetRepeatCount(const AndroidInputEvent* keyEvent) noexcept;
	int64_t AndroidKeyEventGetDownTime(const AndroidInputEvent* keyEvent) noexcept;
	int64_t AndroidKeyEventGetEventTime(const AndroidInputEvent* keyEvent) noexcept;
}

#endif // SYSTEM_ANDROID_ANDROID_INPUT_KEY_EVENT_FWD_H