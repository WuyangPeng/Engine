///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 18:37)

#ifndef SYSTEM_HELPER_HPUX_H
#define SYSTEM_HELPER_HPUX_H

#if defined(__hpux)

    //  hpux ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "HP-UX"
    #define SYSTEM_PLATFORM_HPUX static_cast<void>(0)

#endif  // __hpux

#endif  // SYSTEM_HELPER_HPUX_H
