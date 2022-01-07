///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 22:56)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_QUEUE_H
#define SYSTEM_ANDROID_ANDROID_INPUT_QUEUE_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidInputUsing.h"
#include "Using/AndroidLooperUsing.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE AndroidInputQueueAttachLooper(AndroidInputQueue* queue, AndroidLooper* looper, LooperID ident, AndroidLooperCallbackFunc callback, void* data) noexcept;
    void SYSTEM_DEFAULT_DECLARE AndroidInputQueueDetachLooper(AndroidInputQueue* queue) noexcept;
    NODISCARD int32_t SYSTEM_DEFAULT_DECLARE AndroidInputQueueHasEvents(AndroidInputQueue* queue) noexcept;
    NODISCARD int32_t SYSTEM_DEFAULT_DECLARE AndroidInputQueueGetEvent(AndroidInputQueue* queue, AndroidInputEvent** outEvent) noexcept;
    NODISCARD int32_t SYSTEM_DEFAULT_DECLARE AndroidInputQueuePreDispatchEvent(AndroidInputQueue* queue, AndroidInputEvent* event) noexcept;
    void SYSTEM_DEFAULT_DECLARE AndroidInputQueueFinishEvent(AndroidInputQueue* queue, AndroidInputEvent* event, int32_t handled) noexcept;
}

#endif  // SYSTEM_ANDROID_ANDROID_INPUT_QUEUE_H
