///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/23 23:11)

#ifndef SYSTEM_SECURITY_SECURITY_ACL_USING_H
#define SYSTEM_SECURITY_SECURITY_ACL_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using AccessCheckACL = ACL;
    using AccessCheckACLPtr = PACL;
    using SecurityAclInformationClass = ACL_INFORMATION_CLASS;
    using SecurityAclRevisionInformation = ACL_REVISION_INFORMATION;
    using SecurityAclRevisionInformationPtr = PACL_REVISION_INFORMATION;
    using SecurityAclSizeInformation = ACL_SIZE_INFORMATION;
    using SecurityAclSizeInformationPtr = PACL_SIZE_INFORMATION;

#else  // !SYSTEM_PLATFORM_WIN32

    struct AccessCheckACL
    {
        uint8_t AclRevision;
        uint8_t Sbz1;
        uint16_t AclSize;
        uint16_t AceCount;
        uint16_t Sbz2;
    };
    using AccessCheckACLPtr = AccessCheckACL*;

    enum SecurityAclInformationClass
    {
        AclRevisionInformation = 1,
        AclSizeInformation
    };

    struct SecurityAclRevisionInformation
    {
        uint32_t AclRevision;
    };
    using SecurityAclRevisionInformationPtr = SecurityAclRevisionInformation*;

    struct SecurityAclSizeInformation
    {
        uint32_t AceCount;
        uint32_t AclBytesInUse;
        uint32_t AclBytesFree;
    };
    using SecurityAclSizeInformationPtr = SecurityAclSizeInformation*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_SECURITY_ACL_USING_H