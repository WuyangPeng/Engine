/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 18:07)

#ifndef SYSTEM_HELPER_VMS_H
#define SYSTEM_HELPER_VMS_H

#if defined(__VMS)

    #define TCRE_SYSTEM_PLATFORM "OpenVMS"
    #define SYSTEM_PLATFORM_VMS static_cast<void>(0)

#endif  // defined(__VMS)

#endif  // SYSTEM_HELPER_VMS_H
