// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 16:14)

#ifndef SYSTEM_THREADING_THREAD_TOOLS_H
#define SYSTEM_THREADING_THREAD_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ThreadUsing.h"
#include "Using/ThreadToolsUsing.h"
#include "System/FileManager/Using/FileUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
	// 线程辅助工具。

	ThreadHandle SYSTEM_DEFAULT_DECLARE CreateSystemRemoteThread(WindowHandle process, WindowSecurityAttributesPtr threadAttributes, WindowSize stackSize, ThreadStartRoutine startAddress,
																 WindowVoidPtr parameter, ThreadCreation creationFlags, WindowDWordPtr threadID) noexcept;
	ThreadHandle SYSTEM_DEFAULT_DECLARE CreateSystemRemoteThread(WindowHandle process, WindowSecurityAttributesPtr threadAttributes, WindowSize stackSize,
																 ThreadStartRoutine startAddress, WindowVoidPtr parameter, ThreadCreation creationFlags,
																 ProcThreadAttributeListPtr attributeList, WindowDWordPtr threadID) noexcept;
	ThreadHandle SYSTEM_DEFAULT_DECLARE OpenSystemThread(ThreadStandardAccess standardDesiredAccess, ThreadSpecificAccess specificDesiredAccess, bool inheritHandle, WindowDWord threadID) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetThreadExitCode(ThreadHandle thread, WindowDWordPtr exitCode) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemThreadID(ThreadHandle thread) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemThreadPriorityBoost(ThreadHandle thread, bool disablePriorityBoost) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemThreadPriorityBoost(ThreadHandle thread, WindowBoolPtr disablePriorityBoost) noexcept;

	bool SYSTEM_DEFAULT_DECLARE SwitchToSystemThread() noexcept;
	bool SYSTEM_DEFAULT_DECLARE OpenSystemThreadToken(ThreadHandle thread, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, bool openAsSelf, WindowHandlePtr tokenHandle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemThreadToken(ThreadHandlePtr thread, WindowHandle tokenHandle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE CloseTokenHandle(WindowHandle tokenHandle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ImpersonateThreadSelf(SecurityImpersonationLevel securityImpersonationLevel) noexcept;
	void SYSTEM_DEFAULT_DECLARE InitThreadContextFlags(WindowContext& context, ThreadContextState flags) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemThreadContext(ThreadHandle thread, WindowContextPtr context) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemThreadContext(ThreadHandle thread, const WindowContext* context) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemThreadTimes(ThreadHandle thread, FileTimePtr creationTime, FileTimePtr exitTime, FileTimePtr kernelTime, FileTimePtr userTime) noexcept;
}

#endif // SYSTEM_THREADING_THREAD_TOOLS_H