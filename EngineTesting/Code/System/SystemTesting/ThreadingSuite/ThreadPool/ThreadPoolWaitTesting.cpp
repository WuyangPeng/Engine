// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.1 (2020/01/14 10:27)

#include "ThreadPoolWaitTesting.h"
#include "System/Threading/Mutex.h"
#include "System/Threading/SyncTools.h"
#include "System/Threading/ThreadPool.h"
#include "System/Threading/Using/WaitableTimerUsing.h"

#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(System, ThreadPoolWaitTesting)

void System::ThreadPoolWaitTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UsingThreadPoolTest);
}

void System::ThreadPoolWaitTesting::UsingThreadPoolTest()
{
    ThreadPoolCallbackEnviron callBackEnviron{};

    InitializeThreadPoolEnvironment(&callBackEnviron);

    auto threadPoolPool = CreateThreadPool();
    ASSERT_UNEQUAL_NULL_PTR(threadPoolPool);

    SetThreadPoolMaximumThread(threadPoolPool, 1);
    ASSERT_TRUE(SetThreadPoolMinimumThread(threadPoolPool, 1));

    auto cleanupgroup = CreateThreadPoolCleanupGroup();
    ASSERT_UNEQUAL_NULL_PTR(cleanupgroup);

    SetThreadPoolCallbackCleanupGroup(&callBackEnviron, cleanupgroup, nullptr);

    auto work = CreateThreadPoolWork(ClassType::WorkCallback, this, &callBackEnviron);
    ASSERT_UNEQUAL_NULL_PTR(work);

    SubmitThreadPoolWork(work);

    auto timer = CreateThreadPoolTimer(ClassType::TimerCallback, this, &callBackEnviron);
    ASSERT_UNEQUAL_NULL_PTR(timer);

    WindowLargeInteger dueTime{};
    dueTime.QuadPart = (-1 * 10 * 1000 * 1000);

    FileTime fileDueTime{};
    fileDueTime.dwHighDateTime = dueTime.HighPart;
    fileDueTime.dwLowDateTime = dueTime.LowPart;

    SetThreadPoolTimer(timer, &fileDueTime, 0, 0);

    auto poolWait = CreateThreadPoolWait(WaitCallback, this, &callBackEnviron);
    ASSERT_UNEQUAL_NULL_PTR(poolWait);

    auto mutexHandle = CreateSystemMutex();
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    SetThreadPoolWait(poolWait, mutexHandle, nullptr);

    SystemSleep(1500);

    WaitForThreadPoolWorkCallbacks(work, false);
    WaitForThreadPoolTimerCallbacks(timer, false);
    WaitForThreadPoolWaitCallbacks(poolWait, false);

    ASSERT_TRUE(CloseSystemMutex(mutexHandle));
    CloseThreadPoolWait(poolWait);
    CloseThreadPoolCleanupGroupMembers(cleanupgroup, false, nullptr);
    CloseThreadPoolCleanupGroup(cleanupgroup);
    CloseThreadPool(threadPoolPool);
    DestroyThreadPoolEnvironment(&callBackEnviron);
}

void System::ThreadPoolWaitTesting::WorkCallback([[maybe_unused]] ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, [[maybe_unused]] ThreadPoolWorkPtr work)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26471)
    auto ptr = reinterpret_cast<ClassType*>(context);

    ptr->GetStream() << "这里进行了WorkCallback回调函数的调用。\n";
#include STSTEM_WARNING_POP
}

void System::ThreadPoolWaitTesting::TimerCallback([[maybe_unused]] ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, [[maybe_unused]] ThreadPoolTimerPtr timer)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26471)
    auto ptr = reinterpret_cast<ClassType*>(context);

    ptr->GetStream() << "这里进行了TimerCallback回调函数的调用。\n";
#include STSTEM_WARNING_POP
}

void System::ThreadPoolWaitTesting::WaitCallback([[maybe_unused]] ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, [[maybe_unused]] ThreadPoolWaitPtr wait, ThreadPoolWaitResult waitResult)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26471)
    auto ptr = reinterpret_cast<ClassType*>(context);

    ptr->GetStream() << "这里进行了WaitCallback回调函数的调用。结果是：" << waitResult << "\n";
#include STSTEM_WARNING_POP
}
