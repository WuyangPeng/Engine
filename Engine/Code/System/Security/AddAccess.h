///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 10:46)

#ifndef SYSTEM_SECURITY_AND_ACCESS_H
#define SYSTEM_SECURITY_AND_ACCESS_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/CreateSecurityUsing.h"
#include "Using/LookupPrivilegeUsing.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecurityDescriptorUsing.h"
#include "Using/SecuritySidUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // ��ӷ���Ȩ��

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessAllowedAccessControlEntries(AccessCheckACLPtr acl,
                                                                               AccessControlListRevision aceRevision,
                                                                               SpecificAccess accessMask,
                                                                               SecuritySIDPtr sid) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessAllowedAccessControlEntries(AccessCheckACLPtr acl,
                                                                               AccessControlListRevision aceRevision,
                                                                               ControlACEInheritance aceFlags,
                                                                               SpecificAccess accessMask,
                                                                               SecuritySIDPtr sid) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessAllowedObjectAccessControlEntries(AccessCheckACLPtr acl,
                                                                                     AccessControlListRevision aceRevision,
                                                                                     ControlACEInheritance aceFlags,
                                                                                     SpecificAccess accessMask,
                                                                                     SystemGUID* objectTypeGuid,
                                                                                     SystemGUID* inheritedObjectTypeGuid,
                                                                                     SecuritySIDPtr sid) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessDeniedAccessControlEntries(AccessCheckACLPtr acl,
                                                                              AccessControlListRevision aceRevision,
                                                                              SpecificAccess accessMask,
                                                                              SecuritySIDPtr sid) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessDeniedAccessControlEntries(AccessCheckACLPtr acl,
                                                                              AccessControlListRevision aceRevision,
                                                                              ControlACEInheritance aceFlags,
                                                                              SpecificAccess accessMask,
                                                                              SecuritySIDPtr sid) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessDeniedObjectAccessControlEntries(AccessCheckACLPtr acl,
                                                                                    AccessControlListRevision aceRevision,
                                                                                    ControlACEInheritance aceFlags,
                                                                                    SpecificAccess accessMask,
                                                                                    SystemGUID* objectTypeGuid,
                                                                                    SystemGUID* inheritedObjectTypeGuid,
                                                                                    SecuritySIDPtr sid) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAuditAccessAccessControlEntries(AccessCheckACLPtr acl,
                                                                             AccessControlListRevision aceRevision,
                                                                             SpecificAccess accessMask,
                                                                             SecuritySIDPtr sid,
                                                                             bool auditSuccess,
                                                                             bool auditFailure) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAuditAccessAccessControlEntries(AccessCheckACLPtr acl,
                                                                             AccessControlListRevision aceRevision,
                                                                             ControlACEInheritance aceFlags,
                                                                             SpecificAccess accessMask,
                                                                             SecuritySIDPtr sid,
                                                                             bool auditSuccess,
                                                                             bool auditFailure) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAuditAccessObjectAccessControlEntries(AccessCheckACLPtr acl,
                                                                                   AccessControlListRevision aceRevision,
                                                                                   ControlACEInheritance aceFlags,
                                                                                   SpecificAccess accessMask,
                                                                                   SystemGUID* objectTypeGuid,
                                                                                   SystemGUID* inheritedObjectTypeGuid,
                                                                                   SecuritySIDPtr sid,
                                                                                   bool auditSuccess,
                                                                                   bool auditFailure) noexcept;
}

#endif  // SYSTEM_SECURITY_ACCESS_CHECK_H