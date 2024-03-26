/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 21:48)

#ifndef SYSTEM_HELPER_NETWORK_MACRO_H
#define SYSTEM_HELPER_NETWORK_MACRO_H

/// 下面宏仅在System库内部调用，如果外部需要使用，WIN32需要链接Ws2_32.lib。

#ifdef SYSTEM_PLATFORM_LINUX

    #include <sys/select.h>

#endif  // SYSTEM_PLATFORM_LINUX

#ifdef BUILDING_SYSTEM_EXPORT

    #define SYSTEM_FD_CLEAR(fd, set) FD_CLR(fd, set)
    #define SYSTEM_FD_IS_SET(fd, set) FD_ISSET(fd, set)
    #define SYSTEM_FD_SET(fd, set) FD_SET(fd, set)
    #define SYSTEM_FD_ZERO(set) FD_ZERO(set)

#endif  // BUILDING_SYSTEM_EXPORT

#endif  // SYSTEM_HELPER_NETWORK_MACRO_H
