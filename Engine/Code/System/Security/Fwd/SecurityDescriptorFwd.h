// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:52)

#ifndef SYSTEM_SECURITY_SECURITY_DESCRIPTOR_FWD_H 
#define SYSTEM_SECURITY_SECURITY_DESCRIPTOR_FWD_H  

#include "SecurityFlagsFwd.h"
#include "System/Security/Using/SecurityDescriptorUsing.h" 

namespace System
{
	bool InitializeSystemSecurityDescriptor(SecurityDescriptorPtr securityDescriptor) noexcept;
	bool GetUserObjectSystemSecurity(ThreadHandle obj, SecurityRequestedInformation requested, SecurityDescriptorPtr securityDescriptor,
									 WindowDWord length, WindowDWordPtr lengthNeeded) noexcept;
	bool SetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor, SecurityDescriptorControlBits controlBitsOfInterest, SecurityDescriptorControlBits controlBitsToSet) noexcept;

	bool SetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor, bool daclPresent, AccessCheckACLPtr dacl, bool daclDefaulted) noexcept;
	bool SetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr group, bool groupDefaulted) noexcept;

	bool SetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr group, bool ownerDefaulted) noexcept;

	bool SetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor, WindowUCharPtr rmControl) noexcept;

	bool SetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor, bool saclPresent, AccessCheckACLPtr sacl, bool saclDefaulted) noexcept;

	bool GetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor, SecurityDescriptorControlBits* control, WindowDWordPtr revision) noexcept;

	bool GetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor, WindowBoolPtr daclPresent, AccessCheckACLPtr* dacl, bool* daclDefaulted) noexcept;

	bool GetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr* group, bool* groupDefaulted) noexcept;

	WindowDWord GetSystemSecurityDescriptorLength(SecurityDescriptorPtr securityDescriptor) noexcept;
	bool GetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr* owner, bool* ownerDefaulted) noexcept;

	bool GetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor, WindowUCharPtr rmControl) noexcept;

	bool GetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor, WindowBoolPtr saclPresent, AccessCheckACLPtr* sacl, bool* saclDefaulted) noexcept;

	bool IsSecurityDescriptorValid(SecurityDescriptorPtr securityDescriptor) noexcept;
}

#endif // SYSTEM_SECURITY_SECURITY_DESCRIPTOR_FWD_H