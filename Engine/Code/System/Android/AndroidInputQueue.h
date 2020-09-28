//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 18:43)

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
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE AndroidInputQueueHasEvents(AndroidInputQueue* queue) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE AndroidInputQueueGetEvent(AndroidInputQueue* queue, AndroidInputEvent** outEvent) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE AndroidInputQueuePreDispatchEvent(AndroidInputQueue* queue, AndroidInputEvent* event) noexcept;
    void SYSTEM_DEFAULT_DECLARE AndroidInputQueueFinishEvent(AndroidInputQueue* queue, AndroidInputEvent* event, int handled) noexcept;
}

#endif  // SYSTEM_ANDROID_ANDROID_INPUT_QUEUE_H
