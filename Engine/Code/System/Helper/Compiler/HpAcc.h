///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/29 11:24)

#ifndef SYSTEM_HELPER_HP_ACC_H
#define SYSTEM_HELPER_HP_ACC_H

// HP aCC C++ ���������ã�

#ifdef __HP_aCC

    // �汾��飺���ǲ�֧�ְ汾33000֮ǰ��HP aCC��
    #if __HP_aCC < 33000

        #error "����������֧��"

    #endif  // __HP_aCC < 33000

    // ��PA-RISC��֧��aCC����չ���
    #if 30000 < __HP_aCC && __HP_aCC < 50000

        #if __HP_aCC < 38000

            // ��֧�ְ汾A.03.80֮ǰ�İ汾
            #error "����������֧��"

        #elif !defined(__hpxstd98)

            // ����ʹ��ѡ��+hpxstd98�ͱ�A.03.80���߰汾���б���
            #error "������ѡ�+hpxstd98������ȷ֧���������"

        #endif  // PA-RISC

    #endif  // 30000 < __HP_aCC && __HP_aCC < 50000

    // HP-UX/ia64������ѵİ汾Ϊ61300��PA-RISC������ѵİ汾Ϊ38000
    #if ((61300 < __HP_aCC) || ((38000 < __HP_aCC) && defined(__hpxstd98)))

        #error "δ֪�������汾"

    #endif  // ((61300 < __HP_aCC) || ((38000 < __HP_aCC) && defined(__hpxstd98)))

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_HP_ACC

        #define TCRE_USE_HP_ACC 1

    #endif  // TCRE_USE_HP_ACC

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __HP_aCC

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "HP aCC �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

#endif  // __HP_aCC

#endif  // SYSTEM_HELPER_HP_ACC_H
