//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 23:11)

#include "System/SystemExport.h"

#include "AndroidInputQueue.h"
#include "Using/AndroidInputUsing.h"

void System::AndroidInputQueueAttachLooper([[maybe_unused]] AndroidInputQueue* queue, [[maybe_unused]] AndroidLooper* looper, [[maybe_unused]] LooperID ident, [[maybe_unused]] AndroidLooperCallbackFunc callback, [[maybe_unused]] void* data) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AInputQueue_attachLooper(queue, looper, ident, callback, data);
#else  // !SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidInputQueueDetachLooper([[maybe_unused]] AndroidInputQueue* queue) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AInputQueue_detachLooper(queue);
#else  // !SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_PLATFORM_ANDROID
}

int System::AndroidInputQueueHasEvents([[maybe_unused]] AndroidInputQueue* queue) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AInputQueue_hasEvents(queue);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 0;
#endif  // SYSTEM_PLATFORM_ANDROID
}

int System::AndroidInputQueueGetEvent(AndroidInputQueue* queue, AndroidInputEvent** outEvent) noexcept
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

int System::AndroidInputQueuePreDispatchEvent([[maybe_unused]] AndroidInputQueue* queue, [[maybe_unused]] AndroidInputEvent* event) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AInputQueue_preDispatchEvent(queue, event);
#else  // !SYSTEM_PLATFORM_ANDROID
    return 1;
#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidInputQueueFinishEvent([[maybe_unused]] AndroidInputQueue* queue, [[maybe_unused]] AndroidInputEvent* event, [[maybe_unused]] int handled) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
    return AInputQueue_finishEvent(queue, event, handled);
#else  // !SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_PLATFORM_ANDROID
}
