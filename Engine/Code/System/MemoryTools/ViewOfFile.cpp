///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 17:01)

#include "System/SystemExport.h"

#include "ViewOfFile.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "System/Windows/LastPlatformError.h"
#include "System/Windows/WindowsSystem.h"

System::WindowsHandle System::CreateSystemFileMapping(WindowsHandle file,
                                                      MemoryProtect protect,
                                                      FileMapProtection otherProtect,
                                                      WindowsDWord maximumSizeHigh,
                                                      WindowsDWord maximumSizeLow,
                                                      const TChar* name,
                                                      bool* isExists) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto handle = ::CreateFileMapping(file, nullptr, EnumCastUnderlying(protect) | EnumCastUnderlying(otherProtect), maximumSizeHigh, maximumSizeLow, name);
    if (isExists != nullptr)
    {
        const auto errorFlag = GetPlatformLastError();
        if (errorFlag == WindowError::AlreadyExists)
            *isExists = true;
        else
            *isExists = false;

        SetPlatformLastError(errorFlag);
    }

    return handle;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(file, protect, otherProtect, maximumSizeHigh, maximumSizeLow, name, isExists);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsHandle System::OpenSystemFileMapping(FileMapDesiredAccess desiredAccess, bool inheritHandle, const TChar* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::OpenFileMapping(EnumCastUnderlying(desiredAccess), BoolConversion(inheritHandle), name);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(desiredAccess, inheritHandle, name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsVoidPtr System::MapSystemViewOfFile(WindowsHandle fileMappingObject, FileMapDesiredAccess desiredAccess, WindowsDWord maximumSizeHigh, WindowsDWord maximumSizeLow, WindowsSize numberOfBytesToMap) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::MapViewOfFile(fileMappingObject, EnumCastUnderlying(desiredAccess), maximumSizeHigh, maximumSizeLow, numberOfBytesToMap);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(fileMappingObject, desiredAccess, maximumSizeHigh, maximumSizeLow, numberOfBytesToMap);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsVoidPtr System::MapSystemViewOfFile(WindowsHandle fileMappingObject,
                                                   FileMapDesiredAccess desiredAccess,
                                                   WindowsDWord maximumSizeHigh,
                                                   WindowsDWord maximumSizeLow,
                                                   WindowsSize numberOfBytesToMap,
                                                   WindowsVoidPtr baseAddress) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::MapViewOfFileEx(fileMappingObject, EnumCastUnderlying(desiredAccess), maximumSizeHigh, maximumSizeLow, numberOfBytesToMap, baseAddress);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(fileMappingObject, desiredAccess, maximumSizeHigh, maximumSizeLow, numberOfBytesToMap, baseAddress);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FlushSystemViewOfFile(WindowsVoidPtr baseAddress, WindowsSize numberOfBytesToFlush) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::FlushViewOfFile(baseAddress, numberOfBytesToFlush) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(baseAddress, numberOfBytesToFlush);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::UnMapSystemViewOfFile(WindowsVoidPtr baseAddress) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::UnmapViewOfFile(baseAddress) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(baseAddress);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseFileMapping(WindowsHandle fileMappingHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CloseHandle(fileMappingHandle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(fileMappingHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
