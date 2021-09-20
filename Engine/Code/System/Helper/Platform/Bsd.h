///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/08 11:52)

#ifndef SYSTEM_HELPER_BSD_H
#define SYSTEM_HELPER_BSD_H

#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)

    //  通用 BSD 具体配置选项：

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
