// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 12:54)

#include "System/SystemExport.h"

#include "Mutex.h"
#include "Flags/MutexFlags.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Window/WindowSystem.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26487)

System::WindowHandle System
	::CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes, bool initialOwner, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateMutex(mutexAttributes, BoolConversion(initialOwner), name);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(mutexAttributes);
	SYSTEM_UNUSED_ARG(initialOwner);
	SYSTEM_UNUSED_ARG(name);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes, const TChar* name, MutexCreate flag, MutexStandardAccess desiredAccess, MutexSpecificAccess specificAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateMutexEx(mutexAttributes, name, EnumCastUnderlying(flag), EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(mutexAttributes);
	SYSTEM_UNUSED_ARG(name);
	SYSTEM_UNUSED_ARG(flag);
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(specificAccess);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::CreateSystemMutex() noexcept
{
	return CreateSystemMutex(nullptr, false, nullptr);
}

bool System
	::CloseSystemMutex(WindowHandle handle) noexcept
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
	::ReleaseSystemMutex(WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ReleaseMutex(handle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WaitForSystemMutex(WindowHandle handle) noexcept
{
	return MutexWaitReturn::Failed != WaitForSystemMutex(handle, EnumCastUnderlying(MutexWait::Infinite));
}

System::MutexWaitReturn System
	::WaitForSystemMutex(WindowHandle handle, WindowDWord milliseconds) noexcept
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
	::WaitForSystemMutex(WindowHandle handle, WindowDWord milliseconds, bool alertable) noexcept
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
	::WaitForSystemMutex(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept
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
	::WaitForSystemMutex(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept
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
	::OpenThreadingMutex(MutexStandardAccess desiredAccess, MutexSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::OpenMutex(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess), BoolConversion(inheritHandle), name);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(specificAccess);
	SYSTEM_UNUSED_ARG(inheritHandle);
	SYSTEM_UNUSED_ARG(name);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
System::PthreadResult System
	::PthreadMutexAttributeInit(PthreadMutexattrT* attribute) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
	return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutexattr_init(attribute));
#elif defined(SYSTEM_PLATFORM_WIN32)
	if (attribute != nullptr)
		return PthreadResult::Successful;
	else
		return PthreadResult::ENomem;
#else // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(attribute);

	return PthreadResult::ENomem;
#endif // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System
	::PthreadMutexAttributeSetType(PthreadMutexattrT* attribute) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
	return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutexattr_settype(attribute, EnumCastUnderlying(PthreadMutexCompatibility::Recursive)));
#elif defined(SYSTEM_PLATFORM_WIN32) 

	SYSTEM_UNUSED_ARG(attribute);

	return PthreadResult::Successful;

#else // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(attribute);

	return PthreadResult::ENomem;
#endif // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System
	::PthreadMutexInit(PthreadMutexattrT* attribute, PthreadMutexT* mutex) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
	return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutex_init(mutex, attribute));
#elif defined(SYSTEM_PLATFORM_WIN32) 
	if (attribute == nullptr || mutex == nullptr)
	{
		return PthreadResult::EInval;
	}
	else
	{
		*mutex = CreateSystemMutex();
		if (*mutex != nullptr)
			return PthreadResult::Successful;
		else
			return PthreadResult::EInval;
	}

#else // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(attribute);
	SYSTEM_UNUSED_ARG(mutex);

	return PthreadResult::EInval;
#endif // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System
	::PthreadMutexAttributeDestroy(PthreadMutexattrT* attribute) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
	return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutexattr_destroy(attribute));
#elif defined(SYSTEM_PLATFORM_WIN32) 
	if (attribute != nullptr)
		return PthreadResult::Successful;
	else
		return PthreadResult::EInval;
#else // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(attribute);

	return PthreadResult::EInval;
#endif // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}
#include STSTEM_WARNING_POP

System::PthreadResult System
	::PthreadMutexDestroy(PthreadMutexT* mutex) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
	return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutex_destroy(mutex));
#elif defined(SYSTEM_PLATFORM_WIN32) 

	if (mutex == nullptr)
		return PthreadResult::EInval;
	else  if (CloseSystemMutex(*mutex))
		return PthreadResult::Successful;
	else
		return PthreadResult::EInval;

#else // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(mutex);

	return PthreadResult::EInval;
#endif // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System
	::PthreadMutexLock(PthreadMutexT* mutex) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
	return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutex_lock(mutex));
#elif defined(SYSTEM_PLATFORM_WIN32) 

	if (mutex == nullptr)
		return PthreadResult::EInval;
	else if (WaitForSystemMutex(*mutex))
		return PthreadResult::Successful;
	else
		return PthreadResult::EInval;

#else // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(mutex);

	return PthreadResult::EInval;
#endif // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System
	::PthreadMutexUnlock(PthreadMutexT* mutex) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
	return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutex_unlock(mutex));
#elif defined(SYSTEM_PLATFORM_WIN32)

	if (mutex == nullptr)
		return PthreadResult::EInval;
	else  if (ReleaseSystemMutex(*mutex))
		return PthreadResult::Successful;
	else
		return PthreadResult::EInval;

#else // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(mutex);

	return PthreadResult::EInval;
#endif // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System
	::PthreadMutexTrylock(PthreadMutexT* mutex) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
	return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutex_trylock(mutex));
#elif defined(SYSTEM_PLATFORM_WIN32)  

	if (mutex == nullptr)
		return PthreadResult::EInval;
	else if (WaitForSystemMutex(*mutex, EnumCastUnderlying(MutexWait::Ignore)) == MutexWaitReturn::Object0)
		return PthreadResult::Successful;
	else
		return PthreadResult::EInval;

#else // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(mutex);

	return PthreadResult::EInval;
#endif // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

bool System
	::IsSystemMutexValid(WindowHandle handle) noexcept
{
	if (handle != nullptr && handle != g_InvalidHandleValue)
		return true;
	else
		return false;
}

#include STSTEM_WARNING_POP