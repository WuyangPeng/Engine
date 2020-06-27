// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:57)

#include "System/SystemExport.h"

#include "FindFile.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h" 
#include "System/Window/WindowSystem.h"
#include "System/Helper/EnumCast.h"
#include "System/Threading/Flags/SemaphoreFlags.h"

bool System
	::FindSystemClose(WindowHandle findFile) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::FindClose(findFile) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(findFile);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FindSystemCloseChangeNotification(WindowHandle changeHandle) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::FindCloseChangeNotification(changeHandle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(changeHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::FindFirstSystemFile(const String& fileName, FileWin32FindDataPtr findFileData) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::FindFirstFile(fileName.c_str(), findFileData);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileName);
	SYSTEM_UNUSED_ARG(findFileData);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::FindFirstSystemFile(const String& fileName, FileInfoLevels infoLevelId, WindowVoidPtr findFileData, FileSearchOps searchOp, FindFirstFileAdditional additionalFlags) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::FindFirstFileEx(fileName.c_str(), infoLevelId, findFileData, searchOp, nullptr, EnumCastUnderlying(additionalFlags));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(fileName);
	SYSTEM_UNUSED_ARG(infoLevelId);
	SYSTEM_UNUSED_ARG(findFileData);
	SYSTEM_UNUSED_ARG(searchOp);
	SYSTEM_UNUSED_ARG(additionalFlags);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::FindFirstSystemChangeNotification(const String& pathName, bool watchSubtree, FileNotifyFilter notifyFilter) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::FindFirstChangeNotification(pathName.c_str(), BoolConversion(watchSubtree), EnumCastUnderlying(notifyFilter));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(pathName);
	SYSTEM_UNUSED_ARG(watchSubtree);
	SYSTEM_UNUSED_ARG(notifyFilter);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System
	::FindFirstSystemVolume(TChar* volumeName, WindowDWord bufferLength) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	return ::FindFirstVolume(volumeName, bufferLength);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(volumeName);
	SYSTEM_UNUSED_ARG(bufferLength);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FindNextSystemChangeNotification(WindowHandle changeHandle) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::FindNextChangeNotification(changeHandle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(changeHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FindNextSystemVolume(WindowHandle findVolume, TChar* volumeName, WindowDWord bufferLength) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::FindNextVolume(findVolume, volumeName, bufferLength) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(findVolume);
	SYSTEM_UNUSED_ARG(volumeName);
	SYSTEM_UNUSED_ARG(bufferLength);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FindSystemVolumeClose(WindowHandle findVolume) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::FindVolumeClose(findVolume) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(findVolume);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FindNextSystemFile(WindowHandle findFile, FileWin32FindDataPtr findFileData) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)	
	if (::FindNextFile(findFile, findFileData) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(findFile);
	SYSTEM_UNUSED_ARG(findFileData);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::WaitForChangeNotification(WindowHandle changeHandle) noexcept
{
	return WaitForChangeNotification(changeHandle, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System
	::WaitForChangeNotification(WindowHandle changeHandle, WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(changeHandle, milliseconds));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(changeHandle);
	SYSTEM_UNUSED_ARG(milliseconds);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System
	::WaitForChangeNotification(WindowHandle changeHandle, WindowDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(changeHandle, milliseconds, BoolConversion(alertable)));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(changeHandle);
	SYSTEM_UNUSED_ARG(milliseconds);
	SYSTEM_UNUSED_ARG(alertable);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System
	::WaitForChangeNotification(WindowDWord count, const WindowHandle* changeHandle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, changeHandle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(count);
	SYSTEM_UNUSED_ARG(changeHandle);
	SYSTEM_UNUSED_ARG(waitAll);
	SYSTEM_UNUSED_ARG(milliseconds);
	SYSTEM_UNUSED_ARG(alertable);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System
	::WaitForChangeNotification(WindowDWord count, const WindowHandle* changeHandle, bool waitAll, WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, changeHandle, BoolConversion(waitAll), milliseconds));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(count);
	SYSTEM_UNUSED_ARG(changeHandle);
	SYSTEM_UNUSED_ARG(waitAll);
	SYSTEM_UNUSED_ARG(milliseconds);

	return MutexWaitReturn::Failed;
#endif // SYSTEM_PLATFORM_WIN32
}