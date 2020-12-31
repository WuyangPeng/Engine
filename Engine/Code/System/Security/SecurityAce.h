//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 15:24)

#ifndef SYSTEM_SECURITY_SECURITY_ACE_H
#define SYSTEM_SECURITY_SECURITY_ACE_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecuritySidUsing.h"

namespace System
{
    // 访问控制项

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE AddAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, WindowDWord startingAceIndex,
                                                                      WindowVoidPtr aceList, WindowDWord aceListLength) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE AddMandatoryAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags,
                                                                               MandatoryPolicy mandatoryPolicy, SecuritySIDPtr labelSid) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE DeleteAccessControlEntries(AccessCheckACLPtr acl, WindowDWord aceIndex) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FindFirstFreeAccessControlEntries(AccessCheckACLPtr acl, WindowVoidPtr* ace) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetAccessControlEntries(AccessCheckACLPtr acl, WindowDWord aceIndex, WindowVoidPtr* ace) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_ACE_H