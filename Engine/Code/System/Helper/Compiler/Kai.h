///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/11 23:11)

#ifndef SYSTEM_HELPER_KAI_H
#define SYSTEM_HELPER_KAI_H

#ifdef __KCC

    // Kai C++ ���������ã�

    #if (4001 < __KCC_VERSION)

        #error "δ֪������"

    #endif  // (4001 < __KCC_VERSION)

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_KAI

        #define TCRE_USE_KAI 1

    #endif  // TCRE_USE_KAI

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __KCC_VERSION

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "Kai C++ �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

#endif  // __KCC

#endif  // SYSTEM_HELPER_KAI_H
