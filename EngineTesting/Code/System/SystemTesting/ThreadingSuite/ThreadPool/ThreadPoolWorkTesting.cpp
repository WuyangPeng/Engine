// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.1 (2020/01/14 10:27)

#include "ThreadPoolWorkTesting.h"

#include "System/Threading/SyncTools.h"
#include "System/Threading/ThreadPool.h"
#include "System/Threading/Using/WaitableTimerUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(System, ThreadPoolWorkTesting)

void System::ThreadPoolWorkTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UsingThreadPoolTest);
}

void System::ThreadPoolWorkTesting::UsingThreadPoolTest()
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

    ASSERT_TRUE(TrySubmitThreadPoolCallback(SimpleCallback, this, &callBackEnviron));

    SystemSleep(1500);

    WaitForThreadPoolWorkCallbacks(work, false);
    WaitForThreadPoolTimerCallbacks(timer, false);

    CloseThreadPoolWork(work);
    CloseThreadPoolCleanupGroupMembers(cleanupgroup, false, nullptr);
    CloseThreadPoolCleanupGroup(cleanupgroup);
    CloseThreadPool(threadPoolPool);
    DestroyThreadPoolEnvironment(&callBackEnviron);
}

void System::ThreadPoolWorkTesting::WorkCallback([[maybe_unused]] ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, [[maybe_unused]] ThreadPoolWorkPtr work)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26471)
    auto ptr = reinterpret_cast<ClassType*>(context);
#include STSTEM_WARNING_POP

    ptr->GetStream() << "���������WorkCallback�ص������ĵ��á�\n";
}

void System::ThreadPoolWorkTesting::TimerCallback([[maybe_unused]] ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, [[maybe_unused]] ThreadPoolTimerPtr timer)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26471)
    auto ptr = reinterpret_cast<ClassType*>(context);
#include STSTEM_WARNING_POP

    ptr->GetStream() << "���������TimerCallback�ص������ĵ��á�\n";
}

void System::ThreadPoolWorkTesting::SimpleCallback([[maybe_unused]] ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26471)
    auto ptr = reinterpret_cast<ClassType*>(context);
#include STSTEM_WARNING_POP

    ptr->GetStream() << "���������SimpleCallback�ص������ĵ��á�\n";
}