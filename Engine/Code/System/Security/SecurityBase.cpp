//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 17:19)

#include "System/SystemExport.h"

#include "SecurityBase.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

bool System::GetAdjustTokenGroups([[maybe_unused]] WindowHandle tokenHandle, [[maybe_unused]] bool resetToDefault, [[maybe_unused]] SecurityTokenGroupsPtr newState,
                                  [[maybe_unused]] WindowDWord bufferLength, [[maybe_unused]] SecurityTokenGroupsPtr previousState, [[maybe_unused]] WindowDWordPtr returnLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::AdjustTokenGroups(tokenHandle, BoolConversion(resetToDefault), newState, bufferLength, previousState, returnLength) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetAdjustTokenPrivileges([[maybe_unused]] WindowHandle tokenHandle, [[maybe_unused]] bool disableAllPrivileges, [[maybe_unused]] SecurityTokenPrivilegesPtr newState,
                                      [[maybe_unused]] WindowDWord bufferLength, [[maybe_unused]] SecurityTokenPrivilegesPtr previousState, [[maybe_unused]] WindowDWordPtr returnLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::AdjustTokenPrivileges(tokenHandle, BoolConversion(disableAllPrivileges), newState, bufferLength, previousState, returnLength) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetAllocateLocallyUniqueID([[maybe_unused]] LookupPrivilegeLUIDPtr luid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::AllocateLocallyUniqueId(luid) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32

    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsAreAllAccessesGranted([[maybe_unused]] AccessGenericMask grantedAccess, [[maybe_unused]] AccessGenericMask desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::AreAllAccessesGranted(EnumCastUnderlying(grantedAccess), EnumCastUnderlying(desiredAccess)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsAreAnyAccessesGranted([[maybe_unused]] AccessGenericMask grantedAccess, [[maybe_unused]] AccessGenericMask desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::AreAnyAccessesGranted(EnumCastUnderlying(grantedAccess), EnumCastUnderlying(desiredAccess)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CheckSystemTokenMembership([[maybe_unused]] WindowHandle tokenHandle, [[maybe_unused]] SecuritySIDPtr sidToCheck, [[maybe_unused]] bool* isMember) noexcept
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
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CreateSystemRestrictedToken([[maybe_unused]] WindowHandle existingTokenHandle, [[maybe_unused]] SpecifiesAdditionalPrivilegeOptions flags, [[maybe_unused]] WindowDWord disableSidCount,
                                         [[maybe_unused]] SecuritySidAndAttributesPtr sidsToDisable, [[maybe_unused]] WindowDWord deletePrivilegeCount, [[maybe_unused]] LUIDAndAttributesPtr privilegesToDelete,
                                         [[maybe_unused]] WindowDWord restrictedSidCount, [[maybe_unused]] SecuritySidAndAttributesPtr sidsToRestrict, [[maybe_unused]] WindowHandlePtr newTokenHandle) noexcept
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
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DuplicateSystemToken([[maybe_unused]] WindowHandle existingTokenHandle, [[maybe_unused]] SecurityImpersonationLevel impersonationLevel, [[maybe_unused]] WindowHandlePtr duplicateTokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::DuplicateToken(existingTokenHandle, impersonationLevel, duplicateTokenHandle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DuplicateSystemToken([[maybe_unused]] WindowHandle existingTokenHandle, [[maybe_unused]] TokenStandardAccess standardAccess, [[maybe_unused]] TokenSpecificAccess specificAccess, [[maybe_unused]] WindowSecurityAttributesPtr tokenAttributes,
                                  [[maybe_unused]] SecurityImpersonationLevel impersonationLevel, [[maybe_unused]] SecurityTokenType tokenType, [[maybe_unused]] WindowHandlePtr newToken) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::DuplicateTokenEx(existingTokenHandle, EnumCastUnderlying(standardAccess) | EnumCastUnderlying(specificAccess), tokenAttributes, impersonationLevel, tokenType, newToken) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::SecuritySIDIndentifierAuthorityPtr System::GetSecuritySidIdentifierAuthority([[maybe_unused]] SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetSidIdentifierAuthority(sid);
#else  // !SYSTEM_PLATFORM_WIN32
    return SecuritySIDIndentifierAuthorityPtr{};
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemTokenInformation([[maybe_unused]] WindowHandle handle, [[maybe_unused]] TokenInformationClass tokenInformationClass, [[maybe_unused]] WindowVoidPtr tokenInformation,
                                       [[maybe_unused]] WindowDWord tokenInformationLength, [[maybe_unused]] WindowDWordPtr returnLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetTokenInformation(handle, tokenInformationClass, tokenInformation, tokenInformationLength, returnLength) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsImpersonateAnonymousToken([[maybe_unused]] ThreadHandle threadHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ImpersonateAnonymousToken(threadHandle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsImpersonateLoggedOnUser([[maybe_unused]] WindowHandle token) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ImpersonateLoggedOnUser(token) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSystemTokenRestricted([[maybe_unused]] WindowHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::IsTokenRestricted(tokenHandle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetMakeAbsoluteSD([[maybe_unused]] SecurityDescriptorPtr selfRelativeSecurityDescriptor, [[maybe_unused]] SecurityDescriptorPtr absoluteSecurityDescriptor, [[maybe_unused]] WindowDWordPtr absoluteSecurityDescriptorSize,
                               [[maybe_unused]] AccessCheckACLPtr dacl, [[maybe_unused]] WindowDWordPtr daclSize, [[maybe_unused]] AccessCheckACLPtr sacl, [[maybe_unused]] WindowDWordPtr saclSize,
                               [[maybe_unused]] SecuritySIDPtr owner, [[maybe_unused]] WindowDWordPtr ownerSize, [[maybe_unused]] SecuritySIDPtr primaryGroup, [[maybe_unused]] WindowDWordPtr primaryGroupSize) noexcept
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
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetMakeSelfRelativeSD([[maybe_unused]] SecurityDescriptorPtr absoluteSecurityDescriptor, [[maybe_unused]] SecurityDescriptorPtr selfRelativeSecurityDescriptor, [[maybe_unused]] WindowDWordPtr bufferLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::MakeSelfRelativeSD(absoluteSecurityDescriptor, selfRelativeSecurityDescriptor, bufferLength) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetPrivilegeCheck([[maybe_unused]] WindowHandle clientToken, [[maybe_unused]] SecurityPrivilegeSetPtr requiredPrivileges, [[maybe_unused]] WindowBoolPtr result) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::PrivilegeCheck(clientToken, requiredPrivileges, result) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::QuerySystemSecurityAccessMask([[maybe_unused]] SecurityRequestedInformation securityInformation, [[maybe_unused]] WindowDWordPtr desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::QuerySecurityAccessMask(EnumCastUnderlying(securityInformation), desiredAccess);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsRevertToSelf() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::RevertToSelf() != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
