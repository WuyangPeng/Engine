/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 17:45)

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