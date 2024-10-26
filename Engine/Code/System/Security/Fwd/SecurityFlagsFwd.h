/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 17:46)

#ifndef SYSTEM_SECURITY_SECURITY_FLAGS_FWD_H
#define SYSTEM_SECURITY_SECURITY_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    /// AccessCheck
    enum class AccessGenericMask;

    /// AddAccess
    enum class SpecificAccess;

    /// CreateSecurity
    enum class SecurityRequestedInformation : uint32_t;
    enum class SecurityAutoInherit;

    /// SecurityAce
    enum class ControlAceInheritance;
    enum class MandatoryPolicy;

    /// SecurityAcl
    enum class AccessControlListRevision;

    /// SecurityBase
    enum class SecurityTokenAttributesPrivilege : uint32_t;
    enum class SecurityTokenAttributesGroup : uint32_t;
    enum class SpecifiesAdditionalPrivilegeOptions : int8_t;

    /// SecurityDescriptor
    enum class InitializeSecurityDescriptorRevision : int8_t;
    enum class SecurityDescriptorControlBits;
    enum class SecurityDescriptorRmControlReturn : int8_t;

    /// LookupPrivilegeName
    enum class LookupPrivilegeNameDescription;
}

#endif  // SYSTEM_SECURITY_SECURITY_FLAGS_FWD_H