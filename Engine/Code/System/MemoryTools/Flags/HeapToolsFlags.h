///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 16:38)

#ifndef SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_FLAGS_H
#define SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class HeapCreate
    {
        Default = 0,
        NoSerialize = HEAP_NO_SERIALIZE,

        // 程序捕获异常，这个标志被忽略。
        GenerateExceptions = HEAP_GENERATE_EXCEPTIONS,

        CreateEnableExecute = HEAP_CREATE_ENABLE_EXECUTE,
        ZeroMemory = HEAP_ZERO_MEMORY,
        ReAllocInPlaceOnly = HEAP_REALLOC_IN_PLACE_ONLY,

        GrowAble = HEAP_GROWABLE,
        TailCheckingEnabled = HEAP_TAIL_CHECKING_ENABLED,
        FreeCheckingEnabled = HEAP_FREE_CHECKING_ENABLED,
        DisableCoalesceOnFree = HEAP_DISABLE_COALESCE_ON_FREE,
        CreateAlign16 = HEAP_CREATE_ALIGN_16,
        CreateEnableTracing = HEAP_CREATE_ENABLE_TRACING,
        MaximumTag = HEAP_MAXIMUM_TAG,
        PseudoTagFlag = HEAP_PSEUDO_TAG_FLAG,
        TagShift = HEAP_TAG_SHIFT,
        CreateSegmentHeap = HEAP_CREATE_SEGMENT_HEAP,
        CreateHardened = HEAP_CREATE_HARDENED,
    };

    enum class ProcessHeap
    {
        Region = PROCESS_HEAP_REGION,
        UncommittedRange = PROCESS_HEAP_UNCOMMITTED_RANGE,
        EntryBusy = PROCESS_HEAP_ENTRY_BUSY,
        HeapSegAlloc = PROCESS_HEAP_SEG_ALLOC,
        EntryMoveable = PROCESS_HEAP_ENTRY_MOVEABLE,
        EntryDdeShare = PROCESS_HEAP_ENTRY_DDESHARE,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class HeapCreate
    {
        Default = 0,
        NoSerialize = 0x00000001,

        GenerateExceptions = 0x00000004,
        ZeroMemory = 0x00000008,
        ReAllocInPlaceOnly = 0x00000010,

        GrowAble = 0x00000002,
        TailCheckingEnabled = 0x00000020,
        FreeCheckingEnabled = 0x00000040,
        DisableCoalesceOnFree = 0x00000080,
        CreateAlign16 = 0x00010000,
        CreateEnableTracing = 0x00020000,
        CreateEnableExecute = 0x00040000,
        MaximumTag = 0x0FFF,
        PseudoTagFlag = 0x8000,
        TagShift = 18,
        CreateSegmentHeap = 0x00000100,
        CreateHardened = 0x00000200,
    };

    enum class ProcessHeap
    {
        Region = 0x0001,
        UncommittedRange = 0x0002,
        EntryBusy = 0x0004,
        HeapSegAlloc = 0x0008,
        EntryMoveable = 0x0010,
        EntryDdeShare = 0x0020,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_FLAGS_H
