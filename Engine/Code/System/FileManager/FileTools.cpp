// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:57)

#include "System/SystemExport.h"

#include "FileTools.h"
#include "Using/FileUsing.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/LastPlatformError.h"
#include "System/Window/Flags/PlatformErrorFlags.h"
#include "System/EnumOperator/EnumCastDetail.h"

bool System
	::CreateFileDirectory(const String& pathName, WindowSecurityAttributesPtr securityAttributes) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::CreateDirectory(pathName.c_str(), securityAttributes) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(pathName);
	SYSTEM_UNUSED_ARG(securityAttributes);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::DefineDosDeviceName(DefineDosDeviceControllable flags, const String& deviceName, const TChar* targetPath) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::DefineDosDevice(EnumCastUnderlying(flags), deviceName.c_str(), targetPath) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(deviceName);
	SYSTEM_UNUSED_ARG(targetPath);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::DeleteDriveLetterOrMountedFolder(const String& volumeMountPoint) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::DeleteVolumeMountPoint(volumeMountPoint.c_str()) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(volumeMountPoint);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetDiskFreeSpaceWithRoot(const TChar* rootPathName, WindowDWordPtr sectorsPerCluster, WindowDWordPtr bytesPerSector,
							   WindowDWordPtr numberOfFreeClusters, WindowDWordPtr totalNumberOfClusters) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::GetDiskFreeSpace(rootPathName, sectorsPerCluster, bytesPerSector, numberOfFreeClusters, totalNumberOfClusters) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(rootPathName);
	SYSTEM_UNUSED_ARG(sectorsPerCluster);
	SYSTEM_UNUSED_ARG(bytesPerSector);
	SYSTEM_UNUSED_ARG(numberOfFreeClusters);
	SYSTEM_UNUSED_ARG(totalNumberOfClusters);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetDiskFreeSpaceWithRoot(const TChar* directoryName, WindowULargeIntegerPtr freeBytesAvailableToCaller,
							   WindowULargeIntegerPtr totalNumberOfBytes, WindowULargeIntegerPtr totalNumberOfFreeBytes) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::GetDiskFreeSpaceEx(directoryName, freeBytesAvailableToCaller, totalNumberOfBytes, totalNumberOfFreeBytes) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(directoryName);
	SYSTEM_UNUSED_ARG(freeBytesAvailableToCaller);
	SYSTEM_UNUSED_ARG(totalNumberOfBytes);
	SYSTEM_UNUSED_ARG(totalNumberOfFreeBytes);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::Drive System
	::GetDriveTypeFlag(const TChar* rootPathName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return UnderlyingCastEnum<Drive>(::GetDriveType(rootPathName));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(rootPathName);

	return Drive::Unknow;
#endif // SYSTEM_PLATFORM_WIN32
}

System::FileHandleAttributes System
	::GetSystemFileAttributes(const TChar* fileName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return UnderlyingCastEnum<FileHandleAttributes>(::GetFileAttributes(fileName));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileName);

	return FileHandleAttributes::Temporary;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemFileAttributes(const TChar* fileName, FileAttributeDataPtr fileInformation) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::GetFileAttributesEx(fileName, GetFileExInfoStandard, fileInformation) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileName);
	SYSTEM_UNUSED_ARG(fileInformation);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemFileInformationByHandle(WindowHandle file, ByHandleFileInformationPtr fileInformation) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::GetFileInformationByHandle(file, fileInformation) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(fileInformation);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::FileType System
	::GetFileTypeFlags(WindowHandle file) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return UnderlyingCastEnum<FileType>(::GetFileType(file));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);

	return FileType::Unknown;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemFinalPathNameByHandle(WindowHandle file, TChar* filePath, WindowDWord filePathSize, GetFinalPathName flags) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::GetFinalPathNameByHandle(file, filePath, filePathSize, EnumCastUnderlying(flags));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(filePath);
	SYSTEM_UNUSED_ARG(filePathSize);
	SYSTEM_UNUSED_ARG(flags);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemFullPathName(const TChar* fileName, WindowDWord bufferLength, TChar* buffer, TChar** filePart) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::GetFullPathName(fileName, bufferLength, buffer, filePart);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileName);
	SYSTEM_UNUSED_ARG(bufferLength);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(filePart);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemLogicalDrives() noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::GetLogicalDrives();
