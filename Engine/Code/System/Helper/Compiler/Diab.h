///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 18:42)

#ifndef SYSTEM_HELPER_DIAB_H
#define SYSTEM_HELPER_DIAB_H

#ifdef __DCC__

    // Wind River Diab C++���������ã�

    #ifndef __EDG_VERSION__
        #error "δ֪��Diab�������汾"
    #endif  // __EDG_VERSION__

    #ifndef TCRE_USE_DCC
        #define TCRE_USE_DCC 1
    #endif  // TCRE_USE_DCC

    #ifndef TCRE_COMPILER_VERSION
        #define TCRE_COMPILER_VERSION __EDG_VERSION__
    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER
        #define TCRE_SYSTEM_COMPILER "Wind River Diab C++ �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #endif  // TCRE_SYSTEM_COMPILER

#endif  // __DCC__

#endif  // SYSTEM_HELPER_DIAB_H