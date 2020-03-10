// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 15:58)

#ifndef SYSTEM_SECURITY_SECURITY_SID_H
#define SYSTEM_SECURITY_SECURITY_SID_H

#include "System/SystemDll.h" 

#include "Using/SecuritySidUsing.h" 
#include "System/Window/Using/WindowRegistryUsing.h"

namespace System
{
	// 安全标识符

	bool SYSTEM_DEFAULT_DECLARE InitializeSecurityIdentifier(SecuritySIDPtr sid, SecuritySIDIndentifierAuthorityPtr identifierAuthority, WindowByte subAuthorityCount) noexcept;
	bool SYSTEM_DEFAULT_DECLARE	AllocateAndInitializeSecurityIdentifier(SecuritySIDIndentifierAuthorityPtr identifierAuthority, WindowByte subAuthorityCount, WindowDWord subAuthority0,
																	    WindowDWord subAuthority1, WindowDWord subAuthority2, WindowDWord subAuthority3,
																		WindowDWord subAuthority4, WindowDWord subAuthority5, WindowDWord subAuthority6,
																		WindowDWord subAuthority7, SecuritySIDPtr* sid) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsSecurityIdentifierValid(SecuritySIDPtr sid) noexcept;
	WindowVoidPtr SYSTEM_DEFAULT_DECLARE FreeSecurityIdentifier(SecuritySIDPtr sid) noexcept;
	WindowDWordPtr SYSTEM_DEFAULT_DECLARE GetSecurityIdentifierSubAuthority(SecuritySIDPtr sid, WindowDWord subAuthority) noexcept;
	WindowUCharPtr SYSTEM_DEFAULT_DECLARE GetSecurityIdentifierSubAuthorityCount(SecuritySIDPtr sid) noexcept;

	bool SYSTEM_DEFAULT_DECLARE CreateWellKnownSecurityIdentifier(SecurityWellKnownSidType wellKnownSidType, SecuritySIDPtr domainSid, SecuritySIDPtr sid, WindowDWord* sidCount) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsWellKnownSecurityIdentifier(SecuritySIDPtr sid, SecurityWellKnownSidType wellKnownSidType) noexcept;

	bool SYSTEM_DEFAULT_DECLARE	CopySecurityIdentifier(WindowDWord destinationSidLength, SecuritySIDPtr destinationSid, SecuritySIDPtr sourceSid) noexcept;
	bool SYSTEM_DEFAULT_DECLARE	EqualDomainSecurityIdentifier(SecuritySIDPtr sid1, SecuritySIDPtr sid2, bool* equal) noexcept;

	bool SYSTEM_DEFAULT_DECLARE EqualPrefixSecurityIdentifier(SecuritySIDPtr sid1, SecuritySIDPtr sid2) noexcept;
	bool SYSTEM_DEFAULT_DECLARE EqualSecurityIdentifier(SecuritySIDPtr sid1, SecuritySIDPtr sid2) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetLengthSecurityIdentifier(SecuritySIDPtr sid) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetSecurityIdentifierLengthRequired(WindowUChar subAuthorityCount) noexcept;
}

#endif // SYSTEM_SECURITY_SECURITY_SID_H