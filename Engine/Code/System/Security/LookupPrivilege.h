///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:52)

#ifndef SYSTEM_SECURITY_LOOKUP_PRIVILEGE_H
#define SYSTEM_SECURITY_LOOKUP_PRIVILEGE_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/LookupPrivilegeUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // 查找权限

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeValue(const TChar* systemName, const TChar* name, LookupPrivilegeLUIDPtr luid) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeName(const TChar* systemName,
                                                                 LookupPrivilegeLUIDPtr luid,
                                                                 TChar* name,
                                                                 WindowsDWordPtr nameSize) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeDisplayName(const TChar* systemName,
                                                                        const TChar* name,
                                                                        TChar* displayName,
                                                                        WindowsDWordPtr displayNameSize,
                                                                        WindowsDWordPtr languageID) noexcept;

    NODISCARD String SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription lookupPrivilegeName);
}

#endif  // SYSTEM_SECURITY_LOOKUP_PRIVILEGE_H