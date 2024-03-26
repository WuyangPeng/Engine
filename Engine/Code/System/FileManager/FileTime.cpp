/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 09:33)

#include "System/SystemExport.h"

#include "FileTime.h"
#include "System/FileManager/Flags/FileTimeFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

System::ComparesFileTimeReturn System::FileTimeCompare(const FileTime* lhsFileTime, const FileTime* rhsFileTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return UnderlyingCastEnum<ComparesFileTimeReturn>(::CompareFileTime(lhsFileTime, rhsFileTime));

#else  // !SYSTEM_PLATFORM_WIN32

    if (lhsFileTime->dwHighDateTime < rhsFileTime->dwHighDateTime)
        return ComparesFileTimeReturn::Earlier;
    else if (rhsFileTime->dwHighDateTime < lhsFileTime->dwHighDateTime)
        return ComparesFileTimeReturn::Later;
    else if (lhsFileTime->dwLowDateTime < rhsFileTime->dwLowDateTime)
        return ComparesFileTimeReturn::Earlier;
    else if (rhsFileTime->dwLowDateTime < lhsFileTime->dwLowDateTime)
        return ComparesFileTimeReturn::Later;
    else
        return ComparesFileTimeReturn::Equal;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FileTimeConvertLocalFileTime(const FileTime* fileTime, FileTimePtr localFileTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::FileTimeToLocalFileTime(fileTime, localFileTime) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(fileTime, localFileTime);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemFileTime(WindowsHandle file, FileTimePtr creationTime, FileTimePtr lastAccessTime, FileTimePtr lastWriteTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::GetFileTime(file, creationTime, lastAccessTime, lastWriteTime) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file, creationTime, lastAccessTime, lastWriteTime);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::LocalFileTimeConvertFileTime(const FileTime* localFileTime, FileTimePtr fileTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::LocalFileTimeToFileTime(localFileTime, fileTime) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(localFileTime, fileTime);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemFileTime(WindowsHandle file, const FileTime* creationTime, const FileTime* lastAccessTime, const FileTime* lastWriteTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::SetFileTime(file, creationTime, lastAccessTime, lastWriteTime) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file, creationTime, lastAccessTime, lastWriteTime);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
