///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.1 (2023/01/30 12:59)

#ifndef SYSTEM_THREADING_EVENT_FLAGS_H
#define SYSTEM_THREADING_EVENT_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class EventSpecificAccess
    {
        Default = 0x0000,
        ModifyState = EVENT_MODIFY_STATE,
        AllAccess = EVENT_ALL_ACCESS,
    };

    enum class CreateEventType
    {
        // 初始无信号，自动复位
        Default = 0x00000000,
        // 初始有信号，自动复位
        InitalSet = CREATE_EVENT_INITIAL_SET,
        // 初始无信号，手动复位
        ManualReset = CREATE_EVENT_MANUAL_RESET,
        // 初始有信号，手动复位
        All = InitalSet | ManualReset,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class EventSpecificAccess
    {
        Default = 0x0000,
        ModifyState = 0x0002,
        AllAccess = 0x000F0000L | 0x00100000L | 0x3,
    };

    enum class CreateEventType
    {
        Default = 0x00000000,
        InitalSet = 0x00000002,
        ManualReset = 0x00000001,
        All = InitalSet | ManualReset,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_EVENT_FLAGS_H