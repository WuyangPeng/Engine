/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 19:29)

#include "System/SystemExport.h"

#include "AndroidInputQueueFacade.h"
#include "Using/AndroidInputUsing.h"
#include "System/Helper/Tools.h"

System::AndroidInputQueueFacade::AndroidInputQueueFacade(AndroidInputQueue* androidInputQueue) noexcept
    : androidInputQueue{ androidInputQueue }
{
}

void System::AndroidInputQueueFacade::AttachLooper(AndroidLooper* looper, LooperId ident, AndroidLooperCallbackFunction callback, void* data) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AInputQueue_attachLooper(androidInputQueue, looper, ident, callback, data);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(looper, ident, callback, data);

#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidInputQueueFacade::DetachLooper() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AInputQueue_detachLooper(androidInputQueue);

#else  // !SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidInputQueueFacade::HasEvents() noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AInputQueue_hasEvents(androidInputQueue);

#else  // !SYSTEM_PLATFORM_ANDROID

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidInputQueueFacade::GetEvent(AndroidInputEvent** outEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AInputQueue_getEvent(androidInputQueue, outEvent);

#else  // !SYSTEM_PLATFORM_ANDROID

    if (androidInputQueue != nullptr)
    {
        if (outEvent != nullptr)
        {
            *outEvent = androidInputQueue->GetCurrentAndroidInputEvent();
        }

        return androidInputQueue->GetSize();
    }
    else
    {
        return 0;
    }

#endif  // SYSTEM_PLATFORM_ANDROID
}

int32_t System::AndroidInputQueueFacade::PreviousDispatchEvent(AndroidInputEvent* event) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AInputQueue_preDispatchEvent(androidInputQueue, event);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(event);

    return 0;

#endif  // SYSTEM_PLATFORM_ANDROID
}

void System::AndroidInputQueueFacade::FinishEvent(AndroidInputEvent* event, int32_t handled) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID

    return AInputQueue_finishEvent(androidInputQueue, event, handled);

#else  // !SYSTEM_PLATFORM_ANDROID

    UnusedFunction(event, handled);

#endif  // SYSTEM_PLATFORM_ANDROID
}
