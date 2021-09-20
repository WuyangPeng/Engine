///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/05/24 16:57)

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

    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsSystemTokenElevated() noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemTokenInformation(WindowsHandle handle,
                                                                    TokenInformationClass tokenInformationClass,
                                                                    WindowsVoidPtr tokenInformation,
                                                                    WindowsDWord tokenInformationLength,
                                                                    WindowsDWordPtr returnLength) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetAdjustTokenPrivileges(WindowsHandle tokenHandle,
                                                                   bool disableAllPrivileges,
                                                                   SecurityTokenPrivilegesPtr newState,
                                                                   WindowsDWord bufferLength,
                                                                   SecurityTokenPrivilegesPtr previousState,
                                                                   WindowsDWordPtr returnLength) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetAdjustTokenGroups(WindowsHandle tokenHandle,
                                                               bool resetToDefault,
                                                               SecurityTokenGroupsPtr newState,
                                                               WindowsDWord bufferLength,
                                                               SecurityTokenGroupsPtr previousState,
                                                               WindowsDWordPtr returnLength) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsAreAllAccessesGranted(AccessGenericMask grantedAccess, AccessGenericMask desiredAccess) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsAreAnyAccessesGranted(AccessGenericMask grantedAccess, AccessGenericMask desiredAccess) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE DuplicateSystemToken(WindowsHandle existingTokenHandle,
                                                               SecurityImpersonationLevel impersonationLevel,
                                                               WindowsHandlePtr duplicateTokenHandle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE DuplicateSystemToken(WindowsHandle existingTokenHandle,
                                                               TokenStandardAccess standardAccess,
                                                               TokenSpecificAccess specificAccess,
                                                               WindowSecurityAttributesPtr tokenAttributes,
                                                               SecurityImpersonationLevel impersonationLevel,
                                                               SecurityTokenType tokenType,
                                                               WindowsHandlePtr newToken) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CreateSystemRestrictedToken(WindowsHandle existingTokenHandle,
                                                                      SpecifiesAdditionalPrivilegeOptions flags,
                                                                      WindowsDWord disableSidCount,
                                                                      SecuritySidAndAttributesPtr sidsToDisable,
                                                                      WindowsDWord deletePrivilegeCount,
                                                                      LUIDAndAttributesPtr privilegesToDelete,
                                                                      WindowsDWord restrictedSidCount,
                                                                      SecuritySidAndAttributesPtr sidsToRestrict, WindowsHandlePtr newTokenHandle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsSystemTokenRestricted(WindowsHandle tokenHandle) noexcept;

    void SYSTEM_DEFAULT_DECLARE QuerySystemSecurityAccessMask(SecurityRequestedInformation securityInformation, WindowsDWordPtr desiredAccess) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_BASE_H