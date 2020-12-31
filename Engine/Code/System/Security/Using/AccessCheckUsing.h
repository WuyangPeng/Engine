//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 14:12)

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

#else  // !SYSTEM_PLATFORM_WIN32

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

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_ACCESS_CHECK_USING_H