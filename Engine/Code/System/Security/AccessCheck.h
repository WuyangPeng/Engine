// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:57)

#ifndef SYSTEM_SECURITY_ACCESS_CHECK_H
#define SYSTEM_SECURITY_ACCESS_CHECK_H

#include "System/SystemDll.h"  

#include "Fwd/SecurityFlagsFwd.h"
#include "Using/AccessCheckUsing.h"
#include "Using/SecuritySidUsing.h"
#include "Using/CreateSecurityUsing.h"
#include "System/Helper/UnicodeUsing.h" 
#include "System/FileManager/Fwd/FileFlagsFwd.h"

namespace System
{
	// ∑√Œ ºÏ≤È

	void SYSTEM_DEFAULT_DECLARE GetMapGenericMask(WindowDWordPtr accessMask, AccessCheckGenericMappingPtr genericMapping) noexcept;
	AccessGenericMask SYSTEM_DEFAULT_DECLARE GetFileMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept;
	AccessGenericMask SYSTEM_DEFAULT_DECLARE GetTransactionManagerMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept;
	AccessGenericMask SYSTEM_DEFAULT_DECLARE GetTransactionMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept;
	AccessGenericMask SYSTEM_DEFAULT_DECLARE GetResourceManagerMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept;
	AccessGenericMask SYSTEM_DEFAULT_DECLARE GetEnlistmentMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMappings) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetAccessCheck(SecurityDescriptorPtr securityDescriptor, WindowHandle clientToken, AccessGenericMask desiredAccess, AccessCheckGenericMappingPtr genericMapping,
											   SecurityPrivilegeSetPtr privilegeSet, WindowDWordPtr privilegeSetLength, WindowDWordPtr grantedAccess, bool* accessStatus) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetAccessCheckByType(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr principalSelfSid, WindowHandle clientToken, AccessGenericMask desiredAccess,
													 SecurityObjectTypeListPtr objectTypeList, WindowDWord objectTypeListLength, AccessCheckGenericMappingPtr genericMapping, SecurityPrivilegeSetPtr privilegeSet,
													 WindowDWordPtr privilegeSetLength, WindowDWordPtr grantedAccess, bool* accessStatus) noexcept;

	bool SYSTEM_DEFAULT_DECLARE GetAccessCheckByTypeResultList(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr principalSelfSid, WindowHandle clientToken, AccessGenericMask desiredAccess,
															   SecurityObjectTypeListPtr objectTypeList, WindowDWord objectTypeListLength, AccessCheckGenericMappingPtr genericMapping, SecurityPrivilegeSetPtr privilegeSet,
															   WindowDWordPtr privilegeSetLength, WindowDWordPtr grantedAccessList, WindowDWordPtr accessStatusList) noexcept;
}

#endif // SYSTEM_SECURITY_ACCESS_CHECK_H