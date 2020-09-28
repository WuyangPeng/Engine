//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 15:26)

#ifndef SYSTEM_SECURITY_SECURITY_SID_H
#define SYSTEM_SECURITY_SECURITY_SID_H

#include "System/SystemDll.h"

#include "Using/SecuritySidUsing.h"
#include "System/Window/Using/WindowRegistryUsing.h"

namespace System
{
    // 安全标识符

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE InitializeSecurityIdentifier(SecuritySIDPtr sid, SecuritySIDIndentifierAuthorityPtr identifierAuthority, WindowByte subAuthorityCount) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE AllocateAndInitializeSecurityIdentifier(SecuritySIDIndentifierAuthorityPtr identifierAuthority, WindowByte subAuthorityCount, WindowDWord subAuthority0,
                                                                                      WindowDWord subAuthority1, WindowDWord subAuthority2, WindowDWord subAuthority3,
                                                                                      WindowDWord subAuthority4, WindowDWord subAuthority5, WindowDWord subAuthority6,
                                                                                      WindowDWord subAuthority7, SecuritySIDPtr* sid) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsSecurityIdentifierValid(SecuritySIDPtr sid) noexcept;
    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE FreeSecurityIdentifier(SecuritySIDPtr sid) noexcept;
    [[nodiscard]] WindowDWordPtr SYSTEM_DEFAULT_DECLARE GetSecurityIdentifierSubAuthority(SecuritySIDPtr sid, WindowDWord subAuthority) noexcept;
    [[nodiscard]] WindowUCharPtr SYSTEM_DEFAULT_DECLARE GetSecurityIdentifierSubAuthorityCount(SecuritySIDPtr sid) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CreateWellKnownSecurityIdentifier(SecurityWellKnownSidType wellKnownSidType, SecuritySIDPtr domainSid, SecuritySIDPtr sid, WindowDWord* sidCount) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsWellKnownSecurityIdentifier(SecuritySIDPtr sid, SecurityWellKnownSidType wellKnownSidType) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CopySecurityIdentifier(WindowDWord destinationSidLength, SecuritySIDPtr destinationSid, SecuritySIDPtr sourceSid) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE EqualDomainSecurityIdentifier(SecuritySIDPtr sid1, SecuritySIDPtr sid2, bool* equal) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE EqualPrefixSecurityIdentifier(SecuritySIDPtr sid1, SecuritySIDPtr sid2) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE EqualSecurityIdentifier(SecuritySIDPtr sid1, SecuritySIDPtr sid2) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetLengthSecurityIdentifier(SecuritySIDPtr sid) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSecurityIdentifierLengthRequired(WindowUChar subAuthorityCount) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_SID_H