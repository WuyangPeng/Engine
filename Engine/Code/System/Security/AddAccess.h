// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:57)

#ifndef SYSTEM_SECURITY_AND_ACCESS_H
#define SYSTEM_SECURITY_AND_ACCESS_H

#include "System/SystemDll.h"  

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/SecuritySidUsing.h"
#include "Using/SecurityAclUsing.h" 
#include "Using/CreateSecurityUsing.h"
#include "Using/LookupPrivilegeUsing.h"
#include "Using/SecurityDescriptorUsing.h"
#include "System/Com/Using/IUnknownUsing.h"

namespace System
{
	// 添加访问权限

	bool SYSTEM_DEFAULT_DECLARE	AddAccessAllowedAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, SpecificAccess accessMask, SecuritySIDPtr sid) noexcept;
	bool SYSTEM_DEFAULT_DECLARE	AddAccessAllowedAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags,
																	 SpecificAccess accessMask, SecuritySIDPtr sid) noexcept;
	bool SYSTEM_DEFAULT_DECLARE	AddAccessAllowedObjectAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags, SpecificAccess accessMask,
																		   SystemGUID* objectTypeGuid, SystemGUID* inheritedObjectTypeGuid, SecuritySIDPtr sid) noexcept;
	bool SYSTEM_DEFAULT_DECLARE AddAccessDeniedAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, SpecificAccess accessMask, SecuritySIDPtr sid) noexcept;
	bool SYSTEM_DEFAULT_DECLARE AddAccessDeniedAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags,
																    SpecificAccess accessMask, SecuritySIDPtr sid) noexcept;
	bool SYSTEM_DEFAULT_DECLARE AddAccessDeniedObjectAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags, SpecificAccess accessMask,
																		  SystemGUID* objectTypeGuid, SystemGUID* inheritedObjectTypeGuid, SecuritySIDPtr sid) noexcept;
	bool SYSTEM_DEFAULT_DECLARE AddAuditAccessAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, SpecificAccess accessMask,
																   SecuritySIDPtr sid, bool auditSuccess, bool auditFailure) noexcept;
	bool SYSTEM_DEFAULT_DECLARE AddAuditAccessAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags, SpecificAccess accessMask,
																   SecuritySIDPtr sid, bool auditSuccess, bool auditFailure) noexcept;
	bool SYSTEM_DEFAULT_DECLARE AddAuditAccessObjectAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags,
																		 SpecificAccess accessMask, SystemGUID* objectTypeGuid, SystemGUID* inheritedObjectTypeGuid,
																		 SecuritySIDPtr sid, bool auditSuccess, bool auditFailure) noexcept;
}

#endif // SYSTEM_SECURITY_ACCESS_CHECK_H