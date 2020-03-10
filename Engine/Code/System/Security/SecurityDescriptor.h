// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.0 (2020/01/02 15:58)

#ifndef SYSTEM_SECURITY_SECURITY_DESCRIPTOR_H
#define SYSTEM_SECURITY_SECURITY_DESCRIPTOR_H

#include "System/SystemDll.h" 

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/SecuritySidUsing.h"
#include "Using/SecurityAclUsing.h" 
#include "Using/CreateSecurityUsing.h"
#include "Using/SecurityDescriptorUsing.h"
#include "System/Threading/Using/ThreadUsing.h"

namespace System
{
	// °²È«ÃèÊö·û

	bool SYSTEM_DEFAULT_DECLARE	GetUserObjectSystemSecurity(ThreadHandle obj, SecurityRequestedInformation requested, SecurityDescriptorPtr securityDescriptor,
															WindowDWord length, WindowDWordPtr lengthNeeded) noexcept;

	bool SYSTEM_DEFAULT_DECLARE InitializeSystemSecurityDescriptor(SecurityDescriptorPtr securityDescriptor) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor, bool daclPresent, AccessCheckACLPtr dacl, bool daclDefaulted) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor, WindowBoolPtr daclPresent, AccessCheckACLPtr* dacl, bool* daclDefaulted) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorLength(SecurityDescriptorPtr securityDescriptor) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsSecurityDescriptorValid(SecurityDescriptorPtr securityDescriptor) noexcept;

	bool SYSTEM_DEFAULT_DECLARE SetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor, SecurityDescriptorControlBits controlBitsOfInterest, SecurityDescriptorControlBits controlBitsToSet) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor, SecurityDescriptorControlBits* control, WindowDWordPtr revision) noexcept;

	bool SYSTEM_DEFAULT_DECLARE SetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr group, bool groupDefaulted) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr* group, bool* groupDefaulted) noexcept;

	bool SYSTEM_DEFAULT_DECLARE SetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr group, bool ownerDefaulted) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr* owner, bool* ownerDefaulted) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor, WindowUCharPtr rmControl) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor, WindowUCharPtr rmControl) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor, bool saclPresent, AccessCheckACLPtr sacl, bool saclDefaulted) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor, WindowBoolPtr saclPresent, AccessCheckACLPtr* sacl, bool* saclDefaulted) noexcept;
}

#endif // SYSTEM_SECURITY_SECURITY_DESCRIPTOR_H