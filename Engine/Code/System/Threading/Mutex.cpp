///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 19:10)

#include "System/SystemExport.h"

#include "Mutex.h"
#include "Flags/MutexFlags.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

System::WindowsHandle System::CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes, bool initialOwner, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateMutex(mutexAttributes, BoolConversion(initialOwner), name);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(mutexAttributes, initialOwner, name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes, const TChar* name, MutexCreate flag, MutexStandardAccess desiredAccess, MutexSpecificAccess specificAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateMutexEx(mutexAttributes, name, EnumCastUnderlying(flag), EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(mutexAttributes, name, flag, desiredAccess, specificAccess);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::CreateSystemMutex() noexcept
{
    return CreateSystemMutex(nullptr, false, nullptr);
}

bool System::CloseSystemMutex(WindowsHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CloseHandle(handle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReleaseSystemMutex(WindowsHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::ReleaseMutex(handle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WaitForSystemMutex(WindowsHandle handle) noexcept
{
    return WaitForSystemMutex(handle, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System::WaitForSystemMutex(WindowsHandle handle, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(handle, milliseconds));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemMutex(WindowsHandle handle, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemMutex(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, handle, waitAll, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemMutex(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, handle, waitAll, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::OpenThreadingMutex(MutexStandardAccess desiredAccess, MutexSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::OpenMutex(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess), BoolConversion(inheritHandle), name);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(desiredAccess, specificAccess, inheritHandle, name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::PthreadResult System::PthreadMutexAttributeSetType(PthreadMutexattrT* attribute) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)

    return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutexattr_settype(attribute, EnumCastUnderlying(PthreadMutexCompatibility::Recursive)));

#elif defined(SYSTEM_PLATFORM_WIN32)

    UnusedFunction(attribute);

    return PthreadResult::Successful;

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(attribute);

    return PthreadResult::ENomem;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
System::PthreadResult System::PthreadMutexAttributeInit(PthreadMutexattrT* attribute) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)

    return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutexattr_init(attribute));

#elif defined(SYSTEM_PLATFORM_WIN32)

    if (attribute != nullptr)
        return PthreadResult::Successful;
    else
        return PthreadResult::ENomem;

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(attribute);

    return PthreadResult::ENomem;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System::PthreadMutexInit(PthreadMutexattrT* attribute, PthreadMutexT* mutex) noexcept
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

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(attribute, mutex);

    return PthreadResult::EInval;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System::PthreadMutexAttributeDestroy(PthreadMutexattrT* attribute) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)

    return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutexattr_destroy(attribute));

#elif defined(SYSTEM_PLATFORM_WIN32)

    if (attribute != nullptr)
        return PthreadResult::Successful;
    else
        return PthreadResult::EInval;

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(attribute);

    return PthreadResult::EInval;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}
#include STSTEM_WARNING_POP

System::PthreadResult System::PthreadMutexDestroy(PthreadMutexT* mutex) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)

    return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutex_destroy(mutex));

#elif defined(SYSTEM_PLATFORM_WIN32)

    if (mutex == nullptr)
        return PthreadResult::EInval;
    else if (CloseSystemMutex(*mutex))
        return PthreadResult::Successful;
    else
        return PthreadResult::EInval;

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(mutex);

    return PthreadResult::EInval;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System::PthreadMutexLock(PthreadMutexT* mutex) noexcept
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

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(mutex);

    return PthreadResult::EInval;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System::PthreadMutexUnlock(PthreadMutexT* mutex) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)

    return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutex_unlock(mutex));

#elif defined(SYSTEM_PLATFORM_WIN32)

    if (mutex == nullptr)
        return PthreadResult::EInval;
    else if (ReleaseSystemMutex(*mutex))
        return PthreadResult::Successful;
    else
        return PthreadResult::EInval;

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(mutex);

    return PthreadResult::EInval;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System::PthreadMutexTrylock(PthreadMutexT* mutex) noexcept
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

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(mutex);

    return PthreadResult::EInval;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

bool System::IsSystemMutexValid(WindowsHandle handle) noexcept
{
    if (handle != nullptr && handle != g_InvalidHandleValue)
        return true;
    else
        return false;
}
