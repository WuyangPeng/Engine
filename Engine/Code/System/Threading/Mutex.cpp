/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 16:19)

#include "System/SystemExport.h"

#include "Mutex.h"
#include "Flags/MutexFlags.h"
#include "Flags/SemaphoreFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

#include <gsl/util>

System::WindowsHandle
    System::CreateSystemMutex(WindowSecurityAttributesPtr mutexAttributes, bool initialOwner, const TChar* name) noexcept
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

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForSingleObject(handle, milliseconds)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, milliseconds);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemMutex(WindowsHandle handle, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForSingleObjectEx(handle, milliseconds, BoolConversion(alertable))));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemMutex(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForMultipleObjectsEx(count, handle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable))));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(count, handle, waitAll, milliseconds, alertable);

    return MutexWaitReturn::Failed;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForSystemMutex(WindowsDWord count, const WindowsHandle* handle, bool waitAll, WindowsDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<MutexWaitReturn>(gsl::narrow_cast<int>(::WaitForMultipleObjects(count, handle, BoolConversion(waitAll), milliseconds)));

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

System::PThreadResult System::PThreadMutexAttributeSetType(PThreadMutexAttrT* attribute) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)

    return UnderlyingCastEnum<PThreadResult>(::pthread_mutexattr_settype(attribute, EnumCastUnderlying(PThreadMutexCompatibility::Recursive)));

#elif defined(SYSTEM_PLATFORM_WIN32)

    UnusedFunction(attribute);

    return PThreadResult::Successful;

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(attribute);

    return PThreadResult::ENomem;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)

System::PThreadResult System::PThreadMutexAttributeInit(PThreadMutexAttrT* attribute) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)

    return UnderlyingCastEnum<PThreadResult>(::pthread_mutexattr_init(attribute));

#elif defined(SYSTEM_PLATFORM_WIN32)

    if (attribute != nullptr)
        return PThreadResult::Successful;
    else
        return PThreadResult::ENomem;

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(attribute);

    return PThreadResult::ENomem;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PThreadResult System::PThreadMutexInit(PThreadMutexAttrT* attribute, PThreadMutexT* mutex) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)

    return UnderlyingCastEnum<PThreadResult>(::pthread_mutex_init(mutex, attribute));

#elif defined(SYSTEM_PLATFORM_WIN32)

    if (attribute == nullptr || mutex == nullptr)
    {
        return PThreadResult::EInval;
    }
    else
    {
        *mutex = CreateSystemMutex();
        if (*mutex != nullptr)
            return PThreadResult::Successful;
        else
            return PThreadResult::EInval;
    }

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(attribute, mutex);

    return PThreadResult::EInval;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PThreadResult System::PThreadMutexAttributeDestroy(PThreadMutexAttrT* attribute) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)

    return UnderlyingCastEnum<PThreadResult>(::pthread_mutexattr_destroy(attribute));

#elif defined(SYSTEM_PLATFORM_WIN32)

    if (attribute != nullptr)
        return PThreadResult::Successful;
    else
        return PThreadResult::EInval;

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(attribute);

    return PThreadResult::EInval;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

#include SYSTEM_WARNING_POP

System::PThreadResult System::PThreadMutexDestroy(PThreadMutexT* mutex) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)

    return UnderlyingCastEnum<PThreadResult>(::pthread_mutex_destroy(mutex));

#elif defined(SYSTEM_PLATFORM_WIN32)

    if (mutex == nullptr)
        return PThreadResult::EInval;
    else if (CloseSystemMutex(*mutex))
        return PThreadResult::Successful;
    else
        return PThreadResult::EInval;

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(mutex);

    return PThreadResult::EInval;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PThreadResult System::PThreadMutexLock(PThreadMutexT* mutex) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)

    return UnderlyingCastEnum<PThreadResult>(::pthread_mutex_lock(mutex));

#elif defined(SYSTEM_PLATFORM_WIN32)

    if (mutex == nullptr)
        return PThreadResult::EInval;
    else if (WaitForSystemMutex(*mutex))
        return PThreadResult::Successful;
    else
        return PThreadResult::EInval;

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(mutex);

    return PThreadResult::EInval;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PThreadResult System::PThreadMutexUnlock(PThreadMutexT* mutex) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)

    return UnderlyingCastEnum<PThreadResult>(::pthread_mutex_unlock(mutex));

#elif defined(SYSTEM_PLATFORM_WIN32)

    if (mutex == nullptr)
        return PThreadResult::EInval;
    else if (ReleaseSystemMutex(*mutex))
        return PThreadResult::Successful;
    else
        return PThreadResult::EInval;

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(mutex);

    return PThreadResult::EInval;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

System::PThreadResult System::PThreadMutexTryLock(PThreadMutexT* mutex) noexcept
{
#if defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)

    return UnderlyingCastEnum<PThreadResult>(::pthread_mutex_trylock(mutex));

#elif defined(SYSTEM_PLATFORM_WIN32)

    if (mutex == nullptr)
        return PThreadResult::EInval;
    else if (WaitForSystemMutex(*mutex, EnumCastUnderlying(MutexWait::Ignore)) == MutexWaitReturn::Object0)
        return PThreadResult::Successful;
    else
        return PThreadResult::EInval;

#else  // !SYSTEM_PLATFORM_LINUX && !SYSTEM_PLATFORM_MACOS && !SYSTEM_PLATFORM_WIN32

    UnusedFunction(mutex);

    return PThreadResult::EInval;

#endif  // defined(SYSTEM_PLATFORM_LINUX) || defined(SYSTEM_PLATFORM_MACOS)
}

bool System::IsSystemMutexValid(WindowsHandle handle) noexcept
{
    if (handle != nullptr && handle != invalidHandleValue)
        return true;
    else
        return false;
}
