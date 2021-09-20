///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.3 (2021/05/24 16:56)

#ifndef SYSTEM_SECURITY_SECURITY_ACE_H
#define SYSTEM_SECURITY_SECURITY_ACE_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecuritySidUsing.h"

namespace System
{
    // ���ʿ�����

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessControlEntries(AccessCheckACLPtr acl,
                                                                  AccessControlListRevision aceRevision,
                                                                  WindowsDWord startingAceIndex,
                                                                  WindowsVoidPtr aceList,
                                                                  WindowsDWord aceListLength) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE DeleteAccessControlEntries(AccessCheckACLPtr acl, WindowsDWord aceIndex) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FindFirstFreeAccessControlEntries(AccessCheckACLPtr acl, WindowsVoidPtr* ace) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetAccessControlEntries(AccessCheckACLPtr acl, WindowsDWord aceIndex, WindowsVoidPtr* ace) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddMandatoryAccessControlEntries(AccessCheckACLPtr acl,
                                                                           AccessControlListRevision aceRevision,
                                                                           ControlACEInheritance aceFlags,
                                                                           MandatoryPolicy mandatoryPolicy,
                                                                           SecuritySIDPtr labelSid) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_ACE_H