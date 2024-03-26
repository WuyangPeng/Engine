/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 21:43)

#ifndef SYSTEM_HELPER_SGI_H
#define SYSTEM_HELPER_SGI_H

#if defined(__STL_CONFIG_H)

    ///  ͨ�� SGI STL:

    #ifndef TCRE_CPP_LIB_VERSION

        #define TCRE_CPP_LIB_VERSION 1

    #endif  // TCRE_CPP_LIB_VERSION

    #ifndef TCRE_STDLIB

        #define TCRE_SYSTEM_STD_LIB "SGI ��׼��汾 "

    #endif  // !TCRE_STDLIB

    #if !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))

        #include <unistd.h>

    #endif  // !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))

    #define TCRE_USE_SGI static_cast<void>(0)

#endif  // __STL_CONFIG_H

#endif  // SYSTEM_HELPER_SGI_H
