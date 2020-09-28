//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 14:34)

#ifndef SYSTEM_THREADING_OVERLAPPED_TOOLS_USING_H
#define SYSTEM_THREADING_OVERLAPPED_TOOLS_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using WindowOverlapped = OVERLAPPED;
    using WindowOverlappedPtr = LPOVERLAPPED;
    using WindowOverlappedCompletionRoutine = LPOVERLAPPED_COMPLETION_ROUTINE;
    using WindowOverlappedEntry = OVERLAPPED_ENTRY;
    using WindowOverlappedEntryPtr = LPOVERLAPPED_ENTRY;

#else  // !SYSTEM_PLATFORM_WIN32

    struct WindowOverlapped
    {
        uint64_t Internal;
        uint64_t InternalHigh;
        union
        {
            struct
            {
                uint32_t Offset;
                uint32_t OffsetHigh;
            } DUMMYSTRUCTNAME;
            void* Pointer;
        } DUMMYUNIONNAME;

        WindowHandle hEvent;
    };
    using WindowOverlappedPtr = WindowOverlapped*;

    using WindowOverlappedCompletionRoutine = void (*)(uint32_t errorCode, uint32_t numberOfBytesTransfered, void* overlapped);

    struct WindowOverlappedEntry
    {
        size_t lpCompletionKey;
        WindowOverlappedPtr lpOverlapped;
        size_t Internal;
        uint32_t dwNumberOfBytesTransferred;
    };
    using WindowOverlappedEntryPtr = WindowOverlappedEntry*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_OVERLAPPED_TOOLS_USING_H