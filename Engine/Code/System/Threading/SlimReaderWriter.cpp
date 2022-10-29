///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/21 0:15)

#include "System/SystemExport.h"

#include "SlimReaderWriter.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/WindowsMacro.h"

void System::InitializeSlimReaderWriterLock(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::InitializeSRWLock(slimReaderWriterLock);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(slimReaderWriterLock);

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::ReleaseSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26110)

    ::ReleaseSRWLockExclusive(slimReaderWriterLock);

    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(slimReaderWriterLock);

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::ReleaseSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::ReleaseSRWLockShared(slimReaderWriterLock);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(slimReaderWriterLock);

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::AcquireSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::AcquireSRWLockExclusive(slimReaderWriterLock);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(slimReaderWriterLock);

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::AcquireSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::AcquireSRWLockShared(slimReaderWriterLock);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(slimReaderWriterLock);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::TryAcquireSlimReaderWriterLockExclusive(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::TryAcquireSRWLockExclusive(slimReaderWriterLock) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(slimReaderWriterLock);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::TryAcquireSlimReaderWriterLockShared(SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::TryAcquireSRWLockShared(slimReaderWriterLock) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(slimReaderWriterLock);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
