///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 11:09)

#include "System/SystemExport.h"

#include "SecurityBase.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/ThreadTools.h"
#include "System/Windows/WindowsSystem.h"

bool System::IsSystemTokenElevated() noexcept
{
    WindowsHandle tokenHandle{ nullptr };
    if (!OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle))
    {
        return false;
    }

    SecurityTokenElevation tokenInformation{};
    WindowsDWord returnLength{ 0 };

    if (!GetSystemTokenInformation(tokenHandle, TokenElevation, &tokenInformation, sizeof(tokenInformation), &returnLength))
    {
        return false;
    }

    if (!CloseTokenHandle(tokenHandle))
    {
        OutputDebugStringWithTChar(SYSTEM_TEXT("IsSystemTokenElevated句柄释放失败。\n"));
    }

    return tokenInformation.TokenIsElevated != gFalse;
}

bool System::GetAdjustTokenGroups(WindowsHandle tokenHandle,
                                  bool resetToDefault,
                                  SecurityTokenGroupsPtr newState,
                                  WindowsDWord bufferLength,
                                  SecurityTokenGroupsPtr previousState,
                                  WindowsDWordPtr returnLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AdjustTokenGroups(tokenHandle, BoolConversion(resetToDefault), newState, bufferLength, previousState, returnLength) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(tokenHandle,
                   resetToDefault,
                   newState,
                   bufferLength,
                   previousState,
                   returnLength);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetAdjustTokenPrivileges(WindowsHandle tokenHandle,
                                      bool disableAllPrivileges,
                                      SecurityTokenPrivilegesPtr newState,
                                      WindowsDWord bufferLength,
                                      SecurityTokenPrivilegesPtr previousState,
                                      WindowsDWordPtr returnLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AdjustTokenPrivileges(tokenHandle, BoolConversion(disableAllPrivileges), newState, bufferLength, previousState, returnLength) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(tokenHandle,
                   disableAllPrivileges,
                   newState,
                   bufferLength,
                   previousState,
                   returnLength);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsAreAllAccessesGranted(AccessGenericMask grantedAccess, AccessGenericMask desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AreAllAccessesGranted(EnumCastUnderlying(grantedAccess), EnumCastUnderlying(desiredAccess)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(grantedAccess, desiredAccess);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsAreAnyAccessesGranted(AccessGenericMask grantedAccess, AccessGenericMask desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AreAnyAccessesGranted(EnumCastUnderlying(grantedAccess), EnumCastUnderlying(desiredAccess)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(grantedAccess, desiredAccess);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CreateSystemRestrictedToken(WindowsHandle existingTokenHandle,
                                         SpecifiesAdditionalPrivilegeOptions flags,
                                         WindowsDWord disableSidCount,
                                         SecuritySidAndAttributesPtr sidsToDisable,
                                         WindowsDWord deletePrivilegeCount,
                                         LUIDAndAttributesPtr privilegesToDelete,
                                         WindowsDWord restrictedSidCount,
                                         SecuritySidAndAttributesPtr sidsToRestrict,
                                         WindowsHandlePtr newTokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CreateRestrictedToken(existingTokenHandle,
                                EnumCastUnderlying(flags),
                                disableSidCount,
                                sidsToDisable,
                                deletePrivilegeCount,
                                privilegesToDelete,
                                restrictedSidCount,
                                sidsToRestrict,
                                newTokenHandle) != gFalse)
    {
        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(existingTokenHandle,
                   flags,
                   disableSidCount,
                   sidsToDisable,
                   deletePrivilegeCount,
                   privilegesToDelete,
                   restrictedSidCount,
                   sidsToRestrict,
                   newTokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DuplicateSystemToken(WindowsHandle existingTokenHandle, SecurityImpersonationLevel impersonationLevel, WindowsHandlePtr duplicateTokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::DuplicateToken(existingTokenHandle, impersonationLevel, duplicateTokenHandle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(existingTokenHandle, impersonationLevel, duplicateTokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::DuplicateSystemToken(WindowsHandle existingTokenHandle,
                                  TokenStandardAccess standardAccess,
                                  TokenSpecificAccess specificAccess,
                                  WindowSecurityAttributesPtr tokenAttributes,
                                  SecurityImpersonationLevel impersonationLevel,
                                  SecurityTokenType tokenType,
                                  WindowsHandlePtr newToken) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::DuplicateTokenEx(existingTokenHandle, EnumCastUnderlying(standardAccess) | EnumCastUnderlying(specificAccess), tokenAttributes, impersonationLevel, tokenType, newToken) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(existingTokenHandle,
                   standardAccess,
                   specificAccess,
                   tokenAttributes,
                   impersonationLevel,
                   tokenType,
                   newToken);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemTokenInformation(WindowsHandle handle,
                                       TokenInformationClass tokenInformationClass,
                                       WindowsVoidPtr tokenInformation,
                                       WindowsDWord tokenInformationLength,
                                       WindowsDWordPtr returnLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetTokenInformation(handle, tokenInformationClass, tokenInformation, tokenInformationLength, returnLength) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(handle, tokenInformationClass, tokenInformation, tokenInformationLength, returnLength);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSystemTokenRestricted(WindowsHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::IsTokenRestricted(tokenHandle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(tokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::QuerySystemSecurityAccessMask(SecurityRequestedInformation securityInformation, WindowsDWordPtr desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::QuerySecurityAccessMask(EnumCastUnderlying(securityInformation), desiredAccess);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(securityInformation, desiredAccess);

#endif  // SYSTEM_PLATFORM_WIN32
}
