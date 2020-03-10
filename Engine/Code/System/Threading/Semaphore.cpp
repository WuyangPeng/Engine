// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:16)

#include "System/SystemExport.h"

#include "Semaphore.h"  
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Window/WindowSystem.h"
#include "System/EnumOperator/EnumCastDetail.h"

System::WindowHandle System
    ::CreateSystemSemaphore(WindowSecurityAttributesPtr semaphoreAttributes,WindowLong initialCount,WindowLong maximumCount,const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateSemaphore(semaphoreAttributes, initialCount, maximumCount, name);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(semaphoreAttributes);
	SYSTEM_UNUSED_ARG(initialCount);
	SYSTEM_UNUSED_ARG(maximumCount);
	SYSTEM_UNUSED_ARG(name);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::CreateSystemSemaphore(WindowLong initialCount, WindowLong maximumCount) noexcept
{
	return CreateSystemSemaphore(nullptr, initialCount, maximumCount, nullptr);
}

bool System
    ::WaitForSystemSemaphore(WindowHandle handle) noexcept
{
	return MutexWaitReturn::Failed != WaitForSystemSemaphore(handle, EnumCastUnderlying(MutexWait::Infinite));
}

System::MutexWaitReturn System
	::WaitForSystemSemaphore(WindowHandle handle, WindowDWord milliseconds) noexcept
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
	::WaitForSystemSemaphore(WindowHandle handle, WindowDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(handle, milliseconds,BoolConversion(alertable)));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(milliseconds);
	SYSTEM_UNUSED_ARG(alertable);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System
	::WaitForSystemSemaphore(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept
{	
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll),milliseconds, BoolConversion(alertable)));
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
	::WaitForSystemSemaphore(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept
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

bool System
    ::ReleaseSystemSemaphore(WindowHandle handle,WindowLong releaseCount,WindowLongPtr previousCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
     if(::ReleaseSemaphore(handle, releaseCount, previousCount) != g_False)
        return true;
     else
        return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(releaseCount);
	SYSTEM_UNUSED_ARG(previousCount);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
    ::CloseSystemSemaphore(WindowHandle handle) noexcept
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

System::WindowHandle System
	::OpenSystemSemaphore(MutexStandardAccess desiredAccess, SemaphoreSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::OpenSemaphore(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess),BoolConversion(inheritHandle), name);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(specificAccess);
	SYSTEM_UNUSED_ARG(inheritHandle);
	SYSTEM_UNUSED_ARG(name);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsSystemSemaphoreValid(WindowHandle handle) noexcept
{
	if (handle != nullptr && handle != g_InvalidHandleValue)
		return true;
	else
		return false;
} 