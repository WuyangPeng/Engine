//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 11:09)

#ifndef SYSTEM_HELPER_SUNPRO_CC_H
#define SYSTEM_HELPER_SUNPRO_CC_H

#if defined(__SUNPRO_CC)

    // Sun C++ ���������ã�

    #if __SUNPRO_CC < 0x400
        #error "������δ����"
    #endif  // __SUNPRO_CC < 0x400

    #if (0x590 < __SUNPRO_CC)
        #error "δ֪�ı�����"
    #endif  // (0x590 < __SUNPRO_CC)

    #ifndef SYSTEM_CPP_STANDARD
        #define SYSTEM_CPP_STANDARD 3
    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_SUNPRO_CC
        #define TCRE_USE_SUNPRO_CC 1
    #endif  // TCRE_USE_SUNPRO_CC

    #ifndef TCRE_COMPILER_VERSION
        #define TCRE_COMPILER_VERSION __SUNPRO_CC
    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER
        #define TCRE_SYSTEM_COMPILER "Sun �������汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #endif  // TCRE_SYSTEM_COMPILER

#endif  // defined(__SUNPRO_CC)

#endif  // SYSTEM_HELPER_SUNPRO_CC_H
