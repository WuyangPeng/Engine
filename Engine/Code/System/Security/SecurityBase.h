//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 15:25)

#ifndef SYSTEM_SECURITY_SECURITY_BASE_H
#define SYSTEM_SECURITY_SECURITY_BASE_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/AccessCheckUsing.h"
#include "Using/CreateSecurityUsing.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecurityBaseUsing.h"
#include "Using/SecuritySidUsing.h"
#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "System/Threading/Using/ThreadUsing.h"

namespace System
{
    // 安全基础

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemTokenInformation(WindowHandle handle, TokenInformationClass tokenInformationClass, WindowVoidPtr tokenInformation,
                                                                        WindowDWord tokenInformationLength, WindowDWordPtr returnLength) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetAdjustTokenPrivileges(WindowHandle tokenHandle, bool disableAllPrivileges, SecurityTokenPrivilegesPtr newState,
                                                                       WindowDWord bufferLength, SecurityTokenPrivilegesPtr previousState, WindowDWordPtr returnLength) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetAdjustTokenGroups(WindowHandle tokenHandle, bool resetToDefault, SecurityTokenGroupsPtr newState,
                                                                   WindowDWord bufferLength, SecurityTokenGroupsPtr previousState, WindowDWordPtr returnLength) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsAreAllAccessesGranted(AccessGenericMask grantedAccess, AccessGenericMask desiredAccess) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsAreAnyAccessesGranted(AccessGenericMask grantedAccess, AccessGenericMask desiredAccess) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE DuplicateSystemToken(WindowHandle existingTokenHandle, SecurityImpersonationLevel impersonationLevel, WindowHandlePtr duplicateTokenHandle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE DuplicateSystemToken(WindowHandle existingTokenHandle, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, WindowSecurityAttributesPtr tokenAttributes,
                                                                   SecurityImpersonationLevel impersonationLevel, SecurityTokenType tokenType, WindowHandlePtr newToken) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CreateSystemRestrictedToken(WindowHandle existingTokenHandle, SpecifiesAdditionalPrivilegeOptions flags, WindowDWord disableSidCount,
                                                                          SecuritySidAndAttributesPtr sidsToDisable, WindowDWord deletePrivilegeCount, LUIDAndAttributesPtr privilegesToDelete,
                                                                          WindowDWord restrictedSidCount, SecuritySidAndAttributesPtr sidsToRestrict, WindowHandlePtr newTokenHandle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsSystemTokenRestricted(WindowHandle tokenHandle) noexcept;

    [[nodiscard]] void SYSTEM_DEFAULT_DECLARE QuerySystemSecurityAccessMask(SecurityRequestedInformation securityInformation, WindowDWordPtr desiredAccess) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetAllocateLocallyUniqueID(LookupPrivilegeLUIDPtr luid) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CheckSystemTokenMembership(WindowHandle tokenHandle, SecuritySIDPtr sidToCheck, bool* isMember) noexcept;

    [[nodiscard]] SecuritySIDIndentifierAuthorityPtr SYSTEM_DEFAULT_DECLARE GetSecuritySidIdentifierAuthority(SecuritySIDPtr sid) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsImpersonateAnonymousToken(ThreadHandle threadHandle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsImpersonateLoggedOnUser(WindowHandle token) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsRevertToSelf() noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetPrivilegeCheck(WindowHandle clientToken, SecurityPrivilegeSetPtr requiredPrivileges, WindowBoolPtr result) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetMakeAbsoluteSD(SecurityDescriptorPtr selfRelativeSecurityDescriptor, SecurityDescriptorPtr absoluteSecurityDescriptor, WindowDWordPtr absoluteSecurityDescriptorSize,
                                                                AccessCheckACLPtr dacl, WindowDWordPtr daclSize, AccessCheckACLPtr sacl, WindowDWordPtr saclSize,
                                                                SecuritySIDPtr owner, WindowDWordPtr ownerSize, SecuritySIDPtr primaryGroup, WindowDWordPtr primaryGroupSize) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetMakeSelfRelativeSD(SecurityDescriptorPtr absoluteSecurityDescriptor, SecurityDescriptorPtr selfRelativeSecurityDescriptor, WindowDWordPtr bufferLength) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_BASE_H