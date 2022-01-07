///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 10:47)

#ifndef SYSTEM_SECURITY_SECURITY_ACL_H
#define SYSTEM_SECURITY_SECURITY_ACL_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecuritySidUsing.h"

namespace System
{
    // 访问控制列表

    NODISCARD bool SYSTEM_DEFAULT_DECLARE InitializeAccessControlList(AccessCheckACLPtr acl, WindowsDWord aclLength, AccessControlListRevision aclRevision) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsAccessControlListValid(AccessCheckACLPtr acl) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclSizeInformationPtr aclInformation) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_BASE_H