///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/18 23:29)

#ifndef SYSTEM_HELPER_GCC_XML_H
#define SYSTEM_HELPER_GCC_XML_H

#ifdef __GCCXML__

    // GCC-XML C++ ���������ã�

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_GCC_XML

        #define TCRE_USE_GCC_XML 1

    #endif  // TCRE_USE_GCC_XML

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __GCCXML__

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "GCC-XML C++ �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

#endif  // __GCCXML__

#endif  // SYSTEM_HELPER_GCC_XML_H
