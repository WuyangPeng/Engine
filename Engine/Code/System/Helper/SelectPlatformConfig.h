///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/05 0:08)

#ifndef SYSTEM_HELPER_SELECT_PLATFORM_CONFIG_H
#define SYSTEM_HELPER_SELECT_PLATFORM_CONFIG_H

// 找到我们所在的平台，并根据需要定义TCRE_PLATFORM_CONFIG。
// 各个头文件中定义宏TCRE_SYSTEM_PLATFORM表示平台名称。

#if (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)

    // linux，还有使用GLIBC的其他平台（Hurd等）。
    #define TCRE_PLATFORM_CONFIG "Platform/Linux.h"

#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)

    // BSD
    #define TCRE_PLATFORM_CONFIG "Platform/Bsd.h"

#elif defined(sun) || defined(__sun)

    // solaris
    #define TCRE_PLATFORM_CONFIG "Platform/Solaris.h"

#elif defined(__sgi)

    // SGI Irix
    #define TCRE_PLATFORM_CONFIG "Platform/Irix.h"

#elif defined(__hpux)

    // hp unix
    #define TCRE_PLATFORM_CONFIG "Platform/Hpux.h"

#elif defined(__CYGWIN__)

    // cygwin 不是 Win32
    #define TCRE_PLATFORM_CONFIG "Platform/Cygwin.h"

#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

    // Win32
    #define TCRE_PLATFORM_CONFIG "Platform/Win32.h"

#elif defined(__HAIKU__)

    // Haiku
    #define TCRE_PLATFORM_CONFIG "Platform/Haiku.h"

#elif defined(__BEOS__)

    // BeOS
    #define TCRE_PLATFORM_CONFIG "Platform/Beos.h"

#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)

    // MacOS
    #define TCRE_PLATFORM_CONFIG "Platform/Macos.h"

#elif defined(__TOS_MVS__)

    // IBM z/OS
    #define TCRE_PLATFORM_CONFIG "Platform/Zos.h"

#elif defined(__IBMCPP__) || defined(_AIX)

    // IBM AIX
    #define TCRE_PLATFORM_CONFIG "Platform/Aix.h"

#elif defined(__amigaos__)

    // AmigaOS
    #define TCRE_PLATFORM_CONFIG "Platform/Amigaos.h"

#elif defined(__QNXNTO__)

    // QNX
    #define TCRE_PLATFORM_CONFIG "Platform/Qnxnto.h"

#elif defined(__VXWORKS__)

    // vxWorks
    #define TCRE_PLATFORM_CONFIG "Platform/Vxworks.h"

#elif defined(__SYMBIAN32__)

    // Symbian
    #define TCRE_PLATFORM_CONFIG "Platform/Symbian.h"

#elif defined(_CRAYC)

    // Cray
    #define TCRE_PLATFORM_CONFIG "Platform/Cray.h"

#elif defined(__VMS)

    // VMS
    #define TCRE_PLATFORM_CONFIG "Platform/Vms.h"

#elif defined(__CloudABI__)

    // Nuxi CloudABI
    #define TCRE_PLATFORM_CONFIG "Platform/CloudAbi.h"

#else  // !defined(ALL_PLATFORM)

    // 这必须在最后，生成一个错误，如果我们无法识别平台。
    #error "平台无法被正确识别。"

#endif  // defined(ALL_PLATFORM)

#include TCRE_PLATFORM_CONFIG

#endif  // SYSTEM_HELPER_SELECT_PLATFORM_CONFIG_H
