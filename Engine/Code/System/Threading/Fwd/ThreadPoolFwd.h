// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:11)

#ifndef SYSTEM_THREADING_THREAD_POOL_FWD_H
#define SYSTEM_THREADING_THREAD_POOL_FWD_H   

#include "System/Threading/Using/ThreadPoolUsing.h"

namespace System
{
	ThreadPoolPoolPtr CreateThreadPool() noexcept;
	void SetThreadPoolMaximumThread(ThreadPoolPoolPtr threadPool, WindowDWord threadMost) noexcept;
	bool SetThreadPoolMinimumThread(ThreadPoolPoolPtr threadPool, WindowDWord threadMic) noexcept;
	bool SetThreadPoolStackInformation(ThreadPoolPoolPtr threadPool, ThreadPoolPoolStackInformationPtr stackInformation) noexcept;
	bool QueryThreadPoolStackInformation(ThreadPoolPoolPtr threadPool, ThreadPoolPoolStackInformationPtr stackInformation) noexcept;
	void CloseThreadPool(ThreadPoolPoolPtr threadPool) noexcept;

	ThreadPoolCleanupGroupPtr CreateThreadPoolCleanupGroup() noexcept;
	void CloseThreadPoolCleanupGroupMembers(ThreadPoolCleanupGroupPtr cleanupGroup, bool cancelPendingCallbacks, WindowVoidPtr cleanupContext) noexcept;
	void CloseThreadPoolCleanupGroup(ThreadPoolCleanupGroupPtr cleanupGroup) noexcept;
	bool CallBackMayRunLong(ThreadPoolCallBackInstancePtr callBackInstance) noexcept;
	void DisassociateCurrentThreadFromCallBack(ThreadPoolCallBackInstancePtr callBackInstance) noexcept;

	void InitializeThreadPoolEnvironment(ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void SetThreadPoolCallbackPool(ThreadPoolCallbackEnvironPtr threadEnviron, ThreadPoolPoolPtr threadPool) noexcept;
	void SetThreadPoolCallbackCleanupGroup(ThreadPoolCallbackEnvironPtr threadEnviron, ThreadPoolCleanupGroupPtr cleanupGroup, ThreadPoolCleanupGroupCancelCallback cancelCallback) noexcept;
	void SetThreadPoolCallbackRunsLong(ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void SetThreadPoolCallBackLibrary(ThreadPoolCallbackEnvironPtr threadEnviron, WindowVoidPtr module) noexcept;
	void SetThreadPoolCallbackPriority(ThreadPoolCallbackEnvironPtr threadEnviron, ThreadPoolCallbackPriority priority) noexcept;
	void SetThreadPoolCallbackPersistent(ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void DestroyThreadPoolEnvironment(ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;

	void SubmitThreadPoolWork(ThreadPoolWorkPtr work) noexcept;
	ThreadPoolWorkPtr CreateThreadPoolWork(ThreadPoolWorkCallback callback, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void CloseThreadPoolWork(ThreadPoolWorkPtr  work) noexcept;
	void WaitForThreadPoolWorkCallbacks(ThreadPoolWorkPtr work, bool cancelPendingCallbacks) noexcept;

	bool TrySubmitThreadPoolCallback(ThreadPoolSimpleCallback function, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	ThreadPoolTimerPtr CreateThreadPoolTimer(ThreadPoolTimerCallback function, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void SetThreadPoolTimer(ThreadPoolTimerPtr timer, FileTimePtr dueTime, WindowDWord period, WindowDWord windowLength) noexcept;
	bool IsThreadPoolTimerSet(ThreadPoolTimerPtr timer) noexcept;
	void CloseThreadPoolTimer(ThreadPoolTimerPtr timer) noexcept;
	void WaitForThreadPoolTimerCallbacks(ThreadPoolTimerPtr timer, bool cancelPendingCallbacks) noexcept;

	ThreadPoolWaitPtr CreateThreadPoolWait(ThreadPoolWaitCallback function, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void SetThreadPoolWait(ThreadPoolWaitPtr poolWait, ThreadHandle handle, FileTimePtr timeout) noexcept;
	void WaitForThreadPoolWaitCallbacks(ThreadPoolWaitPtr poolWait, bool cancelPendingCallbacks) noexcept;
	void CloseThreadPoolWait(ThreadPoolWaitPtr poolWait) noexcept;

	ThreadPoolIOPtr CreateThreadPoolIo(ThreadHandle handle, ThreadPoolWin32IoCallback callback, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void StartThreadPoolIo(ThreadPoolIOPtr threadPoolIO) noexcept;
	void CancelThreadPoolIo(ThreadPoolIOPtr threadPoolIO) noexcept;
	void CloseThreadPoolIo(ThreadPoolIOPtr threadPoolIO) noexcept;
	void WaitForThreadPoolIoCallbacks(ThreadPoolIOPtr threadPoolIO, bool cancelPendingCallbacks) noexcept;

	void SetEventWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, WindowHandle eventHandle) noexcept;
	void ReleaseSemaphoreWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, WindowHandle semaphoreHandle, WindowDWord crel) noexcept;
	void ReleaseMutexWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, WindowHandle mutexHandle) noexcept;
	void LeaveCriticalSectionWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, ThreadingCriticalSectionPtr criticalSection) noexcept;
	void FreeLibraryWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, DynamicLinkModule module) noexcept;
}

#endif // SYSTEM_THREADING_THREAD_POOL_FWD_H