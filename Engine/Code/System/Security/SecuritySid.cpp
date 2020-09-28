//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 17:31)

#include "System/SystemExport.h"

#include "SecuritySid.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"

bool System::AllocateAndInitializeSecurityIdentifier([[maybe_unused]] SecuritySIDIndentifierAuthorityPtr identifierAuthority, [[maybe_unused]] WindowByte subAuthorityCount, [[maybe_unused]] WindowDWord subAuthority0, [[maybe_unused]] WindowDWord subAuthority1,
                                                     [[maybe_unused]] WindowDWord subAuthority2, [[maybe_unused]] WindowDWord subAuthority3, [[maybe_unused]] WindowDWord subAuthority4, [[maybe_unused]] WindowDWord subAuthority5,
                                                     [[maybe_unused]] WindowDWord subAuthority6, [[maybe_unused]] WindowDWord subAuthority7, [[maybe_unused]] SecuritySIDPtr* sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::AllocateAndInitializeSid(identifierAuthority, subAuthorityCount, subAuthority0, subAuthority1, subAuthority2, subAuthority3, subAuthority4, subAuthority5, subAuthority6, subAuthority7, sid) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CopySecurityIdentifier([[maybe_unused]] WindowDWord destinationSidLength, [[maybe_unused]] SecuritySIDPtr destinationSid, [[maybe_unused]] SecuritySIDPtr sourceSid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CopySid(destinationSidLength, destinationSid, sourceSid) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CreateWellKnownSecurityIdentifier([[maybe_unused]] SecurityWellKnownSidType wellKnownSidType, [[maybe_unused]] SecuritySIDPtr domainSid, [[maybe_unused]] SecuritySIDPtr sid, [[maybe_unused]] WindowDWord* sidCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CreateWellKnownSid(wellKnownSidType, domainSid, sid, sidCount) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EqualDomainSecurityIdentifier([[maybe_unused]] SecuritySIDPtr sid1, [[maybe_unused]] SecuritySIDPtr sid2, [[maybe_unused]] bool* equal) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    WindowBool result{ g_False };
    if (::EqualDomainSid(sid1, sid2, &result) != g_False)
    {
        BoolConversion(result, equal);

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

bool System::EqualPrefixSecurityIdentifier([[maybe_unused]] SecuritySIDPtr sid1, [[maybe_unused]] SecuritySIDPtr sid2) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::EqualPrefixSid(sid1, sid2) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EqualSecurityIdentifier([[maybe_unused]] SecuritySIDPtr sid1, [[maybe_unused]] SecuritySIDPtr sid2) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::EqualSid(sid1, sid2) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::FreeSecurityIdentifier([[maybe_unused]] SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::FreeSid(sid);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetLengthSecurityIdentifier([[maybe_unused]] SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetLengthSid(sid);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSecurityIdentifierLengthRequired([[maybe_unused]] WindowUChar subAuthorityCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetSidLengthRequired(subAuthorityCount);
#else  // !SYSTEM_PLATFORM_WIN32
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWordPtr System::GetSecurityIdentifierSubAuthority([[maybe_unused]] SecuritySIDPtr sid, [[maybe_unused]] WindowDWord subAuthority) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetSidSubAuthority(sid, subAuthority);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowUCharPtr System::GetSecurityIdentifierSubAuthorityCount([[maybe_unused]] SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetSidSubAuthorityCount(sid);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::InitializeSecurityIdentifier([[maybe_unused]] SecuritySIDPtr sid, [[maybe_unused]] SecuritySIDIndentifierAuthorityPtr identifierAuthority, [[maybe_unused]] WindowByte subAuthorityCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::InitializeSid(sid, identifierAuthority, subAuthorityCount) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSecurityIdentifierValid([[maybe_unused]] SecuritySIDPtr sid) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::IsValidSid(sid) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsWellKnownSecurityIdentifier([[maybe_unused]] SecuritySIDPtr sid, [[maybe_unused]] SecurityWellKnownSidType wellKnownSidType) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::IsWellKnownSid(sid, wellKnownSidType) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
