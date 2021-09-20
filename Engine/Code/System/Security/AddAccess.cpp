///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.4 (2021/05/25 10:42)

#include "System/SystemExport.h"

#include "AddAccess.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

bool System::AddAccessAllowedAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, SpecificAccess accessMask, SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::AddAccessAllowedAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(accessMask), sid)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<AccessCheckACLPtr, AccessControlListRevision, SpecificAccess, SecuritySIDPtr>(acl, aceRevision, accessMask, sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessAllowedAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags, SpecificAccess accessMask, SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::AddAccessAllowedAceEx(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask), sid)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<AccessCheckACLPtr, AccessControlListRevision, ControlACEInheritance, SpecificAccess, SecuritySIDPtr>(acl, aceRevision, aceFlags, accessMask, sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessAllowedObjectAccessControlEntries(AccessCheckACLPtr acl,
                                                        AccessControlListRevision aceRevision,
                                                        ControlACEInheritance aceFlags,
                                                        SpecificAccess accessMask,
                                                        SystemGUID* objectTypeGuid,
                                                        SystemGUID* inheritedObjectTypeGuid,
                                                        SecuritySIDPtr sid) noexcept
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

    NullFunction<AccessCheckACLPtr,
                 AccessControlListRevision,
                 ControlACEInheritance,
                 SpecificAccess,
                 SystemGUID*,
                 SystemGUID*,
                 SecuritySIDPtr>(acl,
                                 aceRevision,
                                 aceFlags,
                                 accessMask,
                                 objectTypeGuid,
                                 inheritedObjectTypeGuid,
                                 sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessDeniedAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, SpecificAccess accessMask, SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AddAccessDeniedAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(accessMask), sid) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<AccessCheckACLPtr, AccessControlListRevision, SpecificAccess, SecuritySIDPtr>(acl, aceRevision, accessMask, sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessDeniedAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags, SpecificAccess accessMask, SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if ((::AddAccessDeniedAceEx(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(accessMask), sid)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<AccessCheckACLPtr, AccessControlListRevision, ControlACEInheritance, SpecificAccess, SecuritySIDPtr>(acl, aceRevision, aceFlags, accessMask, sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAccessDeniedObjectAccessControlEntries(AccessCheckACLPtr acl,
                                                       AccessControlListRevision aceRevision,
                                                       ControlACEInheritance aceFlags,
                                                       SpecificAccess accessMask,
                                                       SystemGUID* objectTypeGuid,
                                                       SystemGUID* inheritedObjectTypeGuid,
                                                       SecuritySIDPtr sid) noexcept
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

    NullFunction<AccessCheckACLPtr,
                 AccessControlListRevision,
                 ControlACEInheritance,
                 SpecificAccess,
                 SystemGUID*,
                 SystemGUID*,
                 SecuritySIDPtr>(acl,
                                 aceRevision,
                                 aceFlags,
                                 accessMask,
                                 objectTypeGuid,
                                 inheritedObjectTypeGuid,
                                 sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAuditAccessAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, SpecificAccess accessMask, SecuritySIDPtr sid, bool auditSuccess, bool auditFailure) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if ((::AddAuditAccessAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(accessMask), sid, BoolConversion(auditSuccess), BoolConversion(auditFailure))) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<AccessCheckACLPtr, AccessControlListRevision, SpecificAccess, SecuritySIDPtr, bool, bool>(acl, aceRevision, accessMask, sid, auditSuccess, auditFailure);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAuditAccessAccessControlEntries(AccessCheckACLPtr acl,
                                                AccessControlListRevision aceRevision,
                                                ControlACEInheritance aceFlags,
                                                SpecificAccess accessMask,
                                                SecuritySIDPtr sid,
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
                               BoolConversion(auditFailure))) != g_False)
    {
        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<AccessCheckACLPtr,
                 AccessControlListRevision,
                 ControlACEInheritance,
                 SpecificAccess,
                 SecuritySIDPtr,
                 bool,
                 bool>(acl,
                       aceRevision,
                       aceFlags,
                       accessMask,
                       sid,
                       auditSuccess,
                       auditFailure);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddAuditAccessObjectAccessControlEntries(AccessCheckACLPtr acl,
                                                      AccessControlListRevision aceRevision,
                                                      ControlACEInheritance aceFlags,
                                                      SpecificAccess accessMask,
                                                      SystemGUID* objectTypeGuid,
                                                      SystemGUID* inheritedObjectTypeGuid,
                                                      SecuritySIDPtr sid,
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
                                   BoolConversion(auditFailure))) != g_False)
    {
        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<AccessCheckACLPtr,
                 AccessControlListRevision,
                 ControlACEInheritance,
                 SpecificAccess,
                 SystemGUID*,
                 SystemGUID*,
                 SecuritySIDPtr,
                 bool,
                 bool>(acl,
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
