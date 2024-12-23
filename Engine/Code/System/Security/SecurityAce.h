/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 17:41)

#ifndef SYSTEM_SECURITY_SECURITY_ACE_H
#define SYSTEM_SECURITY_SECURITY_ACE_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecuritySidUsing.h"

/// ���ʿ�����
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessControlEntries(AccessCheckAclPtr acl,
                                                                  AccessControlListRevision aceRevision,
                                                                  WindowsDWord startingAceIndex,
                                                                  WindowsVoidPtr aceList,
                                                                  WindowsDWord aceListLength) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE DeleteAccessControlEntries(AccessCheckAclPtr acl, WindowsDWord aceIndex) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FindFirstFreeAccessControlEntries(AccessCheckAclPtr acl, WindowsVoidPtr* ace) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetAccessControlEntries(AccessCheckAclPtr acl, WindowsDWord aceIndex, WindowsVoidPtr* ace) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddMandatoryAccessControlEntries(AccessCheckAclPtr acl,
                                                                           AccessControlListRevision aceRevision,
                                                                           ControlAceInheritance aceFlags,
                                                                           MandatoryPolicy mandatoryPolicy,
                                                                           SecuritySidPtr labelSid) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_ACE_H