// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:58)

#include "System/SystemExport.h"

#include "AccessCheck.h" 
#include "Flags/AccessCheckFlags.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/WindowSystem.h"
#include "System/Helper/EnumCast.h"

void System
	::GetMapGenericMask(WindowDWordPtr accessMask, AccessCheckGenericMappingPtr genericMapping) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	::MapGenericMask(accessMask, genericMapping);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(accessMask);
	SYSTEM_UNUSED_ARG(genericMapping);
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetAccessCheck(SecurityDescriptorPtr securityDescriptor, WindowHandle clientToken, AccessGenericMask desiredAccess, AccessCheckGenericMappingPtr genericMapping,
					 SecurityPrivilegeSetPtr privilegeSet, WindowDWordPtr privilegeSetLength, WindowDWordPtr grantedAccess, bool* accessStatus) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	WindowBool resultAccessStatue{ g_False };
	if (::AccessCheck(securityDescriptor, clientToken, EnumCastUnderlying(desiredAccess), genericMapping, privilegeSet, privilegeSetLength, grantedAccess, &resultAccessStatue) != g_False)
	{
		BoolConversion(resultAccessStatue, accessStatus);

		return true;
	}
	else
	{
		return false;
	}
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(clientToken);
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(genericMapping);
	SYSTEM_UNUSED_ARG(privilegeSet);
	SYSTEM_UNUSED_ARG(privilegeSetLength);
	SYSTEM_UNUSED_ARG(grantedAccess);
	SYSTEM_UNUSED_ARG(accessStatus);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetAccessCheckByType(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr principalSelfSid, WindowHandle clientToken, AccessGenericMask desiredAccess,
						   SecurityObjectTypeListPtr objectTypeList, WindowDWord objectTypeListLength, AccessCheckGenericMappingPtr genericMapping, SecurityPrivilegeSetPtr privilegeSet,
						   WindowDWordPtr privilegeSetLength, WindowDWordPtr grantedAccess, bool* accessStatus) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
	WindowBool resultAccessStatue{ g_False };
	if (::AccessCheckByType(securityDescriptor, principalSelfSid, clientToken, EnumCastUnderlying(desiredAccess), objectTypeList,
							objectTypeListLength, genericMapping, privilegeSet, privilegeSetLength, grantedAccess, &resultAccessStatue) != g_False)
	{
		BoolConversion(resultAccessStatue, accessStatus);

		return true;
	}
	else
	{
		return false;
	}

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(principalSelfSid);
	SYSTEM_UNUSED_ARG(clientToken);
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(objectTypeList);
	SYSTEM_UNUSED_ARG(objectTypeListLength);
	SYSTEM_UNUSED_ARG(genericMapping);
	SYSTEM_UNUSED_ARG(privilegeSet);
	SYSTEM_UNUSED_ARG(privilegeSetLength);
	SYSTEM_UNUSED_ARG(grantedAccess);
	SYSTEM_UNUSED_ARG(accessStatus);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

bool System
	::GetAccessCheckByTypeResultList(SecurityDescriptorPtr securityDescriptor, SecuritySIDPtr principalSelfSid, WindowHandle clientToken, AccessGenericMask desiredAccess,
									 SecurityObjectTypeListPtr objectTypeList, WindowDWord objectTypeListLength, AccessCheckGenericMappingPtr genericMapping, SecurityPrivilegeSetPtr privilegeSet,
									 WindowDWordPtr privilegeSetLength, WindowDWordPtr grantedAccessList, WindowDWordPtr accessStatusList) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

	if (::AccessCheckByTypeResultList(securityDescriptor, principalSelfSid, clientToken, EnumCastUnderlying(desiredAccess), objectTypeList,
									  objectTypeListLength, genericMapping, privilegeSet, privilegeSetLength, grantedAccessList, accessStatusList) != g_False)
	{
		return true;
	}
	else
	{
		return false;
	}

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(securityDescriptor);
	SYSTEM_UNUSED_ARG(principalSelfSid);
	SYSTEM_UNUSED_ARG(clientToken);
	SYSTEM_UNUSED_ARG(desiredAccess);
	SYSTEM_UNUSED_ARG(objectTypeList);
	SYSTEM_UNUSED_ARG(objectTypeListLength);
	SYSTEM_UNUSED_ARG(genericMapping);
	SYSTEM_UNUSED_ARG(privilegeSet);
	SYSTEM_UNUSED_ARG(privilegeSetLength);
	SYSTEM_UNUSED_ARG(grantedAccessList);
	SYSTEM_UNUSED_ARG(accessStatusList);

	return false;
#endif // SYSTEM_PLATFORM_WIN32
}

System::AccessGenericMask System
	::GetFileMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
	genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::FileGenericRead);
	genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::FileGenericWrite);
	genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::FileGenericExecute);
	genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::FileAllAccess);

	auto mapGenericMask = EnumCastUnderlying<WindowDWord>(accessMask);

	GetMapGenericMask(&mapGenericMask, &genericMapping);

	return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}

System::AccessGenericMask System
	::GetTransactionManagerMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
	genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::TransactionManagerGenericRead);
	genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::TransactionManagerGenericWrite);
	genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::TransactionManagerGenericExecute);
	genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::TransactionManagerAllAccess);

	auto mapGenericMask = EnumCastUnderlying<WindowDWord>(accessMask);

	GetMapGenericMask(&mapGenericMask, &genericMapping);

	return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}

System::AccessGenericMask System
	::GetTransactionMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
	genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::TransactionGenericRead);
	genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::TransactionGenericWrite);
	genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::TransactionGenericExecute);
	genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::TransactionAllAccess);

	auto mapGenericMask = EnumCastUnderlying<WindowDWord>(accessMask);

	GetMapGenericMask(&mapGenericMask, &genericMapping);

	return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}

System::AccessGenericMask System
	::GetResourceManagerMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
	genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::ResourceManagerGenericRead);
	genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::ResourceManagerGenericWrite);
	genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::ResourceManagerGenericExecute);
	genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::ResourceManagerAllAccess);

	auto mapGenericMask = EnumCastUnderlying<WindowDWord>(accessMask);

	GetMapGenericMask(&mapGenericMask, &genericMapping);

	return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}

System::AccessGenericMask System
	::GetEnlistmentMapGenericMask(FileHandleDesiredAccess accessMask, AccessCheckGenericMapping& genericMapping) noexcept
{
	genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::EnlistmentGenericRead);
	genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::EnlistmentGenericWrite);
	genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::EnlistmentGenericExecute);
	genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::EnlistmentAllAccess);

	auto mapGenericMask = EnumCastUnderlying<WindowDWord>(accessMask);

	GetMapGenericMask(&mapGenericMask, &genericMapping);

	return UnderlyingCastEnum<AccessGenericMask>(mapGenericMask);
}