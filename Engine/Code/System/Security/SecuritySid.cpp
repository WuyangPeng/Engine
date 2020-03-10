// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:00)

#include "System/SystemExport.h"

#include "SecuritySid.h" 
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

bool System
	::AllocateAndInitializeSecurityIdentifier(SecuritySIDIndentifierAuthorityPtr identifierAuthority, WindowByte subAuthorityCount, WindowDWord subAuthority0, WindowDWord subAuthority1,
											  WindowDWord subAuthority2, WindowDWord subAuthority3, WindowDWord subAuthority4, WindowDWord subAuthority5,
											  WindowDWord subAuthority6, WindowDWord subAuthority7, SecuritySIDPtr* sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::AllocateAndInitializeSid(identifierAuthority, subAuthorityCount, subAuthority0, subAuthority1, subAuthority2, subAuthority3, subAuthority4, subAuthority5, subAuthority6, subAuthority7, sid) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(identifierAuthority);
	SYSTEM_UNUSED_ARG(subAuthorityCount);
	SYSTEM_UNUSED_ARG(subAuthority0);
	SYSTEM_UNUSED_ARG(subAuthority1);
	SYSTEM_UNUSED_ARG(subAuthority2);
	SYSTEM_UNUSED_ARG(subAuthority3);
	SYSTEM_UNUSED_ARG(subAuthority4);
	SYSTEM_UNUSED_ARG(subAuthority5);
	SYSTEM_UNUSED_ARG(subAuthority6);
	SYSTEM_UNUSED_ARG(subAuthority7);
	SYSTEM_UNUSED_ARG(sid);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CopySecurityIdentifier(WindowDWord destinationSidLength, SecuritySIDPtr destinationSid, SecuritySIDPtr sourceSid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CopySid(destinationSidLength, destinationSid, sourceSid) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(destinationSidLength);
	SYSTEM_UNUSED_ARG(destinationSid);
	SYSTEM_UNUSED_ARG(sourceSid);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CreateWellKnownSecurityIdentifier(SecurityWellKnownSidType wellKnownSidType, SecuritySIDPtr domainSid, SecuritySIDPtr sid, WindowDWord* sidCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CreateWellKnownSid(wellKnownSidType, domainSid, sid, sidCount) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(wellKnownSidType);
	SYSTEM_UNUSED_ARG(domainSid);
	SYSTEM_UNUSED_ARG(sid);
	SYSTEM_UNUSED_ARG(sidCount);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::EqualDomainSecurityIdentifier(SecuritySIDPtr sid1, SecuritySIDPtr sid2, bool* equal) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	WindowBool result{ g_False };
	if (::EqualDomainSid(sid1, sid2, &result) != g_False)
	{
		BoolConversion(result, equal);

		return true;
	}		
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(sid1);
	SYSTEM_UNUSED_ARG(sid2);
	SYSTEM_UNUSED_ARG(equal);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::EqualPrefixSecurityIdentifier(SecuritySIDPtr sid1, SecuritySIDPtr sid2) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::EqualPrefixSid(sid1, sid2) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(sid1);
	SYSTEM_UNUSED_ARG(sid2);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::EqualSecurityIdentifier(SecuritySIDPtr sid1, SecuritySIDPtr sid2) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::EqualSid(sid1, sid2) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(sid1);
	SYSTEM_UNUSED_ARG(sid2);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System
	::FreeSecurityIdentifier(SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::FreeSid(sid);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(sid1);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetLengthSecurityIdentifier(SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetLengthSid(sid);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(sid1);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System
	::GetSecurityIdentifierLengthRequired(WindowUChar subAuthorityCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetSidLengthRequired(subAuthorityCount);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(subAuthorityCount);

	return 0;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowDWordPtr System
	::GetSecurityIdentifierSubAuthority(SecuritySIDPtr sid, WindowDWord subAuthority) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetSidSubAuthority(sid, subAuthority);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(sid);
	SYSTEM_UNUSED_ARG(subAuthority);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

System::WindowUCharPtr System
	::GetSecurityIdentifierSubAuthorityCount(SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetSidSubAuthorityCount(sid);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(sid);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::InitializeSecurityIdentifier(SecuritySIDPtr sid, SecuritySIDIndentifierAuthorityPtr identifierAuthority, WindowByte subAuthorityCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::InitializeSid(sid, identifierAuthority, subAuthorityCount) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(sid);
	SYSTEM_UNUSED_ARG(identifierAuthority);
	SYSTEM_UNUSED_ARG(subAuthorityCount);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}


bool System
	::IsSecurityIdentifierValid(SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::IsValidSid(sid) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(sid);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsWellKnownSecurityIdentifier(SecuritySIDPtr sid, SecurityWellKnownSidType wellKnownSidType) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::IsWellKnownSid(sid, wellKnownSidType) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(sid);
	SYSTEM_UNUSED_ARG(wellKnownSidType);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
