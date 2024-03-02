/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/28 11:00)

#include "System/SystemExport.h"

#include "SecurityAce.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

bool System::AddAccessControlEntries(AccessCheckAclPtr acl, AccessControlListRevision aceRevision, WindowsDWord startingAceIndex, WindowsVoidPtr aceList, WindowsDWord aceListLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::AddAce(acl, EnumCastUnderlying(aceRevision), startingAceIndex, aceList, aceListLength) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aceRevision, startingAceIndex, aceList, aceListLength);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddMandatoryAccessControlEntries(AccessCheckAclPtr acl, AccessControlListRevision aceRevision, ControlAceInheritance aceFlags, MandatoryPolicy mandatoryPolicy, SecuritySidPtr labelSid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::AddMandatoryAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(mandatoryPolicy), labelSid) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aceRevision, aceFlags, mandatoryPolicy, labelSid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DeleteAccessControlEntries(AccessCheckAclPtr acl, WindowsDWord aceIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::DeleteAce(acl, aceIndex) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aceIndex);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FindFirstFreeAccessControlEntries(AccessCheckAclPtr acl, WindowsVoidPtr* ace) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::FindFirstFreeAce(acl, ace) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, ace);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetAccessControlEntries(AccessCheckAclPtr acl, WindowsDWord aceIndex, WindowsVoidPtr* ace) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetAce(acl, aceIndex, ace) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(acl, aceIndex, ace);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}