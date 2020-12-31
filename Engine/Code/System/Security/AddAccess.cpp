//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 17:10)

#include "System/SystemExport.h"

#include "AddAccess.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

bool System::AddAccessAllowedAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] AccessControlListRevision aceRevision, [[maybe_unused]] SpecificAccess accessMask, [[maybe_unused]] SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if ((::AddAccessAllowedAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(accessMask), sid)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessAllowedAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] AccessControlListRevision aceRevision, [[maybe_unused]] ControlACEInheritance aceFlags, [[maybe_unused]] SpecificAccess accessMask, [[maybe_unused]] SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if ((::AddAccessAllowedAceEx(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask), sid)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessAllowedObjectAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] AccessControlListRevision aceRevision, [[maybe_unused]] ControlACEInheritance aceFlags, [[maybe_unused]] SpecificAccess accessMask,
                                                        [[maybe_unused]] SystemGUID* objectTypeGuid, [[maybe_unused]] SystemGUID* inheritedObjectTypeGuid, [[maybe_unused]] SecuritySIDPtr sid) noexcept
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

#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessDeniedAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] AccessControlListRevision aceRevision, [[maybe_unused]] SpecificAccess accessMask, [[maybe_unused]] SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::AddAccessDeniedAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(accessMask), sid) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessDeniedAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] AccessControlListRevision aceRevision, [[maybe_unused]] ControlACEInheritance aceFlags, [[maybe_unused]] SpecificAccess accessMask, [[maybe_unused]] SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if ((::AddAccessDeniedAceEx(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask), sid)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessDeniedObjectAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] AccessControlListRevision aceRevision, [[maybe_unused]] ControlACEInheritance aceFlags, [[maybe_unused]] SpecificAccess accessMask,
                                                       [[maybe_unused]] SystemGUID* objectTypeGuid, [[maybe_unused]] SystemGUID* inheritedObjectTypeGuid, [[maybe_unused]] SecuritySIDPtr sid) noexcept
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

#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAuditAccessAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] AccessControlListRevision aceRevision, [[maybe_unused]] SpecificAccess accessMask, [[maybe_unused]] SecuritySIDPtr sid, [[maybe_unused]] bool auditSuccess, [[maybe_unused]] bool auditFailure) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if ((::AddAuditAccessAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(accessMask), sid, BoolConversion(auditSuccess), BoolConversion(auditFailure))) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAuditAccessAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] AccessControlListRevision aceRevision, [[maybe_unused]] ControlACEInheritance aceFlags, [[maybe_unused]] SpecificAccess accessMask,
                                                [[maybe_unused]] SecuritySIDPtr sid, [[maybe_unused]] bool auditSuccess, [[maybe_unused]] bool auditFailure) noexcept
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

#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAuditAccessObjectAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] AccessControlListRevision aceRevision, [[maybe_unused]] ControlACEInheritance aceFlags,
                                                      [[maybe_unused]] SpecificAccess accessMask, [[maybe_unused]] SystemGUID* objectTypeGuid, [[maybe_unused]] SystemGUID* inheritedObjectTypeGuid,
                                                      [[maybe_unused]] SecuritySIDPtr sid, [[maybe_unused]] bool auditSuccess, [[maybe_unused]] bool auditFailure) noexcept
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

#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
