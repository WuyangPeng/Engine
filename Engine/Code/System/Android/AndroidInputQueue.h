// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:27)

#ifndef SYSTEM_ANDROID_ANDROID_INPUT_QUEUE_H
#define SYSTEM_ANDROID_ANDROID_INPUT_QUEUE_H

#include "System/SystemDll.h"

#include "Fwd/AndroidFlagsFwd.h"
#include "Using/AndroidLooperUsing.h"
#include "Using/AndroidInputUsing.h"

namespace System
{
	void SYSTEM_DEFAULT_DECLARE AndroidInputQueueAttachLooper(AndroidInputQueue* queue, AndroidLooper* looper, LooperID ident, AndroidLooperCallbackFunc callback, void* data) noexcept;
	void SYSTEM_DEFAULT_DECLARE AndroidInputQueueDetachLooper(AndroidInputQueue* queue) noexcept;
	int SYSTEM_DEFAULT_DECLARE AndroidInputQueueHasEvents(AndroidInputQueue* queue) noexcept;
	int SYSTEM_DEFAULT_DECLARE AndroidInputQueueGetEvent(AndroidInputQueue* queue, AndroidInputEvent** outEvent) noexcept;
	int SYSTEM_DEFAULT_DECLARE AndroidInputQueuePreDispatchEvent(AndroidInputQueue* queue, AndroidInputEvent* event) noexcept;
	void SYSTEM_DEFAULT_DECLARE AndroidInputQueueFinishEvent(AndroidInputQueue* queue, AndroidInputEvent* event, int handled) noexcept;
}

#endif // SYSTEM_ANDROID_ANDROID_INPUT_QUEUE_H
