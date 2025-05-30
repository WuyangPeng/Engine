/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:41)

#ifndef SYSTEM_SECURITY_LOOKUP_PRIVILEGE_H
#define SYSTEM_SECURITY_LOOKUP_PRIVILEGE_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/LookupPrivilegeUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

/// 查找权限
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeValue(const TChar* systemName, const TChar* name, LookupPrivilegeLocallyUniqueIdentifierPtr locallyUniqueIdentifier) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeName(const TChar* systemName,
                                                                 LookupPrivilegeLocallyUniqueIdentifierPtr locallyUniqueIdentifier,
                                                                 TChar* name,
                                                                 WindowsDWordPtr nameSize) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeDisplayName(const TChar* systemName,
                                                                        const TChar* name,
                                                                        TChar* displayName,
                                                                        WindowsDWordPtr displayNameSize,
                                                                        WindowsDWordPtr languageId) noexcept;

    NODISCARD String SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription lookupPrivilegeName);
}

#endif  // SYSTEM_SECURITY_LOOKUP_PRIVILEGE_H