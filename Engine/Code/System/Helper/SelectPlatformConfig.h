///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/05 0:08)

#ifndef SYSTEM_HELPER_SELECT_PLATFORM_CONFIG_H
#define SYSTEM_HELPER_SELECT_PLATFORM_CONFIG_H

// �ҵ��������ڵ�ƽ̨����������Ҫ����TCRE_PLATFORM_CONFIG��
// ����ͷ�ļ��ж����TCRE_SYSTEM_PLATFORM��ʾƽ̨���ơ�

#if (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)

    // linux������ʹ��GLIBC������ƽ̨��Hurd�ȣ���
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

    // cygwin ���� Win32
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

    // ��������������һ��������������޷�ʶ��ƽ̨��
    #error "ƽ̨�޷�����ȷʶ��"

#endif  // defined(ALL_PLATFORM)

#include TCRE_PLATFORM_CONFIG

#endif  // SYSTEM_HELPER_SELECT_PLATFORM_CONFIG_H
