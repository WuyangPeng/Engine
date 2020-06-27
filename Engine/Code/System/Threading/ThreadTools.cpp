// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:17)

#include "System/SystemExport.h"

#include "ThreadTools.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"
#include "System/Helper/EnumCast.h"

System::ThreadHandle System
	::CreateSystemRemoteThread(WindowHandle process, WindowSecurityAttributesPtr threadAttributes, WindowSize stackSize, ThreadStartRoutine startAddress,
							   WindowVoidPtr parameter, ThreadCreation creationFlags, WindowDWordPtr threadID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateRemoteThread(process, threadAttributes, stackSize, startAddress, parameter, EnumCastUnderlying(creationFlags), threadID);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(threadAttributes);
	SYSTEM_UNUSED_ARG(stackSize);
	SYSTEM_UNUSED_ARG(startAddress);
	SYSTEM_UNUSED_ARG(parameter);
	SYSTEM_UNUSED_ARG(creationFlags);
	SYSTEM_UNUSED_ARG(threadID);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System
	::CreateSystemRemoteThread(WindowHandle process, WindowSecurityAttributesPtr threadAttributes, WindowSize stackSize, ThreadStartRoutine startAddress,
							   WindowVoidPtr parameter, ThreadCreation creationFlags, ProcThreadAttributeListPtr attributeList, WindowDWordPtr threadID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateRemoteThreadEx(process, threadAttributes, stackSize, startAddress, parameter, EnumCastUnderlying(creationFlags), attributeList, threadID);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(process);
	SYSTEM_UNUSED_ARG(threadAttributes);
	SYSTEM_UNUSED_ARG(stackSize);
	SYSTEM_UNUSED_ARG(startAddress);
	SYSTEM_UNUSED_ARG(parameter);
	SYSTEM_UNUSED_ARG(creationFlags);
	SYSTEM_UNUSED_ARG(attributeList);
	SYSTEM_UNUSED_ARG(threadID);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::ThreadHandle System
	::OpenSystemThread(ThreadStandardAccess standardDesiredAccess, ThreadSpecificAccess specificDesiredAccess, bool inheritHandle, WindowDWord threadID) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::OpenThread(EnumCastUnderlying(standardDesiredAccess) | EnumCastUnderlying(specificDesiredAccess), BoolConversion(inheritHandle), threadID);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(standardDesiredAccess);
	SYSTEM_UNUSED_ARG(specificDesiredAccess);
	SYSTEM_UNUSED_ARG(inheritHandle);
	SYSTEM_UNUSED_ARG(threadID);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetThreadExitCode(ThreadHandle thread, WindowDWordPtr exitCode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetExitCodeThread(thread, exitCode) != g_False)
		return true;
	else
		return false;
#else // SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(exitCode);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemThreadID(ThreadHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetThreadId(thread);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemThreadPriorityBoost(ThreadHandle thread, bool disablePriorityBoost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetThreadPriorityBoost(thread, disablePriorityBoost) != g_False)
		return true;
	else
		return false;
#else // SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(disablePriorityBoost);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemThreadPriorityBoost(ThreadHandle thread, WindowBoolPtr disablePriorityBoost) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetThreadPriorityBoost(thread, disablePriorityBoost) != g_False)
		return true;
	else
		return false;
#else // SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(disablePriorityBoost);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SwitchToSystemThread() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SwitchToThread() != g_False)
		return true;
	else
		return false;
#else // SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::OpenSystemThreadToken(ThreadHandle thread, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, bool openAsSelf, WindowHandlePtr tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::OpenThreadToken(thread, EnumCastUnderlying(standardAccess) | EnumCastUnderlying(specificAccess), BoolConversion(openAsSelf), tokenHandle) != g_False)
		return true;
	else
		return false;
#else // SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(standardAccess);
	SYSTEM_UNUSED_ARG(specificAccess);
	SYSTEM_UNUSED_ARG(openAsSelf);
	SYSTEM_UNUSED_ARG(tokenHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemThreadToken(ThreadHandlePtr thread, WindowHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetThreadToken(thread, tokenHandle) != g_False)
		return true;
	else
		return false;
#else // SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(tokenHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemThreadContext(ThreadHandle thread, WindowContextPtr context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetThreadContext(thread, context) != g_False)
		return true;
	else
		return false;
#else // SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(context);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemThreadContext(ThreadHandle thread, const WindowContext* context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetThreadContext(thread, context) != g_False)
		return true;
	else
		return false;
#else // SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(context);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemThreadTimes(ThreadHandle thread, FileTimePtr creationTime, FileTimePtr exitTime, FileTimePtr kernelTime, FileTimePtr userTime) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetThreadTimes(thread, creationTime, exitTime, kernelTime, userTime) != g_False)
		return true;
	else
		return false;
#else // SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);
	SYSTEM_UNUSED_ARG(creationTime);
	SYSTEM_UNUSED_ARG(exitTime);
	SYSTEM_UNUSED_ARG(kernelTime);
	SYSTEM_UNUSED_ARG(userTime);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CloseTokenHandle(WindowHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CloseHandle(tokenHandle) != g_False)
		return true;
	else
		return false;
#else // SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(tokenHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ImpersonateThreadSelf(SecurityImpersonationLevel securityImpersonationLevel) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ImpersonateSelf(securityImpersonationLevel) != g_False)
		return true;
	else
		return false;
#else // SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityImpersonationLevel);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::InitThreadContextFlags(WindowContext& context, ThreadContextState flags) noexcept
{
	context.ContextFlags = EnumCastUnderlying(flags);
}

