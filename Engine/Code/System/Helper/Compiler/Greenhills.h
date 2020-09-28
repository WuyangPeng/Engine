//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 11:05)

#ifndef SYSTEM_HELPER_GREENHILLS_H
#define SYSTEM_HELPER_GREENHILLS_H

#ifdef __ghs

    // Greenhills C++ ���������ã�

    // �汾��飺
    #if (__ghs < 0)
        #error "������δ����"
    #endif  // __ghs < 0

    #if (0 < __ghs)
        #error "δ֪�ı������汾"
    #endif  // 0 < __ghs

    #ifndef SYSTEM_CPP_STANDARD
        #define SYSTEM_CPP_STANDARD 3
    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_GREENHILLS
        #define TCRE_USE_GREENHILLS 1
    #endif  // TCRE_USE_GREENHILLS

    #ifndef TCRE_COMPILER_VERSION
        #define TCRE_COMPILER_VERSION __ghs
    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER
        #define TCRE_SYSTEM_COMPILER "Greenhills C++ �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #endif  // TCRE_SYSTEM_COMPILER

#endif  // __ghs

#endif  // SYSTEM_HELPER_GREENHILLS_H
