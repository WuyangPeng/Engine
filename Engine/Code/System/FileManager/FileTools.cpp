///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/29 19:30)

#include "System/SystemExport.h"

#include "FileTools.h"
#include "Using/FileUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "System/Windows/LastPlatformError.h"

bool System::CreateFileDirectory(const String& pathName, WindowSecurityAttributesPtr securityAttributes) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (::CreateDirectory(pathName.c_str(), securityAttributes) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pathName, securityAttributes);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetDiskFreeSpaceWithRoot(const TChar* rootPathName,
                                      WindowsDWordPtr sectorsPerCluster,
                                      WindowsDWordPtr bytesPerSector,
                                      WindowsDWordPtr numberOfFreeClusters,
                                      WindowsDWordPtr totalNumberOfClusters) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (::GetDiskFreeSpace(rootPathName, sectorsPerCluster, bytesPerSector, numberOfFreeClusters, totalNumberOfClusters) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(rootPathName, sectorsPerCluster, bytesPerSector, numberOfFreeClusters, totalNumberOfClusters);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetDiskFreeSpaceWithRoot(const TChar* directoryName,
                                      WindowsULargeIntegerPtr freeBytesAvailableToCaller,
                                      WindowsULargeIntegerPtr totalNumberOfBytes,
                                      WindowsULargeIntegerPtr totalNumberOfFreeBytes) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (::GetDiskFreeSpaceEx(directoryName, freeBytesAvailableToCaller, totalNumberOfBytes, totalNumberOfFreeBytes) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(directoryName, freeBytesAvailableToCaller, totalNumberOfBytes, totalNumberOfFreeBytes);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::RemoveSystemDirectory(const TChar* pathName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (::RemoveDirectory(pathName) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pathName);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
