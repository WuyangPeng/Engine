//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 15:24)

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
#include "System/Window/Using/IUnknownUsing.h"

namespace System
{
    // 创建安全句柄

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemFileSecurity(const String& fileName, SecurityRequestedInformation requestedInformation, SecurityDescriptorPtr securityDescriptor,
                                                                    WindowDWord length, WindowDWordPtr lengthNeeded) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemFileSecurity(const TChar* fileName, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr securityDescriptor) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemKernelObjectSecurity(ThreadHandle handle, SecurityRequestedInformation requestedInformation, SecurityDescriptorPtr securityDescriptor,
                                                                            WindowDWord length, WindowDWordPtr lengthNeeded) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemKernelObjectSecurity(ThreadHandle handle, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr securityDescriptor) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CreateSystemPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr creatorDescriptor, SecurityDescriptorPtr* newDescriptor,
                                                                                bool isDirectoryObject, WindowHandle token, AccessCheckGenericMappingPtr genericMapping) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CreateSystemPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr creatorDescriptor, SecurityDescriptorPtr* newDescriptor,
                                                                                SystemGUID* objectType, bool isContainerObject, SecurityAutoInherit autoInheritFlags,
                                                                                WindowHandle token, AccessCheckGenericMappingPtr genericMapping) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CreateSystemPrivateObjectSecurityWithMultipleInheritance(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr creatorDescriptor, SecurityDescriptorPtr* newDescriptor,
                                                                                                       SystemGUID** objectTypes, WindowULong guidCount, bool isContainerObject,
                                                                                                       SecurityAutoInherit autoInheritFlags, WindowHandle token, AccessCheckGenericMappingPtr genericMapping) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE DestroySystemPrivateObjectSecurity(SecurityDescriptorPtr* objectDescriptor) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemPrivateObjectSecurity(SecurityDescriptorPtr objectDescriptor, SecurityRequestedInformation securityInformation, SecurityDescriptorPtr resultantDescriptor,
                                                                             WindowDWord descriptorLength, WindowDWordPtr returnLength) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemPrivateObjectSecurity(SecurityRequestedInformation securityInformation, SecurityDescriptorPtr modificationDescriptor, SecurityDescriptorPtr* objectsSecurityDescriptor,
                                                                             AccessCheckGenericMappingPtr genericMapping, WindowHandle token) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemPrivateObjectSecurity(SecurityRequestedInformation securityInformation, SecurityDescriptorPtr modificationDescriptor, SecurityDescriptorPtr* objectsSecurityDescriptor,
                                                                             SecurityAutoInherit autoInheritFlags, AccessCheckGenericMappingPtr genericMapping, WindowHandle token) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SystemConvertToAutoInheritPrivateObjectSecurity(SecurityDescriptorPtr parentDescriptor, SecurityDescriptorPtr currentSecurityDescriptor, SecurityDescriptorPtr* newSecurityDescriptor,
                                                                                              SystemGUID* objectType, bool isDirectoryObject, AccessCheckGenericMappingPtr genericMapping) noexcept;

    [[nodiscard]] void SYSTEM_DEFAULT_DECLARE SetSystemSecurityAccessMask(SecurityRequestedInformation securityInformation, WindowDWordPtr desiredAccess) noexcept;
}

#endif  // SYSTEM_SECURITY_CREATE_SECURITY_H