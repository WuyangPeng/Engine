// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:57)

#ifndef SYSTEM_SECURITY_CREATE_SECURITY_H
#define SYSTEM_SECURITY_CREATE_SECURITY_H

#include "System/SystemDll.h" 

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/CreateSecurityUsing.h"
#include "Using/LookupPrivilegeUsing.h" 
#include "System/Helper/UnicodeUsing.h"
#include "System/Com/Using/IUnknownUsing.h"
#include "System/FileManager/Using/FileUsing.h"
#include "System/Threading/Using/ThreadUsing.h"
#include "System/Threading/Using/ThreadToolsUsing.h"
#include "System/MemoryTools/Using/HeapToolsUsing.h"

namespace System
{
	// 创建安全句柄

	bool SYSTEM_DEFAULT_DECLARE	GetSystemFileSecurity(const String& fileName, SecurityRequestedInformation requestedInformation, SecurityDescriptorPtr securityDescriptor,
												      WindowDWord length, WindowDWordPtr lengthNeeded) noexcept;

	bool SYSTEM_DEFAULT_DECLARE	SetSystemFileSecurity(const TChar* fileName, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr securityDescriptor) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetSystemKernelObjectSecurity(ThreadHandle handle, SecurityRequestedInformation requestedInformation, SecurityDescriptorPtr securityDescriptor,
															  WindowDWord length, WindowDWordPtr lengthNeeded) noexcept;

	bool SYSTEM_DEFAULT_DECLARE	SetSystemKernelObjectSecurity(ThreadHandle handle, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr securityDescriptor) noexcept;

	bool SYSTEM_DEFAULT_DECLARE	CreateSystemPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr creatorDescriptor, SecurityDescriptorPtr* newDescriptor,
																  bool isDirectoryObject, WindowHandle token, AccessCheckGenericMappingPtr genericMapping) noexcept;
	bool SYSTEM_DEFAULT_DECLARE	CreateSystemPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr creatorDescriptor, SecurityDescriptorPtr* newDescriptor,
																  SystemGUID* objectType, bool isContainerObject, SecurityAutoInherit autoInheritFlags,
																  WindowHandle token, AccessCheckGenericMappingPtr genericMapping) noexcept;

	bool SYSTEM_DEFAULT_DECLARE	CreateSystemPrivateObjectSecurityWithMultipleInheritance(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr creatorDescriptor, SecurityDescriptorPtr* newDescriptor,
																					     SystemGUID** objectTypes, WindowULong guidCount, bool isContainerObject,
																						 SecurityAutoInherit autoInheritFlags, WindowHandle token, AccessCheckGenericMappingPtr genericMapping) noexcept;

	bool SYSTEM_DEFAULT_DECLARE	DestroySystemPrivateObjectSecurity(SecurityDescriptorPtr* objectDescriptor) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetSystemPrivateObjectSecurity(SecurityDescriptorPtr objectDescriptor, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr resultantDescriptor,
															   WindowDWord descriptorLength, WindowDWordPtr returnLength) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemPrivateObjectSecurity(SecurityRequestedInformation securityInformation, SecurityDescriptorPtr modificationDescriptor, SecurityDescriptorPtr* objectsSecurityDescriptor,
															   AccessCheckGenericMappingPtr genericMapping, WindowHandle token) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemPrivateObjectSecurity(SecurityRequestedInformation securityInformation, SecurityDescriptorPtr modificationDescriptor, SecurityDescriptorPtr* objectsSecurityDescriptor,
															   SecurityAutoInherit autoInheritFlags, AccessCheckGenericMappingPtr genericMapping, WindowHandle token) noexcept;

	bool SYSTEM_DEFAULT_DECLARE SystemConvertToAutoInheritPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr currentSecurityDescriptor, SecurityDescriptorPtr* newSecurityDescriptor,
																				SystemGUID* objectType, bool isDirectoryObject, AccessCheckGenericMappingPtr genericMapping) noexcept;

	void SYSTEM_DEFAULT_DECLARE SetSystemSecurityAccessMask(SecurityRequestedInformation securityInformation, WindowDWordPtr desiredAccess) noexcept;
}

#endif // SYSTEM_SECURITY_CREATE_SECURITY_H