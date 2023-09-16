///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/30 15:11)

#ifndef SYSTEM_SECURITY_ACCESS_CHECK_H
#define SYSTEM_SECURITY_ACCESS_CHECK_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/AccessCheckUsing.h"
#include "Using/CreateSecurityUsing.h"
#include "Using/SecuritySidUsing.h"
#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

// 访问检查
namespace System
{
    void SYSTEM_DEFAULT_DECLARE GetMapGenericMask(WindowsDWordPtr accessMask, AccessCheckGenericMappingPtr genericMapping) noexcept;
    NODISCARD AccessGenericMask SYSTEM_DEFAULT_DECLARE GetFileMapGenericMask(FileHandleDesiredAccess accessMask,
                                                                             AccessCheckGenericMapping& genericMapping) noexcept;
    NODISCARD AccessGenericMask SYSTEM_DEFAULT_DECLARE GetTransactionManagerMapGenericMask(FileHandleDesiredAccess accessMask,
                                                                                           AccessCheckGenericMapping& genericMapping) noexcept;
    NODISCARD AccessGenericMask SYSTEM_DEFAULT_DECLARE GetTransactionMapGenericMask(FileHandleDesiredAccess accessMask,
                                                                                    AccessCheckGenericMapping& genericMapping) noexcept;
    NODISCARD AccessGenericMask SYSTEM_DEFAULT_DECLARE GetResourceManagerMapGenericMask(FileHandleDesiredAccess accessMask,
                                                                                        AccessCheckGenericMapping& genericMapping) noexcept;
    NODISCARD AccessGenericMask SYSTEM_DEFAULT_DECLARE GetEnlistmentMapGenericMask(FileHandleDesiredAccess accessMask,
                                                                                   AccessCheckGenericMapping& genericMappings) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetAccessCheck(SecurityDescriptorPtr securityDescriptor,
                                                         WindowsHandle clientToken,
                                                         AccessGenericMask desiredAccess,
                                                         AccessCheckGenericMappingPtr genericMapping,
                                                         SecurityPrivilegeSetPtr privilegeSet,
                                                         WindowsDWordPtr privilegeSetLength,
                                                         WindowsDWordPtr grantedAccess,
                                                         bool* accessStatus) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetAccessCheckByType(SecurityDescriptorPtr securityDescriptor,
                                                               SecuritySidPtr principalSelfSid,
                                                               WindowsHandle clientToken,
                                                               AccessGenericMask desiredAccess,
                                                               SecurityObjectTypeListPtr objectTypeList,
                                                               WindowsDWord objectTypeListLength,
                                                               AccessCheckGenericMappingPtr genericMapping,
                                                               SecurityPrivilegeSetPtr privilegeSet,
                                                               WindowsDWordPtr privilegeSetLength,
                                                               WindowsDWordPtr grantedAccess,
                                                               bool* accessStatus) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetAccessCheckByTypeResultList(SecurityDescriptorPtr securityDescriptor,
                                                                         SecuritySidPtr principalSelfSid,
                                                                         WindowsHandle clientToken,
                                                                         AccessGenericMask desiredAccess,
                                                                         SecurityObjectTypeListPtr objectTypeList,
                                                                         WindowsDWord objectTypeListLength,
                                                                         AccessCheckGenericMappingPtr genericMapping,
                                                                         SecurityPrivilegeSetPtr privilegeSet,
                                                                         WindowsDWordPtr privilegeSetLength,
                                                                         WindowsDWordPtr grantedAccessList,
                                                                         WindowsDWordPtr accessStatusList) noexcept;
}

#endif  // SYSTEM_SECURITY_ACCESS_CHECK_H