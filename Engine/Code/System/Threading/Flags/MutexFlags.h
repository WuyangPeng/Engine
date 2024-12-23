/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 16:52)

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

    enum class PThreadResult : uint32_t
    {
        Successful = 0,
        ENoMem = WAIT_FAILED,
        EAgain = WAIT_FAILED,
        EPerm = WAIT_FAILED,
        EBusy = WAIT_FAILED,
        EInVal = WAIT_FAILED,
        EDeadLk = WAIT_FAILED,
    };

    enum class PThreadMutexCompatibility
    {
        FastNp = 0,
        RecursiveNp = 1,
        ErrorCheckNp = 2,
        TimedNp = 0,
        AdaptiveNp = 0,

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

    enum class PThreadResult : uint32_t
    {
        Successful = 0,
        ENoMem = ENOMEM,
        EAgain = EAGAIN,
        EPerm = EPERM,
        EBusy = EBUSY,
        EInVal = EINVAL,
        EDeadLk = EDEADLK,
    };

    enum class PThreadMutexCompatibility
    {
        FastNp = PTHREAD_MUTEX_FAST_NP,
        RecursiveNp = PTHREAD_MUTEX_RECURSIVE_NP,
        ErrorCheckNp = PTHREAD_MUTEX_ERRORCHECK_NP,
        TimedNp = PTHREAD_MUTEX_TIMED_NP,
        AdaptiveNp = PTHREAD_MUTEX_ADAPTIVE_NP,

        Normal = PTHREAD_MUTEX_NORMAL,
        Recursive = PTHREAD_MUTEX_RECURSIVE,
        ErrorCheck = PTHREAD_MUTEX_ERRORCHECK,
        Default = PTHREAD_MUTEX_DEFAULT,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_MUTEX_FLAGS_H