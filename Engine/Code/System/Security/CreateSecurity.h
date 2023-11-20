///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/30 15:13)

#ifndef SYSTEM_SECURITY_CREATE_SECURITY_H
#define SYSTEM_SECURITY_CREATE_SECURITY_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/CreateSecurityUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Threading/Using/ThreadUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

// ������ȫ���
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

    void SYSTEM_DEFAULT_DECLARE SetSystemSecurityAccessMask(SecurityRequestedInformation securityInformation,
                                                            WindowsDWordPtr desiredAccess) noexcept;
}

#endif  // SYSTEM_SECURITY_CREATE_SECURITY_H