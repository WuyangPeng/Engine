// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:38)

#ifndef SYSTEM_WINDOW_WINDOW_REGISTRY_H
#define SYSTEM_WINDOW_WINDOW_REGISTRY_H

#include "System/SystemDll.h"

#include "Fwd/WindowFlagsFwd.h"
#include "Using/WindowRegistryUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/FileManager/Using/FileUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
	// ע���Ĵ�����ɾ�����޸ġ� 

	bool SYSTEM_DEFAULT_DECLARE RegistryCreateKey(SystemHKey key, const TChar* subKey, TChar* userDefinedClassType, RegistryOpenCreateOptions options, RegistrySpecificAccess samDesired,
												  WindowSecurityAttributesPtr securityAttributes, SystemHKey* keyResult, WindowDWord* disposition, WindowError* windowError = nullptr) noexcept;
	bool SYSTEM_DEFAULT_DECLARE RegistrySetValue(SystemHKey key, const TChar* valueName, RegistryPredefinedValue registryValueTypes, const WindowByte* data, WindowDWord dataSize) noexcept;

	bool SYSTEM_DEFAULT_DECLARE RegistryCloseKey(SystemHKey key) noexcept;

	bool SYSTEM_DEFAULT_DECLARE RegistryEnumKey(SystemHKey key, WindowDWord index, TChar* name, WindowDWord* nameSize,
												TChar* className, WindowDWord* classNameSize, FileTimePtr lastWriteTime) noexcept;

	bool SYSTEM_DEFAULT_DECLARE RegistryOpenKey(SystemHKey key, const TChar* subKey, RegistryOpenCreateOptions options, RegistrySpecificAccess samDesired, SystemHKey* keyResult) noexcept;

	bool SYSTEM_DEFAULT_DECLARE RegistryDeleteKey(SystemHKey key, const TChar* subKey) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_REGISTRY_H