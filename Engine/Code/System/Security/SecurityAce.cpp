///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 11:09)

#include "System/SystemExport.h"

#include "SecurityAce.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::AddAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, WindowsDWord startingAceIndex, WindowsVoidPtr aceList, WindowsDWord aceListLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AddAce(acl, EnumCastUnderlying(aceRevision), startingAceIndex, aceList, aceListLength) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aceRevision, startingAceIndex, aceList, aceListLength);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddMandatoryAccessControlEntries(AccessCheckACLPtr acl, AccessControlListRevision aceRevision, ControlACEInheritance aceFlags, MandatoryPolicy mandatoryPolicy, SecuritySIDPtr labelSid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AddMandatoryAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(mandatoryPolicy), labelSid) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aceRevision, aceFlags, mandatoryPolicy, labelSid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DeleteAccessControlEntries(AccessCheckACLPtr acl, WindowsDWord aceIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::DeleteAce(acl, aceIndex) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aceIndex);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FindFirstFreeAccessControlEntries(AccessCheckACLPtr acl, WindowsVoidPtr* ace) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::FindFirstFreeAce(acl, ace) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, ace);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetAccessControlEntries(AccessCheckACLPtr acl, WindowsDWord aceIndex, WindowsVoidPtr* ace) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetAce(acl, aceIndex, ace) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aceIndex, ace);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}