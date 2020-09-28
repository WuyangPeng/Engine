//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 16:33)

#include "System/SystemExport.h"

#include "OverlappedTools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

bool System::GetSystemOverlappedResult([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowOverlappedPtr overlapped, [[maybe_unused]] WindowDWordPtr numberOfBytesTransferred, [[maybe_unused]] bool wait) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetOverlappedResult(file, overlapped, numberOfBytesTransferred, BoolConversion(wait)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::CreateSystemIoCompletionPort([[maybe_unused]] WindowHandle fileHandle, [[maybe_unused]] WindowHandle existingCompletionPort, [[maybe_unused]] WindowPtrULong completionKey, [[maybe_unused]] WindowDWord numberOfConcurrentThreads) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateIoCompletionPort(fileHandle, existingCompletionPort, completionKey, numberOfConcurrentThreads);
#else  // !SYSTEM_PLATFORM_WIN32 
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemQueuedCompletionStatus([[maybe_unused]] WindowHandle completionPort, [[maybe_unused]] WindowDWordPtr numberOfBytesTransferred, [[maybe_unused]] WindowPtrULongPtr completionKey, [[maybe_unused]] WindowOverlappedPtr* overlapped, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetQueuedCompletionStatus(completionPort, numberOfBytesTransferred, completionKey, overlapped, milliseconds) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemQueuedCompletionStatus([[maybe_unused]] WindowHandle completionPort, [[maybe_unused]] WindowOverlappedEntryPtr completionPortEntries, [[maybe_unused]] WindowULong count,
                                             [[maybe_unused]] WindowULongPtr numEntriesRemoved, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetQueuedCompletionStatusEx(completionPort, completionPortEntries, count, numEntriesRemoved, milliseconds, BoolConversion(alertable)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::PostSystemQueuedCompletionStatus([[maybe_unused]] WindowHandle completionPort, [[maybe_unused]] WindowDWord numberOfBytesTransferred, [[maybe_unused]] WindowPtrULong completionKey, [[maybe_unused]] WindowOverlappedPtr overlapped) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::PostQueuedCompletionStatus(completionPort, numberOfBytesTransferred, completionKey, overlapped) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemDeviceIOControl([[maybe_unused]] WindowHandle device, [[maybe_unused]] WindowDWord ioControlCode, [[maybe_unused]] WindowVoidPtr inBuffer, [[maybe_unused]] WindowDWord inBufferSize,
                                   [[maybe_unused]] WindowVoidPtr outBuffer, [[maybe_unused]] WindowDWord outBufferSize, [[maybe_unused]] WindowDWordPtr bytesReturned, [[maybe_unused]] WindowOverlappedPtr overlapped) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::DeviceIoControl(device, ioControlCode, inBuffer, inBufferSize, outBuffer, outBufferSize, bytesReturned, overlapped) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CancelSystemIO([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowOverlappedPtr overlapped) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CancelIoEx(file, overlapped) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CancelSystemIO([[maybe_unused]] WindowHandle file) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CancelIo(file) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CancelSystemSynchronousIO([[maybe_unused]] WindowHandle thread) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CancelSynchronousIo(thread) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseIoCompletionPort([[maybe_unused]] WindowHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CloseHandle(handle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
