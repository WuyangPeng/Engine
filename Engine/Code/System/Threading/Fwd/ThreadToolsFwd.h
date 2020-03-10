// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:11)

#ifndef SYSTEM_THREADING_THREAD_TOOLS_FWD_H
#define SYSTEM_THREADING_THREAD_TOOLS_FWD_H  

#include "ThreadingFlagsFwd.h"
#include "System/Threading/Using/ThreadToolsUsing.h"
#include "System/Threading/Using/ThreadPoolUsing.h"

namespace System
{
	ThreadHandle CreateSystemRemoteThread(WindowHandle process, WindowSecurityAttributesPtr threadAttributes, WindowSize stackSize, ThreadStartRoutine startAddress,
										  WindowVoidPtr parameter, ThreadCreation creationFlags, WindowDWordPtr threadID) noexcept;
	ThreadHandle CreateSystemRemoteThread(WindowHandle process, WindowSecurityAttributesPtr threadAttributes, WindowSize stackSize, ThreadStartRoutine startAddress,
										  WindowVoidPtr parameter, ThreadCreation creationFlags, ProcThreadAttributeListPtr attributeList, WindowDWordPtr threadID) noexcept;
	ThreadHandle OpenSystemThread(ThreadStandardAccess standardDesiredAccess, ThreadSpecificAccess specificDesiredAccess, bool inheritHandle, WindowDWord threadID) noexcept;
	bool GetThreadExitCode(ThreadHandle thread, WindowDWordPtr exitCode) noexcept;
	WindowDWord GetSystemThreadID(ThreadHandle thread) noexcept;
	bool SetSystemThreadPriorityBoost(ThreadHandle thread, bool disablePriorityBoost) noexcept;
	bool GetSystemThreadPriorityBoost(ThreadHandle thread, WindowBoolPtr disablePriorityBoost) noexcept;

	bool SwitchToSystemThread() noexcept;
	bool OpenSystemThreadToken(ThreadHandle thread, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, bool openAsSelf, WindowHandlePtr tokenHandle) noexcept;
	bool SetSystemThreadToken(ThreadHandlePtr thread, WindowHandle tokenHandle) noexcept;
	bool CloseTokenHandle(WindowHandle tokenHandle) noexcept;
	bool ImpersonateThreadSelf(SecurityImpersonationLevel securityImpersonationLevel) noexcept;
	bool GetSystemThreadContext(ThreadHandle thread, WindowContextPtr context) noexcept;
	bool SetSystemThreadContext(ThreadHandle thread, const WindowContext* context) noexcept;
	void InitThreadContextFlags(WindowContext& context, ThreadContextState flags) noexcept;
	bool GetSystemThreadTimes(ThreadHandle thread, FileTimePtr creationTime, FileTimePtr exitTime, FileTimePtr kernelTime, FileTimePtr userTime) noexcept;
}

#endif // SYSTEM_THREADING_THREAD_TOOLS_FWD_H