///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/23 23:17)

#include "System/SystemExport.h"

#include "SecurityAcl.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::GetAccessControlListInformation(AccessCheckACLPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetAclInformation(acl, aclInformation, sizeof(SecurityAclRevisionInformation), AclRevisionInformation) != gFalse)
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

    if (::GetAclInformation(acl, aclInformation, sizeof(SecurityAclSizeInformation), AclSizeInformation) != gFalse)
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

    if (::InitializeAcl(acl, aclLength, EnumCastUnderlying(aclRevision)) != gFalse)
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

    if (::IsValidAcl(acl) != gFalse)
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

    if (::SetAclInformation(acl, aclInformation, sizeof(SecurityAclRevisionInformation), AclRevisionInformation) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aclInformation);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}