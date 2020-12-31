//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 11:03)

#ifndef SYSTEM_HELPER_CODE_GEAR_H
#define SYSTEM_HELPER_CODE_GEAR_H

#ifdef __CODEGEARC__

    // CodeGear C++���������ã�

    // �汾��飺�����֪�İ汾��0x621
    #if (0x621 < __CODEGEARC__)
        #error "δ֪�汾"
    #endif  // 0x621 < __CODEGEARC__

    #ifndef SYSTEM_CPP_STANDARD
        #define SYSTEM_CPP_STANDARD 3
    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_CODE_GEAR
        #define TCRE_USE_CODE_GEAR 1
    #endif  // TCRE_USE_CODE_GEAR

    #ifndef TCRE_COMPILER_VERSION
        #define TCRE_COMPILER_VERSION __CODEGEARC__
    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER
        #define TCRE_SYSTEM_COMPILER "CodeGear C++ �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #endif  // TCRE_SYSTEM_COMPILER

    // ��Щ����Ƶ���������Ż���ģ�������
    #pragma warn - 8004  // var��ֵ������δʹ��
    #pragma warn - 8008  // ����������/��
    #pragma warn - 8066  // ��������Զ����ִ��
    #pragma warn - 8104  // ��̬��Ա���캯�������̰߳�ȫ
    #pragma warn - 8105  // ���ó�Ա��û�й��캯��������

    #if defined(NDEBUG)
        // �޸����ϱ�׼��<cstring>
        #include <cstring>
        #undef strcmp
    #endif  // defined(NDEBUG)

    // �޸����ϱ�׼��errno������
    #include <errno.h>
    #ifndef errno
        #define errno errno
    #endif  // errno

#endif  // __CODEGEARC__

#endif  // SYSTEM_HELPER_CODE_GEAR_H
