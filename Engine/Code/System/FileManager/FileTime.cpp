//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 13:00)

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

bool System::FileTimeConvertLocalFileTime([[maybe_unused]] const FileTime* fileTime, [[maybe_unused]] FileTimePtr localFileTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::FileTimeToLocalFileTime(fileTime, localFileTime) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemFileTime([[maybe_unused]] WindowHandle file, [[maybe_unused]] FileTimePtr creationTime, [[maybe_unused]] FileTimePtr lastAccessTime, [[maybe_unused]] FileTimePtr lastWriteTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::GetFileTime(file, creationTime, lastAccessTime, lastWriteTime) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::LocalFileTimeConvertFileTime([[maybe_unused]] const FileTime* localFileTime, [[maybe_unused]] FileTimePtr fileTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::LocalFileTimeToFileTime(localFileTime, fileTime) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemFileTime([[maybe_unused]] WindowHandle file, [[maybe_unused]] const FileTime* creationTime, [[maybe_unused]] const FileTime* lastAccessTime, [[maybe_unused]] const FileTime* lastWriteTime) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::SetFileTime(file, creationTime, lastAccessTime, lastWriteTime) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
