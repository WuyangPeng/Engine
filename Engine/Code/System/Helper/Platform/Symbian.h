///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.5 (2022/12/16 22:07)

#ifndef SYSTEM_HELPER_SYMBIAN_H
#define SYSTEM_HELPER_SYMBIAN_H

#if defined(__SYMBIAN32__)

    //  symbian 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "Symbian"
    #define SYSTEM_PLATFORM_SYMBIAN static_cast<void>(0)

    #include <sys/endian.h>
    #include <cstdlib>

    #if defined(__LITTLE_ENDIAN)

        #define SYSTEM_LITTLE_ENDIAN static_cast<void>(0)

    #else  // !defined(__LITTLE_ENDIAN)

        #define SYSTEM_BIG_ENDIAN static_cast<void>(0)

    #endif  // defined(__LITTLE_ENDIAN)

    #if !defined(__S60_3X__)

        #error "不支持 Symbian SDK"

    #endif  // !defined(__S60_3X__)

#endif  // defined(__SYMBIAN32__)

#endif  // SYSTEM_HELPER_SYMBIAN_H
