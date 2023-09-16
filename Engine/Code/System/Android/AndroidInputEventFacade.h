///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/26 15:32)

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

        NODISCARD AndroidInputEventType GetType() noexcept;
        NODISCARD int32_t GetDeviceId() noexcept;
        NODISCARD AndroidInputSource GetSource() noexcept;
        NODISCARD AndroidKeyEventAction GetAction() noexcept;
        NODISCARD AndroidKeyEventFlag GetFlags() noexcept;
        NODISCARD AndroidKeyCodes GetKeyCode() noexcept;
        NODISCARD int32_t GetScanCode() noexcept;
        NODISCARD AndroidMeta GetMetaState() noexcept;
        NODISCARD int32_t GetRepeatCount() noexcept;
        NODISCARD int64_t GetDownTime() noexcept;
        NODISCARD int64_t GetEventTime() noexcept;

    private:
        const AndroidInputEvent* androidInputEvent;
    };

}

#endif  // SYSTEM_ANDROID_ANDROID_INPUT_EVENT_FACADE_H
