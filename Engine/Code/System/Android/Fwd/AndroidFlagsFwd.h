// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 15:21)

#ifndef SYSTEM_ANDROID_ANDROID_FLAGS_FWD_H
#define SYSTEM_ANDROID_ANDROID_FLAGS_FWD_H  

#include "System/Helper/ConfigMacro.h"

namespace System
{
	// AndroidInput
	enum class AndroidKeyState;
	enum class AndroidMeta;
	enum class AndroidInputEventType;
	enum class AndroidKeyEventAction;
	enum class AndroidKeyEvent;
	enum class AndroidMotionEventAction;
	enum class AndroidMotionEvent;
	enum class AndroidMotionEventEdge;
	enum class AndroidMotionEventAxis;
	enum class AndroidMotionEventButton;
	enum class AndroidMotionEventTool;
	enum class AndroidInputSourceClass;
	enum class AndroidInputSource : uint32_t;
	enum class AndroidInputKeyboard;

	// AndroidKeyCodes
	enum class AndroidKeyCodes;

	// AndroidLooper
	enum class AndroidLooperPrepareAllow;
	enum class AndroidLooperPoll;
	enum class AndroidLooperEvent;

	// AndroidNativeAppGlue
	enum class LooperID;
	enum class AppCmd;

	// AndroidNativeWindow
	enum class WindowFormat;
}

#endif // SYSTEM_ANDROID_ANDROID_FLAGS_FWD_H