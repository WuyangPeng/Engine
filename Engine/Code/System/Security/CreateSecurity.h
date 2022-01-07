///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 10:46)

#ifndef SYSTEM_SECURITY_CREATE_SECURITY_H
#define SYSTEM_SECURITY_CREATE_SECURITY_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/CreateSecurityUsing.h"
#include "Using/LookupPrivilegeUsing.h"
#include "System/FileManager/Using/FileUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/MemoryTools/Using/HeapToolsUsing.h"
#include "System/Threading/Using/ThreadToolsUsing.h"
#include "System/Threading/Using/ThreadUsing.h"

namespace System
{
    // 创建安全句柄

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemFileSecurity(const String& fileName,
                                                                SecurityRequestedInformation requestedInformation,
                                                                SecurityDescriptorPtr securityDescriptor,
                                                                WindowsDWord length,
                                                                WindowsDWordPtr lengthNeeded) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemFileSecurity(const TChar* fileName,
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
                                                                            SystemGUID* objectType,
                                                                            bool isContainerObject,
                                                                            SecurityAutoInherit autoInheritFlags,
                                                                            WindowsHandle token,
                                                                            AccessCheckGenericMappingPtr genericMapping) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE CreateSystemPrivateObjectSecurityWithMultipleInheritance(SecurityDescriptorPtr parentDescriptor,
                                                                                                   SecurityDescriptorPtr creatorDescriptor,
                                                                                                   SecurityDescriptorPtr* newDescriptor,
                                                                                                   SystemGUID** objectTypes,
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
                                                                                          SystemGUID* objectType,
                                                                                          bool isDirectoryObject,
                                                                                          AccessCheckGenericMappingPtr genericMapping) noexcept;

    NODISCARD void SYSTEM_DEFAULT_DECLARE SetSystemSecurityAccessMask(SecurityRequestedInformation securityInformation,
                                                                      WindowsDWordPtr desiredAccess) noexcept;
}

#endif  // SYSTEM_SECURITY_CREATE_SECURITY_H