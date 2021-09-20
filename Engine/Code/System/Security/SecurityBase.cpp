///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.4 (2021/05/27 22:55)

#include "System/SystemExport.h"

#include "SecurityBase.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
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

    MAYBE_UNUSED const auto result = CloseTokenHandle(tokenHandle);

    return tokenInformation.TokenIsElevated != g_False;
}

bool System::GetAdjustTokenGroups(WindowsHandle tokenHandle,
                                  bool resetToDefault,
                                  SecurityTokenGroupsPtr newState,
                                  WindowsDWord bufferLength,
                                  SecurityTokenGroupsPtr previousState,
                                  WindowsDWordPtr returnLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AdjustTokenGroups(tokenHandle, BoolConversion(resetToDefault), newState, bufferLength, previousState, returnLength) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle,
                 bool,
                 SecurityTokenGroupsPtr,
                 WindowsDWord,
                 SecurityTokenGroupsPtr,
                 WindowsDWordPtr>(tokenHandle,
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

    if (::AdjustTokenPrivileges(tokenHandle, BoolConversion(disableAllPrivileges), newState, bufferLength, previousState, returnLength) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle,
                 bool,
                 SecurityTokenPrivilegesPtr,
                 WindowsDWord,
                 SecurityTokenPrivilegesPtr,
                 WindowsDWordPtr>(tokenHandle,
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

    if (::AreAllAccessesGranted(EnumCastUnderlying(grantedAccess), EnumCastUnderlying(desiredAccess)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<AccessGenericMask, AccessGenericMask>(grantedAccess, desiredAccess);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsAreAnyAccessesGranted(AccessGenericMask grantedAccess, AccessGenericMask desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AreAnyAccessesGranted(EnumCastUnderlying(grantedAccess), EnumCastUnderlying(desiredAccess)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<AccessGenericMask, AccessGenericMask>(grantedAccess, desiredAccess);

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
                                newTokenHandle) != g_False)
    {
        return true;
    }
    else
    {
        return false;
    }

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle,
                 SpecifiesAdditionalPrivilegeOptions,
                 WindowsDWord,
                 SecuritySidAndAttributesPtr,
                 WindowsDWord,
                 LUIDAndAttributesPtr,
                 WindowsDWord,
                 SecuritySidAndAttributesPtr,
                 WindowsHandlePtr>(existingTokenHandle,
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

    if (::DuplicateToken(existingTokenHandle, impersonationLevel, duplicateTokenHandle) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, SecurityImpersonationLevel, WindowsHandlePtr>(existingTokenHandle, impersonationLevel, duplicateTokenHandle);

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

    if (::DuplicateTokenEx(existingTokenHandle, EnumCastUnderlying(standardAccess) | EnumCastUnderlying(specificAccess), tokenAttributes, impersonationLevel, tokenType, newToken) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle,
                 TokenStandardAccess,
                 TokenSpecificAccess,
                 WindowSecurityAttributesPtr,
                 SecurityImpersonationLevel,
                 SecurityTokenType,
                 WindowsHandlePtr>(existingTokenHandle,
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

    if (::GetTokenInformation(handle, tokenInformationClass, tokenInformation, tokenInformationLength, returnLength) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, TokenInformationClass, WindowsVoidPtr, WindowsDWord, WindowsDWordPtr>(handle, tokenInformationClass, tokenInformation, tokenInformationLength, returnLength);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSystemTokenRestricted(WindowsHandle tokenHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::IsTokenRestricted(tokenHandle) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<ThreadHandle>(tokenHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::QuerySystemSecurityAccessMask(SecurityRequestedInformation securityInformation, WindowsDWordPtr desiredAccess) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::QuerySecurityAccessMask(EnumCastUnderlying(securityInformation), desiredAccess);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<SecurityRequestedInformation, WindowsDWordPtr>(securityInformation, desiredAccess);

#endif  // SYSTEM_PLATFORM_WIN32
}
