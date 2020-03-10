// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.0 (2020/01/02 15:58)

#ifndef SYSTEM_SECURITY_SECURITY_BASE_H
#define SYSTEM_SECURITY_SECURITY_BASE_H

#include "System/SystemDll.h" 

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/SecuritySidUsing.h"
#include "Using/AccessCheckUsing.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecurityBaseUsing.h"
#include "Using/CreateSecurityUsing.h"
#include "System/Threading/Using/ThreadUsing.h"
#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"

namespace System
{
	// °²È«»ù´¡

	bool SYSTEM_DEFAULT_DECLARE GetSystemTokenInformation(WindowHandle handle, TokenInformationClass tokenInformationClass, WindowVoidPtr tokenInformation,
														  WindowDWord tokenInformationLength, WindowDWordPtr returnLength) noexcept;

	bool SYSTEM_DEFAULT_DECLARE	GetAdjustTokenPrivileges(WindowHandle tokenHandle, bool disableAllPrivileges, SecurityTokenPrivilegesPtr newState,
														 WindowDWord bufferLength, SecurityTokenPrivilegesPtr previousState, WindowDWordPtr returnLength) noexcept;
	bool SYSTEM_DEFAULT_DECLARE	GetAdjustTokenGroups(WindowHandle tokenHandle, bool resetToDefault, SecurityTokenGroupsPtr newState,
													 WindowDWord bufferLength, SecurityTokenGroupsPtr previousState, WindowDWordPtr returnLength) noexcept;

	bool SYSTEM_DEFAULT_DECLARE	IsAreAllAccessesGranted(AccessGenericMask grantedAccess, AccessGenericMask desiredAccess) noexcept;
	bool SYSTEM_DEFAULT_DECLARE	IsAreAnyAccessesGranted(AccessGenericMask grantedAccess, AccessGenericMask desiredAccess) noexcept;

	bool SYSTEM_DEFAULT_DECLARE DuplicateSystemToken(WindowHandle existingTokenHandle, SecurityImpersonationLevel impersonationLevel, WindowHandlePtr duplicateTokenHandle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE DuplicateSystemToken(WindowHandle existingTokenHandle, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, WindowSecurityAttributesPtr tokenAttributes,
													 SecurityImpersonationLevel impersonationLevel, SecurityTokenType tokenType, WindowHandlePtr newToken) noexcept;

	bool SYSTEM_DEFAULT_DECLARE	CreateSystemRestrictedToken(WindowHandle existingTokenHandle, SpecifiesAdditionalPrivilegeOptions flags, WindowDWord disableSidCount,
															SecuritySidAndAttributesPtr sidsToDisable, WindowDWord deletePrivilegeCount, LUIDAndAttributesPtr privilegesToDelete,
															WindowDWord restrictedSidCount, SecuritySidAndAttributesPtr sidsToRestrict, WindowHandlePtr newTokenHandle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsSystemTokenRestricted(WindowHandle tokenHandle) noexcept;

	void SYSTEM_DEFAULT_DECLARE	QuerySystemSecurityAccessMask(SecurityRequestedInformation securityInformation, WindowDWordPtr desiredAccess) noexcept;

	bool SYSTEM_DEFAULT_DECLARE	GetAllocateLocallyUniqueID(LookupPrivilegeLUIDPtr luid) noexcept;
	bool SYSTEM_DEFAULT_DECLARE	CheckSystemTokenMembership(WindowHandle tokenHandle, SecuritySIDPtr sidToCheck, bool* isMember) noexcept;

	SecuritySIDIndentifierAuthorityPtr SYSTEM_DEFAULT_DECLARE  GetSecuritySidIdentifierAuthority(SecuritySIDPtr sid) noexcept;

	bool SYSTEM_DEFAULT_DECLARE IsImpersonateAnonymousToken(ThreadHandle threadHandle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsImpersonateLoggedOnUser(WindowHandle token) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsRevertToSelf() noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetPrivilegeCheck(WindowHandle clientToken, SecurityPrivilegeSetPtr requiredPrivileges, WindowBoolPtr result) noexcept;

	bool SYSTEM_DEFAULT_DECLARE	GetMakeAbsoluteSD(SecurityDescriptorPtr selfRelativeSecurityDescriptor, SecurityDescriptorPtr absoluteSecurityDescriptor, WindowDWordPtr absoluteSecurityDescriptorSize,
												  AccessCheckACLPtr dacl, WindowDWordPtr daclSize, AccessCheckACLPtr sacl, WindowDWordPtr saclSize,
												  SecuritySIDPtr owner, WindowDWordPtr ownerSize, SecuritySIDPtr primaryGroup, WindowDWordPtr primaryGroupSize) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetMakeSelfRelativeSD(SecurityDescriptorPtr absoluteSecurityDescriptor, SecurityDescriptorPtr selfRelativeSecurityDescriptor, WindowDWordPtr bufferLength) noexcept;
}

#endif // SYSTEM_SECURITY_SECURITY_BASE_H