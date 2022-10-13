///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/11 23:14)

#ifndef SYSTEM_HELPER_SGI_MIPSPRO_H
#define SYSTEM_HELPER_SGI_MIPSPRO_H

#if defined(__sgi)

    // SGI C++ ���������ã�

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_SGI_MIPSPRO

        #define TCRE_USE_SGI_MIPSPRO 1

    #endif  // TCRE_USE_SGI_MIPSPRO

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION _COMPILER_VERSION

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "SGI Irix �������汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

#endif  // defined(__sgi)

#endif  // SYSTEM_HELPER_SGI_MIPSPRO_H
