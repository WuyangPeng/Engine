//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 15:42)

#include "System/SystemExport.h"

#include "WindowRegistry.h"

#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/Flags/PlatformErrorFlags.h"

bool System::RegistryCreateKey([[maybe_unused]] SystemHKey key, [[maybe_unused]] const TChar* subKey, [[maybe_unused]] TChar* userDefinedClassType, [[maybe_unused]] RegistryOpenCreateOptions options, [[maybe_unused]] RegistrySpecificAccess samDesired,
                               [[maybe_unused]] WindowSecurityAttributesPtr securityAttributes, [[maybe_unused]] SystemHKey* keyResult, [[maybe_unused]] WindowDWord* disposition, [[maybe_unused]] WindowError* windowError) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    const auto result = ::RegCreateKeyEx(key, subKey, 0, userDefinedClassType, EnumCastUnderlying(options), EnumCastUnderlying(samDesired), securityAttributes, keyResult, disposition);

    UnderlyingCastEnumPtr(result, windowError);

    if (result == EnumCastUnderlying(WindowError::Success))
        return true;
    else
        return false;
#else  // !WIN32
    return false;
#endif  // WIN32
}

bool System::RegistrySetValue([[maybe_unused]] SystemHKey key, [[maybe_unused]] const TChar* valueName, [[maybe_unused]] RegistryPredefinedValue registryValueTypes, [[maybe_unused]] const WindowByte* data, [[maybe_unused]] WindowDWord dataSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::RegSetValueEx(key, valueName, 0, EnumCastUnderlying(registryValueTypes), data, dataSize) == EnumCastUnderlying(WindowError::Success))
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::RegistryCloseKey([[maybe_unused]] SystemHKey key) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::RegCloseKey(key) == EnumCastUnderlying(WindowError::Success))
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::RegistryEnumKey([[maybe_unused]] SystemHKey key, [[maybe_unused]] WindowDWord index, [[maybe_unused]] TChar* name, [[maybe_unused]] WindowDWord* nameSize, [[maybe_unused]] TChar* className, [[maybe_unused]] WindowDWord* classNameSize, [[maybe_unused]] FileTimePtr lastWriteTime) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::RegEnumKeyEx(key, index, name, nameSize, nullptr, className, classNameSize, lastWriteTime) == EnumCastUnderlying(WindowError::Success))
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::RegistryOpenKey([[maybe_unused]] SystemHKey key, [[maybe_unused]] const TChar* subKey, [[maybe_unused]] RegistryOpenCreateOptions options, [[maybe_unused]] RegistrySpecificAccess samDesired, [[maybe_unused]] SystemHKey* keyResult) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::RegOpenKeyEx(key, subKey, EnumCastUnderlying(options), EnumCastUnderlying(samDesired), keyResult) == EnumCastUnderlying(WindowError::Success))
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::RegistryDeleteKey([[maybe_unused]] SystemHKey key, [[maybe_unused]] const TChar* subKey) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::RegDeleteKey(key, subKey) == EnumCastUnderlying(WindowError::Success))
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
