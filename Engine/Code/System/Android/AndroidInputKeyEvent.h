// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:27)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_KEY_EVENT_H
#define SYSTEM_ANDROID_ANDROID_INPUT_KEY_EVENT_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidInputUsing.h"

namespace System
{
	AndroidInputEventType SYSTEM_DEFAULT_DECLARE AndroidInputEventGetType(const AndroidInputEvent* event) noexcept;
	int SYSTEM_DEFAULT_DECLARE AndroidInputEventGetDeviceId(const AndroidInputEvent* event) noexcept;
	AndroidInputSource SYSTEM_DEFAULT_DECLARE AndroidInputEventGetSource(const AndroidInputEvent* event) noexcept;
	AndroidKeyEventAction SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetAction(const AndroidInputEvent* keyEvent) noexcept;
	AndroidKeyEvent SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetFlags(const AndroidInputEvent* keyEvent) noexcept;
	AndroidKeyCodes SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetKeyCode(const AndroidInputEvent* keyEvent) noexcept;
	int SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetScanCode(const AndroidInputEvent* keyEvent) noexcept;
	AndroidMeta SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetMetaState(const AndroidInputEvent* keyEvent) noexcept;
	int SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetRepeatCount(const AndroidInputEvent* keyEvent) noexcept;
	int64_t SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetDownTime(const AndroidInputEvent* keyEvent) noexcept;
	int64_t SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetEventTime(const AndroidInputEvent* keyEvent) noexcept;
}

#endif // SYSTEM_ANDROID_ANDROID_INPUT_KEY_EVENT_H
