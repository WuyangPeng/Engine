// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.0 (2020/01/02 13:03)

#include "System/SystemExport.h"

#include "AndroidInputQueue.h"
#include "Using/AndroidInputUsing.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
#include SYSTEM_WARNING_DISABLE(26487)
void System
	::AndroidInputQueueAttachLooper(AndroidInputQueue* queue, AndroidLooper* looper, LooperID ident, AndroidLooperCallbackFunc callback, void* data) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AInputQueue_attachLooper(queue, looper, ident, callback, data);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(queue);
	SYSTEM_UNUSED_ARG(looper);
	SYSTEM_UNUSED_ARG(ident);
	SYSTEM_UNUSED_ARG(callback);
	SYSTEM_UNUSED_ARG(data);
#endif // SYSTEM_PLATFORM_ANDROID
}

void System
	::AndroidInputQueueDetachLooper(AndroidInputQueue* queue) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AInputQueue_detachLooper(queue);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(queue);
#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidInputQueueHasEvents(AndroidInputQueue* queue) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AInputQueue_hasEvents(queue);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(queue);

	return 0;
#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidInputQueueGetEvent(AndroidInputQueue* queue, AndroidInputEvent** outEvent) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AInputQueue_getEvent(queue, outEvent);
#else // !SYSTEM_PLATFORM_ANDROID	

	if (queue != nullptr && outEvent != nullptr)
	{
		*outEvent = queue->GetCurrentAndroidInputEvent();

		return queue->GetSize();
	}
	else
	{
		return 0;
	}

#endif // SYSTEM_PLATFORM_ANDROID
}

int System
	::AndroidInputQueuePreDispatchEvent(AndroidInputQueue* queue, AndroidInputEvent* event) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AInputQueue_preDispatchEvent(queue, event);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(queue);
	SYSTEM_UNUSED_ARG(event);

	return 1;
#endif // SYSTEM_PLATFORM_ANDROID
}

void System
	::AndroidInputQueueFinishEvent(AndroidInputQueue* queue, AndroidInputEvent* event, int handled) noexcept
{
#ifdef SYSTEM_PLATFORM_ANDROID
	return AInputQueue_finishEvent(queue, event, handled);
#else // !SYSTEM_PLATFORM_ANDROID
	SYSTEM_UNUSED_ARG(queue);
	SYSTEM_UNUSED_ARG(event);
	SYSTEM_UNUSED_ARG(handled);
#endif // SYSTEM_PLATFORM_ANDROID
}
#include STSTEM_WARNING_POP





