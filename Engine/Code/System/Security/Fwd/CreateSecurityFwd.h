// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:52)

#ifndef SYSTEM_SECURITY_CREATE_SECURITY_FWD_H 
#define SYSTEM_SECURITY_CREATE_SECURITY_FWD_H  

#include "SecurityFlagsFwd.h"
#include "System/Com/Using/IUnknownUsing.h"
#include "System/Security/Using/CreateSecurityUsing.h"

namespace System
{
	bool GetSystemFileSecurity(const String& fileName, SecurityRequestedInformation requestedInformation, SecurityDescriptorPtr securityDescriptor,
							   WindowDWord length, WindowDWordPtr lengthNeeded) noexcept;

	bool SetSystemFileSecurity(const TChar* fileName, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr securityDescriptor) noexcept;

	bool SystemConvertToAutoInheritPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr currentSecurityDescriptor, SecurityDescriptorPtr* newSecurityDescriptor,
														 SystemGUID* objectType, bool isDirectoryObject, AccessCheckGenericMappingPtr genericMapping) noexcept;
	bool CreateSystemPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr creatorDescriptor, SecurityDescriptorPtr* newDescriptor,
										   bool isDirectoryObject, WindowHandle token, AccessCheckGenericMappingPtr genericMapping) noexcept;
	bool CreateSystemPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr creatorDescriptor, SecurityDescriptorPtr* newDescriptor, SystemGUID* objectType,
										   bool isContainerObject, SecurityAutoInherit autoInheritFlags, WindowHandle token, AccessCheckGenericMappingPtr genericMapping) noexcept;

	bool CreateSystemPrivateObjectSecurityWithMultipleInheritance(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr creatorDescriptor, SecurityDescriptorPtr* newDescriptor,
																  SystemGUID** objectTypes, WindowULong guidCount, bool isContainerObject,
																  SecurityAutoInherit autoInheritFlags, WindowHandle token, AccessCheckGenericMappingPtr genericMapping) noexcept;

	bool DestroySystemPrivateObjectSecurity(SecurityDescriptorPtr* objectDescriptor) noexcept;

	bool GetSystemKernelObjectSecurity(ThreadHandle handle, SecurityRequestedInformation requestedInformation, SecurityDescriptorPtr securityDescriptor,
									   WindowDWord length, WindowDWordPtr lengthNeeded) noexcept;
	bool GetSystemPrivateObjectSecurity(SecurityDescriptorPtr objectDescriptor, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr resultantDescriptor,
										WindowDWord descriptorLength, WindowDWordPtr returnLength) noexcept;

	bool SetSystemKernelObjectSecurity(ThreadHandle handle, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr securityDescriptor) noexcept;

	bool SetSystemPrivateObjectSecurity(SecurityRequestedInformation securityInformation, SecurityDescriptorPtr modificationDescriptor, SecurityDescriptorPtr* objectsSecurityDescriptor,
										AccessCheckGenericMappingPtr genericMapping, WindowHandle token) noexcept;
	bool SetSystemPrivateObjectSecurity(SecurityRequestedInformation securityInformation, SecurityDescriptorPtr modificationDescriptor, SecurityDescriptorPtr* objectsSecurityDescriptor,
										SecurityAutoInherit autoInheritFlags, AccessCheckGenericMappingPtr genericMapping, WindowHandle token) noexcept;

	void SetSystemSecurityAccessMask(SecurityRequestedInformation securityInformation, WindowDWordPtr desiredAccess) noexcept;
}

#endif // SYSTEM_SECURITY_CREATE_SECURITY_FWD_H