/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:19)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_EVENT_FACADE_H
#define SYSTEM_ANDROID_ANDROID_INPUT_EVENT_FACADE_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidInputUsing.h"

namespace System
{
    class SYSTEM_DEFAULT_DECLARE AndroidInputEventFacade final
    {
    public:
        using ClassType = AndroidInputEventFacade;

    public:
        explicit AndroidInputEventFacade(const AndroidInputEvent* androidInputEvent) noexcept;

        NODISCARD AndroidInputEventType GetType() const noexcept;
        NODISCARD int32_t GetDeviceId() const noexcept;
        NODISCARD AndroidInputSource GetSource() const noexcept;
        NODISCARD AndroidKeyEventAction GetAction() const noexcept;
        NODISCARD AndroidKeyEventFlag GetFlags() const noexcept;
        NODISCARD AndroidKeyCodes GetKeyCode() const noexcept;
        NODISCARD int32_t GetScanCode() const noexcept;
        NODISCARD AndroidMeta GetMetaState() const noexcept;
        NODISCARD int32_t GetRepeatCount() const noexcept;
        NODISCARD int64_t GetDownTime() const noexcept;
        NODISCARD int64_t GetEventTime() const noexcept;

    private:
        const AndroidInputEvent* androidInputEvent;
    };

}

#endif  // SYSTEM_ANDROID_ANDROID_INPUT_EVENT_FACADE_H
