//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 11:38)

#ifndef SYSTEM_WINDOW_WINDOW_REGISTRY_H
#define SYSTEM_WINDOW_WINDOW_REGISTRY_H

#include "System/SystemDll.h"

#include "Fwd/WindowFlagsFwd.h"
#include "Using/WindowRegistryUsing.h"
#include "System/FileManager/Using/FileUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // 注册表的创建、删除和修改。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE RegistryCreateKey(SystemHKey key, const TChar* subKey, TChar* userDefinedClassType, RegistryOpenCreateOptions options, RegistrySpecificAccess samDesired,
                                                                WindowSecurityAttributesPtr securityAttributes, SystemHKey* keyResult, WindowDWord* disposition, WindowError* windowError = nullptr) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE RegistrySetValue(SystemHKey key, const TChar* valueName, RegistryPredefinedValue registryValueTypes, const WindowByte* data, WindowDWord dataSize) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE RegistryCloseKey(SystemHKey key) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE RegistryEnumKey(SystemHKey key, WindowDWord index, TChar* name, WindowDWord* nameSize,
                                                              TChar* className, WindowDWord* classNameSize, FileTimePtr lastWriteTime) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE RegistryOpenKey(SystemHKey key, const TChar* subKey, RegistryOpenCreateOptions options, RegistrySpecificAccess samDesired, SystemHKey* keyResult) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE RegistryDeleteKey(SystemHKey key, const TChar* subKey) noexcept;
}

#endif  // SYSTEM_WINDOW_WINDOW_REGISTRY_H