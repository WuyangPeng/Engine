/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 16:28)

#include "System/SystemExport.h"

#include "AddAccess.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

bool System::AddAccessAllowedAccessControlEntries(AccessCheckAclPtr acl, AccessControlListRevision aceRevision, SpecificAccess accessMask, SecuritySidPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::AddAccessAllowedAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(accessMask), sid)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aceRevision, accessMask, sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessAllowedAccessControlEntries(AccessCheckAclPtr acl, AccessControlListRevision aceRevision, ControlAceInheritance aceFlags, SpecificAccess accessMask, SecuritySidPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::AddAccessAllowedAceEx(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask), sid)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aceRevision, aceFlags, accessMask, sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessAllowedObjectAccessControlEntries(AccessCheckAclPtr acl,
                                                        AccessControlListRevision aceRevision,
                                                        ControlAceInheritance aceFlags,
                                                        SpecificAccess accessMask,
                                                        SystemGloballyUniqueIdentifier* objectTypeGuid,
                                                        SystemGloballyUniqueIdentifier* inheritedObjectTypeGuid,
                                                        SecuritySidPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::AddAccessAllowedObjectAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask), objectTypeGuid, inheritedObjectTypeGuid, sid)) != gFalse)
    {
        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl,
                   aceRevision,
                   aceFlags,
                   accessMask,
                   objectTypeGuid,
                   inheritedObjectTypeGuid,
                   sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessDeniedAccessControlEntries(AccessCheckAclPtr acl, AccessControlListRevision aceRevision, SpecificAccess accessMask, SecuritySidPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AddAccessDeniedAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(accessMask), sid) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aceRevision, accessMask, sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessDeniedAccessControlEntries(AccessCheckAclPtr acl, AccessControlListRevision aceRevision, ControlAceInheritance aceFlags, SpecificAccess accessMask, SecuritySidPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::AddAccessDeniedAceEx(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask), sid)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aceRevision, aceFlags, accessMask, sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessDeniedObjectAccessControlEntries(AccessCheckAclPtr acl,
                                                       AccessControlListRevision aceRevision,
                                                       ControlAceInheritance aceFlags,
                                                       SpecificAccess accessMask,
                                                       SystemGloballyUniqueIdentifier* objectTypeGuid,
                                                       SystemGloballyUniqueIdentifier* inheritedObjectTypeGuid,
                                                       SecuritySidPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::AddAccessDeniedObjectAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask), objectTypeGuid, inheritedObjectTypeGuid, sid)) != gFalse)
    {
        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl,
                   aceRevision,
                   aceFlags,
                   accessMask,
                   objectTypeGuid,
                   inheritedObjectTypeGuid,
                   sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAuditAccessAccessControlEntries(AccessCheckAclPtr acl, AccessControlListRevision aceRevision, SpecificAccess accessMask, SecuritySidPtr sid, bool auditSuccess, bool auditFailure) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::AddAuditAccessAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(accessMask), sid, BoolConversion(auditSuccess), BoolConversion(auditFailure))) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aceRevision, accessMask, sid, auditSuccess, auditFailure);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAuditAccessAccessControlEntries(AccessCheckAclPtr acl,
                                                AccessControlListRevision aceRevision,
                                                ControlAceInheritance aceFlags,
                                                SpecificAccess accessMask,
                                                SecuritySidPtr sid,
                                                bool auditSuccess,
                                                bool auditFailure) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::AddAuditAccessAceEx(acl,
                               EnumCastUnderlying(aceRevision),
                               EnumCastUnderlying(aceFlags),
                               EnumCastUnderlying(accessMask),
                               sid,
                               BoolConversion(auditSuccess),
                               BoolConversion(auditFailure))) != gFalse)
    {
        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl,
                   aceRevision,
                   aceFlags,
                   accessMask,
                   sid,
                   auditSuccess,
                   auditFailure);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAuditAccessObjectAccessControlEntries(AccessCheckAclPtr acl,
                                                      AccessControlListRevision aceRevision,
                                                      ControlAceInheritance aceFlags,
                                                      SpecificAccess accessMask,
                                                      SystemGloballyUniqueIdentifier* objectTypeGuid,
                                                      SystemGloballyUniqueIdentifier* inheritedObjectTypeGuid,
                                                      SecuritySidPtr sid,
                                                      bool auditSuccess,
                                                      bool auditFailure) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::AddAuditAccessObjectAce(acl,
                                   EnumCastUnderlying(aceRevision),
                                   EnumCastUnderlying(aceFlags),
                                   EnumCastUnderlying(accessMask),
                                   objectTypeGuid,
                                   inheritedObjectTypeGuid,
                                   sid,
                                   BoolConversion(auditSuccess),
                                   BoolConversion(auditFailure))) != gFalse)
    {
        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl,
                   aceRevision,
                   aceFlags,
                   accessMask,
                   objectTypeGuid,
                   inheritedObjectTypeGuid,
                   sid,
                   auditSuccess,
                   auditFailure);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
