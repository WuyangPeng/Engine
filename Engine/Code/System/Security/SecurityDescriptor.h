//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 15:25)

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

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetUserObjectSystemSecurity(ThreadHandle obj, SecurityRequestedInformation requested, SecurityDescriptorPtr securityDescriptor,
                                                                          WindowDWord length, WindowDWordPtr lengthNeeded) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE InitializeSystemSecurityDescriptor(SecurityDescriptorPtr securityDescriptor) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor, bool daclPresent, AccessCheckACLPtr dacl, bool daclDefaulted) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSecurityDescriptorDiscretionaryAccessControlList(SecurityDescriptorPtr securityDescriptor, WindowBoolPtr daclPresent, AccessCheckACLPtr* dacl, bool* daclDefaulted) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorLength(SecurityDescriptorPtr securityDescriptor) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsSecurityDescriptorValid(SecurityDescriptorPtr securityDescriptor) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor, SecurityDescriptorControlBits controlBitsOfInterest, SecurityDescriptorControlBits controlBitsToSet) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorControl(SecurityDescriptorPtr securityDescriptor, SecurityDescriptorControlBits* control, WindowDWordPtr revision) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr group, bool groupDefaulted) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorGroup(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr* group, bool* groupDefaulted) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr group, bool ownerDefaulted) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemSecurityDescriptorOwner(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr* owner, bool* ownerDefaulted) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor, WindowUCharPtr rmControl) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSecurityDescriptorResourceManagerControl(SecurityDescriptorPtr securityDescriptor, WindowUCharPtr rmControl) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor, bool saclPresent, AccessCheckACLPtr sacl, bool saclDefaulted) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSecurityDescriptorSystemAccessControlList(SecurityDescriptorPtr securityDescriptor, WindowBoolPtr saclPresent, AccessCheckACLPtr* sacl, bool* saclDefaulted) noexcept;
}

#endif  // SYSTEM_SECURITY_SECURITY_DESCRIPTOR_H