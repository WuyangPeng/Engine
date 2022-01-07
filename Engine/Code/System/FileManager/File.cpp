///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:51)

#include "System/SystemExport.h"

#include "File.h"
#include "Flags/FileFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "System/Windows/LastPlatformError.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "System/Windows/WindowsSystem.h"

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

System::WindowsHandle System::CreateSystemFile(const String& fileName,
                                               FileHandleDesiredAccess access,
                                               FileHandleShareMode shareMode,
                                               WindowSecurityAttributesPtr securityAttributes,
                                               FileHandleCreationDisposition creation,
                                               FileHandleAttributes attributes,
                                               FileHandleOther other,
                                               FileHandleSecurity security,
                                               WindowsHandle templateFile) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::CreateFile(fileName.c_str(),
                        EnumCastUnderlying(access),
                        EnumCastUnderlying(shareMode),
                        securityAttributes,
                        EnumCastUnderlying(creation),
                        EnumCastUnderlying(attributes) | EnumCastUnderlying(other) | EnumCastUnderlying(security),
                        templateFile);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(fileName,
                   access,
                   shareMode,
                   securityAttributes,
                   creation,
                   attributes,
                   other,
                   security,
                   templateFile);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::CreateSystemFile(const String& fileName, FileHandleDesiredAccess access, FileHandleShareMode shareMode, FileHandleCreationDisposition creation) noexcept
{
    return CreateSystemFile(fileName, access, shareMode, nullptr, creation, FileHandleAttributes::Normal, FileHandleOther::SequentialScan, FileHandleSecurity::Default, nullptr);
}

System::WindowsHandle System::CreateSystemFile(const String& fileName,
                                               FileHandleDesiredAccess access,
                                               FileHandleShareMode shareMode,
                                               FileHandleCreationDisposition creation,
                                               FileHandleAttributes attributes,
                                               FileHandleOther other,
                                               FileHandleSecurity security) noexcept
{
    return CreateSystemFile(fileName, access, shareMode, nullptr, creation, attributes, other, security, nullptr);
}

bool System::CloseSystemFile(WindowsHandle file) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (::CloseHandle(file) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsFileHandleValid(WindowsHandle file) noexcept
{
    if (file != nullptr && file != g_InvalidHandleValue)
        return true;
    else
        return false;
}

bool System::GetFileLength(WindowsHandle file, uint64_t& fileSize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    WindowsDWord fileSizeHigh{ 0 };
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

    UnusedFunction(file, fileSize);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetFileLength(WindowsHandle file, WindowsLargeIntegerPtr fileSize) noexcept
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

    UnusedFunction(file, fileSize);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReadSystemFile(WindowsHandle file, WindowsVoidPtr buffer, WindowsDWord numberOfBytesToRead, WindowsDWordPtr numberOfBytesRead, WindowOverlappedPtr overlapped) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (::ReadFile(file, buffer, numberOfBytesToRead, numberOfBytesRead, overlapped) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file, buffer, numberOfBytesToRead, numberOfBytesRead, overlapped);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReadSystemFile(WindowsHandle file, WindowsVoidPtr buffer, WindowsDWord numberOfBytesToRead, WindowsDWordPtr numberOfBytesRead) noexcept
{
    return ReadSystemFile(file, buffer, numberOfBytesToRead, numberOfBytesRead, nullptr);
}

bool System::ReadSystemFile(WindowsHandle file, WindowsVoidPtr buffer, WindowsDWord numberOfBytesToRead, WindowOverlappedPtr overlapped, WindowOverlappedCompletionRoutine completionRoutine) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (::ReadFileEx(file, buffer, numberOfBytesToRead, overlapped, completionRoutine) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file, buffer, numberOfBytesToRead, overlapped, completionRoutine);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemFile(WindowsHandle file, WindowsConstVoidPtr buffer, WindowsDWord numberOfBytesToWrite, WindowsDWordPtr numberOfBytesWritten, WindowOverlappedPtr overlapped) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (::WriteFile(file, buffer, numberOfBytesToWrite, numberOfBytesWritten, overlapped) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file, buffer, numberOfBytesToWrite, numberOfBytesWritten, overlapped);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemFile(WindowsHandle file, WindowsConstVoidPtr buffer, WindowsDWord numberOfBytesToWrite, WindowsDWordPtr numberOfBytesWritten) noexcept
{
    return WriteSystemFile(file, buffer, numberOfBytesToWrite, numberOfBytesWritten, nullptr);
}

bool System::WriteSystemFile(WindowsHandle file, WindowsConstVoidPtr buffer, WindowsDWord numberOfBytesToWrite, WindowOverlappedPtr overlapped, WindowOverlappedCompletionRoutine completionRoutine) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (::WriteFileEx(file, buffer, numberOfBytesToWrite, overlapped, completionRoutine) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file, buffer, numberOfBytesToWrite, overlapped, completionRoutine);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AppendSystemFile(WindowsHandle file, WindowsConstVoidPtr buffer, WindowsDWord numberOfBytesToWrite, WindowsDWordPtr numberOfBytesWritten) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    WindowOverlapped overlapped{};

    overlapped.Offset = 0xFFFFFFFF;
    overlapped.OffsetHigh = 0xFFFFFFFF;

    return WriteSystemFile(file, buffer, numberOfBytesToWrite, numberOfBytesWritten, &overlapped);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file, buffer, numberOfBytesToWrite, numberOfBytesWritten, overlapped);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CopySystemFile(const String& existingFileName, const String& newFileName) noexcept
{
    return CopySystemFile(existingFileName, newFileName, false);
}

bool System::CopySystemFile(const String& existingFileName, const String& newFileName, bool failIfExists) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (::CopyFile(existingFileName.c_str(), newFileName.c_str(), BoolConversion(failIfExists)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(existingFileName, newFileName, failIfExists);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemFilePointer(WindowsHandle file, WindowsLong distanceToMove, WindowsLargeIntegerPtr newFilePointer, FilePointer moveMethod) noexcept
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

    UnusedFunction(file, distanceToMove, newFilePointer, moveMethod);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemFilePointer(WindowsHandle file, WindowsLargeInteger distanceToMove, WindowsLargeIntegerPtr newFilePointer, FilePointer moveMethod) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetFilePointerEx(file, distanceToMove, newFilePointer, EnumCastUnderlying(moveMethod)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file, distanceToMove, newFilePointer, moveMethod);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetEndOfSystemFile(WindowsHandle file) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::SetEndOfFile(file)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FlushSystemFileBuffers(WindowsHandle file) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::FlushFileBuffers(file)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::MoveSystemFile(const String& oldFileName, const String& newFileName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::MoveFile(oldFileName.c_str(), newFileName.c_str())) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(oldFileName, newFileName);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
