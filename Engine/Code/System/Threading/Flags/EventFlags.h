///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.1 (2023/01/30 12:59)

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
        // ��ʼ���źţ��Զ���λ
        Default = 0x00000000,
        // ��ʼ���źţ��Զ���λ
        InitalSet = CREATE_EVENT_INITIAL_SET,
        // ��ʼ���źţ��ֶ���λ
        ManualReset = CREATE_EVENT_MANUAL_RESET,
        // ��ʼ���źţ��ֶ���λ
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