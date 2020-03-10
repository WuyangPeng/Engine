// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 14:55)

#ifndef SYSTEM_FILE_MANAGE_FIND_FILE_H
#define SYSTEM_FILE_MANAGE_FIND_FILE_H

#include "System/SystemDll.h" 

#include "Fwd/FileFlagsFwd.h"
#include "Using/FileUsing.h"
#include "Using/FindFileUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"

#include <string> 

namespace System
{
	// 文件查找

	bool SYSTEM_DEFAULT_DECLARE FindSystemClose(WindowHandle findFile) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FindSystemCloseChangeNotification(WindowHandle changeHandle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FindSystemVolumeClose(WindowHandle findVolume) noexcept;

	WindowHandle SYSTEM_DEFAULT_DECLARE FindFirstSystemFile(const String& fileName, FileWin32FindDataPtr findFileData) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE FindFirstSystemChangeNotification(const String& pathName, bool watchSubtree, FileNotifyFilter notifyFilter) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE FindFirstSystemFile(const String& fileName, FileInfoLevels infoLevelId, WindowVoidPtr findFileData,
															FileSearchOps searchOp, FindFirstFileAdditional additionalFlags) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE FindFirstSystemVolume(TChar* volumeName, WindowDWord bufferLength) noexcept;

	bool SYSTEM_DEFAULT_DECLARE FindNextSystemChangeNotification(WindowHandle changeHandle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FindNextSystemFile(WindowHandle findFile, FileWin32FindDataPtr findFileData) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FindNextSystemVolume(WindowHandle findVolume, TChar* volumeName, WindowDWord bufferLength) noexcept;

	bool SYSTEM_DEFAULT_DECLARE WaitForChangeNotification(WindowHandle changeHandle) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForChangeNotification(WindowHandle changeHandle, WindowDWord milliseconds) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForChangeNotification(WindowHandle changeHandle, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForChangeNotification(WindowDWord count, const WindowHandle* changeHandle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForChangeNotification(WindowDWord count, const WindowHandle* changeHandle, bool waitAll, WindowDWord milliseconds) noexcept;
}

#endif // SYSTEM_FILE_MANAGE_FIND_FILE_H