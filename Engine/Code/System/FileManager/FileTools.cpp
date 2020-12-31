//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 13:00)

#include "System/SystemExport.h"

#include "FileTools.h"
#include "Using/FileUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/Flags/PlatformErrorFlags.h"
#include "System/Window/LastPlatformError.h"

bool System::CreateFileDirectory([[maybe_unused]] const String& pathName, [[maybe_unused]] WindowSecurityAttributesPtr securityAttributes) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::CreateDirectory(pathName.c_str(), securityAttributes) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DefineDosDeviceName([[maybe_unused]] DefineDosDeviceControllable flags, [[maybe_unused]] const String& deviceName, [[maybe_unused]] const TChar* targetPath) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::DefineDosDevice(EnumCastUnderlying(flags), deviceName.c_str(), targetPath) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DeleteDriveLetterOrMountedFolder([[maybe_unused]] const String& volumeMountPoint) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::DeleteVolumeMountPoint(volumeMountPoint.c_str()) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetDiskFreeSpaceWithRoot([[maybe_unused]] const TChar* rootPathName, [[maybe_unused]] WindowDWordPtr sectorsPerCluster, [[maybe_unused]] WindowDWordPtr bytesPerSector,
                                      [[maybe_unused]] WindowDWordPtr numberOfFreeClusters, [[maybe_unused]] WindowDWordPtr totalNumberOfClusters) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::GetDiskFreeSpace(rootPathName, sectorsPerCluster, bytesPerSector, numberOfFreeClusters, totalNumberOfClusters) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetDiskFreeSpaceWithRoot([[maybe_unused]] const TChar* directoryName, [[maybe_unused]] WindowULargeIntegerPtr freeBytesAvailableToCaller,
                                      [[maybe_unused]] WindowULargeIntegerPtr totalNumberOfBytes, [[maybe_unused]] WindowULargeIntegerPtr totalNumberOfFreeBytes) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::GetDiskFreeSpaceEx(directoryName, freeBytesAvailableToCaller, totalNumberOfBytes, totalNumberOfFreeBytes) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::Drive System::GetDriveTypeFlag([[maybe_unused]] const TChar* rootPathName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return UnderlyingCastEnum<Drive>(::GetDriveType(rootPathName));
#else  // !SYSTEM_PLATFORM_WIN32
    return Drive::Unknow;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::FileHandleAttributes System::GetSystemFileAttributes([[maybe_unused]] const TChar* fileName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return UnderlyingCastEnum<FileHandleAttributes>(::GetFileAttributes(fileName));
#else  // !SYSTEM_PLATFORM_WIN32
    return FileHandleAttributes::Temporary;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemFileAttributes([[maybe_unused]] const TChar* fileName, [[maybe_unused]] FileAttributeDataPtr fileInformation) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::GetFileAttributesEx(fileName, GetFileExInfoStandard, fileInformation) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemFileInformationByHandle([[maybe_unused]] WindowHandle file, [[maybe_unused]] ByHandleFileInformationPtr fileInformation) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::GetFileInformationByHandle(file, fileInformation) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::FileType System::GetFileTypeFlags([[maybe_unused]] WindowHandle file) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return UnderlyingCastEnum<FileType>(::GetFileType(file));
#else  // !SYSTEM_PLATFORM_WIN32
    return FileType::Unknown;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemFinalPathNameByHandle([[maybe_unused]] WindowHandle file, [[maybe_unused]] TChar* filePath, [[maybe_unused]] WindowDWord filePathSize, [[maybe_unused]] GetFinalPathName flags) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::GetFinalPathNameByHandle(file, filePath, filePathSize, EnumCastUnderlying(flags));
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemFullPathName([[maybe_unused]] const TChar* fileName, [[maybe_unused]] WindowDWord bufferLength, [[maybe_unused]] TChar* buffer, [[maybe_unused]] TChar** filePart) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::GetFullPathName(fileName, bufferLength, buffer, filePart);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemLogicalDrives() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::GetLogicalDrives();
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemLogicalDriveStrings([[maybe_unused]] WindowDWord bufferLength, [[maybe_unused]] TChar* buffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::GetLogicalDriveStrings(bufferLength, buffer);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemLongPathName([[maybe_unused]] const TChar* shortPath, [[maybe_unused]] TChar* longPath, [[maybe_unused]] WindowDWord buffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::GetLongPathName(shortPath, longPath, buffer);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemShortPathName([[maybe_unused]] const TChar* longPath, [[maybe_unused]] TChar* shortPath, [[maybe_unused]] WindowDWord buffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::GetShortPathName(longPath, shortPath, buffer);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowUInt System::GetSystemTempFileName([[maybe_unused]] const TChar* pathName, [[maybe_unused]] const TChar* prefixString, [[maybe_unused]] WindowUInt unique, [[maybe_unused]] TChar* tempFileName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::GetTempFileName(pathName, prefixString, unique, tempFileName);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemVolumeInformationByHandle([[maybe_unused]] WindowHandle file, [[maybe_unused]] wchar_t* volumeNameBuffer, [[maybe_unused]] WindowDWord volumeNameSize, [[maybe_unused]] WindowDWordPtr volumeSerialNumber,
                                                [[maybe_unused]] WindowDWordPtr maximumComponentLength, [[maybe_unused]] FileSystem* fileSystemFlags, [[maybe_unused]] wchar_t* fileSystemNameBuffer, [[maybe_unused]] WindowDWord fileSystemNameSize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    WindowDWord resultFileSystemFlags{ 0 };

    if (::GetVolumeInformationByHandleW(file, volumeNameBuffer, volumeNameSize, volumeSerialNumber, maximumComponentLength, &resultFileSystemFlags, fileSystemNameBuffer, fileSystemNameSize) != g_False)
    {
        UnderlyingCastEnumPtr(resultFileSystemFlags, fileSystemFlags);

        return true;
    }
    else
    {
        return false;
    }
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemVolumeInformationByHandle([[maybe_unused]] const TChar* rootPathName, [[maybe_unused]] TChar* volumeNameBuffer, [[maybe_unused]] WindowDWord volumeNameSize, [[maybe_unused]] WindowDWordPtr volumeSerialNumber,
                                                [[maybe_unused]] WindowDWordPtr maximumComponentLength, [[maybe_unused]] FileSystem* fileSystemFlags, TChar* fileSystemNameBuffer, [[maybe_unused]] WindowDWord fileSystemNameSize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    WindowDWord resultFileSystemFlags{ 0 };

    if (::GetVolumeInformation(rootPathName, volumeNameBuffer, volumeNameSize, volumeSerialNumber, maximumComponentLength, &resultFileSystemFlags, fileSystemNameBuffer, fileSystemNameSize) != g_False)
    {
        UnderlyingCastEnumPtr(resultFileSystemFlags, fileSystemFlags);

        return true;
    }
    else
    {
        return false;
    }
#else  // !SYSTEM_PLATFORM_WIN32

    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemVolumePathName([[maybe_unused]] const TChar* fileName, [[maybe_unused]] TChar* volumePathName, [[maybe_unused]] WindowDWord bufferLength) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::GetVolumePathName(fileName, volumePathName, bufferLength) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::LockSystemFile([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowDWord fileOffsetLow, [[maybe_unused]] WindowDWord fileOffsetHigh, [[maybe_unused]] WindowDWord numberOfBytesToLockLow, [[maybe_unused]] WindowDWord numberOfBytesToLockHigh) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::LockFile(file, fileOffsetLow, fileOffsetHigh, numberOfBytesToLockLow, numberOfBytesToLockHigh) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::LockSystemFile([[maybe_unused]] WindowHandle file, [[maybe_unused]] LockFile flags, [[maybe_unused]] WindowDWord numberOfBytesToLockLow, [[maybe_unused]] WindowDWord numberOfBytesToLockHigh, [[maybe_unused]] WindowOverlappedPtr overlapped) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::LockFileEx(file, EnumCastUnderlying(flags), 0, numberOfBytesToLockLow, numberOfBytesToLockHigh, overlapped) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::QueryDosDeviceName([[maybe_unused]] const TChar* deviceName, [[maybe_unused]] TChar* targetPath, [[maybe_unused]] WindowDWord max) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::QueryDosDevice(deviceName, targetPath, max);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::RemoveSystemDirectory([[maybe_unused]] const TChar* pathName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::RemoveDirectory(pathName) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemFileAttributes([[maybe_unused]] const TChar* fileName, [[maybe_unused]] FileHandleAttributes fileAttributes) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::SetFileAttributes(fileName, EnumCastUnderlying(fileAttributes)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemFileInformationByHandle([[maybe_unused]] WindowHandle file, [[maybe_unused]] FileInfoByHandleClass fileInformationClass, [[maybe_unused]] WindowVoidPtr fileInformation, [[maybe_unused]] WindowDWord bufferSize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::SetFileInformationByHandle(file, fileInformationClass, fileInformation, bufferSize) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::UnlockSystemFile([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowDWord fileOffsetLow, [[maybe_unused]] WindowDWord fileOffsetHigh, [[maybe_unused]] WindowDWord numberOfBytesToLockLow, [[maybe_unused]] WindowDWord numberOfBytesToLockHigh) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::UnlockFile(file, fileOffsetLow, fileOffsetHigh, numberOfBytesToLockLow, numberOfBytesToLockHigh) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::UnlockSystemFile([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowDWord numberOfBytesToLockLow, [[maybe_unused]] WindowDWord numberOfBytesToLockHigh, [[maybe_unused]] WindowOverlappedPtr overlapped) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::UnlockFileEx(file, 0, numberOfBytesToLockLow, numberOfBytesToLockHigh, overlapped) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemTempPath([[maybe_unused]] WindowDWord bufferLength, [[maybe_unused]] TChar* buffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::GetTempPath(bufferLength, buffer);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemVolumeNameForVolumeMountPoint([[maybe_unused]] const TChar* volumeMountPoint, [[maybe_unused]] TChar* volumeName, [[maybe_unused]] WindowDWord bufferLength) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::GetVolumeNameForVolumeMountPoint(volumeMountPoint, volumeName, bufferLength) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemVolumePathNamesForVolumeName([[maybe_unused]] const TChar* volumeName, [[maybe_unused]] TChar* volumePathNames, [[maybe_unused]] WindowDWord bufferLength, [[maybe_unused]] WindowDWordPtr returnLength) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::GetVolumePathNamesForVolumeName(volumeName, volumePathNames, bufferLength, returnLength) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemCompressedFileSize([[maybe_unused]] const TChar* fileName, [[maybe_unused]] uint64_t& fileSize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    WindowDWord fileSizeHigh{ 0 };
    auto fileSizeLow = ::GetCompressedFileSize(fileName, &fileSizeHigh);
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

bool System::SetSystemVolumeMountPoint([[maybe_unused]] const TChar* volumeMountPoint, [[maybe_unused]] const TChar* volumeName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::SetVolumeMountPoint(volumeMountPoint, volumeName) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
