// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:17)

#include "System/SystemExport.h"

#include "ThreadPool.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h" 
#include "System/Window/WindowSystem.h"

System::ThreadPoolPoolPtr System
	::CreateThreadPool() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateThreadpool(nullptr);
#else // !SYSTEM_PLATFORM_WIN32
	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetThreadPoolMaximumThread(ThreadPoolPoolPtr threadPool, WindowDWord threadMost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SetThreadpoolThreadMaximum(threadPool, threadMost);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadPool);
	SYSTEM_UNUSED_ARG(threadMost);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetThreadPoolMinimumThread(ThreadPoolPoolPtr threadPool, WindowDWord threadMic) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetThreadpoolThreadMinimum(threadPool, threadMic) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadPool);
	SYSTEM_UNUSED_ARG(threadMic);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SubmitThreadPoolWork(ThreadPoolWorkPtr work) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::SubmitThreadpoolWork(work);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(work);
#endif // SYSTEM_PLATFORM_WIN32
}

System::ThreadPoolWorkPtr System
	::CreateThreadPoolWork(ThreadPoolWorkCallback callback, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateThreadpoolWork(callback, data, threadEnviron);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(callback);
	SYSTEM_UNUSED_ARG(data);
	SYSTEM_UNUSED_ARG(threadEnviron);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::CloseThreadPoolWork(ThreadPoolWorkPtr work) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::CloseThreadpoolWork(work);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(work);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::WaitForThreadPoolWorkCallbacks(ThreadPoolWorkPtr work, bool cancelPendingCallbacks) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::WaitForThreadpoolWorkCallbacks(work, BoolConversion(cancelPendingCallbacks));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(work);
	SYSTEM_UNUSED_ARG(cancelPendingCallbacks);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetThreadPoolStackInformation(ThreadPoolPoolPtr threadPool, ThreadPoolPoolStackInformationPtr stackInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetThreadpoolStackInformation(threadPool, stackInformation) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadPool);
	SYSTEM_UNUSED_ARG(stackInformation);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::QueryThreadPoolStackInformation(ThreadPoolPoolPtr threadPool, ThreadPoolPoolStackInformationPtr stackInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::QueryThreadpoolStackInformation(threadPool, stackInformation) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadPool);
	SYSTEM_UNUSED_ARG(stackInformation);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::CloseThreadPool(ThreadPoolPoolPtr threadPool) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::CloseThreadpool(threadPool);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadPool);
#endif // SYSTEM_PLATFORM_WIN32
}

System::ThreadPoolCleanupGroupPtr System
	::CreateThreadPoolCleanupGroup() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateThreadpoolCleanupGroup();
