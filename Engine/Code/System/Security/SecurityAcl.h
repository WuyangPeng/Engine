// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 15:57)

#ifndef SYSTEM_SECURITY_SECURITY_ACL_H
#define SYSTEM_SECURITY_SECURITY_ACL_H

#include "System/SystemDll.h" 

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecuritySidUsing.h"  

namespace System
{
	// ���ʿ����б�

	bool SYSTEM_DEFAULT_DECLARE InitializeAccessControlList(AccessCheckACLPtr acl, WindowDWord aclLength, AccessControlListRevision aclRevision) noexcept;

	bool SYSTEM_DEFAULT_DECLARE IsAccessControlListValid(AccessCheckACLPtr acl) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclSizeInformationPtr aclInformation) noexcept;

	bool SYSTEM_DEFAULT_DECLARE SetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept;
}

#endif // SYSTEM_SECURITY_SECURITY_BASE_H