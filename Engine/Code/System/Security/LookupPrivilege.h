/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 16:27)

#ifndef SYSTEM_SECURITY_LOOKUP_PRIVILEGE_H
#define SYSTEM_SECURITY_LOOKUP_PRIVILEGE_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/LookupPrivilegeUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// ����Ȩ��
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeValue(const TChar* systemName, const TChar* name, LookupPrivilegeLuidPtr luid) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeName(const TChar* systemName,
                                                                 LookupPrivilegeLuidPtr luid,
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