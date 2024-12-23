/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:48)

#ifndef SYSTEM_SECURITY_CREATE_SECURITY_FLAGS_H
#define SYSTEM_SECURITY_CREATE_SECURITY_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class SecurityRequestedInformation : uint32_t
    {
        Owner = OWNER_SECURITY_INFORMATION,
        Group = GROUP_SECURITY_INFORMATION,
        Dacl = DACL_SECURITY_INFORMATION,
        Sacl = SACL_SECURITY_INFORMATION,
        Label = LABEL_SECURITY_INFORMATION,

        ProtectedDacl = PROTECTED_DACL_SECURITY_INFORMATION,
        ProtectedSacl = PROTECTED_SACL_SECURITY_INFORMATION,
        UnprotectedDacl = UNPROTECTED_DACL_SECURITY_INFORMATION,
        UnprotectedSacl = UNPROTECTED_SACL_SECURITY_INFORMATION,
    };

    enum class SecurityAutoInherit
    {
        DaclAutoInherit = SEF_DACL_AUTO_INHERIT,
        SaclAutoInherit = SEF_SACL_AUTO_INHERIT,
        DefaultDescriptorForObject = SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT,
        AvoidPrivilegeCheck = SEF_AVOID_PRIVILEGE_CHECK,
        AvoidOwnerCheck = SEF_AVOID_OWNER_CHECK,
        DefaultOwnerFromParent = SEF_DEFAULT_OWNER_FROM_PARENT,
        DefaultGroupFromParent = SEF_DEFAULT_GROUP_FROM_PARENT,
        MaclNoWriteUp = SEF_MACL_NO_WRITE_UP,
        MaclNoReadUp = SEF_MACL_NO_READ_UP,
        MaclNoExecuteUp = SEF_MACL_NO_EXECUTE_UP,
        AvoidOwnerRestriction = SEF_AVOID_OWNER_RESTRICTION,
        MaclValidFlags = SEF_MACL_VALID_FLAGS,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class SecurityRequestedInformation : uint32_t
    {
        Owner = (0x00000001L),
        Group = (0x00000002L),
        Dacl = (0x00000004L),
        Sacl = (0x00000008L),
        Label = (0x00000010L),

        ProtectedDacl = (0x80000000L),
        ProtectedSacl = (0x40000000L),
        UnprotectedDacl = (0x20000000L),
        UnprotectedSacl = (0x10000000L),
    };

    enum class SecurityAutoInherit
    {
        DaclAutoInherit = 0x01,
        SaclAutoInherit = 0x02,
        DefaultDescriptorForObject = 0x04,
        AvoidPrivilegeCheck = 0x08,
        AvoidOwnerCheck = 0x10,
        DefaultOwnerFromParent = 0x20,
        DefaultGroupFromParent = 0x40,
        MaclNoWriteUp = 0x100,
        MaclNoReadUp = 0x200,
        MaclNoExecuteUp = 0x400,
        AiUseExtraParams = 0x800,
        AvoidOwnerRestriction = 0x1000,
        MaclValidFlags = (MaclNoWriteUp | MaclNoReadUp | MaclNoExecuteUp),
    };

#endif  // SYSTEM_PLATFORM_WIN32

}

#endif  // SYSTEM_SECURITY_CREATE_SECURITY_FLAGS_H
