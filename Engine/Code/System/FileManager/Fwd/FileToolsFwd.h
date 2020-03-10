// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:52)

#ifndef SYSTEM_FILE_MANAGE_FILE_TOOLS_FWD_H
#define SYSTEM_FILE_MANAGE_FILE_TOOLS_FWD_H  

#include "FileFlagsFwd.h"
#include "System/FileManager/Using/FileToolsUsing.h"

namespace System
{
	bool CreateFileDirectory(const String& pathName, WindowSecurityAttributesPtr securityAttributes) noexcept;
	bool DefineDosDeviceName(DefineDosDeviceControllable flags, const String& deviceName, const TChar* targetPath) noexcept;

	bool DeleteDriveLetterOrMountedFolder(const String& volumeMountPoint) noexcept;

	bool GetDiskFreeSpaceWithRoot(const TChar* rootPathName, WindowDWordPtr sectorsPerCluster, WindowDWordPtr bytesPerSector,
								  WindowDWordPtr numberOfFreeClusters, WindowDWordPtr totalNumberOfClusters) noexcept;
	bool GetDiskFreeSpaceWithRoot(const TChar* directoryName, WindowULargeIntegerPtr freeBytesAvailableToCaller,
								  WindowULargeIntegerPtr totalNumberOfBytes, WindowULargeIntegerPtr totalNumberOfFreeBytes) noexcept;
	Drive GetDriveTypeFlag(const TChar* rootPathName) noexcept;
	FileHandleAttributes GetSystemFileAttributes(const TChar* fileName) noexcept;
	bool GetSystemFileAttributes(const TChar* fileName, FileAttributeDataPtr fileInformation) noexcept;
	bool GetSystemFileInformationByHandle(WindowHandle file, ByHandleFileInformationPtr fileInformation) noexcept;
	FileType GetFileTypeFlags(WindowHandle file) noexcept;
	WindowDWord GetSystemFinalPathNameByHandle(WindowHandle file, TChar* filePath, WindowDWord filePathSize, GetFinalPathName flags) noexcept;
	WindowDWord GetSystemFullPathName(const TChar* fileName, WindowDWord bufferLength, TChar* buffer, TChar** filePart) noexcept;

	WindowDWord GetSystemLogicalDrives() noexcept;
	WindowDWord GetSystemLogicalDriveStrings(WindowDWord bufferLength, TChar* buffer) noexcept;
	WindowDWord GetSystemLongPathName(const TChar* shortPath, TChar* longPath, WindowDWord buffer) noexcept;
	WindowDWord GetSystemShortPathName(const TChar* longPath, TChar* shortPath, WindowDWord buffer) noexcept;
	WindowUInt GetSystemTempFileName(const TChar* pathName, const TChar* prefixString, WindowUInt unique, TChar* tempFileName) noexcept;
	bool GetSystemVolumeInformationByHandle(WindowHandle file, wchar_t* volumeNameBuffer, WindowDWord volumeNameSize, WindowDWordPtr volumeSerialNumber,
											WindowDWordPtr maximumComponentLength, FileSystem* fileSystemFlags, wchar_t* fileSystemNameBuffer, WindowDWord fileSystemNameSize) noexcept;

	bool GetSystemVolumeInformationByHandle(const TChar* rootPathName, TChar* volumeNameBuffer, WindowDWord volumeNameSize, WindowDWordPtr volumeSerialNumber,
											WindowDWordPtr maximumComponentLength, FileSystem* fileSystemFlags, TChar* fileSystemNameBuffer, WindowDWord fileSystemNameSize) noexcept;

	bool GetSystemVolumePathName(const TChar* fileName, TChar* volumePathName, WindowDWord bufferLength) noexcept;
	bool LockSystemFile(WindowHandle file, WindowDWord fileOffsetLow, WindowDWord fileOffsetHigh, WindowDWord numberOfBytesToLockLow, WindowDWord numberOfBytesToLockHigh) noexcept;
	bool LockSystemFile(WindowHandle file, LockFile flags, WindowDWord numberOfBytesToLockLow, WindowDWord numberOfBytesToLockHigh, WindowOverlappedPtr overlapped) noexcept;
	WindowDWord QueryDosDeviceName(const TChar* deviceName, TChar* targetPath, WindowDWord max) noexcept;

	bool RemoveSystemDirectory(const TChar* pathName) noexcept;

	bool SetSystemFileAttributes(const TChar* fileName, FileHandleAttributes fileAttributes) noexcept;

	bool SetSystemFileInformationByHandle(WindowHandle file, FileInfoByHandleClass fileInformationClass, WindowVoidPtr fileInformation, WindowDWord bufferSize) noexcept;

	bool UnlockSystemFile(WindowHandle file, WindowDWord fileOffsetLow, WindowDWord fileOffsetHigh, WindowDWord numberOfBytesToLockLow, WindowDWord numberOfBytesToLockHigh) noexcept;
	bool UnlockSystemFile(WindowHandle file, WindowDWord numberOfBytesToLockLow, WindowDWord numberOfBytesToLockHigh, WindowOverlappedPtr overlapped) noexcept;

	WindowDWord GetSystemTempPath(WindowDWord bufferLength, TChar* buffer) noexcept;
	bool GetSystemVolumeNameForVolumeMountPoint(const TChar* volumeMountPoint, TChar* volumeName, WindowDWord bufferLength) noexcept;

	bool GetSystemVolumePathNamesForVolumeName(const TChar* volumeName, TChar* volumePathNames, WindowDWord bufferLength, WindowDWordPtr returnLength) noexcept;
	bool GetSystemCompressedFileSize(const TChar* fileName, uint64_t& fileSize) noexcept;
	bool SetSystemVolumeMountPoint(const TChar* volumeMountPoint, const TChar* volumeName) noexcept;
}

#endif // SYSTEM_FILE_MANAGE_FILE_TOOLS_FWD_H