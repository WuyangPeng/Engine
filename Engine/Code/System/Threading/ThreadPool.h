// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/10 11:34)

#ifndef SYSTEM_THREADING_THREAD_POOL_H
#define SYSTEM_THREADING_THREAD_POOL_H

#include "System/SystemDll.h"

#include "Using/ThreadUsing.h"
#include "Using/ThreadPoolUsing.h" 
#include "Using/CriticalSectionUsing.h"
#include "System/FileManager/Using/FileUsing.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"

namespace System
{
	// 线程池的相关操作

	ThreadPoolPoolPtr SYSTEM_DEFAULT_DECLARE CreateThreadPool() noexcept;
	void SYSTEM_DEFAULT_DECLARE SetThreadPoolMaximumThread(ThreadPoolPoolPtr threadPool, WindowDWord threadMost) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetThreadPoolMinimumThread(ThreadPoolPoolPtr threadPool, WindowDWord threadMic) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetThreadPoolStackInformation(ThreadPoolPoolPtr threadPool, ThreadPoolPoolStackInformationPtr stackInformation) noexcept;
	bool SYSTEM_DEFAULT_DECLARE QueryThreadPoolStackInformation(ThreadPoolPoolPtr threadPool, ThreadPoolPoolStackInformationPtr stackInformation) noexcept;
	void SYSTEM_DEFAULT_DECLARE CloseThreadPool(ThreadPoolPoolPtr threadPool) noexcept;

	ThreadPoolCleanupGroupPtr SYSTEM_DEFAULT_DECLARE CreateThreadPoolCleanupGroup() noexcept;
	void SYSTEM_DEFAULT_DECLARE CloseThreadPoolCleanupGroupMembers(ThreadPoolCleanupGroupPtr cleanupGroup, bool cancelPendingCallbacks, WindowVoidPtr cleanupContext) noexcept;
	void SYSTEM_DEFAULT_DECLARE CloseThreadPoolCleanupGroup(ThreadPoolCleanupGroupPtr cleanupGroup) noexcept;
	bool SYSTEM_DEFAULT_DECLARE CallBackMayRunLong(ThreadPoolCallBackInstancePtr callBackInstance) noexcept;
	void SYSTEM_DEFAULT_DECLARE DisassociateCurrentThreadFromCallBack(ThreadPoolCallBackInstancePtr callBackInstance) noexcept;

	void SYSTEM_DEFAULT_DECLARE	InitializeThreadPoolEnvironment(ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void SYSTEM_DEFAULT_DECLARE	SetThreadPoolCallbackPool(ThreadPoolCallbackEnvironPtr threadEnviron, ThreadPoolPoolPtr threadPool) noexcept;
	void SYSTEM_DEFAULT_DECLARE SetThreadPoolCallbackCleanupGroup(ThreadPoolCallbackEnvironPtr threadEnviron, ThreadPoolCleanupGroupPtr cleanupGroup, ThreadPoolCleanupGroupCancelCallback cancelCallback) noexcept;
	void SYSTEM_DEFAULT_DECLARE SetThreadPoolCallbackRunsLong(ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void SYSTEM_DEFAULT_DECLARE SetThreadPoolCallBackLibrary(ThreadPoolCallbackEnvironPtr threadEnviron, WindowVoidPtr module) noexcept;
	void SYSTEM_DEFAULT_DECLARE SetThreadPoolCallbackPriority(ThreadPoolCallbackEnvironPtr threadEnviron, ThreadPoolCallbackPriority priority) noexcept;
	void SYSTEM_DEFAULT_DECLARE SetThreadPoolCallbackPersistent(ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void SYSTEM_DEFAULT_DECLARE DestroyThreadPoolEnvironment(ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;

	void SYSTEM_DEFAULT_DECLARE SubmitThreadPoolWork(ThreadPoolWorkPtr work) noexcept;
	ThreadPoolWorkPtr SYSTEM_DEFAULT_DECLARE CreateThreadPoolWork(ThreadPoolWorkCallback callback, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void SYSTEM_DEFAULT_DECLARE CloseThreadPoolWork(ThreadPoolWorkPtr work) noexcept;
	void SYSTEM_DEFAULT_DECLARE WaitForThreadPoolWorkCallbacks(ThreadPoolWorkPtr work, bool cancelPendingCallbacks) noexcept;
	bool SYSTEM_DEFAULT_DECLARE TrySubmitThreadPoolCallback(ThreadPoolSimpleCallback function, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;

	ThreadPoolTimerPtr SYSTEM_DEFAULT_DECLARE CreateThreadPoolTimer(ThreadPoolTimerCallback function, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void SYSTEM_DEFAULT_DECLARE SetThreadPoolTimer(ThreadPoolTimerPtr timer, FileTimePtr dueTime, WindowDWord period, WindowDWord windowLength) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsThreadPoolTimerSet(ThreadPoolTimerPtr timer) noexcept;
	void SYSTEM_DEFAULT_DECLARE	CloseThreadPoolTimer(ThreadPoolTimerPtr timer) noexcept;
	void SYSTEM_DEFAULT_DECLARE	WaitForThreadPoolTimerCallbacks(ThreadPoolTimerPtr timer, bool cancelPendingCallbacks) noexcept;

	ThreadPoolWaitPtr SYSTEM_DEFAULT_DECLARE CreateThreadPoolWait(ThreadPoolWaitCallback function, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void SYSTEM_DEFAULT_DECLARE SetThreadPoolWait(ThreadPoolWaitPtr poolWait, ThreadHandle handle, FileTimePtr timeout) noexcept;
	void SYSTEM_DEFAULT_DECLARE WaitForThreadPoolWaitCallbacks(ThreadPoolWaitPtr poolWait, bool cancelPendingCallbacks) noexcept;
	void SYSTEM_DEFAULT_DECLARE CloseThreadPoolWait(ThreadPoolWaitPtr poolWait) noexcept;

	ThreadPoolIOPtr SYSTEM_DEFAULT_DECLARE CreateThreadPoolIo(ThreadHandle handle, ThreadPoolWin32IoCallback callback, WindowVoidPtr data, ThreadPoolCallbackEnvironPtr threadEnviron) noexcept;
	void SYSTEM_DEFAULT_DECLARE StartThreadPoolIo(ThreadPoolIOPtr threadPoolIO) noexcept;
	void SYSTEM_DEFAULT_DECLARE CancelThreadPoolIo(ThreadPoolIOPtr threadPoolIO) noexcept;
	void SYSTEM_DEFAULT_DECLARE CloseThreadPoolIo(ThreadPoolIOPtr threadPoolIO) noexcept;
	void SYSTEM_DEFAULT_DECLARE WaitForThreadPoolIoCallbacks(ThreadPoolIOPtr threadPoolIO, bool cancelPendingCallbacks) noexcept;

	void SYSTEM_DEFAULT_DECLARE SetEventWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, WindowHandle eventHandle) noexcept;
	void SYSTEM_DEFAULT_DECLARE ReleaseSemaphoreWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, WindowHandle semaphoreHandle, WindowDWord crel) noexcept;
	void SYSTEM_DEFAULT_DECLARE ReleaseMutexWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, WindowHandle mutexHandle) noexcept;
	void SYSTEM_DEFAULT_DECLARE LeaveCriticalSectionWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, ThreadingCriticalSectionPtr criticalSection) noexcept;
	void SYSTEM_DEFAULT_DECLARE FreeLibraryWhenCallBackReturns(ThreadPoolCallBackInstancePtr callBackInstance, DynamicLinkModule module) noexcept;
}

#endif // SYSTEM_THREADING_THREAD_POOL_H