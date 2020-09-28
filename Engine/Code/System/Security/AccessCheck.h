//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 15:22)

#ifndef SYSTEM_SECURITY_ACCESS_CHECK_H
#define SYSTEM_SECURITY_ACCESS_CHECK_H

#include "System/SystemDll.h"

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/AccessCheckUsing.h"
#include "Using/CreateSecurityUsing.h"
#include "Using/SecuritySidUsing.h"
#include "System/FileManager/Fwd/FileFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"

namespace System
{
    // 访问检查

    void SYSTEM_DEFAULT_DECLARE GetMapGenericMask(WindowDWordPtr accessMask, AccessCheckGenericMappingPtr genericMapping) noexcept;
    [[nodiscard]] AccessGenericMask SYSTEM_DEFAULT_DECLARE GetFileMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept;
    [[nodiscard]] AccessGenericMask SYSTEM_DEFAULT_DECLARE GetTransactionManagerMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept;
    [[nodiscard]] AccessGenericMask SYSTEM_DEFAULT_DECLARE GetTransactionMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept;
    [[nodiscard]] AccessGenericMask SYSTEM_DEFAULT_DECLARE GetResourceManagerMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept;
    [[nodiscard]] AccessGenericMask SYSTEM_DEFAULT_DECLARE GetEnlistmentMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMappings) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetAccessCheck(SecurityDescriptorPtr securityDescriptor, WindowHandle clientToken, AccessGenericMask desiredAccess, AccessCheckGenericMappingPtr genericMapping,
                                                             SecurityPrivilegeSetPtr privilegeSet, WindowDWordPtr privilegeSetLength, WindowDWordPtr grantedAccess, bool* accessStatus) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetAccessCheckByType(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr principalSelfSid, WindowHandle clientToken, AccessGenericMask desiredAccess,
                                                                   SecurityObjectTypeListPtr objectTypeList, WindowDWord objectTypeListLength, AccessCheckGenericMappingPtr genericMapping, SecurityPrivilegeSetPtr privilegeSet,
                                                                   WindowDWordPtr privilegeSetLength, WindowDWordPtr grantedAccess, bool* accessStatus) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetAccessCheckByTypeResultList(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr principalSelfSid, WindowHandle clientToken, AccessGenericMask desiredAccess,
                                                                             SecurityObjectTypeListPtr objectTypeList, WindowDWord objectTypeListLength, AccessCheckGenericMappingPtr genericMapping, SecurityPrivilegeSetPtr privilegeSet,
                                                                             WindowDWordPtr privilegeSetLength, WindowDWordPtr grantedAccessList, WindowDWordPtr accessStatusList) noexcept;
}

#endif  // SYSTEM_SECURITY_ACCESS_CHECK_H