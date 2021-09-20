///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/05/24 16:56)

#ifndef SYSTEM_SECURITY_SECURITY_ACE_H
#define SYSTEM_SECURITY_SECURITY_ACE_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecuritySidUsing.h"

namespace System
{
    // 访问控制项

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