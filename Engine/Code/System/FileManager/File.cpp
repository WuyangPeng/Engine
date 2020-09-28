//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 13:00)

#include "System/SystemExport.h"

#include "File.h"
#include "Flags/FileFlags.h"
#include "System/Helper/EnumCast.h" 
#include "System/Helper/WindowsMacro.h"
#include "System/Window/Flags/PlatformErrorFlags.h"
#include "System/Window/LastPlatformError.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/WindowSystem.h"

bool System::RemoveSystemFile(const CFileString& fileName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::DeleteFile(fileName.c_str()) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    if (::remove(fileName.c_str()) == 0)
        return true;
    else
        return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::CreateSystemFile([[maybe_unused]] const String& fileName, FileHandleDesiredAccess access, [[maybe_unused]] FileHandleShareMode shareMode, [[maybe_unused]] WindowSecurityAttributesPtr securityAttributes, FileHandleCreationDisposition creation,
                                              [[maybe_unused]] FileHandleAttributes attributes, [[maybe_unused]] FileHandleOther other, [[maybe_unused]] FileHandleSecurity security, [[maybe_unused]] WindowHandle templateFile) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::CreateFile(fileName.c_str(), EnumCastUnderlying(access), EnumCastUnderlying(shareMode), securityAttributes,
                        EnumCastUnderlying(creation), EnumCastUnderlying(attributes) | EnumCastUnderlying(other) | EnumCastUnderlying(security), templateFile);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation) noexcept
{
    return CreateSystemFile(fileName, access, shareMode, nullptr, creation, FileHandleAttributes::Normal, FileHandleOther::SequentialScan, FileHandleSecurity::Default, nullptr);
}

System::WindowHandle System::CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation,
                                              FileHandleAttributes attributes, FileHandleOther other, FileHandleSecurity security) noexcept
{
    return CreateSystemFile(fileName, access, shareMode, nullptr, creation, attributes, other, security, nullptr);
}

bool System::CloseSystemFile([[maybe_unused]] WindowHandle file) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::CloseHandle(file) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsFileHandleValid(WindowHandle file) noexcept
{
    if (file != nullptr && file != g_InvalidHandleValue)
        return true;
    else
        return false;
}

bool System::GetFileLength([[maybe_unused]] WindowHandle file, [[maybe_unused]] uint64_t& fileSize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    WindowDWord fileSizeHigh{ 0 };
    auto fileSizeLow = ::GetFileSize(file, &fileSizeHigh);
    const auto lastError = GetPlatformLastError();

    if (lastError == WindowError::Success || fileSizeLow != g_InvalidFileSize)
    {
        fileSize = (static_cast<uint64_t>(fileSizeHigh) << 32ULL) + fileSizeLow;
        return true;
    }
    else
    {
        SetPlatformLastError(lastError);
        fileSize = 0;

        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetFileLength([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowLargeIntegerPtr fileSize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    #if defined(TCRE_USE_GCC)

    uint64_t size{ 0 };
    auto result = GetFileLength(file, size);

    if (result)
    {
        fileSize->QuadPart = size;
    }

    return result;

    #else  // !TCRE_USE_GCC

    if (::GetFileSizeEx(file, fileSize) != g_False)
        return true;
    else
        return false;

    #endif  // TCRE_USE_GCC
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReadSystemFile([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowVoidPtr buffer, [[maybe_unused]] WindowDWord numberOfBytesToRead, [[maybe_unused]] WindowDWordPtr numberOfBytesRead, [[maybe_unused]] WindowOverlappedPtr overlapped) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::ReadFile(file, buffer, numberOfBytesToRead, numberOfBytesRead, overlapped) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReadSystemFile(WindowHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowDWordPtr numberOfBytesRead) noexcept
{
    return ReadSystemFile(file, buffer, numberOfBytesToRead, numberOfBytesRead, nullptr);
}

bool System::ReadSystemFile([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowVoidPtr buffer, [[maybe_unused]] WindowDWord numberOfBytesToRead, [[maybe_unused]] WindowOverlappedPtr overlapped, [[maybe_unused]] WindowOverlappedCompletionRoutine completionRoutine) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::ReadFileEx(file, buffer, numberOfBytesToRead, overlapped, completionRoutine) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemFile([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowConstVoidPtr buffer, [[maybe_unused]] WindowDWord numberOfBytesToWrite, [[maybe_unused]] WindowDWordPtr numberOfBytesWritten, [[maybe_unused]] WindowOverlappedPtr overlapped) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::WriteFile(file, buffer, numberOfBytesToWrite, numberOfBytesWritten, overlapped) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemFile(WindowHandle file, WindowConstVoidPtr buffer, WindowDWord numberOfBytesToWrite, WindowDWordPtr numberOfBytesWritten) noexcept
{
    return WriteSystemFile(file, buffer, numberOfBytesToWrite, numberOfBytesWritten, nullptr);
}

bool System::WriteSystemFile([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowConstVoidPtr buffer, [[maybe_unused]] WindowDWord numberOfBytesToWrite, [[maybe_unused]] WindowOverlappedPtr overlapped, [[maybe_unused]] WindowOverlappedCompletionRoutine completionRoutine) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::WriteFileEx(file, buffer, numberOfBytesToWrite, overlapped, completionRoutine) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AppendSystemFile([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowConstVoidPtr buffer, [[maybe_unused]] WindowDWord numberOfBytesToWrite, [[maybe_unused]] WindowDWordPtr numberOfBytesWritten) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    WindowOverlapped overlapped{};

    overlapped.Offset = 0xFFFFFFFF;
    overlapped.OffsetHigh = 0xFFFFFFFF;

    return WriteSystemFile(file, buffer, numberOfBytesToWrite, numberOfBytesWritten, &overlapped);

#else  // !SYSTEM_PLATFORM_WIN32

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CopySystemFile(const String& existingFileName, const String& newFileName) noexcept
{
    return CopySystemFile(existingFileName, newFileName, false);
}

bool System::CopySystemFile([[maybe_unused]] const String& existingFileName, [[maybe_unused]] const String& newFileName, [[maybe_unused]] bool failIfExists) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::CopyFile(existingFileName.c_str(), newFileName.c_str(), BoolConversion(failIfExists)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemFilePointer([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowLong distanceToMove, [[maybe_unused]] WindowLargeIntegerPtr newFilePointer, [[maybe_unused]] FilePointer moveMethod) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    newFilePointer->QuadPart = distanceToMove;

    newFilePointer->LowPart = ::SetFilePointer(file, newFilePointer->LowPart, &newFilePointer->HighPart, EnumCastUnderlying(moveMethod));

    const auto lastError = GetPlatformLastError();

    if (lastError != WindowError::Success && newFilePointer->LowPart == g_InvalidSetFilePointer)
    {
        SetPlatformLastError(lastError);
        newFilePointer->QuadPart = -1;
        return false;
    }

    return true;

#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemFilePointer([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowLargeInteger distanceToMove, [[maybe_unused]] WindowLargeIntegerPtr newFilePointer, [[maybe_unused]] FilePointer moveMethod) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetFilePointerEx(file, distanceToMove, newFilePointer, EnumCastUnderlying(moveMethod)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetEndOfSystemFile([[maybe_unused]] WindowHandle file) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if ((::SetEndOfFile(file)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FlushSystemFileBuffers([[maybe_unused]] WindowHandle file) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if ((::FlushFileBuffers(file)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::MoveSystemFile([[maybe_unused]] const String& oldFileName, [[maybe_unused]] const String& newFileName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if ((::MoveFile(oldFileName.c_str(), newFileName.c_str())) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
