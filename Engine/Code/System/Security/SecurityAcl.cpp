//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 17:19)

#include "System/SystemExport.h"

#include "SecurityAcl.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::GetAccessControlListInformation([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] SecurityAclRevisionInformationPtr aclInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetAclInformation(acl, aclInformation, sizeof(SecurityAclRevisionInformation), AclRevisionInformation) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetAccessControlListInformation([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] SecurityAclSizeInformationPtr aclInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetAclInformation(acl, aclInformation, sizeof(SecurityAclSizeInformation), AclSizeInformation) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::InitializeAccessControlList([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] WindowDWord aclLength, [[maybe_unused]] AccessControlListRevision aclRevision) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::InitializeAcl(acl, aclLength, EnumCastUnderlying(aclRevision)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsAccessControlListValid([[maybe_unused]] AccessCheckACLPtr acl) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::IsValidAcl(acl) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetAccessControlListInformation([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] SecurityAclRevisionInformationPtr aclInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetAclInformation(acl, aclInformation, sizeof(SecurityAclRevisionInformation), AclRevisionInformation) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}