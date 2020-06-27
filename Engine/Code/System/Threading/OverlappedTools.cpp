// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 12:59)	

#include "System/SystemExport.h"

#include "OverlappedTools.h"    
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

bool System
	::GetSystemOverlappedResult(WindowHandle file, WindowOverlappedPtr overlapped, WindowDWordPtr numberOfBytesTransferred, bool wait) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetOverlappedResult(file, overlapped, numberOfBytesTransferred, BoolConversion(wait)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(overlapped);
	SYSTEM_UNUSED_ARG(numberOfBytesTransferred);
	SYSTEM_UNUSED_ARG(wait);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::CreateSystemIoCompletionPort(WindowHandle fileHandle, WindowHandle existingCompletionPort, WindowPtrULong completionKey, WindowDWord numberOfConcurrentThreads) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::CreateIoCompletionPort(fileHandle, existingCompletionPort, completionKey, numberOfConcurrentThreads);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileHandle);
	SYSTEM_UNUSED_ARG(existingCompletionPort);
	SYSTEM_UNUSED_ARG(completionKey);
	SYSTEM_UNUSED_ARG(numberOfConcurrentThreads);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemQueuedCompletionStatus(WindowHandle completionPort, WindowDWordPtr numberOfBytesTransferred, WindowPtrULongPtr completionKey, WindowOverlappedPtr* overlapped, WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetQueuedCompletionStatus(completionPort, numberOfBytesTransferred, completionKey, overlapped, milliseconds) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(completionPort);
	SYSTEM_UNUSED_ARG(numberOfBytesTransferred);
	SYSTEM_UNUSED_ARG(completionKey);
	SYSTEM_UNUSED_ARG(overlapped);
	SYSTEM_UNUSED_ARG(milliseconds);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemQueuedCompletionStatus(WindowHandle completionPort, WindowOverlappedEntryPtr completionPortEntries, WindowULong count,
									  WindowULongPtr numEntriesRemoved, WindowDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetQueuedCompletionStatusEx(completionPort, completionPortEntries, count, numEntriesRemoved, milliseconds, BoolConversion(alertable)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(completionPort);
	SYSTEM_UNUSED_ARG(completionPortEntries);
	SYSTEM_UNUSED_ARG(count);
	SYSTEM_UNUSED_ARG(numEntriesRemoved);
	SYSTEM_UNUSED_ARG(milliseconds);
	SYSTEM_UNUSED_ARG(alertable);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::PostSystemQueuedCompletionStatus(WindowHandle completionPort, WindowDWord numberOfBytesTransferred, WindowPtrULong completionKey, WindowOverlappedPtr overlapped) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::PostQueuedCompletionStatus(completionPort, numberOfBytesTransferred, completionKey, overlapped) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(completionPort);
	SYSTEM_UNUSED_ARG(numberOfBytesTransferred);
	SYSTEM_UNUSED_ARG(completionKey);
	SYSTEM_UNUSED_ARG(overlapped);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SystemDeviceIOControl(WindowHandle device, WindowDWord ioControlCode, WindowVoidPtr inBuffer, WindowDWord inBufferSize,
							WindowVoidPtr outBuffer, WindowDWord outBufferSize, WindowDWordPtr bytesReturned, WindowOverlappedPtr overlapped) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::DeviceIoControl(device, ioControlCode, inBuffer, inBufferSize, outBuffer, outBufferSize, bytesReturned, overlapped) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(device);
	SYSTEM_UNUSED_ARG(ioControlCode);
	SYSTEM_UNUSED_ARG(inBuffer);
	SYSTEM_UNUSED_ARG(inBufferSize);
	SYSTEM_UNUSED_ARG(outBuffer);
	SYSTEM_UNUSED_ARG(outBufferSize);
	SYSTEM_UNUSED_ARG(bytesReturned);
	SYSTEM_UNUSED_ARG(overlapped);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CancelSystemIO(WindowHandle file, WindowOverlappedPtr overlapped) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CancelIoEx(file, overlapped) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(overlapped);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CancelSystemIO(WindowHandle file) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CancelIo(file) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CancelSystemSynchronousIO(WindowHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CancelSynchronousIo(thread) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(thread);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CloseIoCompletionPort(WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CloseHandle(handle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(hThread);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
