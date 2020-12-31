//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 17:44)

#include "System/SystemExport.h"

#include "ThreadPool.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

System::ThreadPoolPoolPtr System::CreateThreadPool() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateThreadpool(nullptr);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetThreadPoolMaximumThread([[maybe_unused]] ThreadPoolPoolPtr threadPool, [[maybe_unused]] WindowDWord threadMost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SetThreadpoolThreadMaximum(threadPool, threadMost);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetThreadPoolMinimumThread([[maybe_unused]] ThreadPoolPoolPtr threadPool, [[maybe_unused]] WindowDWord threadMic) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetThreadpoolThreadMinimum(threadPool, threadMic) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32

    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SubmitThreadPoolWork([[maybe_unused]] ThreadPoolWorkPtr work) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::SubmitThreadpoolWork(work);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadPoolWorkPtr System::CreateThreadPoolWork([[maybe_unused]] ThreadPoolWorkCallback callback, [[maybe_unused]] WindowVoidPtr data, [[maybe_unused]] ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateThreadpoolWork(callback, data, threadEnviron);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::CloseThreadPoolWork([[maybe_unused]] ThreadPoolWorkPtr work) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::CloseThreadpoolWork(work);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WaitForThreadPoolWorkCallbacks([[maybe_unused]] ThreadPoolWorkPtr work, [[maybe_unused]] bool cancelPendingCallbacks) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::WaitForThreadpoolWorkCallbacks(work, BoolConversion(cancelPendingCallbacks));
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetThreadPoolStackInformation([[maybe_unused]] ThreadPoolPoolPtr threadPool, [[maybe_unused]] ThreadPoolPoolStackInformationPtr stackInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetThreadpoolStackInformation(threadPool, stackInformation) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::QueryThreadPoolStackInformation([[maybe_unused]] ThreadPoolPoolPtr threadPool, [[maybe_unused]] ThreadPoolPoolStackInformationPtr stackInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::QueryThreadpoolStackInformation(threadPool, stackInformation) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::CloseThreadPool([[maybe_unused]] ThreadPoolPoolPtr threadPool) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::CloseThreadpool(threadPool);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadPoolCleanupGroupPtr System::CreateThreadPoolCleanupGroup() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateThreadpoolCleanupGroup();
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::CloseThreadPoolCleanupGroupMembers([[maybe_unused]] ThreadPoolCleanupGroupPtr cleanupGroup, [[maybe_unused]] bool cancelPendingCallbacks, [[maybe_unused]] WindowVoidPtr cleanupContext) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::CloseThreadpoolCleanupGroupMembers(cleanupGroup, BoolConversion(cancelPendingCallbacks), cleanupContext);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::CloseThreadPoolCleanupGroup([[maybe_unused]] ThreadPoolCleanupGroupPtr cleanupGroup) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::CloseThreadpoolCleanupGroup(cleanupGroup);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CallBackMayRunLong([[maybe_unused]] ThreadPoolCallBackInstancePtr callBackInstance) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CallbackMayRunLong(callBackInstance) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32

    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::DisassociateCurrentThreadFromCallBack([[maybe_unused]] ThreadPoolCallBackInstancePtr callBackInstance) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::DisassociateCurrentThreadFromCallback(callBackInstance);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::TrySubmitThreadPoolCallback([[maybe_unused]] ThreadPoolSimpleCallback function, [[maybe_unused]] WindowVoidPtr data, [[maybe_unused]] ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::TrySubmitThreadpoolCallback(function, data, threadEnviron) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadPoolTimerPtr System::CreateThreadPoolTimer([[maybe_unused]] ThreadPoolTimerCallback function, [[maybe_unused]] WindowVoidPtr data, [[maybe_unused]] ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateThreadpoolTimer(function, data, threadEnviron);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetThreadPoolTimer([[maybe_unused]] ThreadPoolTimerPtr timer, [[maybe_unused]] FileTimePtr dueTime, [[maybe_unused]] WindowDWord period, [[maybe_unused]] WindowDWord windowLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SetThreadpoolTimer(timer, dueTime, period, windowLength);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsThreadPoolTimerSet([[maybe_unused]] ThreadPoolTimerPtr timer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::IsThreadpoolTimerSet(timer) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::CloseThreadPoolTimer([[maybe_unused]] ThreadPoolTimerPtr timer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CloseThreadpoolTimer(timer);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WaitForThreadPoolTimerCallbacks([[maybe_unused]] ThreadPoolTimerPtr timer, [[maybe_unused]] bool cancelPendingCallbacks) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::WaitForThreadpoolTimerCallbacks(timer, BoolConversion(cancelPendingCallbacks));
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadPoolWaitPtr System::CreateThreadPoolWait([[maybe_unused]] ThreadPoolWaitCallback function, [[maybe_unused]] WindowVoidPtr data, [[maybe_unused]] ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateThreadpoolWait(function, data, threadEnviron);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetThreadPoolWait([[maybe_unused]] ThreadPoolWaitPtr poolWait, [[maybe_unused]] ThreadHandle handle, [[maybe_unused]] FileTimePtr timeout) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SetThreadpoolWait(poolWait, handle, timeout);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WaitForThreadPoolWaitCallbacks([[maybe_unused]] ThreadPoolWaitPtr poolWait, [[maybe_unused]] bool cancelPendingCallbacks) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::WaitForThreadpoolWaitCallbacks(poolWait, BoolConversion(cancelPendingCallbacks));
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::CloseThreadPoolWait([[maybe_unused]] ThreadPoolWaitPtr poolWait) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CloseThreadpoolWait(poolWait);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ThreadPoolIOPtr System::CreateThreadPoolIo([[maybe_unused]] ThreadHandle handle, [[maybe_unused]] ThreadPoolWin32IoCallback callback, [[maybe_unused]] WindowVoidPtr data, [[maybe_unused]] ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateThreadpoolIo(handle, callback, data, threadEnviron);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::StartThreadPoolIo([[maybe_unused]] ThreadPoolIOPtr threadPoolIO) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::StartThreadpoolIo(threadPoolIO);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::CancelThreadPoolIo([[maybe_unused]] ThreadPoolIOPtr threadPoolIO) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CancelThreadpoolIo(threadPoolIO);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::CloseThreadPoolIo([[maybe_unused]] ThreadPoolIOPtr threadPoolIO) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CloseThreadpoolIo(threadPoolIO);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::WaitForThreadPoolIoCallbacks([[maybe_unused]] ThreadPoolIOPtr threadPoolIO, [[maybe_unused]] bool cancelPendingCallbacks) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::WaitForThreadpoolIoCallbacks(threadPoolIO, BoolConversion(cancelPendingCallbacks));
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetEventWhenCallBackReturns([[maybe_unused]] ThreadPoolCallBackInstancePtr callBackInstance, [[maybe_unused]] WindowHandle eventHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SetEventWhenCallbackReturns(callBackInstance, eventHandle);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::ReleaseSemaphoreWhenCallBackReturns([[maybe_unused]] ThreadPoolCallBackInstancePtr callBackInstance, [[maybe_unused]] WindowHandle semaphoreHandle, [[maybe_unused]] WindowDWord crel) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::ReleaseSemaphoreWhenCallbackReturns(callBackInstance, semaphoreHandle, crel);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::ReleaseMutexWhenCallBackReturns([[maybe_unused]] ThreadPoolCallBackInstancePtr callBackInstance, [[maybe_unused]] WindowHandle mutexHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::ReleaseMutexWhenCallbackReturns(callBackInstance, mutexHandle);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::LeaveCriticalSectionWhenCallBackReturns([[maybe_unused]] ThreadPoolCallBackInstancePtr callBackInstance, [[maybe_unused]] ThreadingCriticalSectionPtr criticalSection) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::LeaveCriticalSectionWhenCallbackReturns(callBackInstance, criticalSection);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::FreeLibraryWhenCallBackReturns([[maybe_unused]] ThreadPoolCallBackInstancePtr callBackInstance, [[maybe_unused]] DynamicLinkModule module) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::FreeLibraryWhenCallbackReturns(callBackInstance, module);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::InitializeThreadPoolEnvironment([[maybe_unused]] ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::InitializeThreadpoolEnvironment(threadEnviron);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetThreadPoolCallbackPool([[maybe_unused]] ThreadPoolCallbackEnvironPtr threadEnviron, [[maybe_unused]] ThreadPoolPoolPtr threadPool) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SetThreadpoolCallbackPool(threadEnviron, threadPool);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetThreadPoolCallbackCleanupGroup([[maybe_unused]] ThreadPoolCallbackEnvironPtr threadEnviron, [[maybe_unused]] ThreadPoolCleanupGroupPtr cleanupGroup, [[maybe_unused]] ThreadPoolCleanupGroupCancelCallback cancelCallback) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SetThreadpoolCallbackCleanupGroup(threadEnviron, cleanupGroup, cancelCallback);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetThreadPoolCallbackRunsLong([[maybe_unused]] ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SetThreadpoolCallbackRunsLong(threadEnviron);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetThreadPoolCallBackLibrary([[maybe_unused]] ThreadPoolCallbackEnvironPtr threadEnviron, [[maybe_unused]] WindowVoidPtr module) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SetThreadpoolCallbackLibrary(threadEnviron, module);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetThreadPoolCallbackPriority([[maybe_unused]] ThreadPoolCallbackEnvironPtr threadEnviron, [[maybe_unused]] ThreadPoolCallbackPriority priority) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SetThreadpoolCallbackPriority(threadEnviron, priority);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetThreadPoolCallbackPersistent([[maybe_unused]] ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SetThreadpoolCallbackPersistent(threadEnviron);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::DestroyThreadPoolEnvironment([[maybe_unused]] ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::DestroyThreadpoolEnvironment(threadEnviron);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}
