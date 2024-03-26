/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/08 19:31)

#ifndef SYSTEM_HELPER_GREEN_HILLS_H
#define SYSTEM_HELPER_GREEN_HILLS_H

#ifdef __ghs

    /// GreenHills C++ ���������ã�

    /// �汾��飺
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

        #define TCRE_USE_GREEN_HILLS 1

    #endif  // TCRE_USE_GREEN_HILLS

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __ghs

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "Greenhills C++ �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

#endif  // __ghs

#endif  // SYSTEM_HELPER_GREEN_HILLS_H
