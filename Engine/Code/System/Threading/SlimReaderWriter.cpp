//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 17:34)

#include "System/SystemExport.h"

#include "SlimReaderWriter.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/WindowsMacro.h"

void System::InitializeSlimReaderWriterLock([[maybe_unused]] SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::InitializeSRWLock(slimReaderWriterLock);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::ReleaseSlimReaderWriterLockExclusive([[maybe_unused]] SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26110)
    ::ReleaseSRWLockExclusive(slimReaderWriterLock);
    #include STSTEM_WARNING_POP

#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::ReleaseSlimReaderWriterLockShared([[maybe_unused]] SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::ReleaseSRWLockShared(slimReaderWriterLock);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::AcquireSlimReaderWriterLockExclusive([[maybe_unused]] SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::AcquireSRWLockExclusive(slimReaderWriterLock);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::AcquireSlimReaderWriterLockShared([[maybe_unused]] SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::AcquireSRWLockShared(slimReaderWriterLock);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::TryAcquireSlimReaderWriterLockExclusive([[maybe_unused]] SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::TryAcquireSRWLockExclusive(slimReaderWriterLock) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::TryAcquireSlimReaderWriterLockShared([[maybe_unused]] SlimReaderWriterLockPtr slimReaderWriterLock) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::TryAcquireSRWLockShared(slimReaderWriterLock) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
