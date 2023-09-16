///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/30 15:17)

#include "System/SystemExport.h"

#include "SecuritySid.h"
#include "System/Helper/WindowsMacro.h"

bool System::AllocateAndInitializeSecurityIdentifier(SecuritySidIdentifierAuthorityPtr identifierAuthority,
                                                     WindowsByte subAuthorityCount,
                                                     WindowsDWord subAuthority0,
                                                     WindowsDWord subAuthority1,
                                                     WindowsDWord subAuthority2,
                                                     WindowsDWord subAuthority3,
                                                     WindowsDWord subAuthority4,
                                                     WindowsDWord subAuthority5,
                                                     WindowsDWord subAuthority6,
                                                     WindowsDWord subAuthority7,
                                                     SecuritySidPtr* sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AllocateAndInitializeSid(identifierAuthority, subAuthorityCount, subAuthority0, subAuthority1, subAuthority2, subAuthority3, subAuthority4, subAuthority5, subAuthority6, subAuthority7, sid) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(identifierAuthority,
                   subAuthorityCount,
                   subAuthority0,
                   subAuthority1,
                   subAuthority2,
                   subAuthority3,
                   subAuthority4,
                   subAuthority5,
                   subAuthority6,
                   subAuthority7,
                   sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CopySecurityIdentifier(WindowsDWord destinationSidLength, SecuritySidPtr destinationSid, SecuritySidPtr sourceSid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CopySid(destinationSidLength, destinationSid, sourceSid) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(destinationSidLength, destinationSid, sourceSid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CreateWellKnownSecurityIdentifier(SecurityWellKnownSidType wellKnownSidType, SecuritySidPtr domainSid, SecuritySidPtr sid, WindowsDWord* sidCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CreateWellKnownSid(wellKnownSidType, domainSid, sid, sidCount) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(wellKnownSidType, domainSid, sid, sidCount);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsVoidPtr System::FreeSecurityIdentifier(SecuritySidPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::FreeSid(sid);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(sid);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetLengthSecurityIdentifier(SecuritySidPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetLengthSid(sid);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(sid);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWordPtr System::GetSecurityIdentifierSubAuthority(SecuritySidPtr sid, WindowsDWord subAuthority) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetSidSubAuthority(sid, subAuthority);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(sid, subAuthority);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsUCharPtr System::GetSecurityIdentifierSubAuthorityCount(SecuritySidPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetSidSubAuthorityCount(sid);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(sid);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::InitializeSecurityIdentifier(SecuritySidPtr sid, SecuritySidIdentifierAuthorityPtr identifierAuthority, WindowsByte subAuthorityCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::InitializeSid(sid, identifierAuthority, subAuthorityCount) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(sid, identifierAuthority, subAuthorityCount);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSecurityIdentifierValid(SecuritySidPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::IsValidSid(sid) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsWellKnownSecurityIdentifier(SecuritySidPtr sid, SecurityWellKnownSidType wellKnownSidType) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::IsWellKnownSid(sid, wellKnownSidType) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(sid, wellKnownSidType);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
