//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 13:00)

#include "System/SystemExport.h"

#include "FindFile.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Window/WindowSystem.h"

bool System::FindSystemClose([[maybe_unused]] WindowHandle findFile) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::FindClose(findFile) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FindSystemCloseChangeNotification([[maybe_unused]] WindowHandle changeHandle) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::FindCloseChangeNotification(changeHandle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::FindFirstSystemFile([[maybe_unused]] const String& fileName, [[maybe_unused]] FileWin32FindDataPtr findFileData) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::FindFirstFile(fileName.c_str(), findFileData);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::FindFirstSystemFile([[maybe_unused]] const String& fileName, [[maybe_unused]] FileInfoLevels infoLevelId, [[maybe_unused]] WindowVoidPtr findFileData, [[maybe_unused]] FileSearchOps searchOp, [[maybe_unused]] FindFirstFileAdditional additionalFlags) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::FindFirstFileEx(fileName.c_str(), infoLevelId, findFileData, searchOp, nullptr, EnumCastUnderlying(additionalFlags));
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::FindFirstSystemChangeNotification([[maybe_unused]] const String& pathName, [[maybe_unused]] bool watchSubtree, [[maybe_unused]] FileNotifyFilter notifyFilter) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::FindFirstChangeNotification(pathName.c_str(), BoolConversion(watchSubtree), EnumCastUnderlying(notifyFilter));
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::FindFirstSystemVolume([[maybe_unused]] TChar* volumeName, [[maybe_unused]] WindowDWord bufferLength) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    return ::FindFirstVolume(volumeName, bufferLength);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FindNextSystemChangeNotification([[maybe_unused]] WindowHandle changeHandle) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::FindNextChangeNotification(changeHandle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FindNextSystemVolume([[maybe_unused]] WindowHandle findVolume, [[maybe_unused]] TChar* volumeName, [[maybe_unused]] WindowDWord bufferLength) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::FindNextVolume(findVolume, volumeName, bufferLength) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FindSystemVolumeClose([[maybe_unused]] WindowHandle findVolume) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::FindVolumeClose(findVolume) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FindNextSystemFile([[maybe_unused]] WindowHandle findFile, [[maybe_unused]] FileWin32FindDataPtr findFileData) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)
    if (::FindNextFile(findFile, findFileData) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::WaitForChangeNotification(WindowHandle changeHandle) noexcept
{
    return WaitForChangeNotification(changeHandle, EnumCastUnderlying(MutexWait::Infinite)) != MutexWaitReturn::Failed;
}

System::MutexWaitReturn System::WaitForChangeNotification([[maybe_unused]] WindowHandle changeHandle, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObject(changeHandle, milliseconds));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForChangeNotification([[maybe_unused]] WindowHandle changeHandle, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForSingleObjectEx(changeHandle, milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForChangeNotification([[maybe_unused]] WindowDWord count, [[maybe_unused]] const WindowHandle* changeHandle, [[maybe_unused]] bool waitAll, [[maybe_unused]] WindowDWord milliseconds, [[maybe_unused]] bool alertable) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjectsEx(count, changeHandle, BoolConversion(waitAll), milliseconds, BoolConversion(alertable)));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::MutexWaitReturn System::WaitForChangeNotification([[maybe_unused]] WindowDWord count, [[maybe_unused]] const WindowHandle* changeHandle, [[maybe_unused]] bool waitAll, [[maybe_unused]] WindowDWord milliseconds) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return UnderlyingCastEnum<MutexWaitReturn>(::WaitForMultipleObjects(count, changeHandle, BoolConversion(waitAll), milliseconds));
#else  // !SYSTEM_PLATFORM_WIN32
    return MutexWaitReturn::Failed;
#endif  // SYSTEM_PLATFORM_WIN32
}