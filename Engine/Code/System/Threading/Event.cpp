// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:15)

#include "System/SystemExport.h"

#include "Event.h"  
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"
#include "System/EnumOperator/EnumCastDetail.h"

System::WindowHandle System
	::CreateSystemEvent(WindowSecurityAttributesPtr securityAttributes, bool manualReset, bool initialState, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateEvent(securityAttributes, BoolConversion(manualReset), BoolConversion(initialState), name);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityAttributes);
	SYSTEM_UNUSED_ARG(manualReset);
	SYSTEM_UNUSED_ARG(initialState);
	SYSTEM_UNUSED_ARG(name);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::CreateSystemEvent(bool manualReset, bool initialState) noexcept
{
	return CreateSystemEvent(nullptr, manualReset, initialState, nullptr);
}

System::WindowHandle System
	::CreateSystemEvent(WindowSecurityAttributesPtr securityAttributes, const TChar* name, CreateEventType flag, MutexStandardAccess desiredAccess, EventSpecificAccess specificAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateEventEx(securityAttributes, name, EnumCastUnderlying(flag), EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityAttributes);
	SYSTEM_UNUSED_ARG(name);
	SYSTEM_UNUSED_ARG(flag);
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(specificAccess);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CloseSystemEvent(WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CloseHandle(handle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemEvent(WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetEvent(handle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::ResetSystemEvent(WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ResetEvent(handle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WaitForSystemEvent(WindowHandle handle) noexcept
{
	return MutexWaitReturn::Failed != WaitForSystemEvent(handle, EnumCastUnderlying(MutexWait::Infinite));
}

System::MutexWaitReturn System
	::WaitForSystemEvent(WindowHandle handle, WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(handle, milliseconds));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(milliseconds);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System
	::WaitForSystemEvent(WindowHandle handle, WindowDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable)));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(milliseconds);
	SYSTEM_UNUSED_ARG(alertable);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System
	::WaitForSystemEvent(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(count);
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(waitAll);
	SYSTEM_UNUSED_ARG(milliseconds);
	SYSTEM_UNUSED_ARG(alertable);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System
	::WaitForSystemEvent(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(count);
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(waitAll);
	SYSTEM_UNUSED_ARG(milliseconds);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::OpenSystemEvent(MutexStandardAccess desiredAccess, EventSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::OpenEvent(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess), BoolConversion(inheritHandle), name);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(specificAccess);
	SYSTEM_UNUSED_ARG(inheritHandle);
	SYSTEM_UNUSED_ARG(name);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsSystemEventValid(WindowHandle eventHandle) noexcept
{
	if (eventHandle != nullptr && eventHandle != g_InvalidHandleValue)
		return true;
	else
		return false;
}









