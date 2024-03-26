/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 09:34)

#include "System/SystemExport.h"

#include "FileTools.h"
#include "Using/FileUsing.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

#include <filesystem>

namespace System
{
    void RecursionDeleteFileDirectory(const std::filesystem::directory_entry& element)
    {
        if (element.is_directory())
        {
            RecursionDeleteFileDirectory(element.path());
            std::filesystem::remove(element.path());
        }
        else if (element.is_regular_file())
        {
            std::filesystem::remove(element.path());
        }
    }
}

void System::RecursionDeleteFileDirectory(const String& pathName)
{
    for (const auto& element : std::filesystem::directory_iterator(pathName))
    {
        RecursionDeleteFileDirectory(element);
    }
}

void System::CreateFileDirectory(const String& pathName) noexcept
{
    const auto result = CreateFileDirectory(pathName, nullptr);

    UnusedFunction(result);
}

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

bool System::DeleteFileDirectory(const TChar* pathName) noexcept
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

bool System::GetDiskFreeSpaceWithRoot(const TChar* rootPathName,
                                      WindowsDWordPtr sectorsPerCluster,
                                      WindowsDWordPtr bytesPerSector,
                                      WindowsDWordPtr numberOfFreeClusters,
                                      WindowsDWordPtr totalNumberOfClusters) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    return ::GetDiskFreeSpace(rootPathName, sectorsPerCluster, bytesPerSector, numberOfFreeClusters, totalNumberOfClusters) != gFalse;

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

    return ::GetDiskFreeSpaceEx(directoryName, freeBytesAvailableToCaller, totalNumberOfBytes, totalNumberOfFreeBytes) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(directoryName, freeBytesAvailableToCaller, totalNumberOfBytes, totalNumberOfFreeBytes);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
