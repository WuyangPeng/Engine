///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.5 (2022/12/16 22:06)

#ifndef SYSTEM_HELPER_HPUX_H
#define SYSTEM_HELPER_HPUX_H

#if defined(__hpux)

    //  hpux ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "HP-UX"
    #define SYSTEM_PLATFORM_HPUX static_cast<void>(0)

#endif  // __hpux

#endif  // SYSTEM_HELPER_HPUX_H
