///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/30 15:14)

#ifndef SYSTEM_SECURITY_SECURITY_DESCRIPTOR_H
#define SYSTEM_SECURITY_SECURITY_DESCRIPTOR_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/CreateSecurityUsing.h"
#include "Using/SecurityAclUsing.h"
#include "Using/SecuritySidUsing.h"
#include "System/Threading/Using/ThreadUsing.h"

// 安全描述符
namespace System
{
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
                                                                                              AccessCheckAclPtr dacl,
                                                                                              bool daclDefaulted) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor,
                                                                                              bool* daclPresent,
                                                                                              AccessCheckAclPtr* dacl,
                                                                                              bool* daclDefaulted) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor,
                                                                             SecurityDescriptorControlBits controlBitsOfInterest,
                                                                             SecurityDescriptorControlBits controlBitsToSet) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor,
                                                                             SecurityDescriptorControlBits* control,
                                                                             WindowsDWordPtr revision) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor,
                                                                           SecuritySidPtr group,
                                                                           bool groupDefaulted) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor,
                                                                           SecuritySidPtr* group,
                                                                           bool* groupDefaulted) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor,
                                                                           SecuritySidPtr group,
                                                                           bool ownerDefaulted) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor,
                                                                           SecuritySidPtr* owner,
                                                                           bool* ownerDefaulted) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor,
                                                                                      WindowsUCharPtr rmControl) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor,
                                                                                      WindowsUCharPtr rmControl) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor,
                                                                                       bool saclPresent,
                                                                                       AccessCheckAclPtr sacl,
                                                                                       bool saclDefaulted) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor,
                                                                                       bool* saclPresent,
                                                                                       AccessCheckAclPtr* sacl,
                                                                                       bool* saclDefaulted) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_DESCRIPTOR_H