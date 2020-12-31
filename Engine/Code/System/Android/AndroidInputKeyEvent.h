//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 18:43)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_KEY_EVENT_H
#define SYSTEM_ANDROID_ANDROID_INPUT_KEY_EVENT_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidInputUsing.h"

namespace System
{
    [[nodiscard]] AndroidInputEventType SYSTEM_DEFAULT_DECLARE AndroidInputEventGetType(const AndroidInputEvent* event) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE AndroidInputEventGetDeviceId(const AndroidInputEvent* event) noexcept;
    [[nodiscard]] AndroidInputSource SYSTEM_DEFAULT_DECLARE AndroidInputEventGetSource(const AndroidInputEvent* event) noexcept;
    [[nodiscard]] AndroidKeyEventAction SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetAction(const AndroidInputEvent* keyEvent) noexcept;
    [[nodiscard]] AndroidKeyEvent SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetFlags(const AndroidInputEvent* keyEvent) noexcept;
    [[nodiscard]] AndroidKeyCodes SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetKeyCode(const AndroidInputEvent* keyEvent) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetScanCode(const AndroidInputEvent* keyEvent) noexcept;
    [[nodiscard]] AndroidMeta SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetMetaState(const AndroidInputEvent* keyEvent) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetRepeatCount(const AndroidInputEvent* keyEvent) noexcept;
    [[nodiscard]] int64_t SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetDownTime(const AndroidInputEvent* keyEvent) noexcept;
    [[nodiscard]] int64_t SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetEventTime(const AndroidInputEvent* keyEvent) noexcept;
}

#endif  // SYSTEM_ANDROID_ANDROID_INPUT_KEY_EVENT_H
