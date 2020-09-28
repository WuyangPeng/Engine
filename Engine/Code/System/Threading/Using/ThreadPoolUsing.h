//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 14:36)

#ifndef SYSTEM_THREADING_THREAD_POOL_USING_H
#define SYSTEM_THREADING_THREAD_POOL_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ThreadPoolWork = TP_WORK;
    using ThreadPoolWorkPtr = PTP_WORK;
    using ThreadPoolCallBackInstance = TP_CALLBACK_INSTANCE;
    using ThreadPoolCallBackInstancePtr = PTP_CALLBACK_INSTANCE;
    using ThreadPoolWorkCallback = PTP_WORK_CALLBACK;
    using ThreadPoolCallbackEnviron = TP_CALLBACK_ENVIRON;
    using ThreadPoolCallbackEnvironPtr = PTP_CALLBACK_ENVIRON;
    using ThreadPoolVersion = TP_VERSION;
    using ThreadPoolVersionPtr = PTP_VERSION;
    using ThreadPoolPool = TP_POOL;
    using ThreadPoolPoolPtr = PTP_POOL;
    using ThreadPoolCleanupGroup = TP_CLEANUP_GROUP;
    using ThreadPoolCleanupGroupPtr = PTP_CLEANUP_GROUP;
    using ThreadPoolCallbackPriority = TP_CALLBACK_PRIORITY;
    using ThreadPoolCleanupGroupCancelCallback = PTP_CLEANUP_GROUP_CANCEL_CALLBACK;
    using ThreadPoolSimpleCallback = PTP_SIMPLE_CALLBACK;
    using ThreadPoolPoolStackInformation = TP_POOL_STACK_INFORMATION;
    using ThreadPoolPoolStackInformationPtr = PTP_POOL_STACK_INFORMATION;
    using ThreadPoolTimer = TP_TIMER;
    using ThreadPoolTimerPtr = PTP_TIMER;
    using ThreadPoolTimerCallback = PTP_TIMER_CALLBACK;
    using ThreadPoolWait = TP_WAIT;
    using ThreadPoolWaitPtr = PTP_WAIT;
    using ThreadPoolWaitCallback = PTP_WAIT_CALLBACK;
    using ThreadPoolWaitResult = TP_WAIT_RESULT;
    using ThreadPoolIO = TP_IO;
    using ThreadPoolIOPtr = PTP_IO;
    using ThreadPoolWin32IoCallback = PTP_WIN32_IO_CALLBACK;

#else  // !SYSTEM_PLATFORM_WIN32

    struct ThreadPoolWork
    {
    };
    using ThreadPoolWorkPtr = ThreadPoolWork*;

    struct ThreadPoolCallBackInstance
    {
    };
    using ThreadPoolCallBackInstancePtr = ThreadPoolCallBackInstance*;
    using ThreadPoolWorkCallback = void (*)(ThreadPoolCallBackInstancePtr instance, void* context, ThreadPoolWorkPtr work);
    using ThreadPoolVersion = uint32_t;
    using ThreadPoolVersionPtr = ThreadPoolVersion*;

    struct ThreadPoolPool
    {
    };

    using ThreadPoolPoolPtr = ThreadPoolPool*;

    struct ThreadPoolCleanupGroup
    {
    };

    using ThreadPoolCleanupGroupPtr = ThreadPoolCleanupGroup*;

    enum ThreadPoolCallbackPriority
    {
        TP_CALLBACK_PRIORITY_HIGH,
        TP_CALLBACK_PRIORITY_NORMAL,
        TP_CALLBACK_PRIORITY_LOW,
        TP_CALLBACK_PRIORITY_INVALID,
        TP_CALLBACK_PRIORITY_COUNT = TP_CALLBACK_PRIORITY_INVALID
    };
    using ThreadPoolCleanupGroupCancelCallback = void (*)(void* objectContext, void* cleanupContext);
    using ThreadPoolSimpleCallback = void (*)(ThreadPoolCallBackInstancePtr instance, void* context);
    struct ThreadPoolActivationContext
    {
    };

    struct ThreadPoolCallbackEnviron
    {
        ThreadPoolVersion Version;
        ThreadPoolPoolPtr Pool;
        ThreadPoolCleanupGroupPtr CleanupGroup;
        ThreadPoolCleanupGroupCancelCallback CleanupGroupCancelCallback;
        void* RaceDll;
        ThreadPoolActivationContext* ActivationContext;
        ThreadPoolSimpleCallback FinalizationCallback;
        union
        {
            uint32_t Flags;
            struct
            {
                uint32_t LongFunction : 1;
                uint32_t Persistent : 1;
                uint32_t Private : 30;
            } s;
        } u;
        ThreadPoolCallbackPriority CallbackPriority;
        uint32_t Size;
    };

    using ThreadPoolCallbackEnvironPtr = ThreadPoolCallbackEnviron*;

    struct ThreadPoolPoolStackInformation
    {
        uint32_t StackReserve;
        uint32_t StackCommit;
    };
    using ThreadPoolPoolStackInformationPtr = ThreadPoolPoolStackInformation*;

    struct ThreadPoolTimer
    {
    };
    using ThreadPoolTimerPtr = ThreadPoolTimer*;
    using ThreadPoolTimerCallback = void (*)(ThreadPoolCallBackInstancePtr instance, void* context, ThreadPoolTimerPtr timer);

    struct ThreadPoolWait
    {
    };
    using ThreadPoolWaitPtr = ThreadPoolWait*;
    using ThreadPoolWaitResult = uint32_t;
    using ThreadPoolWaitCallback = void (*)(ThreadPoolCallBackInstancePtr instance, void* context, ThreadPoolWaitPtr wait, ThreadPoolWaitResult waitResult);
    struct ThreadPoolIO
    {
    };
    using ThreadPoolIOPtr = ThreadPoolIO*;
    using ThreadPoolWin32IoCallback = void (*)(ThreadPoolCallBackInstancePtr instance, void* context, void* overlapped, unsigned long ioResult,
                                               uint64_t numberOfBytesTransferred, ThreadPoolIOPtr io);

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_THREAD_POOL_USING_H