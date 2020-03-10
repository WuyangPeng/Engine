// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:52)

#ifndef SYSTEM_SECURITY_SECURITY_SID_FWD_H 
#define SYSTEM_SECURITY_SECURITY_SID_FWD_H   

#include "System/Security/Using/SecuritySidUsing.h"
#include "System/Window/Using/WindowRegistryUsing.h"

namespace System
{
	bool CopySecurityIdentifier(WindowDWord destinationSidLength, SecuritySIDPtr destinationSid, SecuritySIDPtr sourceSid) noexcept;

	bool CreateWellKnownSecurityIdentifier(SecurityWellKnownSidType wellKnownSidType, SecuritySIDPtr domainSid, SecuritySIDPtr sid, WindowDWord* sidCount) noexcept;

	bool EqualDomainSecurityIdentifier(SecuritySIDPtr sid1, SecuritySIDPtr sid2, bool* equal) noexcept;

	bool EqualPrefixSecurityIdentifier(SecuritySIDPtr sid1, SecuritySIDPtr sid2) noexcept;
	bool EqualSecurityIdentifier(SecuritySIDPtr sid1, SecuritySIDPtr sid2) noexcept;

	WindowVoidPtr FreeSecurityIdentifier(SecuritySIDPtr sid) noexcept;
	WindowDWord GetLengthSecurityIdentifier(SecuritySIDPtr sid) noexcept;

	WindowDWord GetSecurityIdentifierLengthRequired(WindowUChar subAuthorityCount) noexcept;
	WindowDWordPtr GetSecurityIdentifierSubAuthority(SecuritySIDPtr sid, WindowDWord subAuthority) noexcept;
	WindowUCharPtr GetSecurityIdentifierSubAuthorityCount(SecuritySIDPtr sid) noexcept;

	bool InitializeSecurityIdentifier(SecuritySIDPtr sid, SecuritySIDIndentifierAuthorityPtr identifierAuthority, WindowByte subAuthorityCount) noexcept;

	bool IsSecurityIdentifierValid(SecuritySIDPtr sid) noexcept;
	bool IsWellKnownSecurityIdentifier(SecuritySIDPtr sid, SecurityWellKnownSidType wellKnownSidType) noexcept;

	bool AllocateAndInitializeSecurityIdentifier(SecuritySIDIndentifierAuthorityPtr identifierAuthority, WindowByte subAuthorityCount, WindowDWord subAuthority0, WindowDWord subAuthority1,
												 WindowDWord subAuthority2, WindowDWord subAuthority3, WindowDWord subAuthority4, WindowDWord subAuthority5,
												 WindowDWord subAuthority6, WindowDWord subAuthority7, SecuritySIDPtr* sid) noexcept;
}

#endif // SYSTEM_SECURITY_SECURITY_SID_FWD_H