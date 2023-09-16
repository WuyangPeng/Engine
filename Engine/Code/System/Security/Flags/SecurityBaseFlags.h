///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/30 15:01)

#ifndef SYSTEM_SECURITY_SECURITY_BASE_FLAGS_H
#define SYSTEM_SECURITY_SECURITY_BASE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class SecurityTokenAttributesPrivilege : uint32_t
    {
        EnabledByDefault = SE_PRIVILEGE_ENABLED_BY_DEFAULT,
        Enabled = SE_PRIVILEGE_ENABLED,
        Removed = SE_PRIVILEGE_REMOVED,
        UsedForAccess = SE_PRIVILEGE_USED_FOR_ACCESS,
        ValidAttributes = SE_PRIVILEGE_VALID_ATTRIBUTES,
    };

    enum class SecurityTokenAttributesGroup : uint32_t
    {
        Mandatory = SE_GROUP_MANDATORY,
        EnabledByDefault = SE_GROUP_ENABLED_BY_DEFAULT,
        Enabled = SE_GROUP_ENABLED,
        Owner = SE_GROUP_OWNER,
        UseForDenyOnly = SE_GROUP_USE_FOR_DENY_ONLY,
        Integrity = SE_GROUP_INTEGRITY,
        IntegrityEnabled = SE_GROUP_INTEGRITY_ENABLED,
        LogonId = SE_GROUP_LOGON_ID,
        Resource = SE_GROUP_RESOURCE,

        ValidAttributes = SE_GROUP_VALID_ATTRIBUTES,
    };

    enum class SpecifiesAdditionalPrivilegeOptions
    {
        Default = 0x0,
        DisableMaxPrivilege = DISABLE_MAX_PRIVILEGE,
        SandboxInert = SANDBOX_INERT,
        LuaToken = LUA_TOKEN,
        WriteRestricted = WRITE_RESTRICTED,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class SecurityTokenAttributesPrivilege : uint32_t
    {
        EnabledByDefault = 0x00000001L,
        Enabled = 0x00000002L,
        Removed = 0X00000004L,
        UsedForAccess = 0x80000000L,
        ValidAttributes = EnabledByDefault | Enabled | Removed | UsedForAccess,
    };

    enum class SecurityTokenAttributesGroup : uint32_t
    {
        Mandatory = (0x00000001L),
        EnabledByDefault = (0x00000002L),
        Enabled = (0x00000004L),
        Owner = (0x00000008L),
        UseForDenyOnly = (0x00000010L),
        Integrity = (0x00000020L),
        IntegrityEnabled = (0x00000040L),
        LogonId = (0xC0000000L),
        Resource = (0x20000000L),

        ValidAttributes = (Mandatory |
                           EnabledByDefault |
                           Enabled |
                           Owner |
                           UseForDenyOnly |
                           LogonId |
                           Resource |
                           Integrity |
                           IntegrityEnabled),
    };

    enum class SpecifiesAdditionalPrivilegeOptions
    {
        Default = 0x0,
        DisableMaxPrivilege = 0x1,
        SandboxInert = 0x2,
        LuaToken = 0x4,
        WriteRestricted = 0x8,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_SECURITY_BASE_FLAGS_H
