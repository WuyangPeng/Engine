/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:37)

#include "System/SystemExport.h"

#include "SecurityDescriptor.h"
#include "Flags/SecurityDescriptorFlags.h"
#include "Using/SecurityDescriptorUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

bool System::InitializeSystemSecurityDescriptor(SecurityDescriptorPtr securityDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InitializeSecurityDescriptor(securityDescriptor, EnumCastUnderlying(InitializeSecurityDescriptorRevision::Revision)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor, SecurityDescriptorControlBits controlBitsOfInterest, SecurityDescriptorControlBits controlBitsToSet) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetSecurityDescriptorControl(securityDescriptor, static_cast<SecurityDescriptorControl>(controlBitsOfInterest), static_cast<SecurityDescriptorControl>(controlBitsToSet)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, controlBitsOfInterest, controlBitsToSet);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor, bool daclPresent, AccessCheckAclPtr dacl, bool daclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetSecurityDescriptorDacl(securityDescriptor, BoolConversion(daclPresent), dacl, daclDefaulted) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, daclPresent, dacl, daclDefaulted);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor, SecuritySidPtr group, bool groupDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetSecurityDescriptorGroup(securityDescriptor, group, BoolConversion(groupDefaulted)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, group, groupDefaulted);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor, SecuritySidPtr group, bool ownerDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetSecurityDescriptorOwner(securityDescriptor, group, BoolConversion(ownerDefaulted)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, group, ownerDefaulted);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor, WindowsUCharPtr rmControl) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetSecurityDescriptorRMControl(securityDescriptor, rmControl) == EnumCastUnderlying<WindowsDWord>(SecurityDescriptorRmControlReturn::Success);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, rmControl);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor, bool saclPresent, AccessCheckAclPtr sacl, bool saclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetSecurityDescriptorSacl(securityDescriptor, BoolConversion(saclPresent), sacl, BoolConversion(saclDefaulted)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, saclPresent, sacl, saclDefaulted);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor, SecurityDescriptorControlBits* control, WindowsDWordPtr revision) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    SecurityDescriptorControl securityDescriptorControl{ 0 };
    if (::GetSecurityDescriptorControl(securityDescriptor, &securityDescriptorControl, revision) != gFalse)
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

bool System::GetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor, bool* daclPresent, AccessCheckAclPtr* dacl, bool* daclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsBool daclPresentResult{ gFalse };
    WindowsBool daclDefaultedResult{ gFalse };
    if (::GetSecurityDescriptorDacl(securityDescriptor, &daclPresentResult, dacl, &daclDefaultedResult) != gFalse)
    {
        BoolConversion(daclPresentResult, daclPresent);
        BoolConversion(daclDefaultedResult, daclDefaulted);

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

bool System::GetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor, SecuritySidPtr* group, bool* groupDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsBool result{ gFalse };
    if (::GetSecurityDescriptorGroup(securityDescriptor, group, &result) != gFalse)
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

bool System::GetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor, SecuritySidPtr* owner, bool* ownerDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsBool result{ gFalse };
    if (::GetSecurityDescriptorOwner(securityDescriptor, owner, &result) != gFalse)
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

    return ::GetSecurityDescriptorRMControl(securityDescriptor, rmControl) == EnumCastUnderlying<WindowsDWord>(SecurityDescriptorRmControlReturn::Success);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor, rmControl);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor, bool* saclPresent, AccessCheckAclPtr* sacl, bool* saclDefaulted) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    WindowsBool saclPresentResult{ gFalse };
    WindowsBool saclDefaultedResult{ gFalse };
    if (::GetSecurityDescriptorSacl(securityDescriptor, &saclPresentResult, sacl, &saclDefaultedResult) != gFalse)
    {
        BoolConversion(saclPresentResult, saclPresent);
        BoolConversion(saclDefaultedResult, saclDefaulted);

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

    return ::IsValidSecurityDescriptor(securityDescriptor) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityDescriptor);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetUserObjectSystemSecurity(ThreadHandle obj, SecurityRequestedInformation requested, SecurityDescriptorPtr securityDescriptor, WindowsDWord length, WindowsDWordPtr lengthNeeded) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    auto securityInformation = EnumCastUnderlying<SecurityInformation>(requested);

    return ::GetUserObjectSecurity(obj, &securityInformation, securityDescriptor, length, lengthNeeded) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(obj, requested, securityDescriptor, length, lengthNeeded);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}