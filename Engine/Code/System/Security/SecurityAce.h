// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:57)

#ifndef SYSTEM_SECURITY_SECURITY_ACE_H
#define SYSTEM_SECURITY_SECURITY_ACE_H

#include "System/SystemDll.h" 

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecuritySidUsing.h"  

namespace System
{
	// 访问控制项

	bool SYSTEM_DEFAULT_DECLARE AddAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, WindowDWord startingAceIndex,
														WindowVoidPtr aceList, WindowDWord aceListLength) noexcept;

	bool SYSTEM_DEFAULT_DECLARE AddMandatoryAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags,
																 MandatoryPolicy mandatoryPolicy, SecuritySIDPtr labelSid) noexcept;

	bool SYSTEM_DEFAULT_DECLARE DeleteAccessControlEntries(AccessCheckACLPtr acl, WindowDWord aceIndex) noexcept;
	bool SYSTEM_DEFAULT_DECLARE FindFirstFreeAccessControlEntries(AccessCheckACLPtr acl, WindowVoidPtr* ace) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetAccessControlEntries(AccessCheckACLPtr acl, WindowDWord aceIndex, WindowVoidPtr* ace) noexcept;
}

#endif // SYSTEM_SECURITY_SECURITY_ACE_H