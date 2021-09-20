///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.4 (2021/05/25 20:32)

#include "System/SystemExport.h"

#include "SecuritySid.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

bool System::AllocateAndInitializeSecurityIdentifier(SecuritySIDIndentifierAuthorityPtr identifierAuthority,
                                                     WindowsByte subAuthorityCount,
                                                     WindowsDWord subAuthority0,
                                                     WindowsDWord subAuthority1,
                                                     WindowsDWord subAuthority2,
                                                     WindowsDWord subAuthority3,
                                                     WindowsDWord subAuthority4,
                                                     WindowsDWord subAuthority5,
                                                     WindowsDWord subAuthority6,
                                                     WindowsDWord subAuthority7,
                                                     SecuritySIDPtr* sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AllocateAndInitializeSid(identifierAuthority, subAuthorityCount, subAuthority0, subAuthority1, subAuthority2, subAuthority3, subAuthority4, subAuthority5, subAuthority6, subAuthority7, sid) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<SecuritySIDIndentifierAuthorityPtr,
                 WindowsByte,
                 WindowsDWord,
                 WindowsDWord,
                 WindowsDWord,
                 WindowsDWord,
                 WindowsDWord,
                 WindowsDWord,
                 WindowsDWord,
                 WindowsDWord,
                 SecuritySIDPtr*>(identifierAuthority,
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

bool System::CopySecurityIdentifier(WindowsDWord destinationSidLength, SecuritySIDPtr destinationSid, SecuritySIDPtr sourceSid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CopySid(destinationSidLength, destinationSid, sourceSid) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsDWord, SecuritySIDPtr, SecuritySIDPtr>(destinationSidLength, destinationSid, sourceSid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CreateWellKnownSecurityIdentifier(SecurityWellKnownSidType wellKnownSidType, SecuritySIDPtr domainSid, SecuritySIDPtr sid, WindowsDWord* sidCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CreateWellKnownSid(wellKnownSidType, domainSid, sid, sidCount) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<SecurityWellKnownSidType, SecuritySIDPtr, SecuritySIDPtr, WindowsDWord*>(wellKnownSidType, domainSid, sid, sidCount);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsVoidPtr System::FreeSecurityIdentifier(SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::FreeSid(sid);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<SecuritySIDPtr>(sid);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetLengthSecurityIdentifier(SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetLengthSid(sid);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<SecuritySIDPtr>(sid);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWordPtr System::GetSecurityIdentifierSubAuthority(SecuritySIDPtr sid, WindowsDWord subAuthority) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetSidSubAuthority(sid, subAuthority);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<SecuritySIDPtr, WindowsDWord>(sid, subAuthority);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsUCharPtr System::GetSecurityIdentifierSubAuthorityCount(SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetSidSubAuthorityCount(sid);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<SecuritySIDPtr>(sid);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::InitializeSecurityIdentifier(SecuritySIDPtr sid, SecuritySIDIndentifierAuthorityPtr identifierAuthority, WindowsByte subAuthorityCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::InitializeSid(sid, identifierAuthority, subAuthorityCount) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<SecuritySIDPtr, SecuritySIDIndentifierAuthorityPtr, WindowsByte>(sid, identifierAuthority, subAuthorityCount);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSecurityIdentifierValid(SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::IsValidSid(sid) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<SecuritySIDPtr>(sid);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsWellKnownSecurityIdentifier(SecuritySIDPtr sid, SecurityWellKnownSidType wellKnownSidType) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::IsWellKnownSid(sid, wellKnownSidType) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<SecuritySIDPtr, SecurityWellKnownSidType>(sid, wellKnownSidType);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
