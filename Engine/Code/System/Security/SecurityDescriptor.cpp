///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 11:14)

#include "System/SystemExport.h"

#include "SecurityDescriptor.h"
#include "Flags/SecurityDescriptorFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

bool System::InitializeSystemSecurityDescriptor(SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::InitializeSecurityDescriptor(securityDescriptor, EnumCastUnderlying(InitializeSecurityDescriptorRevision::Revision)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor, SecurityDescriptorControlBits controlBitsOfInterest, SecurityDescriptorControlBits controlBitsToSet) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetSecurityDescriptorControl(securityDescriptor, static_cast<SecurityDescriptorControl>(controlBitsOfInterest), static_cast<SecurityDescriptorControl>(controlBitsToSet)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, controlBitsOfInterest, controlBitsToSet);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor, bool daclPresent, AccessCheckACLPtr dacl, bool daclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetSecurityDescriptorDacl(securityDescriptor, BoolConversion(daclPresent), dacl, daclDefaulted) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, daclPresent, dacl, daclDefaulted);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr group, bool groupDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetSecurityDescriptorGroup(securityDescriptor, group, BoolConversion(groupDefaulted)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, group, groupDefaulted);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr group, bool ownerDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetSecurityDescriptorOwner(securityDescriptor, group, BoolConversion(ownerDefaulted)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, group, ownerDefaulted);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor, WindowsUCharPtr rmControl) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetSecurityDescriptorRMControl(securityDescriptor, rmControl) == EnumCastUnderlying<WindowsDWord>(SecurityDescriptorRMControlReturn::Success))
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, rmControl);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor, bool saclPresent, AccessCheckACLPtr sacl, bool saclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetSecurityDescriptorSacl(securityDescriptor, BoolConversion(saclPresent), sacl, BoolConversion(saclDefaulted)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, saclPresent, sacl, saclDefaulted);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor, SecurityDescriptorControlBits* control, WindowsDWordPtr revision) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    SecurityDescriptorControl securityDescriptorControl{ 0 };
    if (::GetSecurityDescriptorControl(securityDescriptor, &securityDescriptorControl, revision) != g_False)
    {
        UnderlyingCastEnumPtr(securityDescriptorControl, control);

        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, control, revision);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor, WindowsBoolPtr daclPresent, AccessCheckACLPtr* dacl, bool* daclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsBool result{ g_False };
    if (::GetSecurityDescriptorDacl(securityDescriptor, daclPresent, dacl, &result) != g_False)
    {
        BoolConversion(result, daclDefaulted);

        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, daclPresent, dacl, daclDefaulted);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr* group, bool* groupDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsBool result{ g_False };
    if (::GetSecurityDescriptorGroup(securityDescriptor, group, &result) != g_False)
    {
        BoolConversion(result, groupDefaulted);

        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, group, groupDefaulted);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetSystemSecurityDescriptorLength(SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetSecurityDescriptorLength(securityDescriptor);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr* owner, bool* ownerDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsBool result{ g_False };
    if (::GetSecurityDescriptorOwner(securityDescriptor, owner, &result) != g_False)
    {
        BoolConversion(result, ownerDefaulted);

        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, owner, ownerDefaulted);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor, WindowsUCharPtr rmControl) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetSecurityDescriptorRMControl(securityDescriptor, rmControl) == EnumCastUnderlying<WindowsDWord>(SecurityDescriptorRMControlReturn::Success))
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, rmControl);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor, WindowsBoolPtr saclPresent, AccessCheckACLPtr* sacl, bool* saclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsBool result{ g_False };
    if (::GetSecurityDescriptorSacl(securityDescriptor, saclPresent, sacl, &result) != g_False)
    {
        BoolConversion(result, saclDefaulted);

        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, saclPresent, sacl, saclDefaulted);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSecurityDescriptorValid(SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::IsValidSecurityDescriptor(securityDescriptor) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetUserObjectSystemSecurity(ThreadHandle obj, SecurityRequestedInformation requested, SecurityDescriptorPtr securityDescriptor, WindowsDWord length, WindowsDWordPtr lengthNeeded) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    auto securityInformation = EnumCastUnderlying<SecurityInformation>(requested);
    if (g_False != ::GetUserObjectSecurity(obj, &securityInformation, securityDescriptor, length, lengthNeeded))
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(obj, requested, securityDescriptor, length, lengthNeeded);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
