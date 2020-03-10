// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:21)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_QUEUE_FWD_H
#define SYSTEM_ANDROID_ANDROID_INPUT_QUEUE_FWD_H 

#include "AndroidFlagsFwd.h"
#include "System/Android/Using/AndroidLooperUsing.h"

namespace System
{
	void AndroidInputQueueAttachLooper(AndroidInputQueue* queue, AndroidLooper* looper, LooperID ident, AndroidLooperCallbackFunc callback, void* data) noexcept;
	void AndroidInputQueueDetachLooper(AndroidInputQueue* queue) noexcept;
	int AndroidInputQueueHasEvents(AndroidInputQueue* queue) noexcept;
	int AndroidInputQueueGetEvent(AndroidInputQueue* queue, AndroidInputEvent** outEvent) noexcept;
	int AndroidInputQueuePreDispatchEvent(AndroidInputQueue* queue, AndroidInputEvent* event) noexcept;
	void AndroidInputQueueFinishEvent(AndroidInputQueue* queue, AndroidInputEvent* event, int handled) noexcept;
}

#endif // SYSTEM_ANDROID_ANDROID_INPUT_QUEUE_FWD_H