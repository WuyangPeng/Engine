// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:52)

#ifndef SYSTEM_SECURITY_SECURITY_ACL_FWD_H 
#define SYSTEM_SECURITY_SECURITY_ACL_FWD_H  

#include "SecurityFlagsFwd.h"
#include "System/Security/Using/SecurityAclUsing.h" 

namespace System
{
	bool GetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept;
	bool GetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclSizeInformationPtr aclInformation) noexcept;

	bool InitializeAccessControlList(AccessCheckACLPtr acl, WindowDWord aclLength, AccessControlListRevision aclRevision) noexcept;

	bool IsAccessControlListValid(AccessCheckACLPtr acl) noexcept;

	bool SetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept;
}

#endif // SYSTEM_SECURITY_SECURITY_ACL_FWD_H