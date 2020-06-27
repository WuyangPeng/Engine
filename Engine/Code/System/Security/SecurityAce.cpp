// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:59)

#include "System/SystemExport.h"

#include "SecurityAce.h" 
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h" 
#include "System/Helper/EnumCast.h"

bool System
	::AddAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, WindowDWord startingAceIndex, WindowVoidPtr aceList, WindowDWord aceListLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::AddAce(acl, EnumCastUnderlying(aceRevision), startingAceIndex, aceList, aceListLength) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aceRevision);
	SYSTEM_UNUSED_ARG(startingAceIndex);
	SYSTEM_UNUSED_ARG(aceList);
	SYSTEM_UNUSED_ARG(aceListLength);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::AddMandatoryAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags, MandatoryPolicy mandatoryPolicy, SecuritySIDPtr labelSid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::AddMandatoryAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(mandatoryPolicy), labelSid) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aceRevision);
	SYSTEM_UNUSED_ARG(aceFlags);
	SYSTEM_UNUSED_ARG(mandatoryPolicy);
	SYSTEM_UNUSED_ARG(labelSid);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::DeleteAccessControlEntries(AccessCheckACLPtr acl, WindowDWord aceIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::DeleteAce(acl, aceIndex) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aceIndex);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::FindFirstFreeAccessControlEntries(AccessCheckACLPtr acl, WindowVoidPtr* ace) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::FindFirstFreeAce(acl, ace) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(ace);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetAccessControlEntries(AccessCheckACLPtr acl, WindowDWord aceIndex, WindowVoidPtr* ace) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetAce(acl, aceIndex, ace) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aceIndex);
	SYSTEM_UNUSED_ARG(ace);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}