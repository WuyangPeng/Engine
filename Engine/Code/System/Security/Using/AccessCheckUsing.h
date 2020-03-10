// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:52)

#ifndef SYSTEM_SECURITY_ACCESS_CHECK_USING_H
#define SYSTEM_SECURITY_ACCESS_CHECK_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using SecurityPrivilegeSet = PRIVILEGE_SET;
	using SecurityPrivilegeSetPtr = PPRIVILEGE_SET;
	using LUIDAndAttributes = LUID_AND_ATTRIBUTES;
	using LUIDAndAttributesPtr = PLUID_AND_ATTRIBUTES;
	using SecurityObjectTypeList = OBJECT_TYPE_LIST;
	using SecurityObjectTypeListPtr = POBJECT_TYPE_LIST;
	using SecurityAuditEventType = AUDIT_EVENT_TYPE;

#else // !SYSTEM_PLATFORM_WIN32	

	struct LUIDAndAttributes
	{
		LookupPrivilegeLUID Luid;
		uint32_t Attributes;
	};
	using LUIDAndAttributesPtr = LUIDAndAttributes*;
	struct SecurityPrivilegeSet
	{
		uint32_t PrivilegeCount;
		uint32_t Control;
		LUIDAndAttributes Privilege[1];
	};
	using SecurityPrivilegeSetPtr = SecurityPrivilegeSet*;

	struct SecurityObjectTypeList
	{
		uint16_t Level;
		uint16_t Sbz;
		SystemGUID* ObjectType;
	};
	using SecurityObjectTypeListPtr = SecurityObjectTypeList*;
	enum SecurityAuditEventType
	{
		AuditEventObjectAccess,
		AuditEventDirectoryServiceAccess
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_SECURITY_ACCESS_CHECK_USING_H