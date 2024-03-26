/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/22 13:05)

#ifndef SYSTEM_ANDROID_ANDROID_FLAGS_FWD_H
#define SYSTEM_ANDROID_ANDROID_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    /// AndroidInput
    enum class AndroidKeyState;
    enum class AndroidMeta;
    enum class AndroidInputEventType;
    enum class AndroidKeyEventAction;
    enum class AndroidKeyEventFlag;
    enum class AndroidMotionEventAction;
    enum class AndroidMotionEventFlag;
    enum class AndroidMotionEventEdgeFlag;
    enum class AndroidMotionEventAxis;
    enum class AndroidMotionEventButton;
    enum class AndroidMotionEventToolType;
    enum class AndroidInputSourceClass;
    enum class AndroidInputSource : uint32_t;
    enum class AndroidInputKeyboardType;
    enum class AndroidInputMotionRange;

    /// AndroidKeyCodes
    enum class AndroidKeyCodes;

    /// AndroidLooper
    enum class AndroidLooperPrepareAllow;
    enum class AndroidLooperPoll;
    enum class AndroidLooperEvent;

    /// AndroidNativeAppGlue
    enum class LooperId;
    enum class AppCommandType;

    /// AndroidNativeWindow
    enum class WindowFormat;
}

#endif  // SYSTEM_ANDROID_ANDROID_FLAGS_FWD_H