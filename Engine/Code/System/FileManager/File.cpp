/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 09:30)

#include "System/SystemExport.h"

#include "File.h"
#include "Flags/FileFlags.h"
#include "Using/FileUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "System/Windows/LastPlatformError.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "System/Windows/WindowsSystem.h"

#include <gsl/util>

bool System::RemoveSystemFile(const CFileString& fileName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::DeleteFile(fileName.c_str()) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    return ::remove(fileName.c_str()) == 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::CreateSystemFile(const String& fileName,
                                               FileHandleDesiredAccess access,
                                               FileHandleShareMode shareMode,
                                               WindowSecurityAttributesPtr securityAttributes,
                                               FileHandleCreationDisposition creation,
                                               FileHandleAttribute attributes,
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
    return CreateSystemFile(fileName, access, shareMode, nullptr, creation, FileHandleAttribute::Normal, FileHandleOther::SequentialScan, FileHandleSecurity::Default, nullptr);
}

System::WindowsHandle System::CreateSystemFile(const String& fileName,
                                               FileHandleDesiredAccess access,
                                               FileHandleShareMode shareMode,
                                               FileHandleCreationDisposition creation,
                                               FileHandleAttribute attributes,
                                               FileHandleOther other,
                                               FileHandleSecurity security) noexcept
{
    return CreateSystemFile(fileName, access, shareMode, nullptr, creation, attributes, other, security, nullptr);
}

bool System::CloseSystemFile(WindowsHandle file) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::CloseHandle(file) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsFileHandleValid(WindowsHandle file) noexcept
{
    return file != nullptr && file != invalidHandleValue;
}

bool System::GetFileLength(WindowsHandle file, uint64_t& fileSize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    WindowsDWord fileSizeHigh{ 0 };
    const auto fileSizeLow = ::GetFileSize(file, &fileSizeHigh);

    if (const auto lastError = GetPlatformLastError();
        lastError == WindowError::Success || fileSizeLow != gInvalidFileSize)
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
    const auto result = GetFileLength(file, size);

    if (result)
    {
        fileSize->QuadPart = size;
    }

    return result;

    #else  // !TCRE_USE_GCC

    return ::GetFileSizeEx(file, fileSize) != gFalse;

    #endif  // TCRE_USE_GCC

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file, fileSize);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReadSystemFile(WindowsHandle file, WindowsVoidPtr buffer, WindowsDWord numberOfBytesToRead, WindowsDWordPtr numberOfBytesRead, WindowOverlappedPtr overlapped) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::ReadFile(file, buffer, numberOfBytesToRead, numberOfBytesRead, overlapped) != gFalse;

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

    return ::ReadFileEx(file, buffer, numberOfBytesToRead, overlapped, completionRoutine) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file, buffer, numberOfBytesToRead, overlapped, completionRoutine);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WriteSystemFile(WindowsHandle file, WindowsConstVoidPtr buffer, WindowsDWord numberOfBytesToWrite, WindowsDWordPtr numberOfBytesWritten, WindowOverlappedPtr overlapped) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::WriteFile(file, buffer, numberOfBytesToWrite, numberOfBytesWritten, overlapped) != gFalse;

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

    return ::WriteFileEx(file, buffer, numberOfBytesToWrite, overlapped, completionRoutine) != gFalse;

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

    UnusedFunction(file, buffer, numberOfBytesToWrite, numberOfBytesWritten);

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

    return ::CopyFile(existingFileName.c_str(), newFileName.c_str(), BoolConversion(failIfExists)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(existingFileName, newFileName, failIfExists);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemFilePointer(WindowsHandle file, WindowsLong distanceToMove, WindowsLargeIntegerPtr newFilePointer, FilePointer moveMethod) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    newFilePointer->QuadPart = distanceToMove;
    newFilePointer->LowPart = ::SetFilePointer(file, gsl::narrow_cast<WindowsLong>(newFilePointer->LowPart), &newFilePointer->HighPart, EnumCastUnderlying(moveMethod));

    if (const auto lastError = GetPlatformLastError();
        lastError != WindowError::Success && newFilePointer->LowPart == gInvalidSetFilePointer)
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

    return ::SetFilePointerEx(file, distanceToMove, newFilePointer, EnumCastUnderlying(moveMethod)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file, distanceToMove, newFilePointer, moveMethod);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetEndOfSystemFile(WindowsHandle file) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetEndOfFile(file) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FlushSystemFileBuffers(WindowsHandle file) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::FlushFileBuffers(file) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::MoveSystemFile(const String& oldFileName, const String& newFileName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::MoveFile(oldFileName.c_str(), newFileName.c_str()) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(oldFileName, newFileName);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
