//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 17:28)

#include "System/SystemExport.h"

#include "SecurityDescriptor.h"
#include "Flags/SecurityDescriptorFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

bool System::InitializeSystemSecurityDescriptor([[maybe_unused]] SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::InitializeSecurityDescriptor(securityDescriptor, EnumCastUnderlying(InitializeSecurityDescriptorRevision::Revision)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemSecurityDescriptorControl([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] SecurityDescriptorControlBits controlBitsOfInterest, [[maybe_unused]] SecurityDescriptorControlBits controlBitsToSet) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetSecurityDescriptorControl(securityDescriptor, static_cast<SecurityDescriptorControl>(controlBitsOfInterest), static_cast<SecurityDescriptorControl>(controlBitsToSet)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSecurityDescriptorDiscretionaryAccessControlList([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] bool daclPresent, [[maybe_unused]] AccessCheckACLPtr dacl, [[maybe_unused]] bool daclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetSecurityDescriptorDacl(securityDescriptor, BoolConversion(daclPresent), dacl, daclDefaulted) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemSecurityDescriptorGroup([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] SecuritySIDPtr group, [[maybe_unused]] bool groupDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetSecurityDescriptorGroup(securityDescriptor, group, BoolConversion(groupDefaulted)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemSecurityDescriptorOwner([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] SecuritySIDPtr group, [[maybe_unused]] bool ownerDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetSecurityDescriptorOwner(securityDescriptor, group, BoolConversion(ownerDefaulted)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSecurityDescriptorResourceManagerControl([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] WindowUCharPtr rmControl) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetSecurityDescriptorRMControl(securityDescriptor, rmControl) == EnumCastUnderlying<WindowDWord>(SecurityDescriptorRMControlReturn::Success))
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSecurityDescriptorSystemAccessControlList([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] bool saclPresent, [[maybe_unused]] AccessCheckACLPtr sacl, [[maybe_unused]] bool saclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetSecurityDescriptorSacl(securityDescriptor, BoolConversion(saclPresent), sacl, BoolConversion(saclDefaulted)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemSecurityDescriptorControl([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] SecurityDescriptorControlBits* control, [[maybe_unused]] WindowDWordPtr revision) noexcept
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
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSecurityDescriptorDiscretionaryAccessControlList([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] WindowBoolPtr daclPresent, [[maybe_unused]] AccessCheckACLPtr* dacl, [[maybe_unused]] bool* daclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    WindowBool result{ g_False };
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
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemSecurityDescriptorGroup([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] SecuritySIDPtr* group, [[maybe_unused]] bool* groupDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    WindowBool result{ g_False };
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
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemSecurityDescriptorLength([[maybe_unused]] SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetSecurityDescriptorLength(securityDescriptor);
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemSecurityDescriptorOwner([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] SecuritySIDPtr* owner, [[maybe_unused]] bool* ownerDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    WindowBool result{ g_False };
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
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSecurityDescriptorResourceManagerControl([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] WindowUCharPtr rmControl) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetSecurityDescriptorRMControl(securityDescriptor, rmControl) == EnumCastUnderlying<WindowDWord>(SecurityDescriptorRMControlReturn::Success))
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSecurityDescriptorSystemAccessControlList([[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] WindowBoolPtr saclPresent, [[maybe_unused]] AccessCheckACLPtr* sacl, [[maybe_unused]] bool* saclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    WindowBool result{ g_False };
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
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSecurityDescriptorValid([[maybe_unused]] SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::IsValidSecurityDescriptor(securityDescriptor) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32

    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetUserObjectSystemSecurity([[maybe_unused]] ThreadHandle obj, [[maybe_unused]] SecurityRequestedInformation requested, [[maybe_unused]] SecurityDescriptorPtr securityDescriptor, [[maybe_unused]] WindowDWord length, [[maybe_unused]] WindowDWordPtr lengthNeeded) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    SecurityInformation securityInformation{ EnumCastUnderlying<SecurityInformation>(requested) };
    if (g_False != ::GetUserObjectSecurity(obj, &securityInformation, securityDescriptor, length, lengthNeeded))
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
