///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/08 11:58)

#ifndef SYSTEM_HELPER_SYMBIAN_H
#define SYSTEM_HELPER_SYMBIAN_H

#if defined(__SYMBIAN32__)

    //  symbian ��������ѡ�

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
        #error "��֧�� Symbian SDK"
    #endif  // !defined(__S60_3X__)

#endif  // defined(__SYMBIAN32__)

#endif  // SYSTEM_HELPER_SYMBIAN_H
