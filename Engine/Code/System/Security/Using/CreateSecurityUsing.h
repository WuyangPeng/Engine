/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:45)

#ifndef SYSTEM_SECURITY_CREATE_SECURITY_USING_H
#define SYSTEM_SECURITY_CREATE_SECURITY_USING_H

#include "SecurityAceUsing.h"
#include "SecurityAclUsing.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using SecurityInformation = SECURITY_INFORMATION;
    using SecurityDescriptor = SECURITY_DESCRIPTOR;
    using SecurityDescriptorPtr = PSECURITY_DESCRIPTOR;
    using AccessCheckGenericMapping = GENERIC_MAPPING;
    using AccessCheckGenericMappingPtr = PGENERIC_MAPPING;

#else  // !SYSTEM_PLATFORM_WIN32

    using SecurityInformation = uint32_t;

    struct SecurityDescriptor
    {
        uint8_t Revision;
        uint8_t Sbz1;
        uint16_t Control;
        uint16_t Owner;
        uint16_t Group;
        AccessCheckAclPtr Sacl;
        AccessCheckAclPtr Dacl;
    };
    using SecurityDescriptorPtr = void*;

    struct AccessCheckGenericMapping
    {
        AccessMask GenericRead;
        AccessMask GenericWrite;
        AccessMask GenericExecute;
        AccessMask GenericAll;
    };
    using AccessCheckGenericMappingPtr = AccessCheckGenericMapping*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_CREATE_SECURITY_USING_H