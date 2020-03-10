// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:39)

#include "System/SystemExport.h"

#include "WindowRegistry.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"
#include "System/Window/Flags/PlatformErrorFlags.h"

bool System
	::RegistryCreateKey(SystemHKey key, const TChar* subKey, TChar* userDefinedClassType, RegistryOpenCreateOptions  options, RegistrySpecificAccess samDesired,
						WindowSecurityAttributesPtr securityAttributes, SystemHKey* keyResult, WindowDWord* disposition, WindowError* windowError) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	const auto result = ::RegCreateKeyEx(key, subKey, 0, userDefinedClassType, EnumCastUnderlying(options), EnumCastUnderlying(samDesired), securityAttributes, keyResult, disposition);

	UnderlyingCastEnumPtr(result, windowError);

	if (result == EnumCastUnderlying(WindowError::Success))
		return true;
	else
		return false;
#else // !WIN32
	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(subKey);
	SYSTEM_UNUSED_ARG(userDefinedClassType);
	SYSTEM_UNUSED_ARG(options);
	SYSTEM_UNUSED_ARG(samDesired);
	SYSTEM_UNUSED_ARG(securityAttributes);
	SYSTEM_UNUSED_ARG(keyResult);
	SYSTEM_UNUSED_ARG(disposition);

	return false;
#endif // WIN32
}

bool System
	::RegistrySetValue(SystemHKey key, const TChar* valueName, RegistryPredefinedValue registryValueTypes, const WindowByte* data, WindowDWord dataSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::RegSetValueEx(key, valueName, 0, EnumCastUnderlying(registryValueTypes), data, dataSize) == EnumCastUnderlying(WindowError::Success))
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(valueName);
	SYSTEM_UNUSED_ARG(registryValueTypes);
	SYSTEM_UNUSED_ARG(data);
	SYSTEM_UNUSED_ARG(dataSize);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::RegistryCloseKey(SystemHKey key) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::RegCloseKey(key) == EnumCastUnderlying(WindowError::Success))
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(key);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::RegistryEnumKey(SystemHKey key, WindowDWord index, TChar* name, WindowDWord* nameSize, TChar* className, WindowDWord* classNameSize, FileTimePtr lastWriteTime) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::RegEnumKeyEx(key, index, name, nameSize, nullptr, className, classNameSize, lastWriteTime) == EnumCastUnderlying(WindowError::Success))
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(index);
	SYSTEM_UNUSED_ARG(name);
	SYSTEM_UNUSED_ARG(nameSize);
	SYSTEM_UNUSED_ARG(className);
	SYSTEM_UNUSED_ARG(classNameSize);
	SYSTEM_UNUSED_ARG(lastWriteTime);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::RegistryOpenKey(SystemHKey key, const TChar* subKey, RegistryOpenCreateOptions options, RegistrySpecificAccess samDesired, SystemHKey* keyResult) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::RegOpenKeyEx(key, subKey, EnumCastUnderlying(options), EnumCastUnderlying(samDesired), keyResult) == EnumCastUnderlying(WindowError::Success))
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(subKey);
	SYSTEM_UNUSED_ARG(options);
	SYSTEM_UNUSED_ARG(samDesired);
	SYSTEM_UNUSED_ARG(keyResult);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::RegistryDeleteKey(SystemHKey key, const TChar* subKey) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::RegDeleteKey(key, subKey) == EnumCastUnderlying(WindowError::Success))
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(subKey);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
