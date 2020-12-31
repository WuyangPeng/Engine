//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 11:09)

#ifndef SYSTEM_HELPER_PGI_H
#define SYSTEM_HELPER_PGI_H

#if defined(__PGI)

    //  PGI C++ ���������ã�

    #ifndef SYSTEM_CPP_STANDARD
        #define SYSTEM_CPP_STANDARD 3
    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_PGI
        #define TCRE_USE_PGI 1
    #endif  // TCRE_USE_PGI

    #ifndef TCRE_COMPILER_VERSION
        #define TCRE_COMPILER_VERSION SYSTEM_CONCATENATOR(_PGIC__, __PGIC_MINOR__)
    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER
        #define TCRE_SYSTEM_COMPILER "PGI �������汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #endif  // TCRE_SYSTEM_COMPILER

#endif  // defined(__PGI)

#endif  // SYSTEM_HELPER_PGI_H
