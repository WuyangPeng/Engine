// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:36)

#ifndef SYSTEM_WINDOW_WINDOW_REGISTRY_FWD_H 
#define SYSTEM_WINDOW_WINDOW_REGISTRY_FWD_H  

#include "WindowFlagsFwd.h"
#include "System/FileManager/Using/FileUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"
#include "System/Window/Using/WindowRegistryUsing.h"

namespace System
{
	bool RegistryCreateKey(SystemHKey key, const TChar* subKey, TChar* userDefinedClassType, RegistryOpenCreateOptions options, RegistrySpecificAccess samDesired,
						   WindowSecurityAttributesPtr securityAttributes, SystemHKey* keyResult, WindowDWord* disposition, WindowError* windowError = nullptr) noexcept;

	bool RegistrySetValue(SystemHKey key, const TChar* valueName, RegistryPredefinedValue registryValueTypes, const WindowByte* data, WindowDWord dataSize) noexcept;

	bool RegistryCloseKey(SystemHKey key) noexcept;

	bool RegistryEnumKey(SystemHKey key, WindowDWord index, TChar* name, WindowDWord* nameSize, TChar* className, WindowDWord* classNameSize, FileTimePtr lastWriteTime) noexcept;

	bool RegistryOpenKey(SystemHKey key, const TChar* subKey, RegistryOpenCreateOptions options, RegistrySpecificAccess samDesired, SystemHKey* keyResult) noexcept;

	bool RegistryDeleteKey(SystemHKey key, const TChar* subKey) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_REGISTRY_FWD_H