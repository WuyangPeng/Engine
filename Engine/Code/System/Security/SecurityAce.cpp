//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 17:18)

#include "System/SystemExport.h"

#include "SecurityAce.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::AddAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] AccessControlListRevision aceRevision, [[maybe_unused]] WindowDWord startingAceIndex, [[maybe_unused]] WindowVoidPtr aceList, [[maybe_unused]] WindowDWord aceListLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::AddAce(acl, EnumCastUnderlying(aceRevision), startingAceIndex, aceList, aceListLength) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AddMandatoryAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] AccessControlListRevision aceRevision, [[maybe_unused]] ControlACEInheritance aceFlags, [[maybe_unused]] MandatoryPolicy mandatoryPolicy, [[maybe_unused]] SecuritySIDPtr labelSid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::AddMandatoryAce(acl, EnumCastUnderlying(aceRevision), EnumCastUnderlying(aceFlags), EnumCastUnderlying(mandatoryPolicy), labelSid) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DeleteAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] WindowDWord aceIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::DeleteAce(acl, aceIndex) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FindFirstFreeAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] WindowVoidPtr* ace) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::FindFirstFreeAce(acl, ace) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetAccessControlEntries([[maybe_unused]] AccessCheckACLPtr acl, [[maybe_unused]] WindowDWord aceIndex, [[maybe_unused]] WindowVoidPtr* ace) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetAce(acl, aceIndex, ace) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}