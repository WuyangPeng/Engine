///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 18:36)

#ifndef SYSTEM_HELPER_VMS_H
#define SYSTEM_HELPER_VMS_H

#if defined(__VMS)

    #define TCRE_SYSTEM_PLATFORM "OpenVMS"
    #define SYSTEM_PLATFORM_VMS static_cast<void>(0)

#endif  // defined(__VMS)

#endif  // SYSTEM_HELPER_VMS_H
