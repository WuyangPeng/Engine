//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 15:25)

#ifndef SYSTEM_THREADING_OVERLAPPED_TOOLS_H
#define SYSTEM_THREADING_OVERLAPPED_TOOLS_H

#include "System/SystemDll.h"

#include "Using/OverlappedToolsUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 重叠IO

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemOverlappedResult(WindowHandle file, WindowOverlappedPtr overlapped, WindowDWordPtr numberOfBytesTransferred, bool wait) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemIoCompletionPort(WindowHandle fileHandle, WindowHandle existingCompletionPort, WindowPtrULong completionKey, WindowDWord numberOfConcurrentThreads) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CloseIoCompletionPort(WindowHandle handle) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemQueuedCompletionStatus(WindowHandle completionPort, WindowDWordPtr numberOfBytesTransferred, WindowPtrULongPtr completionKey,
                                                                              WindowOverlappedPtr* overlapped, WindowDWord milliseconds) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemQueuedCompletionStatus(WindowHandle completionPort, WindowOverlappedEntryPtr completionPortEntries, WindowULong count,
                                                                              WindowULongPtr numEntriesRemoved, WindowDWord milliseconds, bool alertable) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE PostSystemQueuedCompletionStatus(WindowHandle completionPort, WindowDWord numberOfBytesTransferred, WindowPtrULong completionKey, WindowOverlappedPtr overlapped) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SystemDeviceIOControl(WindowHandle device, WindowDWord ioControlCode, WindowVoidPtr inBuffer, WindowDWord inBufferSize,
                                                                    WindowVoidPtr outBuffer, WindowDWord outBufferSize, WindowDWordPtr bytesReturned, WindowOverlappedPtr overlapped) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CancelSystemIO(WindowHandle file, WindowOverlappedPtr overlapped) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CancelSystemIO(WindowHandle file) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CancelSystemSynchronousIO(WindowHandle thread) noexcept;
}

#endif  // SYSTEM_THREADING_OVERLAPPED_TOOLS_H