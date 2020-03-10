// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:52)

#ifndef SYSTEM_SECURITY_SECURITY_ACE_FWD_H 
#define SYSTEM_SECURITY_SECURITY_ACE_FWD_H  

#include "SecurityFlagsFwd.h"
#include "System/Security/Using/SecurityAclUsing.h" 

namespace System
{
	bool AddAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, WindowDWord startingAceIndex,
								 WindowVoidPtr aceList, WindowDWord aceListLength) noexcept;

	bool AddMandatoryAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags,
										  MandatoryPolicy mandatoryPolicy, SecuritySIDPtr labelSid) noexcept;

	bool DeleteAccessControlEntries(AccessCheckACLPtr acl, WindowDWord aceIndex) noexcept;
	bool FindFirstFreeAccessControlEntries(AccessCheckACLPtr acl, WindowVoidPtr* ace) noexcept;

	bool GetAccessControlEntries(AccessCheckACLPtr acl, WindowDWord aceIndex, WindowVoidPtr* ace) noexcept;
}

#endif // SYSTEM_SECURITY_SECURITY_ACE_FWD_H