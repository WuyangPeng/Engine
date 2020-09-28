//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/24 15:24)

#ifndef SYSTEM_SECURITY_LOOKUP_PRIVILEGE__H
#define SYSTEM_SECURITY_LOOKUP_PRIVILEGE__H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/LookupPrivilegeUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // ����Ȩ��

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeValue(const TChar* systemName, const TChar* name, LookupPrivilegeLUIDPtr luid) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeName(const TChar* systemName, LookupPrivilegeLUIDPtr luid, TChar* name, WindowDWordPtr nameSize) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeDisplayName(const TChar* systemName, const TChar* name, TChar* displayName, WindowDWordPtr displayNameSize, WindowDWordPtr languageID) noexcept;

    [[nodiscard]] String SYSTEM_DEFAULT_DECLARE GetLookupPrivilegeNameDescription(LookupPrivilegeNameDescription lookupPrivilegeName);
}

#endif  // SYSTEM_SECURITY_LOOKUP_PRIVILEGE__H