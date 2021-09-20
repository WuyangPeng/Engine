///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/08 11:52)

#ifndef SYSTEM_HELPER_BSD_H
#define SYSTEM_HELPER_BSD_H

#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)

    //  ͨ�� BSD ��������ѡ�

    #ifdef __FreeBSD__
        #define TCRE_SYSTEM_PLATFORM "FreeBSD " SYSTEM_STRINGIZE(__FreeBSD__)
    #elif defined(__NetBSD__)
        #define TCRE_SYSTEM_PLATFORM "NetBSD " SYSTEM_STRINGIZE(__NetBSD__)
    #elif defined(__OpenBSD__)
        #define TCRE_SYSTEM_PLATFORM "OpenBSD " SYSTEM_STRINGIZE(__OpenBSD__)
    #elif defined(__DragonFly__)
        #define TCRE_SYSTEM_PLATFORM "DragonFly " SYSTEM_STRINGIZE(__DragonFly__)
    #endif  // __FreeBSD__

    #define SYSTEM_PLATFORM_BSD static_cast<void>(0)

#endif  // defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)

#endif  // SYSTEM_HELPER_BSD_H
