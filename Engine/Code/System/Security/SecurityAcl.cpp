// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:59)

#include "System/SystemExport.h"

#include "SecurityAcl.h" 
#include "System/Helper/WindowsMacro.h"
#include "System/Helper/UnusedMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

bool System
	::GetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetAclInformation(acl, aclInformation, sizeof(SecurityAclRevisionInformation), AclRevisionInformation) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aclInformation);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclSizeInformationPtr aclInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetAclInformation(acl, aclInformation, sizeof(SecurityAclSizeInformation), AclSizeInformation) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aclInformation);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::InitializeAccessControlList(AccessCheckACLPtr acl, WindowDWord aclLength, AccessControlListRevision aclRevision) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::InitializeAcl(acl, aclLength, EnumCastUnderlying(aclRevision)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aclLength);
	SYSTEM_UNUSED_ARG(aclRevision);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsAccessControlListValid(AccessCheckACLPtr acl) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::IsValidAcl(acl) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::SetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::SetAclInformation(acl, aclInformation, sizeof(SecurityAclRevisionInformation), AclRevisionInformation) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(acl);
	SYSTEM_UNUSED_ARG(aclInformation);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}