///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/04/25 19:33)

#include "System/SystemExport.h"

#if defined(SYSTEM_USING_VC80) && defined(SYSTEM_USE_SPIN_COUNT_CRITICAL_SECTION)
    // 查看评论在
    // http://msdn.microsoft.com/en-us/library/ms683476(VS.85).aspx，
    // 关于为什么这些#defines要在InitializeCriticalSectionAndSpinCount中暴露。
    #define WIN32_LEAN_AND_MEAN
    #define _WIN32_WINNT 0x0500
#endif  // CORE_TOOLS_USING_VC80 && SYSTEM_SPIN_COUNT_CRITICAL_SECTION

#include "CriticalSection.h"
#include "Flags/CriticalSectionFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/Flags/ExceptionFlags.h"

bool System::InitializeSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection, WindowsDWord spinCount, CriticalSectionInfo flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    #if (_WIN32_WINNT < 0x0600)

    auto succeed = g_True;

    __try
    {
        ::InitializeCriticalSection(criticalSection);

        SetSystemCriticalSectionSpinCount(criticalSection, spinCount);
    }
    __except (EnumCastUnderlying(Exception::ExecuteHandler))
    {
        succeed = g_False;
    }

    return succeed == g_True;

    #else  // (0x0600 <= _WIN32_WINNT)

    if (::InitializeCriticalSectionEx(criticalSection, spinCount, EnumCastUnderlying(flags)) != g_False)
        return true;
    else
        return false;

    #endif  // (_WIN32_WINNT < 0x0600)

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<ThreadingCriticalSectionPtr, WindowsDWord, CriticalSectionInfo>(criticalSection, spinCount, flags);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::InitializeSystemCriticalSectionAndSpinCount(ThreadingCriticalSectionPtr criticalSection, WindowsDWord spinCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::InitializeCriticalSectionAndSpinCount(criticalSection, spinCount) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<ThreadingCriticalSectionPtr, WindowsDWord>(criticalSection, spinCount);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::InitializeSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept
{
#if defined(SYSTEM_USE_SPIN_COUNT_CRITICAL_SECTION)
    // 在MSVS2010文档中提到，堆管理器自旋锁设定为大约4000。让我们看看如何做到4096。
    return InitializeSystemCriticalSectionAndSpinCount(criticalSection, 4096);
#else  // !SYSTEM_SPIN_COUNT_CRITICAL_SECTION
    return InitializeSystemCriticalSection(criticalSection, 0, CriticalSectionInfo::NoDebugInfo);
#endif  // SYSTEM_SPIN_COUNT_CRITICAL_SECTION
}

void System::DeleteSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::DeleteCriticalSection(criticalSection);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<ThreadingCriticalSectionPtr>(criticalSection);

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::EnterSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::EnterCriticalSection(criticalSection);

#else  // !SYSTEM_PLATFORM_WIN32

    criticalSection->lock();

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::LeaveSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::LeaveCriticalSection(criticalSection);

#else  // !SYSTEM_PLATFORM_WIN32

    criticalSection->unlock();

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::TryEnterSystemCriticalSection(ThreadingCriticalSectionPtr criticalSection) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::TryEnterCriticalSection(criticalSection) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    criticalSection->try_lock();

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::SetSystemCriticalSectionSpinCount(ThreadingCriticalSectionPtr criticalSection, WindowsDWord spinCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetCriticalSectionSpinCount(criticalSection, spinCount);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<ThreadingCriticalSectionPtr, WindowsDWord>(criticalSection, spinCount);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}
