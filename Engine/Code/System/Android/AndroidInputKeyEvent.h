///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.6 (2021/07/11 14:00)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_KEY_EVENT_H
#define SYSTEM_ANDROID_ANDROID_INPUT_KEY_EVENT_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidInputUsing.h"

namespace System
{
    NODISCARD AndroidInputEventType SYSTEM_DEFAULT_DECLARE AndroidInputEventGetType(const AndroidInputEvent* event) noexcept;
    NODISCARD int32_t SYSTEM_DEFAULT_DECLARE AndroidInputEventGetDeviceID(const AndroidInputEvent* event) noexcept;
    NODISCARD AndroidInputSource SYSTEM_DEFAULT_DECLARE AndroidInputEventGetSource(const AndroidInputEvent* event) noexcept;
    NODISCARD AndroidKeyEventAction SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetAction(const AndroidInputEvent* keyEvent) noexcept;
    NODISCARD AndroidKeyEvent SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetFlags(const AndroidInputEvent* keyEvent) noexcept;
    NODISCARD AndroidKeyCodes SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetKeyCode(const AndroidInputEvent* keyEvent) noexcept;
    NODISCARD int32_t SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetScanCode(const AndroidInputEvent* keyEvent) noexcept;
    NODISCARD AndroidMeta SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetMetaState(const AndroidInputEvent* keyEvent) noexcept;
    NODISCARD int32_t SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetRepeatCount(const AndroidInputEvent* keyEvent) noexcept;
    NODISCARD int64_t SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetDownTime(const AndroidInputEvent* keyEvent) noexcept;
    NODISCARD int64_t SYSTEM_DEFAULT_DECLARE AndroidKeyEventGetEventTime(const AndroidInputEvent* keyEvent) noexcept;
}

#endif  // SYSTEM_ANDROID_ANDROID_INPUT_KEY_EVENT_H
