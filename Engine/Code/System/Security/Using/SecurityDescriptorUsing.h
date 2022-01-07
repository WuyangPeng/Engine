///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 10:44)

#ifndef SYSTEM_SECURITY_SECURITY_DESCRIPTOR_USING_H
#define SYSTEM_SECURITY_SECURITY_DESCRIPTOR_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using SecurityDescriptorControl = SECURITY_DESCRIPTOR_CONTROL;
    using SecurityDescriptorControlPtr = PSECURITY_DESCRIPTOR_CONTROL;

#else  // !SYSTEM_PLATFORM_WIN32

    using SecurityDescriptorControl = uint16_t;
    using SecurityDescriptorControlPtr = SecurityDescriptorControl*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_SECURITY_DESCRIPTOR_USING_H