#else // !SYSTEM_PLATFORM_WIN32
	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemLogicalDriveStrings(WindowDWord bufferLength, TChar* buffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::GetLogicalDriveStrings(bufferLength, buffer);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(bufferLength);
	SYSTEM_UNUSED_ARG(buffer);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemLongPathName(const TChar* shortPath, TChar* longPath, WindowDWord buffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::GetLongPathName(shortPath, longPath, buffer);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(shortPath);
	SYSTEM_UNUSED_ARG(longPath);
	SYSTEM_UNUSED_ARG(buffer);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSystemShortPathName(const TChar* longPath, TChar* shortPath, WindowDWord buffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::GetShortPathName(longPath, shortPath, buffer);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(longPath);
	SYSTEM_UNUSED_ARG(shortPath);
	SYSTEM_UNUSED_ARG(buffer);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowUInt System
	::GetSystemTempFileName(const TChar* pathName, const TChar* prefixString, WindowUInt unique, TChar* tempFileName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::GetTempFileName(pathName, prefixString, unique, tempFileName);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(pathName);
	SYSTEM_UNUSED_ARG(prefixString);
	SYSTEM_UNUSED_ARG(unique);
	SYSTEM_UNUSED_ARG(tempFileName);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemVolumeInformationByHandle(WindowHandle file, wchar_t* volumeNameBuffer, WindowDWord volumeNameSize, WindowDWordPtr volumeSerialNumber,
										 WindowDWordPtr maximumComponentLength, FileSystem* fileSystemFlags, wchar_t* fileSystemNameBuffer, WindowDWord fileSystemNameSize) noexcept
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
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(volumeNameBuffer);
	SYSTEM_UNUSED_ARG(volumeNameSize);
	SYSTEM_UNUSED_ARG(volumeSerialNumber);
	SYSTEM_UNUSED_ARG(maximumComponentLength);
	SYSTEM_UNUSED_ARG(fileSystemFlags);
	SYSTEM_UNUSED_ARG(fileSystemNameBuffer);
	SYSTEM_UNUSED_ARG(fileSystemNameSize);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemVolumeInformationByHandle(const TChar* rootPathName, TChar* volumeNameBuffer, WindowDWord volumeNameSize, WindowDWordPtr volumeSerialNumber,
										 WindowDWordPtr maximumComponentLength, FileSystem* fileSystemFlags, TChar* fileSystemNameBuffer, WindowDWord fileSystemNameSize) noexcept
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
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(rootPathName);
	SYSTEM_UNUSED_ARG(volumeNameBuffer);
	SYSTEM_UNUSED_ARG(volumeNameSize);
	SYSTEM_UNUSED_ARG(volumeSerialNumber);
	SYSTEM_UNUSED_ARG(maximumComponentLength);
	SYSTEM_UNUSED_ARG(fileSystemFlags);
	SYSTEM_UNUSED_ARG(fileSystemNameBuffer);
	SYSTEM_UNUSED_ARG(fileSystemNameSize);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
	}

bool System
	::GetSystemVolumePathName(const TChar* fileName, TChar* volumePathName, WindowDWord bufferLength) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::GetVolumePathName(fileName, volumePathName, bufferLength) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileName);
	SYSTEM_UNUSED_ARG(volumePathName);
	SYSTEM_UNUSED_ARG(bufferLength);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::LockSystemFile(WindowHandle file, WindowDWord fileOffsetLow, WindowDWord fileOffsetHigh, WindowDWord numberOfBytesToLockLow, WindowDWord numberOfBytesToLockHigh) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::LockFile(file, fileOffsetLow, fileOffsetHigh, numberOfBytesToLockLow, numberOfBytesToLockHigh) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(fileOffsetLow);
	SYSTEM_UNUSED_ARG(fileOffsetHigh);
	SYSTEM_UNUSED_ARG(numberOfBytesToLockLow);
	SYSTEM_UNUSED_ARG(numberOfBytesToLockHigh);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::LockSystemFile(WindowHandle file, LockFile flags, WindowDWord numberOfBytesToLockLow, WindowDWord numberOfBytesToLockHigh, WindowOverlappedPtr overlapped) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::LockFileEx(file, EnumCastUnderlying(flags), 0, numberOfBytesToLockLow, numberOfBytesToLockHigh, overlapped) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(numberOfBytesToLockLow);
	SYSTEM_UNUSED_ARG(numberOfBytesToLockHigh);
	SYSTEM_UNUSED_ARG(overlapped);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::QueryDosDeviceName(const TChar* deviceName, TChar* targetPath, WindowDWord max) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::QueryDosDevice(deviceName, targetPath, max);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(deviceName);
	SYSTEM_UNUSED_ARG(targetPath);
	SYSTEM_UNUSED_ARG(max);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::RemoveSystemDirectory(const TChar* pathName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::RemoveDirectory(pathName) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(pathName);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemFileAttributes(const TChar* fileName, FileHandleAttributes fileAttributes) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::SetFileAttributes(fileName, EnumCastUnderlying(fileAttributes)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileName);
	SYSTEM_UNUSED_ARG(fileAttributes);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemFileInformationByHandle(WindowHandle file, FileInfoByHandleClass fileInformationClass, WindowVoidPtr fileInformation, WindowDWord bufferSize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::SetFileInformationByHandle(file, fileInformationClass, fileInformation, bufferSize) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(fileInformationClass);
	SYSTEM_UNUSED_ARG(fileInformation);
	SYSTEM_UNUSED_ARG(bufferSize);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::UnlockSystemFile(WindowHandle file, WindowDWord fileOffsetLow, WindowDWord fileOffsetHigh, WindowDWord numberOfBytesToLockLow, WindowDWord numberOfBytesToLockHigh) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::UnlockFile(file, fileOffsetLow, fileOffsetHigh, numberOfBytesToLockLow, numberOfBytesToLockHigh) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(fileOffsetLow);
	SYSTEM_UNUSED_ARG(fileOffsetHigh);
	SYSTEM_UNUSED_ARG(numberOfBytesToLockLow);
	SYSTEM_UNUSED_ARG(numberOfBytesToLockHigh);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::UnlockSystemFile(WindowHandle file, WindowDWord numberOfBytesToLockLow, WindowDWord numberOfBytesToLockHigh, WindowOverlappedPtr overlapped) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::UnlockFileEx(file, 0, numberOfBytesToLockLow, numberOfBytesToLockHigh, overlapped) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(numberOfBytesToLockLow);
	SYSTEM_UNUSED_ARG(numberOfBytesToLockHigh);
	SYSTEM_UNUSED_ARG(overlapped);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}


System::WindowDWord System
	::GetSystemTempPath(WindowDWord bufferLength, TChar* buffer) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::GetTempPath(bufferLength, buffer);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(bufferLength);
	SYSTEM_UNUSED_ARG(buffer);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemVolumeNameForVolumeMountPoint(const TChar* volumeMountPoint, TChar* volumeName, WindowDWord bufferLength) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::GetVolumeNameForVolumeMountPoint(volumeMountPoint, volumeName, bufferLength) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(volumeMountPoint);
	SYSTEM_UNUSED_ARG(volumeName);
	SYSTEM_UNUSED_ARG(bufferLength);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemVolumePathNamesForVolumeName(const TChar* volumeName, TChar* volumePathNames, WindowDWord bufferLength, WindowDWordPtr returnLength) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::GetVolumePathNamesForVolumeName(volumeName, volumePathNames, bufferLength, returnLength) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(volumeName);
	SYSTEM_UNUSED_ARG(volumePathNames);
	SYSTEM_UNUSED_ARG(bufferLength);
	SYSTEM_UNUSED_ARG(returnLength);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetSystemCompressedFileSize(const TChar* fileName, uint64_t& fileSize) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	WindowDWord fileSizeHigh{ 0 };
	auto fileSizeLow = ::GetCompressedFileSize(fileName, &fileSizeHigh);
	const auto lastError = GetPlatformLastError();

	if (lastError == WindowError::Success || fileSizeLow != g_InvalidFileSize)
	{
		fileSize = (static_cast<uint64_t>(fileSizeHigh) << 32) + fileSizeLow;
		return true;
	}
	else
	{
		SetPlatformLastError(lastError);
		fileSize = 0;

		return false;
	}

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileName);
	SYSTEM_UNUSED_ARG(fileSize);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetSystemVolumeMountPoint(const TChar* volumeMountPoint, const TChar* volumeName) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::SetVolumeMountPoint(volumeMountPoint, volumeName) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(volumeMountPoint);
	SYSTEM_UNUSED_ARG(volumeName);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