#else // !SYSTEM_PLATFORM_WIN32
	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::CloseThreadPoolCleanupGroupMembers(ThreadPoolCleanupGroupPtr cleanupGroup, bool cancelPendingCallbacks, WindowVoidPtr cleanupContext) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::CloseThreadpoolCleanupGroupMembers(cleanupGroup, BoolConversion(cancelPendingCallbacks), cleanupContext);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(cleanupGroup);
	SYSTEM_UNUSED_ARG(cancelPendingCallbacks);
	SYSTEM_UNUSED_ARG(cleanupContext);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::CloseThreadPoolCleanupGroup(ThreadPoolCleanupGroupPtr cleanupGroup) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::CloseThreadpoolCleanupGroup(cleanupGroup);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(cleanupGroup);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CallBackMayRunLong(ThreadPoolCallBackInstancePtr callBackInstance) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CallbackMayRunLong(callBackInstance) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(callBackInstance);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::DisassociateCurrentThreadFromCallBack(ThreadPoolCallBackInstancePtr callBackInstance) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::DisassociateCurrentThreadFromCallback(callBackInstance);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(callBackInstance);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::TrySubmitThreadPoolCallback(ThreadPoolSimpleCallback function, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::TrySubmitThreadpoolCallback(function, data, threadEnviron) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(function);
	SYSTEM_UNUSED_ARG(data);
	SYSTEM_UNUSED_ARG(threadEnviron);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::ThreadPoolTimerPtr System
	::CreateThreadPoolTimer(ThreadPoolTimerCallback function, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateThreadpoolTimer(function, data, threadEnviron);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(function);
	SYSTEM_UNUSED_ARG(data);
	SYSTEM_UNUSED_ARG(threadEnviron);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetThreadPoolTimer(ThreadPoolTimerPtr timer, FileTimePtr dueTime, WindowDWord period, WindowDWord windowLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SetThreadpoolTimer(timer, dueTime, period, windowLength);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(timer);
	SYSTEM_UNUSED_ARG(dueTime);
	SYSTEM_UNUSED_ARG(period);
	SYSTEM_UNUSED_ARG(windowLength);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsThreadPoolTimerSet(ThreadPoolTimerPtr timer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::IsThreadpoolTimerSet(timer) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(timer);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::CloseThreadPoolTimer(ThreadPoolTimerPtr timer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CloseThreadpoolTimer(timer);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(timer);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::WaitForThreadPoolTimerCallbacks(ThreadPoolTimerPtr timer, bool cancelPendingCallbacks) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::WaitForThreadpoolTimerCallbacks(timer, BoolConversion(cancelPendingCallbacks));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(timer);
	SYSTEM_UNUSED_ARG(cancelPendingCallbacks);
#endif // SYSTEM_PLATFORM_WIN32
}

System::ThreadPoolWaitPtr System
	::CreateThreadPoolWait(ThreadPoolWaitCallback function, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateThreadpoolWait(function, data, threadEnviron);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(function);
	SYSTEM_UNUSED_ARG(data);
	SYSTEM_UNUSED_ARG(threadEnviron);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetThreadPoolWait(ThreadPoolWaitPtr poolWait, ThreadHandle handle, FileTimePtr timeout) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SetThreadpoolWait(poolWait, handle, timeout);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(poolWait);
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(timeout);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::WaitForThreadPoolWaitCallbacks(ThreadPoolWaitPtr poolWait, bool cancelPendingCallbacks) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::WaitForThreadpoolWaitCallbacks(poolWait, BoolConversion(cancelPendingCallbacks));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(poolWait);
	SYSTEM_UNUSED_ARG(cancelPendingCallbacks);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::CloseThreadPoolWait(ThreadPoolWaitPtr poolWait) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CloseThreadpoolWait(poolWait);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(poolWait);
#endif // SYSTEM_PLATFORM_WIN32
}

System::ThreadPoolIOPtr System
	::CreateThreadPoolIo(ThreadHandle handle, ThreadPoolWin32IoCallback callback, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateThreadpoolIo(handle, callback, data, threadEnviron);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(callback);
	SYSTEM_UNUSED_ARG(data);
	SYSTEM_UNUSED_ARG(threadEnviron);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::StartThreadPoolIo(ThreadPoolIOPtr threadPoolIO) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::StartThreadpoolIo(threadPoolIO);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadPoolIO);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::CancelThreadPoolIo(ThreadPoolIOPtr threadPoolIO) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CancelThreadpoolIo(threadPoolIO);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadPoolIO);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::CloseThreadPoolIo(ThreadPoolIOPtr threadPoolIO) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CloseThreadpoolIo(threadPoolIO);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadPoolIO);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::WaitForThreadPoolIoCallbacks(ThreadPoolIOPtr threadPoolIO, bool cancelPendingCallbacks) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::WaitForThreadpoolIoCallbacks(threadPoolIO, BoolConversion(cancelPendingCallbacks));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadPoolIO);
	SYSTEM_UNUSED_ARG(cancelPendingCallbacks);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetEventWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, WindowHandle eventHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SetEventWhenCallbackReturns(callBackInstance, eventHandle);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(callBackInstance);
	SYSTEM_UNUSED_ARG(eventHandle);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::ReleaseSemaphoreWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, WindowHandle semaphoreHandle, WindowDWord crel) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::ReleaseSemaphoreWhenCallbackReturns(callBackInstance, semaphoreHandle, crel);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(callBackInstance);
	SYSTEM_UNUSED_ARG(semaphoreHandle);
	SYSTEM_UNUSED_ARG(crel);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::ReleaseMutexWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, WindowHandle mutexHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::ReleaseMutexWhenCallbackReturns(callBackInstance, mutexHandle);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(callBackInstance);
	SYSTEM_UNUSED_ARG(mutexHandle);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::LeaveCriticalSectionWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, ThreadingCriticalSectionPtr criticalSection) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::LeaveCriticalSectionWhenCallbackReturns(callBackInstance, criticalSection);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(callBackInstance);
	SYSTEM_UNUSED_ARG(criticalSection);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::FreeLibraryWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, DynamicLinkModule module) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::FreeLibraryWhenCallbackReturns(callBackInstance, module);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(callBackInstance);
	SYSTEM_UNUSED_ARG(module);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::InitializeThreadPoolEnvironment(ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::InitializeThreadpoolEnvironment(threadEnviron);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadEnviron);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetThreadPoolCallbackPool(ThreadPoolCallbackEnvironPtr threadEnviron, ThreadPoolPoolPtr threadPool) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SetThreadpoolCallbackPool(threadEnviron, threadPool);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadEnviron);
	SYSTEM_UNUSED_ARG(threadPool);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetThreadPoolCallbackCleanupGroup(ThreadPoolCallbackEnvironPtr threadEnviron, ThreadPoolCleanupGroupPtr cleanupGroup, ThreadPoolCleanupGroupCancelCallback cancelCallback) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SetThreadpoolCallbackCleanupGroup(threadEnviron, cleanupGroup, cancelCallback);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadEnviron);
	SYSTEM_UNUSED_ARG(cleanupGroup);
	SYSTEM_UNUSED_ARG(cancelCallback);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetThreadPoolCallbackRunsLong(ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SetThreadpoolCallbackRunsLong(threadEnviron);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadEnviron);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetThreadPoolCallBackLibrary(ThreadPoolCallbackEnvironPtr threadEnviron, WindowVoidPtr module) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SetThreadpoolCallbackLibrary(threadEnviron, module);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadEnviron);
	SYSTEM_UNUSED_ARG(module);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetThreadPoolCallbackPriority(ThreadPoolCallbackEnvironPtr threadEnviron, ThreadPoolCallbackPriority priority) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SetThreadpoolCallbackPriority(threadEnviron, priority);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadEnviron);
	SYSTEM_UNUSED_ARG(priority);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::SetThreadPoolCallbackPersistent(ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::SetThreadpoolCallbackPersistent(threadEnviron);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadEnviron);
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::DestroyThreadPoolEnvironment(ThreadPoolCallbackEnvironPtr threadEnviron) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::DestroyThreadpoolEnvironment(threadEnviron);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadEnviron);
#endif // SYSTEM_PLATFORM_WIN32
}
