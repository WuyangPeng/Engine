/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 16:29)

#include "System/SystemExport.h"

#include "SecurityAcl.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

bool System::GetAccessControlListInformation(AccessCheckAclPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept
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

bool System::GetAccessControlListInformation(AccessCheckAclPtr acl, SecurityAclSizeInformationPtr aclInformation) noexcept
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

bool System::InitializeAccessControlList(AccessCheckAclPtr acl, WindowsDWord aclLength, AccessControlListRevision aclRevision) noexcept
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

bool System::IsAccessControlListValid(AccessCheckAclPtr acl) noexcept
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

bool System::SetAccessControlListInformation(AccessCheckAclPtr acl, SecurityAclRevisionInformationPtr aclInformation) noexcept
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