/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 17:28)

#ifndef SYSTEM_HELPER_VA_CPP_H
#define SYSTEM_HELPER_VA_CPP_H

#if defined(__IBMCPP__)

    /// Visual Age (IBM) C++ ���������ã�

    #if __IBMCPP__ < 500

        #error "������δ����"

    #endif  // __IBMCPP__ < 500

    #if (1210 < __IBMCPP__)

        #error "δ֪������"

    #endif  // (1210 < __IBMCPP__)

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_VA_CPP

        #define TCRE_USE_VA_CPP 1

    #endif  // TCRE_USE_VA_CPP

    #ifndef COMPILER_VERSION

        #define COMPILER_VERSION __IBMCPP__

    #endif  // COMPILER_VERSION

    #ifndef SYSTEM_COMPILER

        #define SYSTEM_COMPILER "IBM Visual Age �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // SYSTEM_COMPILER

#endif  // defined(__IBMCPP__)

#endif  // SYSTEM_HELPER_VA_CPP_H
