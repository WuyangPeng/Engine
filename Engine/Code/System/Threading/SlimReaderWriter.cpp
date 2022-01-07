///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/12 19:17)

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

    if (::TryAcquireSRWLockExclusive(slimReaderWriterLock) != g_False)
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

    if (::TryAcquireSRWLockShared(slimReaderWriterLock) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(slimReaderWriterLock);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
