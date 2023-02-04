///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.1 (2023/01/30 12:59)

#ifndef SYSTEM_THREADING_MUTEX_FLAGS_H
#define SYSTEM_THREADING_MUTEX_FLAGS_H

#include "System/Helper/Platform.h"

#ifndef SYSTEM_PLATFORM_WIN32

    #include <pthread.h>

#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class MutexCreate
    {
        Default = 0x00000000,
        InitialOwner = CREATE_MUTEX_INITIAL_OWNER,
    };

    enum class MutexSpecificAccess
    {
        Default = 0x0000,
        ModifyState = MUTEX_MODIFY_STATE,
        AllAccess = MUTEX_ALL_ACCESS,
    };

    enum class PthreadResult : uint32_t
    {
        Successful = 0,
        ENomem = WAIT_FAILED,
        EAgain = WAIT_FAILED,
        EPerm = WAIT_FAILED,
        EBusy = WAIT_FAILED,
        EInval = WAIT_FAILED,
        EDeadlk = WAIT_FAILED,
    };

    enum class PthreadMutexCompatibility
    {
        FastNP = 0,
        RecursiveNP = 1,
        ErrorcheckNP = 2,
        TimedNP = 0,
        AdaptiveNP = 0,

        Normal = 0,
        Recursive = 1,
        ErrorCheck = 2,
        Default = 0,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class MutexCreate
    {
        Default = 0x00000000,
        InitialOwner = 0x00000001,
    };

    enum class MutexSpecificAccess
    {
        Default = 0x0000,
        ModifyState = 0x0002,
        AllAccess = 0x000F0000L | 0x00100000L | 0x3,
    };

    enum class PthreadResult : uint32_t
    {
        Successful = 0,
        ENomem = ENOMEM,
        EAgain = EAGAIN,
        EPerm = EPERM,
        EBusy = EBUSY,
        EInval = EINVAL,
        EDeadlk = EDEADLK,
    };

    enum class PthreadMutexCompatibility
    {
        FastNP = PTHREAD_MUTEX_FAST_NP,
        RecursiveNP = PTHREAD_MUTEX_RECURSIVE_NP,
        ErrorcheckNP = PTHREAD_MUTEX_ERRORCHECK_NP,
        TimedNP = PTHREAD_MUTEX_TIMED_NP,
        AdaptiveNP = PTHREAD_MUTEX_ADAPTIVE_NP,

        Normal = PTHREAD_MUTEX_NORMAL,
        Recursive = PTHREAD_MUTEX_RECURSIVE,
        ErrorCheck = PTHREAD_MUTEX_ERRORCHECK,
        Default = PTHREAD_MUTEX_DEFAULT,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_MUTEX_FLAGS_H