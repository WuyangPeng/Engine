// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:52)

#ifndef SYSTEM_FILE_MANAGE_FIND_FILE_FWD_H
#define SYSTEM_FILE_MANAGE_FIND_FILE_FWD_H 

#include "FileFlagsFwd.h"
#include "System/FileManager/Using/FindFileUsing.h" 

namespace System
{
	bool FindSystemClose(WindowHandle findFile) noexcept;
	bool FindSystemCloseChangeNotification(WindowHandle changeHandle) noexcept;
	bool FindSystemVolumeClose(WindowHandle findVolume) noexcept;
	WindowHandle FindFirstSystemFile(const String& fileName, FileWin32FindDataPtr findFileData) noexcept;
	WindowHandle FindFirstSystemChangeNotification(const String& pathName, bool watchSubtree, FileNotifyFilter notifyFilter) noexcept;
	WindowHandle FindFirstSystemFile(const String& fileName, FileInfoLevels infoLevelId, WindowVoidPtr findFileData,
									 FileSearchOps searchOp, FindFirstFileAdditional additionalFlags) noexcept;
	WindowHandle FindFirstSystemVolume(TChar* volumeName, WindowDWord bufferLength) noexcept;
	bool FindNextSystemChangeNotification(WindowHandle changeHandle) noexcept;
	bool FindNextSystemFile(WindowHandle findFile, FileWin32FindDataPtr findFileData) noexcept;
	bool FindNextSystemVolume(WindowHandle findVolume, TChar* volumeName, WindowDWord bufferLength) noexcept;
	bool FindSystemVolumeClose(WindowHandle findVolume) noexcept;

	bool WaitForChangeNotification(WindowHandle changeHandle) noexcept;
	MutexWaitReturn WaitForChangeNotification(WindowHandle changeHandle, WindowDWord milliseconds) noexcept;
	MutexWaitReturn WaitForChangeNotification(WindowHandle changeHandle, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn WaitForChangeNotification(WindowDWord count, const WindowHandle* changeHandle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn WaitForChangeNotification(WindowDWord count, const WindowHandle* changeHandle, bool waitAll, WindowDWord milliseconds) noexcept;
}

#endif // SYSTEM_FILE_MANAGE_FIND_FILE_FWD_H