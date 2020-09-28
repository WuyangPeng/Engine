//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 12:59)

#ifndef SYSTEM_FILE_MANAGE_FILE_TOOLS_H
#define SYSTEM_FILE_MANAGE_FILE_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/FileFlagsFwd.h"
#include "Using/FileToolsUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"
#include "System/Threading/Using/OverlappedToolsUsing.h"

#include <string>

namespace System
{
    // 文件管理辅助工具

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CreateFileDirectory(const String& pathName, WindowSecurityAttributesPtr securityAttributes) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE RemoveSystemDirectory(const TChar* pathName) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE DefineDosDeviceName(DefineDosDeviceControllable flags, const String& deviceName, const TChar* targetPath) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE QueryDosDeviceName(const TChar* deviceName, TChar* targetPath, WindowDWord max) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetDiskFreeSpaceWithRoot(const TChar* rootPathName, WindowDWordPtr sectorsPerCluster, WindowDWordPtr bytesPerSector,
                                                                       WindowDWordPtr numberOfFreeClusters, WindowDWordPtr totalNumberOfClusters) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetDiskFreeSpaceWithRoot(const TChar* directoryName, WindowULargeIntegerPtr freeBytesAvailableToCaller,
                                                                       WindowULargeIntegerPtr totalNumberOfBytes, WindowULargeIntegerPtr totalNumberOfFreeBytes) noexcept;

    [[nodiscard]] Drive SYSTEM_DEFAULT_DECLARE GetDriveTypeFlag(const TChar* rootPathName) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemLogicalDrives() noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemLogicalDriveStrings(WindowDWord bufferLength, TChar* buffer) noexcept;

    [[nodiscard]] FileHandleAttributes SYSTEM_DEFAULT_DECLARE GetSystemFileAttributes(const TChar* fileName) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemFileAttributes(const TChar* fileName, FileAttributeDataPtr fileInformation) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemFileAttributes(const TChar* fileName, FileHandleAttributes fileAttributes) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE LockSystemFile(WindowHandle file, WindowDWord fileOffsetLow, WindowDWord fileOffsetHigh,
                                                             WindowDWord numberOfBytesToLockLow, WindowDWord numberOfBytesToLockHigh) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE LockSystemFile(WindowHandle file, LockFile flags, WindowDWord numberOfBytesToLockLow,
                                                             WindowDWord numberOfBytesToLockHigh, WindowOverlappedPtr overlapped) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE UnlockSystemFile(WindowHandle file, WindowDWord fileOffsetLow, WindowDWord fileOffsetHigh,
                                                               WindowDWord numberOfBytesToLockLow, WindowDWord numberOfBytesToLockHigh) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE UnlockSystemFile(WindowHandle file, WindowDWord numberOfBytesToLockLow, WindowDWord numberOfBytesToLockHigh, WindowOverlappedPtr overlapped) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemFileInformationByHandle(WindowHandle file, ByHandleFileInformationPtr fileInformation) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemFileInformationByHandle(WindowHandle file, FileInfoByHandleClass fileInformationClass, WindowVoidPtr fileInformation, WindowDWord bufferSize) noexcept;

    [[nodiscard]] FileType SYSTEM_DEFAULT_DECLARE GetFileTypeFlags(WindowHandle file) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemFinalPathNameByHandle(WindowHandle file, TChar* filePath, WindowDWord filePathSize, GetFinalPathName flags) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemFullPathName(const TChar* fileName, WindowDWord bufferLength, TChar* buffer, TChar** filePart) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemLongPathName(const TChar* shortPath, TChar* longPath, WindowDWord buffer) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemShortPathName(const TChar* longPath, TChar* shortPath, WindowDWord buffer) noexcept;
    [[nodiscard]] WindowUInt SYSTEM_DEFAULT_DECLARE GetSystemTempFileName(const TChar* pathName, const TChar* prefixString, WindowUInt unique, TChar* tempFileName) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemVolumeInformationByHandle(WindowHandle file, wchar_t* volumeNameBuffer, WindowDWord volumeNameSize, WindowDWordPtr volumeSerialNumber,
                                                                                 WindowDWordPtr maximumComponentLength, FileSystem* fileSystemFlags, wchar_t* fileSystemNameBuffer, WindowDWord fileSystemNameSize) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemVolumeInformationByHandle(const TChar* rootPathName, TChar* volumeNameBuffer, WindowDWord volumeNameSize,
                                                                                 WindowDWordPtr volumeSerialNumber, WindowDWordPtr maximumComponentLength, FileSystem* fileSystemFlags,
                                                                                 TChar* fileSystemNameBuffer, WindowDWord fileSystemNameSize) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemVolumePathName(const TChar* fileName, TChar* volumePathName, WindowDWord bufferLength) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE DeleteDriveLetterOrMountedFolder(const String& volumeMountPoint) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemVolumeNameForVolumeMountPoint(const TChar* volumeMountPoint, TChar* volumeName, WindowDWord bufferLength) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemVolumePathNamesForVolumeName(const TChar* volumeName, TChar* volumePathNames, WindowDWord bufferLength, WindowDWordPtr returnLength) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemVolumeMountPoint(const TChar* volumeMountPoint, const TChar* volumeName) noexcept;

    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemTempPath(WindowDWord bufferLength, TChar* buffer) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemCompressedFileSize(const TChar* fileName, uint64_t& fileSize) noexcept;
}

#endif  // SYSTEM_FILE_MANAGE_FILE_TOOLS_H