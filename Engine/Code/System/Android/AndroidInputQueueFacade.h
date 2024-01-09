/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 19:28)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_QUEUE_FACADE_H
#define SYSTEM_ANDROID_ANDROID_INPUT_QUEUE_FACADE_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidInputUsing.h"
#include "Using/AndroidLooperUsing.h"

namespace System
{
    class SYSTEM_DEFAULT_DECLARE AndroidInputQueueFacade final
    {
    public:
        using ClassType = AndroidInputQueueFacade;

    public:
        explicit AndroidInputQueueFacade(AndroidInputQueue* androidInputQueue) noexcept;

        void AttachLooper(AndroidLooper* looper, LooperId ident, AndroidLooperCallbackFunction callback, void* data) noexcept;
        void DetachLooper() noexcept;
        NODISCARD int32_t HasEvents() noexcept;
        NODISCARD int32_t GetEvent(AndroidInputEvent** outEvent) noexcept;
        NODISCARD int32_t PreviousDispatchEvent(AndroidInputEvent* event) noexcept;
        void FinishEvent(AndroidInputEvent* event, int32_t handled) noexcept;

    private:
        AndroidInputQueue* androidInputQueue;
    };
}

#endif  // SYSTEM_ANDROID_ANDROID_INPUT_QUEUE_FACADE_H
