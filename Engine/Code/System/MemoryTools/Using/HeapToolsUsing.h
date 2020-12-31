//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:59)

#ifndef SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_USING_H
#define SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using MemoryProcessHeapEntry = PROCESS_HEAP_ENTRY;
    using MemoryProcessHeapEntryPtr = LPPROCESS_HEAP_ENTRY;
    using MemoryHeapInformationClass = HEAP_INFORMATION_CLASS;

#else  // !SYSTEM_PLATFORM_WIN32

    struct MemoryProcessHeapEntry
    {
        void* lpData;
        uint32_t cbData;
        uint8_t cbOverhead;
        uint8_t iRegionIndex;
        uint16_t wFlags;
        union
        {
            struct
            {
                WindowHandle hMem;
                uint32_t dwReserved[3];
            } Block;
            struct
            {
                uint32_t dwCommittedSize;
                uint32_t dwUnCommittedSize;
                void* lpFirstBlock;
                void* lpLastBlock;
            } Region;
        } DUMMYUNIONNAME;
    };

    using MemoryProcessHeapEntryPtr = MemoryProcessHeapEntry*;

    enum MemoryHeapInformationClass
    {
        HeapCompatibilityInformation = 0,
        HeapEnableTerminationOnCorruption = 1,
        HeapOptimizeResources = 3,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_MEMORY_TOOLS_HEAP_TOOLS_USING_H