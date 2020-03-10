// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:10)

#ifndef SYSTEM_THREADING_OVERLAPPED_TOOLS_FWD_H
#define SYSTEM_THREADING_OVERLAPPED_TOOLS_FWD_H 

#include "System/Threading/Using/OverlappedToolsUsing.h"

namespace System
{
	bool GetSystemOverlappedResult(WindowHandle file, WindowOverlappedPtr overlapped, WindowDWordPtr numberOfBytesTransferred, bool wait) noexcept;
	WindowHandle CreateSystemIoCompletionPort(WindowHandle fileHandle, WindowHandle existingCompletionPort, WindowPtrULong completionKey, WindowDWord numberOfConcurrentThreads) noexcept;
	bool CloseIoCompletionPort(WindowHandle handle);

	bool GetSystemQueuedCompletionStatus(WindowHandle completionPort, WindowDWordPtr numberOfBytesTransferred, WindowPtrULongPtr completionKey,
										 WindowOverlappedPtr* overlapped, WindowDWord milliseconds) noexcept;

	bool GetSystemQueuedCompletionStatus(WindowHandle completionPort, WindowOverlappedEntryPtr completionPortEntries, WindowULong count,
										 WindowULongPtr numEntriesRemoved, WindowDWord milliseconds, bool alertable) noexcept;

	bool PostSystemQueuedCompletionStatus(WindowHandle completionPort, WindowDWord numberOfBytesTransferred, WindowPtrULong completionKey, WindowOverlappedPtr overlapped) noexcept;

	bool SystemDeviceIOControl(WindowHandle device, WindowDWord ioControlCode, WindowVoidPtr inBuffer, WindowDWord inBufferSize,
							   WindowVoidPtr outBuffer, WindowDWord outBufferSize, WindowDWordPtr bytesReturned, WindowOverlappedPtr overlappedd) noexcept;

	bool CancelSystemIO(WindowHandle file, WindowOverlappedPtr overlapped) noexcept;

	bool CancelSystemIO(WindowHandle file) noexcept;

	bool CancelSystemSynchronousIO(WindowHandle thread) noexcept;
}

#endif // SYSTEM_THREADING_OVERLAPPED_TOOLS_FWD_H