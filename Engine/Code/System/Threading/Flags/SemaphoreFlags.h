///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/21 0:00)

#ifndef SYSTEM_THREADING_SEMAPHORE_FLAGS_H
#define SYSTEM_THREADING_SEMAPHORE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class MutexWait : uint32_t
    {
        Ignore = IGNORE,
        Infinite = INFINITE,
    };

    enum class MutexWaitReturn : uint32_t
    {
        Failed = WAIT_FAILED,
        Object0 = WAIT_OBJECT_0,
        Abandoned = WAIT_ABANDONED,
        Abandoned0 = WAIT_ABANDONED_0,
        IOCompletion = WAIT_IO_COMPLETION,
        Timeout = WAIT_TIMEOUT,
    };

    enum class MutexStandardAccess
    {
        Delete = DELETE,
        ReadControl = READ_CONTROL,
        WriteDac = WRITE_DAC,
        WriteOwner = WRITE_OWNER,
        Synchronize = SYNCHRONIZE,
    };

    enum class SemaphoreSpecificAccess
    {
        Default = 0x0000,
        ModifyState = SEMAPHORE_MODIFY_STATE,
        AllAccess = SEMAPHORE_ALL_ACCESS,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class MutexWait : uint32_t
    {
        Ignore = 0,
        Infinite = 0xFFFFFFFF,
    };

    enum class MutexWaitReturn : uint32_t
    {
        Failed = 0xFFFFFFFFL,
        Object0 = 0x00000000L,
        Abandoned = 0x00000080L,
        Abandoned0 = 0x00000080L,
        IOCompletion = 0x000000C0L,
        Timeout = 258L,
    };

    enum class MutexStandardAccess
    {
        Delete = (0x00010000L),
        ReadControl = (0x00020000L),
        WriteDac = (0x00040000L),
        WriteOwner = (0x00080000L),
        Synchronize = (0x00100000L),
    };

    enum class SemaphoreSpecificAccess
    {
        Default = 0x0000,
        ModifyState = 0x0002,
        AllAccess = 0x000F0000L | 0x00100000L | 0x3,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_SEMAPHORE_FLAGS_H