//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 11:18)

#ifndef SYSTEM_HELPER_LIBCPP_H
#define SYSTEM_HELPER_LIBCPP_H

#if defined(_LIBCPP_VERSION)

    #ifndef TCRE_CPPLIB_VERSION
        #define TCRE_CPPLIB_VERSION _LIBCPP_VERSION
    #endif  // TCRE_CPPLIB_VERSION

    #ifndef TCRE_STDLIB
        #define TCRE_SYSTEM_STDLIB "libc++ �汾 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)
    #endif  // !TCRE_STDLIB

    #define TCRE_USE_LIBCPP

#endif  // _LIBCPP_VERSION

#endif  // SYSTEM_HELPER_LIBCPP_H
