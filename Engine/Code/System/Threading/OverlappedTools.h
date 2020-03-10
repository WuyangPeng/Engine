// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:13)

#ifndef SYSTEM_THREADING_OVERLAPPED_TOOLS_H
#define SYSTEM_THREADING_OVERLAPPED_TOOLS_H

#include "System/SystemDll.h" 

#include "Using/OverlappedToolsUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// ÷ÿµ˛IO

	bool SYSTEM_DEFAULT_DECLARE GetSystemOverlappedResult(WindowHandle file, WindowOverlappedPtr overlapped, WindowDWordPtr numberOfBytesTransferred, bool wait) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemIoCompletionPort(WindowHandle fileHandle, WindowHandle existingCompletionPort, WindowPtrULong completionKey, WindowDWord numberOfConcurrentThreads) noexcept;
	bool SYSTEM_DEFAULT_DECLARE CloseIoCompletionPort(WindowHandle handle) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetSystemQueuedCompletionStatus(WindowHandle completionPort, WindowDWordPtr numberOfBytesTransferred, WindowPtrULongPtr completionKey,
																WindowOverlappedPtr* overlapped, WindowDWord milliseconds) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetSystemQueuedCompletionStatus(WindowHandle completionPort, WindowOverlappedEntryPtr completionPortEntries, WindowULong count,
																WindowULongPtr numEntriesRemoved, WindowDWord milliseconds, bool alertable) noexcept;

	bool SYSTEM_DEFAULT_DECLARE PostSystemQueuedCompletionStatus(WindowHandle completionPort, WindowDWord numberOfBytesTransferred, WindowPtrULong completionKey, WindowOverlappedPtr overlapped) noexcept;

	bool SYSTEM_DEFAULT_DECLARE SystemDeviceIOControl(WindowHandle device, WindowDWord ioControlCode, WindowVoidPtr inBuffer, WindowDWord inBufferSize,
													  WindowVoidPtr outBuffer, WindowDWord outBufferSize, WindowDWordPtr bytesReturned, WindowOverlappedPtr overlapped) noexcept;

	bool SYSTEM_DEFAULT_DECLARE CancelSystemIO(WindowHandle file, WindowOverlappedPtr overlapped) noexcept;

	bool SYSTEM_DEFAULT_DECLARE CancelSystemIO(WindowHandle file) noexcept;

	bool SYSTEM_DEFAULT_DECLARE CancelSystemSynchronousIO(WindowHandle thread) noexcept;
}

#endif // SYSTEM_THREADING_OVERLAPPED_TOOLS_H