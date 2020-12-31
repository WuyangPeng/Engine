//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 14:09)

#ifndef SYSTEM_SECURITY_SECURITY_DESCRIPTOR_FLAGS_H
#define SYSTEM_SECURITY_SECURITY_DESCRIPTOR_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class InitializeSecurityDescriptorRevision
    {
        Revision = SECURITY_DESCRIPTOR_REVISION,
    };

    enum class SecurityDescriptorControlBits
    {
        Clear = (0x0000),
        OwnerDefaulted = SE_OWNER_DEFAULTED,
        GroupDefaulted = SE_GROUP_DEFAULTED,
        DaclPresent = SE_DACL_PRESENT,
        DaclDefaulted = SE_DACL_DEFAULTED,
        SaclPresent = SE_SACL_PRESENT,
        SaclDefaulted = SE_SACL_DEFAULTED,
        DaclAutoInheritReq = SE_DACL_AUTO_INHERIT_REQ,
        SaclAutoInheritReq = SE_SACL_AUTO_INHERIT_REQ,
        DaclAutoInherited = SE_DACL_AUTO_INHERITED,
        SaclAutoInherited = SE_SACL_AUTO_INHERITED,
        DaclProtected = SE_DACL_PROTECTED,
        SaclProtected = SE_SACL_PROTECTED,
        RmControlValid = SE_RM_CONTROL_VALID,
        SelfRelative = SE_SELF_RELATIVE,
    };

    enum class SecurityDescriptorRMControlReturn
    {
        Success = ERROR_SUCCESS,
        InvalidData = ERROR_INVALID_DATA,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class InitializeSecurityDescriptorRevision
    {
        Revision = 1,
    };

    enum class SecurityDescriptorControlBits
    {
        Clear = (0x0000),
        OwnerDefaulted = (0x0001),
        GroupDefaulted = (0x0002),
        DaclPresent = (0x0004),
        DaclDefaulted = (0x0008),
        SaclPresent = (0x0010),
        SaclDefaulted = (0x0020),
        DaclAutoInheritReq = (0x0100),
        SaclAutoInheritReq = (0x0200),
        DaclAutoInherited = (0x0400),
        SaclAutoInherited = (0x0800),
        DaclProtected = (0x1000),
        SaclProtected = (0x2000),
        RmControlValid = (0x4000),
        SelfRelative = (0x8000),
    };

    enum class SecurityDescriptorRMControlReturn
    {
        Success = 0L,
        InvalidData = 13L,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_SECURITY_DESCRIPTOR_FLAGS_H
