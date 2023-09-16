///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/30 15:07)

#ifndef SYSTEM_SECURITY_SECURITY_FLAGS_FWD_H
#define SYSTEM_SECURITY_SECURITY_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    // AccessCheck
    enum class AccessGenericMask;

    // AddAccess
    enum class SpecificAccess;

    // CreateSecurity
    enum class SecurityRequestedInformation : uint32_t;
    enum class SecurityAutoInherit;

    // SecurityAce
    enum class ControlAceInheritance;
    enum class MandatoryPolicy;

    // SecurityAcl
    enum class AccessControlListRevision;

    // SecurityBase
    enum class SecurityTokenAttributesPrivilege : uint32_t;
    enum class SecurityTokenAttributesGroup : uint32_t;
    enum class SpecifiesAdditionalPrivilegeOptions;

    // SecurityDescriptor
    enum class InitializeSecurityDescriptorRevision;
    enum class SecurityDescriptorControlBits;
    enum class SecurityDescriptorRmControlReturn;

    // SecuritySid
    enum class MandatoryLabelAuthority;
    enum class WellKnownAliases;
    enum class WellKnownSecurity;

    // LookupPrivilegeName
    enum class LookupPrivilegeNameDescription;
}

#endif  // SYSTEM_SECURITY_SECURITY_FLAGS_FWD_H