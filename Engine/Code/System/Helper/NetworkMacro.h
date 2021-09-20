///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/09 16:49)

#ifndef SYSTEM_HELPER_NETWORK_MACRO_H
#define SYSTEM_HELPER_NETWORK_MACRO_H

// 下面宏仅在System库内部调用，如果外部需要使用，WIN32需要链接Ws2_32.lib。

#ifdef BUILDING_SYSTEM_EXPORT

    #define SYSTEM_FD_CLRER(fd, set) FD_CLR(fd, set)
    #define SYSTEM_FD_IS_SET(fd, set) FD_ISSET(fd, set)
    #define SYSTEM_FD_SET(fd, set) FD_SET(fd, set)
    #define SYSTEM_FD_ZERO(set) FD_ZERO(set)

#endif  // BUILDING_SYSTEM_EXPORT

#endif  // SYSTEM_HELPER_NETWORK_MACRO_H
