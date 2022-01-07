///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 11:09)

#include "System/SystemExport.h"

#include "SecurityAcl.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::GetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetAclInformation(acl, aclInformation, sizeof(SecurityAclRevisionInformation), AclRevisionInformation) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aclInformation);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclSizeInformationPtr aclInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetAclInformation(acl, aclInformation, sizeof(SecurityAclSizeInformation), AclSizeInformation) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aclInformation);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::InitializeAccessControlList(AccessCheckACLPtr acl, WindowsDWord aclLength, AccessControlListRevision aclRevision) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::InitializeAcl(acl, aclLength, EnumCastUnderlying(aclRevision)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aclLength, aclRevision);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsAccessControlListValid(AccessCheckACLPtr acl) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::IsValidAcl(acl) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetAclInformation(acl, aclInformation, sizeof(SecurityAclRevisionInformation), AclRevisionInformation) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aclInformation);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}