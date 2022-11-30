///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 13:23)

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
