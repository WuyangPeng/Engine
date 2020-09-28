//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 11:17)

#ifndef SYSTEM_HELPER_SYMBIAN_H
#define SYSTEM_HELPER_SYMBIAN_H

#if defined(__SYMBIAN32__)

    //  symbian ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "Symbian"
    #define SYSTEM_PLATFORM_SYMBIAN

    #include <cstdlib>
    #include <sys/endian.h>

    #if defined(__LITTLE_ENDIAN)
        #define SYSTEM_LITTLE_ENDIAN
    #else  // !defined(__LITTLE_ENDIAN)
        #define SYSTEM_BIG_ENDIAN
    #endif  // defined(__LITTLE_ENDIAN)

    #if !defined(__S60_3X__)
        #error "��֧�� Symbian SDK"
    #endif  // !defined(__S60_3X__)

#endif  // defined(__SYMBIAN32__)

#endif  // SYSTEM_HELPER_SYMBIAN_H
