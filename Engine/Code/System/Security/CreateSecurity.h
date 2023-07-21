///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/23 23:14)

#ifndef SYSTEM_SECURITY_CREATE_SECURITY_H
#define SYSTEM_SECURITY_CREATE_SECURITY_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/CreateSecurityUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Threading/Using/ThreadUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// 创建安全句柄
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemFileSecurity(const String& fileName,
                                                                SecurityRequestedInformation requestedInformation,
                                                                SecurityDescriptorPtr securityDescriptor,
                                                                WindowsDWord length,
                                                                WindowsDWordPtr lengthNeeded) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemFileSecurity(const String& fileName,
                                                                SecurityRequestedInformation securityInformation,
                                                                SecurityDescriptorPtr securityDescriptor) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemKernelObjectSecurity(ThreadHandle handle,
                                                                        SecurityRequestedInformation requestedInformation,
                                                                        SecurityDescriptorPtr securityDescriptor,
                                                                        WindowsDWord length,
                                                                        WindowsDWordPtr lengthNeeded) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemKernelObjectSecurity(ThreadHandle handle,
                                                                        SecurityRequestedInformation securityInformation,
                                                                        SecurityDescriptorPtr securityDescriptor) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CreateSystemPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor,
                                                                            SecurityDescriptorPtr creatorDescriptor,
                                                                            SecurityDescriptorPtr* newDescriptor,
                                                                            bool isDirectoryObject,
                                                                            WindowsHandle token,
                                                                            AccessCheckGenericMappingPtr genericMapping) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CreateSystemPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor,
                                                                            SecurityDescriptorPtr creatorDescriptor,
                                                                            SecurityDescriptorPtr* newDescriptor,
                                                                            SystemGloballyUniqueIdentifier* objectType,
                                                                            bool isContainerObject,
                                                                            SecurityAutoInherit autoInheritFlags,
                                                                            WindowsHandle token,
                                                                            AccessCheckGenericMappingPtr genericMapping) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CreateSystemPrivateObjectSecurityWithMultipleInheritance(SecurityDescriptorPtr parentDescriptor,
                                                                                                   SecurityDescriptorPtr creatorDescriptor,
                                                                                                   SecurityDescriptorPtr* newDescriptor,
                                                                                                   SystemGloballyUniqueIdentifier** objectTypes,
                                                                                                   WindowsULong guidCount,
                                                                                                   bool isContainerObject,
                                                                                                   SecurityAutoInherit autoInheritFlags,
                                                                                                   WindowsHandle token,
                                                                                                   AccessCheckGenericMappingPtr genericMapping) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE DestroySystemPrivateObjectSecurity(SecurityDescriptorPtr* objectDescriptor) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemPrivateObjectSecurity(SecurityDescriptorPtr objectDescriptor,
                                                                         SecurityRequestedInformation securityInformation,
                                                                         SecurityDescriptorPtr resultantDescriptor,
                                                                         WindowsDWord descriptorLength,
                                                                         WindowsDWordPtr returnLength) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemPrivateObjectSecurity(SecurityRequestedInformation securityInformation,
                                                                         SecurityDescriptorPtr modificationDescriptor,
                                                                         SecurityDescriptorPtr* objectsSecurityDescriptor,
                                                                         AccessCheckGenericMappingPtr genericMapping,
                                                                         WindowsHandle token) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemPrivateObjectSecurity(SecurityRequestedInformation securityInformation,
                                                                         SecurityDescriptorPtr modificationDescriptor,
                                                                         SecurityDescriptorPtr* objectsSecurityDescriptor,
                                                                         SecurityAutoInherit autoInheritFlags,
                                                                         AccessCheckGenericMappingPtr genericMapping,
                                                                         WindowsHandle token) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemConvertToAutoInheritPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor,
                                                                                          SecurityDescriptorPtr currentSecurityDescriptor,
                                                                                          SecurityDescriptorPtr* newSecurityDescriptor,
                                                                                          SystemGloballyUniqueIdentifier* objectType,
                                                                                          bool isDirectoryObject,
                                                                                          AccessCheckGenericMappingPtr genericMapping) noexcept;

    NODISCARD void SYSTEM_DEFAULT_DECLARE SetSystemSecurityAccessMask(SecurityRequestedInformation securityInformation,
                                                                      WindowsDWordPtr desiredAccess) noexcept;
}

#endif  // SYSTEM_SECURITY_CREATE_SECURITY_H