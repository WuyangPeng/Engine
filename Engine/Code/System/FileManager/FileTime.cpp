///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/05/18 11:00)

#include "System/SystemExport.h"

#include "FileTime.h"
#include "System/Helper/EnumCast.h"
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

    if (::FileTimeToLocalFileTime(fileTime, localFileTime) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const FileTime*, FileTimePtr>(fileTime, localFileTime);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemFileTime(WindowsHandle file, FileTimePtr creationTime, FileTimePtr lastAccessTime, FileTimePtr lastWriteTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (::GetFileTime(file, creationTime, lastAccessTime, lastWriteTime) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, FileTimePtr, FileTimePtr, FileTimePtr>(file, creationTime, lastAccessTime, lastWriteTime);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::LocalFileTimeConvertFileTime(const FileTime* localFileTime, FileTimePtr fileTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (::LocalFileTimeToFileTime(localFileTime, fileTime) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<const FileTime*, FileTimePtr>(localFileTime, fileTime);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemFileTime(WindowsHandle file, const FileTime* creationTime, const FileTime* lastAccessTime, const FileTime* lastWriteTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (::SetFileTime(file, creationTime, lastAccessTime, lastWriteTime) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, const FileTime*, const FileTime*, const FileTime*>(file, creationTime, lastAccessTime, lastWriteTime);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
