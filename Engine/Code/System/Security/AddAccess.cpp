// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:58)

#include "System/SystemExport.h"

#include "AddAccess.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"
#include "System/EnumOperator/EnumCastDetail.h"

bool System
	::AddAccessAllowedAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, SpecificAccess accessMask, SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::AddAccessAllowedAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(accessMask), sid)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aceRevision);
	SYSTEM_UNUSED_ARG(accessMask);
	SYSTEM_UNUSED_ARG(sid);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::AddAccessAllowedAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags, SpecificAccess accessMask, SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::AddAccessAllowedAceEx(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask), sid)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aceRevision);
	SYSTEM_UNUSED_ARG(aceFlags);
	SYSTEM_UNUSED_ARG(accessMask);
	SYSTEM_UNUSED_ARG(sid);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::AddAccessAllowedObjectAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags, SpecificAccess accessMask,
												 SystemGUID* objectTypeGuid, SystemGUID* inheritedObjectTypeGuid, SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	if ((::AddAccessAllowedObjectAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask), objectTypeGuid, inheritedObjectTypeGuid, sid)) != g_False)
	{
		return true;
	}
	else
	{
		return false;
	}

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aceRevision);
	SYSTEM_UNUSED_ARG(aceFlags);
	SYSTEM_UNUSED_ARG(accessMask);
	SYSTEM_UNUSED_ARG(objectTypeGuid);
	SYSTEM_UNUSED_ARG(inheritedObjectTypeGuid);
	SYSTEM_UNUSED_ARG(sid);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::AddAccessDeniedAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, SpecificAccess accessMask, SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::AddAccessDeniedAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(accessMask), sid) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aceRevision);
	SYSTEM_UNUSED_ARG(accessMask);
	SYSTEM_UNUSED_ARG(sid);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::AddAccessDeniedAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags, SpecificAccess accessMask, SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::AddAccessDeniedAceEx(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask), sid)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aceRevision);
	SYSTEM_UNUSED_ARG(aceFlags);
	SYSTEM_UNUSED_ARG(accessMask);
	SYSTEM_UNUSED_ARG(sid);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::AddAccessDeniedObjectAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags, SpecificAccess accessMask,
											    SystemGUID* objectTypeGuid, SystemGUID* inheritedObjectTypeGuid, SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	if ((::AddAccessDeniedObjectAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask), objectTypeGuid, inheritedObjectTypeGuid, sid)) != g_False)
	{
		return true;
	}
	else
	{
		return false;
	}

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aceRevision);
	SYSTEM_UNUSED_ARG(aceFlags);
	SYSTEM_UNUSED_ARG(accessMask);
	SYSTEM_UNUSED_ARG(objectTypeGuid);
	SYSTEM_UNUSED_ARG(inheritedObjectTypeGuid);
	SYSTEM_UNUSED_ARG(sid);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::AddAuditAccessAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, SpecificAccess accessMask, SecuritySIDPtr sid, bool auditSuccess, bool auditFailure) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if ((::AddAuditAccessAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(accessMask), sid, BoolConversion(auditSuccess), BoolConversion(auditFailure))) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aceRevision);
	SYSTEM_UNUSED_ARG(accessMask);
	SYSTEM_UNUSED_ARG(sid);
	SYSTEM_UNUSED_ARG(auditSuccess);
	SYSTEM_UNUSED_ARG(auditFailure);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::AddAuditAccessAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags, SpecificAccess accessMask,
										 SecuritySIDPtr sid, bool auditSuccess, bool auditFailure) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	if ((::AddAuditAccessAceEx(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask),
							   sid, BoolConversion(auditSuccess), BoolConversion(auditFailure))) != g_False)
	{
		return true;
	}
	else
	{
		return false;
	}

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aceRevision);
	SYSTEM_UNUSED_ARG(aceFlags);
	SYSTEM_UNUSED_ARG(accessMask);
	SYSTEM_UNUSED_ARG(sid);
	SYSTEM_UNUSED_ARG(auditSuccess);
	SYSTEM_UNUSED_ARG(auditFailure);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::AddAuditAccessObjectAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags,
											   SpecificAccess accessMask, SystemGUID* objectTypeGuid, SystemGUID* inheritedObjectTypeGuid,
											   SecuritySIDPtr sid, bool auditSuccess, bool auditFailure) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	if ((::AddAuditAccessObjectAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask),
								   objectTypeGuid, inheritedObjectTypeGuid, sid, BoolConversion(auditSuccess), BoolConversion(auditFailure))) != g_False)
	{
		return true;
	}
	else
	{
		return false;
	}

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aceRevision);
	SYSTEM_UNUSED_ARG(aceFlags);
	SYSTEM_UNUSED_ARG(accessMask);
	SYSTEM_UNUSED_ARG(objectTypeGuid);
	SYSTEM_UNUSED_ARG(inheritedObjectTypeGuid);
	SYSTEM_UNUSED_ARG(sid);
	SYSTEM_UNUSED_ARG(auditSuccess);
	SYSTEM_UNUSED_ARG(auditFailure);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}
