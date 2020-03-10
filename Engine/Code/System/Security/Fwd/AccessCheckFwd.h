// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:51)

#ifndef SYSTEM_SECURITY_ACCESS_CHECK_FWD_H 
#define SYSTEM_SECURITY_ACCESS_CHECK_FWD_H   

#include "SecurityFlagsFwd.h"
#include "System/Security/Using/AccessCheckUsing.h"

namespace System
{
	void GetMapGenericMask(WindowDWordPtr accessMask, AccessCheckGenericMappingPtr genericMapping) noexcept;
	AccessGenericMask GetFileMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept;
	AccessGenericMask GetTransactionManagerMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept;
	AccessGenericMask GetTransactionMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept;
	AccessGenericMask GetResourceManagerMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept;
	AccessGenericMask GetEnlistmentMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept;

	bool GetAccessCheck(SecurityDescriptorPtr securityDescriptor, WindowHandle clientToken, AccessGenericMask desiredAccess, AccessCheckGenericMappingPtr genericMapping,
						SecurityPrivilegeSetPtr privilegeSet, WindowDWordPtr privilegeSetLength, WindowDWordPtr grantedAccess, bool* accessStatus) noexcept;

	bool GetAccessCheckByType(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr principalSelfSid, WindowHandle clientToken, AccessGenericMask desiredAccess,
							  SecurityObjectTypeListPtr objectTypeList, WindowDWord objectTypeListLength, AccessCheckGenericMappingPtr genericMapping, SecurityPrivilegeSetPtr privilegeSet,
							  WindowDWordPtr privilegeSetLength, WindowDWordPtr grantedAccess, bool* accessStatus) noexcept;

	bool GetAccessCheckByTypeResultList(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr principalSelfSid, WindowHandle clientToken, AccessGenericMask desiredAccess,
										SecurityObjectTypeListPtr objectTypeList, WindowDWord objectTypeListLength, AccessCheckGenericMappingPtr genericMapping, SecurityPrivilegeSetPtr privilegeSet,
										WindowDWordPtr privilegeSetLength, WindowDWordPtr grantedAccessList, WindowDWordPtr accessStatusList) noexcept;
}

#endif // SYSTEM_SECURITY_ACCESS_CHECK_FWD_H