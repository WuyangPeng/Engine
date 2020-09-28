//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 1:07)

#include "System/SystemExport.h"

#include "ViewOfFile.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/Flags/PlatformErrorFlags.h"
#include "System/Window/LastPlatformError.h"
#include "System/Window/WindowSystem.h"

System::WindowHandle System::CreateSystemFileMapping([[maybe_unused]] WindowHandle file, [[maybe_unused]] MemoryProtect protect, [[maybe_unused]] FileMapProtection otherProtect, [[maybe_unused]] WindowDWord maximumSizeHigh,
                                                     [[maybe_unused]] WindowDWord maximumSizeLow, [[maybe_unused]] const wchar_t* name, [[maybe_unused]] bool* isExists) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    auto handle = ::CreateFileMapping(file, nullptr, EnumCastUnderlying(protect) | EnumCastUnderlying(otherProtect), maximumSizeHigh, maximumSizeLow, name);
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
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::OpenSystemFileMapping([[maybe_unused]] FileMapDesiredAccess desiredAccess, [[maybe_unused]] bool inheritHandle, [[maybe_unused]] const wchar_t* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::OpenFileMapping(EnumCastUnderlying(desiredAccess), BoolConversion(inheritHandle), name);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::CreateSystemFileMappingNuma([[maybe_unused]] WindowHandle file, [[maybe_unused]] WindowSecurityAttributesPtr fileMappingAttributes, [[maybe_unused]] MemoryProtect protect,
                                                         [[maybe_unused]] FileMapProtection otherProtect, [[maybe_unused]] WindowDWord maximumSizeHigh, [[maybe_unused]] WindowDWord maximumSizeLow,
                                                         [[maybe_unused]] const wchar_t* name, [[maybe_unused]] WindowDWord preferred) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateFileMappingNuma(file, fileMappingAttributes, EnumCastUnderlying(protect) | EnumCastUnderlying(otherProtect), maximumSizeHigh, maximumSizeLow, name, preferred);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::MapSystemViewOfFile([[maybe_unused]] WindowHandle fileMappingObject, [[maybe_unused]] FileMapDesiredAccess desiredAccess, [[maybe_unused]] WindowDWord maximumSizeHigh, [[maybe_unused]] WindowDWord maximumSizeLow, [[maybe_unused]] WindowSize numberOfBytesToMap) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::MapViewOfFile(fileMappingObject, EnumCastUnderlying(desiredAccess), maximumSizeHigh, maximumSizeLow, numberOfBytesToMap);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::MapSystemViewOfFile([[maybe_unused]] WindowHandle fileMappingObject, [[maybe_unused]] FileMapDesiredAccess desiredAccess, [[maybe_unused]] WindowDWord maximumSizeHigh,
                                                  [[maybe_unused]] WindowDWord maximumSizeLow, [[maybe_unused]] WindowSize numberOfBytesToMap, [[maybe_unused]] WindowVoidPtr baseAddress) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::MapViewOfFileEx(fileMappingObject, EnumCastUnderlying(desiredAccess), maximumSizeHigh, maximumSizeLow, numberOfBytesToMap, baseAddress);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FlushSystemViewOfFile([[maybe_unused]] WindowVoidPtr baseAddress, [[maybe_unused]] WindowSize numberOfBytesToFlush) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::FlushViewOfFile(baseAddress, numberOfBytesToFlush) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::UnmapSystemViewOfFile([[maybe_unused]] WindowVoidPtr baseAddress) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::UnmapViewOfFile(baseAddress) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseFileMapping([[maybe_unused]] WindowHandle fileMappingHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CloseHandle(fileMappingHandle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
