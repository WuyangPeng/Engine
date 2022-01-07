///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 23:00)

#include "System/SystemExport.h"

#include "AndroidInputQueue.h"
#include "Using/AndroidInputUsing.h"
#include "System/Helper/WindowsMacro.h"

void System::AndroidInputQueueAttachLooper(AndroidInputQueue* queue, AndroidLooper* looper, LooperID ident, AndroidLooperCallbackFunc callback, void* data) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AInputQueue_attachLooper(queue, looper, ident, callback, data);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(queue, looper, ident, callback, data);

#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidInputQueueDetachLooper(AndroidInputQueue* queue) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AInputQueue_detachLooper(queue);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(queue);

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidInputQueueHasEvents(AndroidInputQueue* queue) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AInputQueue_hasEvents(queue);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(queue);

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidInputQueueGetEvent(AndroidInputQueue* queue, AndroidInputEvent** outEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AInputQueue_getEvent(queue, outEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    if (queue != nullptr && outEvent != nullptr)
    {
        *outEvent = queue->GetCurrentAndroidInputEvent();

        return queue->GetSize();
    }
    else
    {
        return 0;
    }

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidInputQueuePreDispatchEvent(AndroidInputQueue* queue, AndroidInputEvent* event) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AInputQueue_preDispatchEvent(queue, event);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(queue, event);

    return 1;

#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidInputQueueFinishEvent(AndroidInputQueue* queue, AndroidInputEvent* event, int32_t handled) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AInputQueue_finishEvent(queue, event, handled);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(queue, event, handled);

#endif  // SYSTEM_PLATFORM_ANDROID
}
