///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:36)

#ifndef SYSTEM_HELPER_MACOS_H
#define SYSTEM_HELPER_MACOS_H

#if defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)

    //  Mac OS 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "Mac OS"
    #define SYSTEM_PLATFORM_MACOS static_cast<void>(0)

    #if defined(__BIG_ENDIAN__)
        #define SYSTEM_BIG_ENDIAN static_cast<void>(0)
    #else  // !defined(__BIG_ENDIAN__)
        #define SYSTEM_LITTLE_ENDIAN static_cast<void>(0)
    #endif  // defined(__BIG_ENDIAN__)

#endif  // defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)

#endif  // SYSTEM_HELPER_MACOS_H
