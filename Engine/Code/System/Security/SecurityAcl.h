//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/24 15:25)

#ifndef SYSTEM_SECURITY_SECURITY_ACL_H
#define SYSTEM_SECURITY_SECURITY_ACL_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecuritySidUsing.h"

namespace System
{
    // ���ʿ����б�

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE InitializeAccessControlList(AccessCheckACLPtr acl, WindowDWord aclLength, AccessControlListRevision aclRevision) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsAccessControlListValid(AccessCheckACLPtr acl) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclSizeInformationPtr aclInformation) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_BASE_H