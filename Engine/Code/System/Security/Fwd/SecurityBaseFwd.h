// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:52)

#ifndef SYSTEM_SECURITY_SECURITY_BASE_FWD_H 
#define SYSTEM_SECURITY_SECURITY_BASE_FWD_H  

#include "SecurityFlagsFwd.h"
#include "System/Security/Using/SecurityBaseUsing.h" 

namespace System
{
	bool GetSystemTokenInformation(WindowHandle handle, TokenInformationClass tokenInformationClass, WindowVoidPtr tokenInformation,
								   WindowDWord tokenInformationLength, WindowDWordPtr returnLength) noexcept;

	bool GetAdjustTokenGroups(WindowHandle tokenHandle, bool resetToDefault, SecurityTokenGroupsPtr newState,
							  WindowDWord bufferLength, SecurityTokenGroupsPtr previousState, WindowDWordPtr returnLength) noexcept;
	bool GetAdjustTokenPrivileges(WindowHandle tokenHandle, bool disableAllPrivileges, SecurityTokenPrivilegesPtr newState,
								  WindowDWord bufferLength, SecurityTokenPrivilegesPtr previousState, WindowDWordPtr returnLength) noexcept;

	bool GetAllocateLocallyUniqueID(LookupPrivilegeLUIDPtr luid) noexcept;
	bool IsAreAllAccessesGranted(AccessGenericMask grantedAccess, AccessGenericMask desiredAccess) noexcept;
	bool IsAreAnyAccessesGranted(AccessGenericMask grantedAccess, AccessGenericMask desiredAccess) noexcept;
	bool CheckSystemTokenMembership(WindowHandle tokenHandle, SecuritySIDPtr sidToCheck, bool* isMember) noexcept;

	bool CreateSystemRestrictedToken(WindowHandle existingTokenHandle, SpecifiesAdditionalPrivilegeOptions flags, WindowDWord disableSidCount,
									 SecuritySidAndAttributesPtr sidsToDisable, WindowDWord deletePrivilegeCount, LUIDAndAttributesPtr privilegesToDelete,
									 WindowDWord restrictedSidCount, SecuritySidAndAttributesPtr sidsToRestrict, WindowHandlePtr newTokenHandle) noexcept;

	bool DuplicateSystemToken(WindowHandle existingTokenHandle, SecurityImpersonationLevel impersonationLevel, WindowHandlePtr duplicateTokenHandle) noexcept;
	bool DuplicateSystemToken(WindowHandle existingTokenHandle, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, WindowSecurityAttributesPtr tokenAttributes,
							  SecurityImpersonationLevel impersonationLevel, SecurityTokenType tokenType, WindowHandlePtr newToken) noexcept;

	SecuritySIDIndentifierAuthorityPtr GetSecuritySidIdentifierAuthority(SecuritySIDPtr sid) noexcept;

	bool IsImpersonateAnonymousToken(ThreadHandle threadHandle) noexcept;
	bool IsImpersonateLoggedOnUser(WindowHandle token) noexcept;

	bool IsSystemTokenRestricted(WindowHandle tokenHandle) noexcept;

	bool GetMakeAbsoluteSD(SecurityDescriptorPtr selfRelativeSecurityDescriptor, SecurityDescriptorPtr absoluteSecurityDescriptor, WindowDWordPtr absoluteSecurityDescriptorSize, AccessCheckACLPtr dacl,
						   WindowDWordPtr daclSize, AccessCheckACLPtr sacl, WindowDWordPtr saclSize, SecuritySIDPtr owner,
						   WindowDWordPtr ownerSize, SecuritySIDPtr primaryGroup, WindowDWordPtr primaryGroupSize) noexcept;

	bool GetMakeSelfRelativeSD(SecurityDescriptorPtr absoluteSecurityDescriptor, SecurityDescriptorPtr selfRelativeSecurityDescriptor, WindowDWordPtr bufferLength) noexcept;

	bool GetPrivilegeCheck(WindowHandle clientToken, SecurityPrivilegeSetPtr requiredPrivileges, WindowBoolPtr result) noexcept;

	void QuerySystemSecurityAccessMask(SecurityRequestedInformation securityInformation, WindowDWordPtr desiredAccess) noexcept;
	bool IsRevertToSelf() noexcept;
}

#endif // SYSTEM_SECURITY_SECURITY_BASE_FWD_H