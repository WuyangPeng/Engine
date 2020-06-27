// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:59)

#include "System/SystemExport.h"

#include "SecurityBase.h" 
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"
#include "System/Helper/EnumCast.h"

bool System
	::GetAdjustTokenGroups(WindowHandle tokenHandle, bool resetToDefault, SecurityTokenGroupsPtr newState,
						   WindowDWord bufferLength, SecurityTokenGroupsPtr previousState, WindowDWordPtr returnLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::AdjustTokenGroups(tokenHandle, BoolConversion(resetToDefault), newState, bufferLength, previousState, returnLength) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(tokenHandle);
	SYSTEM_UNUSED_ARG(resetToDefault);
	SYSTEM_UNUSED_ARG(newState);
	SYSTEM_UNUSED_ARG(bufferLength);
	SYSTEM_UNUSED_ARG(previousState);
	SYSTEM_UNUSED_ARG(returnLength);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetAdjustTokenPrivileges(WindowHandle tokenHandle, bool disableAllPrivileges, SecurityTokenPrivilegesPtr newState,
							   WindowDWord bufferLength, SecurityTokenPrivilegesPtr previousState, WindowDWordPtr returnLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::AdjustTokenPrivileges(tokenHandle, BoolConversion(disableAllPrivileges), newState, bufferLength, previousState, returnLength) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(tokenHandle);
	SYSTEM_UNUSED_ARG(disableAllPrivileges);
	SYSTEM_UNUSED_ARG(newState);
	SYSTEM_UNUSED_ARG(bufferLength);
	SYSTEM_UNUSED_ARG(previousState);
	SYSTEM_UNUSED_ARG(returnLength);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetAllocateLocallyUniqueID(LookupPrivilegeLUIDPtr luid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::AllocateLocallyUniqueId(luid) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(luid);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsAreAllAccessesGranted(AccessGenericMask grantedAccess, AccessGenericMask desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::AreAllAccessesGranted(EnumCastUnderlying(grantedAccess), EnumCastUnderlying(desiredAccess)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(grantedAccess);
	SYSTEM_UNUSED_ARG(desiredAccess);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsAreAnyAccessesGranted(AccessGenericMask grantedAccess, AccessGenericMask desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::AreAnyAccessesGranted(EnumCastUnderlying(grantedAccess), EnumCastUnderlying(desiredAccess)) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(grantedAccess);
	SYSTEM_UNUSED_ARG(desiredAccess);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CheckSystemTokenMembership(WindowHandle tokenHandle, SecuritySIDPtr sidToCheck, bool* isMember) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	auto result = g_False;
	if (g_False != ::CheckTokenMembership(tokenHandle, sidToCheck, &result))
	{
		BoolConversion(result, isMember);

		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(tokenHandle);
	SYSTEM_UNUSED_ARG(sidToCheck);
	SYSTEM_UNUSED_ARG(isMember);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::CreateSystemRestrictedToken(WindowHandle existingTokenHandle, SpecifiesAdditionalPrivilegeOptions flags, WindowDWord disableSidCount,
								  SecuritySidAndAttributesPtr sidsToDisable, WindowDWord deletePrivilegeCount, LUIDAndAttributesPtr privilegesToDelete,
								  WindowDWord restrictedSidCount, SecuritySidAndAttributesPtr sidsToRestrict, WindowHandlePtr newTokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::CreateRestrictedToken(existingTokenHandle, EnumCastUnderlying(flags), disableSidCount, sidsToDisable, deletePrivilegeCount,
								privilegesToDelete, restrictedSidCount, sidsToRestrict, newTokenHandle) != g_False)
	{
		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(existingTokenHandle);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(disableSidCount);
	SYSTEM_UNUSED_ARG(sidsToDisable);
	SYSTEM_UNUSED_ARG(deletePrivilegeCount);
	SYSTEM_UNUSED_ARG(privilegesToDelete);
	SYSTEM_UNUSED_ARG(restrictedSidCount);
	SYSTEM_UNUSED_ARG(sidsToRestrict);
	SYSTEM_UNUSED_ARG(newTokenHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::DuplicateSystemToken(WindowHandle existingTokenHandle, SecurityImpersonationLevel impersonationLevel, WindowHandlePtr duplicateTokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::DuplicateToken(existingTokenHandle, impersonationLevel, duplicateTokenHandle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(existingTokenHandle);
	SYSTEM_UNUSED_ARG(impersonationLevel);
	SYSTEM_UNUSED_ARG(duplicateTokenHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::DuplicateSystemToken(WindowHandle existingTokenHandle, TokenStandardAccess standardAccess, TokenSpecificAccess specificAccess, WindowSecurityAttributesPtr tokenAttributes,
						   SecurityImpersonationLevel impersonationLevel, SecurityTokenType tokenType, WindowHandlePtr newToken) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::DuplicateTokenEx(existingTokenHandle, EnumCastUnderlying(standardAccess) | EnumCastUnderlying(specificAccess), tokenAttributes, impersonationLevel, tokenType, newToken) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(existingTokenHandle);
	SYSTEM_UNUSED_ARG(standardAccess);
	SYSTEM_UNUSED_ARG(specificAccess);
	SYSTEM_UNUSED_ARG(tokenAttributes);
	SYSTEM_UNUSED_ARG(impersonationLevel);
	SYSTEM_UNUSED_ARG(tokenType);
	SYSTEM_UNUSED_ARG(newToken);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::SecuritySIDIndentifierAuthorityPtr System
	::GetSecuritySidIdentifierAuthority(SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	return ::GetSidIdentifierAuthority(sid);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(sid);

	return SecuritySIDIndentifierAuthorityPtr{};
#endif // SYSTEM_PLATFORM_WIN32
}


bool System
	::GetSystemTokenInformation(WindowHandle handle, TokenInformationClass tokenInformationClass, WindowVoidPtr tokenInformation,
								WindowDWord tokenInformationLength, WindowDWordPtr returnLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::GetTokenInformation(handle, tokenInformationClass, tokenInformation, tokenInformationLength, returnLength) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(handle);
	SYSTEM_UNUSED_ARG(tokenInformationClass);
	SYSTEM_UNUSED_ARG(tokenInformation);
	SYSTEM_UNUSED_ARG(tokenInformationLength);
	SYSTEM_UNUSED_ARG(returnLength);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsImpersonateAnonymousToken(ThreadHandle threadHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ImpersonateAnonymousToken(threadHandle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(threadHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsImpersonateLoggedOnUser(WindowHandle token) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::ImpersonateLoggedOnUser(token) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(token);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsSystemTokenRestricted(WindowHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::IsTokenRestricted(tokenHandle) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(tokenHandle);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetMakeAbsoluteSD(SecurityDescriptorPtr selfRelativeSecurityDescriptor, SecurityDescriptorPtr absoluteSecurityDescriptor, WindowDWordPtr absoluteSecurityDescriptorSize,
						AccessCheckACLPtr dacl, WindowDWordPtr daclSize, AccessCheckACLPtr sacl, WindowDWordPtr saclSize,
						SecuritySIDPtr owner, WindowDWordPtr ownerSize, SecuritySIDPtr primaryGroup, WindowDWordPtr primaryGroupSize) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::MakeAbsoluteSD(selfRelativeSecurityDescriptor, absoluteSecurityDescriptor, absoluteSecurityDescriptorSize, dacl, daclSize, sacl,
						 saclSize, owner, ownerSize, primaryGroup, primaryGroupSize) != g_False)
	{
		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(selfRelativeSecurityDescriptor);
	SYSTEM_UNUSED_ARG(absoluteSecurityDescriptor);
	SYSTEM_UNUSED_ARG(absoluteSecurityDescriptorSize);
	SYSTEM_UNUSED_ARG(dacl);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetMakeSelfRelativeSD(SecurityDescriptorPtr absoluteSecurityDescriptor, SecurityDescriptorPtr selfRelativeSecurityDescriptor, WindowDWordPtr bufferLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::MakeSelfRelativeSD(absoluteSecurityDescriptor, selfRelativeSecurityDescriptor, bufferLength) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(absoluteSecurityDescriptor);
	SYSTEM_UNUSED_ARG(selfRelativeSecurityDescriptor);
	SYSTEM_UNUSED_ARG(bufferLength);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetPrivilegeCheck(WindowHandle clientToken, SecurityPrivilegeSetPtr requiredPrivileges, WindowBoolPtr result) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::PrivilegeCheck(clientToken, requiredPrivileges, result) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(clientToken);
	SYSTEM_UNUSED_ARG(requiredPrivileges);
	SYSTEM_UNUSED_ARG(result);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

void System
	::QuerySystemSecurityAccessMask(SecurityRequestedInformation securityInformation, WindowDWordPtr desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::QuerySecurityAccessMask(EnumCastUnderlying(securityInformation), desiredAccess);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityInformation);
	SYSTEM_UNUSED_ARG(desiredAccess);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::IsRevertToSelf() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	if (::RevertToSelf() != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32
}



