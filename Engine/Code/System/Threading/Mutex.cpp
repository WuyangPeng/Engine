//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 16:21)

#include "System/SystemExport.h"

#include "Mutex.h"
#include "Flags/MutexFlags.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

System::WindowHandle System::CreateSystemMutex([[maybe_unused]] WindowSecurityAttributesPtr mutexAttributes, [[maybe_unused]] bool initialOwner, [[maybe_unused]] const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateMutex(mutexAttributes, BoolConversion(initialOwner), name);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::CreateSystemMutex([[maybe_unused]] WindowSecurityAttributesPtr mutexAttributes, [[maybe_unused]] const TChar* name, [[maybe_unused]] MutexCreate flag, [[maybe_unused]] MutexStandardAccess desiredAccess, [[maybe_unused]] MutexSpecificAccess specificAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateMutexEx(mutexAttributes, name, EnumCastUnderlying(flag), EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess));
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::CreateSystemMutex() noexcept
{
    return CreateSystemMutex(nullptr, false, nullptr);
}

bool System::CloseSystemMutex([[maybe_unused]] WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CloseHandle(handle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReleaseSystemMutex([[maybe_unused]] WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ReleaseMutex(handle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WaitForSystemMutex(WindowHandle handle) noexcept
{
    return WaitForSystemMutex(handle, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System::WaitForSystemMutex([[maybe_unused]] WindowHandle handle, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(handle, milliseconds));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemMutex([[maybe_unused]] WindowHandle handle, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemMutex([[maybe_unused]] WindowDWord count, [[maybe_unused]] const WindowHandle* handle, [[maybe_unused]] bool waitAll, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemMutex([[maybe_unused]] WindowDWord count, [[maybe_unused]] const WindowHandle* handle, [[maybe_unused]] bool waitAll, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::OpenThreadingMutex([[maybe_unused]] MutexStandardAccess desiredAccess, [[maybe_unused]] MutexSpecificAccess specificAccess, [[maybe_unused]] bool inheritHandle, [[maybe_unused]] const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::OpenMutex(EnumCastUnderlying(desiredAccess) | EnumCastUnderlying(specificAccess), BoolConversion(inheritHandle), name);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::PthreadResult System::PthreadMutexAttributeSetType([[maybe_unused]] PthreadMutexattrT* attribute) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
    return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutexattr_settype(attribute, EnumCastUnderlying(PthreadMutexCompatibility::Recursive)));
#elif defined(SYSTEM_PLATFORM_WIN32)

    return PthreadResult::Successful;

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    return PthreadResult::ENomem;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
System::PthreadResult System::PthreadMutexAttributeInit([[maybe_unused]] PthreadMutexattrT* attribute) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
    return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutexattr_init(attribute));
#elif defined(SYSTEM_PLATFORM_WIN32)
    if (attribute != nullptr)
        return PthreadResult::Successful;
    else
        return PthreadResult::ENomem;
#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    return PthreadResult::ENomem;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System::PthreadMutexInit([[maybe_unused]] PthreadMutexattrT* attribute, [[maybe_unused]] PthreadMutexT* mutex) noexcept
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
    return PthreadResult::EInval;
#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System::PthreadMutexAttributeDestroy([[maybe_unused]] PthreadMutexattrT* attribute) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
    return UnderlyingCastEnum<PthreadResultFlags>(::pthread_mutexattr_destroy(attribute));
#elif defined(SYSTEM_PLATFORM_WIN32)
    if (attribute != nullptr)
        return PthreadResult::Successful;
    else
        return PthreadResult::EInval;
#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32
    return PthreadResult::EInval;
#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}
#include STSTEM_WARNING_POP

System::PthreadResult System::PthreadMutexDestroy([[maybe_unused]] PthreadMutexT* mutex) noexcept
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
    return PthreadResult::EInval;
#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System::PthreadMutexLock([[maybe_unused]] PthreadMutexT* mutex) noexcept
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
    return PthreadResult::EInval;
#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System::PthreadMutexUnlock([[maybe_unused]] PthreadMutexT* mutex) noexcept
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
    return PthreadResult::EInval;
#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PthreadResult System::PthreadMutexTrylock([[maybe_unused]] PthreadMutexT* mutex) noexcept
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
    return PthreadResult::EInval;
#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

bool System::IsSystemMutexValid(WindowHandle handle) noexcept
{
    if (handle != nullptr && handle != g_InvalidHandleValue)
        return true;
    else
        return false;
}
