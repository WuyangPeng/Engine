/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 10:47)

#ifndef SYSTEM_SECURITY_SECURITY_ACL_H
#define SYSTEM_SECURITY_SECURITY_ACL_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecuritySidUsing.h"

/// 访问控制列表
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE InitializeAccessControlList(AccessCheckAclPtr acl, WindowsDWord aclLength, AccessControlListRevision aclRevision) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsAccessControlListValid(AccessCheckAclPtr acl) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetAccessControlListInformation(AccessCheckAclPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetAccessControlListInformation(AccessCheckAclPtr acl, SecurityAclSizeInformationPtr aclInformation) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetAccessControlListInformation(AccessCheckAclPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_BASE_H