// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.1 (2020/01/14 10:25)

#include "ThreadPoolReturnsTesting.h"

#include "System/Threading/CriticalSection.h"
#include "System/Threading/Event.h"
#include "System/Threading/Mutex.h"
#include "System/Threading/Semaphore.h"
#include "System/Threading/SyncTools.h"
#include "System/Threading/ThreadPool.h"
#include "System/Threading/Using/WaitableTimerUsing.h"

#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(System, ThreadPoolReturnsTesting)

void System::ThreadPoolReturnsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UsingThreadPoolTest);
}

void System::ThreadPoolReturnsTesting::UsingThreadPoolTest()
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

    auto eventHandle = CreateSystemEvent(true, false);
    ASSERT_TRUE(IsSystemEventValid(eventHandle));

    auto work = CreateThreadPoolWork(ClassType::WorkCallback, eventHandle, &callBackEnviron);
    ASSERT_UNEQUAL_NULL_PTR(work);

    SubmitThreadPoolWork(work);

    constexpr WindowLong maxSemphoreCount{ 10 };

    auto semaphoreHandle = CreateSystemSemaphore(0, maxSemphoreCount);
    ASSERT_TRUE(IsSystemSemaphoreValid(semaphoreHandle));

    auto mutexHandle = CreateSystemMutex();
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ThreadingCriticalSection criticalSection{};

    ASSERT_TRUE(InitializeSystemCriticalSection(&criticalSection));

    DynamicLinkString resourcesLibraryDll{ DYNAMIC_LINK_TEXT("Resource/ResourcesLibrary") };

#ifdef BUILDING_STATIC
    resourcesLibraryDll += DYNAMIC_LINK_TEXT("Static");
#endif  // BUILDING_STATIC

#ifdef _DEBUG
    resourcesLibraryDll += DYNAMIC_LINK_TEXT("D");
#endif  // _DEBUG

    auto module = LoadDynamicLibrary(resourcesLibraryDll.c_str(), LoadLibraryType::DontResolveDllReferences);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(module, "ResourcesLibrary ≤ª¥Ê‘⁄°£");

    auto firstTimer = CreateThreadPoolTimer(ClassType::TimerCallback, semaphoreHandle, &callBackEnviron);
    ASSERT_UNEQUAL_NULL_PTR(firstTimer);

    auto secondTimer = CreateThreadPoolTimer(ClassType::MutexTimerCallback, mutexHandle, &callBackEnviron);
    ASSERT_UNEQUAL_NULL_PTR(secondTimer);

    auto thirdTimer = CreateThreadPoolTimer(ClassType::CriticalSectionTimerCallback, &criticalSection, &callBackEnviron);
    ASSERT_UNEQUAL_NULL_PTR(thirdTimer);

    auto fourthTimer = CreateThreadPoolTimer(ClassType::FreeLibraryTimerCallback, module, &callBackEnviron);
    ASSERT_UNEQUAL_NULL_PTR(fourthTimer);

    WindowLargeInteger dueTime{};
    dueTime.QuadPart = (-1 * 10 * 1000 * 1000);

    FileTime fileDueTime{};
    fileDueTime.dwHighDateTime = dueTime.HighPart;
    fileDueTime.dwLowDateTime = dueTime.LowPart;

    SetThreadPoolTimer(firstTimer, &fileDueTime, 0, 0);
    SetThreadPoolTimer(secondTimer, &fileDueTime, 0, 0);
    SetThreadPoolTimer(thirdTimer, &fileDueTime, 0, 0);
    SetThreadPoolTimer(fourthTimer, &fileDueTime, 0, 0);

    SystemSleep(1500);

    ASSERT_TRUE(WaitForSystemMutex(mutexHandle));
    ASSERT_TRUE(WaitForSystemEvent(eventHandle));
    ASSERT_TRUE(WaitForSystemSemaphore(semaphoreHandle));
    WaitForThreadPoolWorkCallbacks(work, false);
    WaitForThreadPoolTimerCallbacks(firstTimer, false);
    WaitForThreadPoolTimerCallbacks(secondTimer, false);
    WaitForThreadPoolTimerCallbacks(thirdTimer, false);
    WaitForThreadPoolTimerCallbacks(fourthTimer, false);

    CloseThreadPoolCleanupGroupMembers(cleanupgroup, false, nullptr);
    CloseThreadPoolCleanupGroup(cleanupgroup);
    CloseThreadPool(threadPoolPool);
    DestroyThreadPoolEnvironment(&callBackEnviron);

    ASSERT_TRUE(CloseSystemEvent(eventHandle));
    ASSERT_TRUE(CloseSystemSemaphore(semaphoreHandle));
    ASSERT_TRUE(CloseSystemMutex(mutexHandle));
    DeleteSystemCriticalSection(&criticalSection);
    ASSERT_FALSE(FreeDynamicLibrary(module));
}

void System::ThreadPoolReturnsTesting::WorkCallback(ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, [[maybe_unused]] ThreadPoolWorkPtr work) noexcept
{
    SetEventWhenCallBackReturns(instance, context);
}

void System::ThreadPoolReturnsTesting::TimerCallback(ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, [[maybe_unused]] ThreadPoolTimerPtr timer) noexcept
{
    ReleaseSemaphoreWhenCallBackReturns(instance, context, 1);
}

void System::ThreadPoolReturnsTesting::MutexTimerCallback(ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, [[maybe_unused]] ThreadPoolTimerPtr timer) noexcept
{
    [[maybe_unused]] const auto value = WaitForSystemMutex(context);

    ReleaseMutexWhenCallBackReturns(instance, context);

    SystemSleep(2500);
}

void System::ThreadPoolReturnsTesting::CriticalSectionTimerCallback(ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, [[maybe_unused]] ThreadPoolTimerPtr timer) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26471)
    auto criticalSection = reinterpret_cast<ThreadingCriticalSectionPtr>(context);

    LeaveCriticalSectionWhenCallBackReturns(instance, criticalSection);
#include STSTEM_WARNING_POP
}

void System::ThreadPoolReturnsTesting::FreeLibraryTimerCallback(ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, [[maybe_unused]] ThreadPoolTimerPtr timer) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26471)
    auto dllModule = reinterpret_cast<DynamicLinkModule>(context);

    FreeLibraryWhenCallBackReturns(instance, dllModule);
#include STSTEM_WARNING_POP
}
