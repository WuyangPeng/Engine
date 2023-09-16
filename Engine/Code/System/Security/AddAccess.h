///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/30 15:11)

#ifndef SYSTEM_SECURITY_AND_ACCESS_H
#define SYSTEM_SECURITY_AND_ACCESS_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecuritySidUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// ��ӷ���Ȩ��
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessAllowedAccessControlEntries(AccessCheckAclPtr acl,
                                                                               AccessControlListRevision aceRevision,
                                                                               SpecificAccess accessMask,
                                                                               SecuritySidPtr sid) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessAllowedAccessControlEntries(AccessCheckAclPtr acl,
                                                                               AccessControlListRevision aceRevision,
                                                                               ControlAceInheritance aceFlags,
                                                                               SpecificAccess accessMask,
                                                                               SecuritySidPtr sid) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessAllowedObjectAccessControlEntries(AccessCheckAclPtr acl,
                                                                                     AccessControlListRevision aceRevision,
                                                                                     ControlAceInheritance aceFlags,
                                                                                     SpecificAccess accessMask,
                                                                                     SystemGloballyUniqueIdentifier* objectTypeGuid,
                                                                                     SystemGloballyUniqueIdentifier* inheritedObjectTypeGuid,
                                                                                     SecuritySidPtr sid) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessDeniedAccessControlEntries(AccessCheckAclPtr acl,
                                                                              AccessControlListRevision aceRevision,
                                                                              SpecificAccess accessMask,
                                                                              SecuritySidPtr sid) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessDeniedAccessControlEntries(AccessCheckAclPtr acl,
                                                                              AccessControlListRevision aceRevision,
                                                                              ControlAceInheritance aceFlags,
                                                                              SpecificAccess accessMask,
                                                                              SecuritySidPtr sid) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAccessDeniedObjectAccessControlEntries(AccessCheckAclPtr acl,
                                                                                    AccessControlListRevision aceRevision,
                                                                                    ControlAceInheritance aceFlags,
                                                                                    SpecificAccess accessMask,
                                                                                    SystemGloballyUniqueIdentifier* objectTypeGuid,
                                                                                    SystemGloballyUniqueIdentifier* inheritedObjectTypeGuid,
                                                                                    SecuritySidPtr sid) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAuditAccessAccessControlEntries(AccessCheckAclPtr acl,
                                                                             AccessControlListRevision aceRevision,
                                                                             SpecificAccess accessMask,
                                                                             SecuritySidPtr sid,
                                                                             bool auditSuccess,
                                                                             bool auditFailure) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAuditAccessAccessControlEntries(AccessCheckAclPtr acl,
                                                                             AccessControlListRevision aceRevision,
                                                                             ControlAceInheritance aceFlags,
                                                                             SpecificAccess accessMask,
                                                                             SecuritySidPtr sid,
                                                                             bool auditSuccess,
                                                                             bool auditFailure) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AddAuditAccessObjectAccessControlEntries(AccessCheckAclPtr acl,
                                                                                   AccessControlListRevision aceRevision,
                                                                                   ControlAceInheritance aceFlags,
                                                                                   SpecificAccess accessMask,
                                                                                   SystemGloballyUniqueIdentifier* objectTypeGuid,
                                                                                   SystemGloballyUniqueIdentifier* inheritedObjectTypeGuid,
                                                                                   SecuritySidPtr sid,
                                                                                   bool auditSuccess,
                                                                                   bool auditFailure) noexcept;
}

#endif  // SYSTEM_SECURITY_ACCESS_CHECK_H