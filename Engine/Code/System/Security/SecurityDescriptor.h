///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 18:53)

#ifndef SYSTEM_SECURITY_SECURITY_DESCRIPTOR_H
#define SYSTEM_SECURITY_SECURITY_DESCRIPTOR_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/CreateSecurityUsing.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecurityDescriptorUsing.h"
#include "Using/SecuritySidUsing.h"
#include "System/Threading/Using/ThreadUsing.h"

namespace System
{
    // 安全描述符

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetUserObjectSystemSecurity(ThreadHandle obj,
                                                                      SecurityRequestedInformation requested,
                                                                      SecurityDescriptorPtr securityDescriptor,
                                                                      WindowsDWord length,
                                                                      WindowsDWordPtr lengthNeeded) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorLength(SecurityDescriptorPtr securityDescriptor) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsSecurityDescriptorValid(SecurityDescriptorPtr securityDescriptor) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE InitializeSystemSecurityDescriptor(SecurityDescriptorPtr securityDescriptor) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor,
                                                                                              bool daclPresent,
                                                                                              AccessCheckACLPtr dacl,
                                                                                              bool daclDefaulted) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor,
                                                                                              WindowsBoolPtr daclPresent,
                                                                                              AccessCheckACLPtr* dacl,
                                                                                              bool* daclDefaulted) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor,
                                                                             SecurityDescriptorControlBits controlBitsOfInterest,
                                                                             SecurityDescriptorControlBits controlBitsToSet) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor,
                                                                             SecurityDescriptorControlBits* control,
                                                                             WindowsDWordPtr revision) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor,
                                                                           SecuritySIDPtr group,
                                                                           bool groupDefaulted) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor,
                                                                           SecuritySIDPtr* group,
                                                                           bool* groupDefaulted) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor,
                                                                           SecuritySIDPtr group,
                                                                           bool ownerDefaulted) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor,
                                                                           SecuritySIDPtr* owner,
                                                                           bool* ownerDefaulted) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor,
                                                                                      WindowsUCharPtr rmControl) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor,
                                                                                      WindowsUCharPtr rmControl) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor,
                                                                                       bool saclPresent,
                                                                                       AccessCheckACLPtr sacl,
                                                                                       bool saclDefaulted) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor,
                                                                                       WindowsBoolPtr saclPresent,
                                                                                       AccessCheckACLPtr* sacl,
                                                                                       bool* saclDefaulted) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_DESCRIPTOR_H