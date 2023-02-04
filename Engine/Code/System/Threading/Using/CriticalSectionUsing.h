///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.1 (2023/01/30 13:01)

#ifndef SYSTEM_THREADING_CRITICAL_SECTION_USING_H
#define SYSTEM_THREADING_CRITICAL_SECTION_USING_H

#include "System/Helper/Platform.h"

#include <mutex>

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ThreadingRtlCriticalSectionDebug = RTL_CRITICAL_SECTION_DEBUG;
    using ThreadingRtlCriticalSectionDebugPtr = PRTL_CRITICAL_SECTION_DEBUG;
    using ThreadingRtlResourceDebug = RTL_RESOURCE_DEBUG;
    using ThreadingRtlResourceDebugPtr = PRTL_RESOURCE_DEBUG;
    using ThreadingCriticalSection = CRITICAL_SECTION;
    using ThreadingCriticalSectionPtr = LPCRITICAL_SECTION;
    using ThreadingListEntry = LIST_ENTRY;
    using ThreadingListEntryPtr = PLIST_ENTRY;

#else  // !SYSTEM_PLATFORM_WIN32

    struct ThreadingListEntry
    {
        struct ThreadingListEntry* Flink;
        struct ThreadingListEntry* Blink;
    };
    using ThreadingListEntryPtr = ThreadingListEntry*;

    struct ThreadingRtlCriticalSectionDebug
    {
        uint16_t Type;
        uint16_t CreatorBackTraceIndex;
        struct ThreadingCriticalSection* CriticalSection;
        ThreadingListEntry ProcessLocksList;
        uint32_t EntryCount;
        uint32_t ContentionCount;
        uint32_t Flags;
        uint16_t CreatorBackTraceIndexHigh;
        uint16_t SpareWORD;
    };

    using ThreadingRtlCriticalSectionDebugPtr = ThreadingRtlCriticalSectionDebug*;
    using ThreadingRtlResourceDebug = ThreadingRtlCriticalSectionDebug;
    using ThreadingRtlResourceDebugPtr = ThreadingRtlResourceDebug*;

    using ThreadingCriticalSection = std::recursive_mutex;
    using ThreadingCriticalSectionPtr = ThreadingCriticalSection*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_CRITICAL_SECTION_USING_H