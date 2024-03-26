/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 21:42)

#ifndef SYSTEM_HELPER_DINKUMWARE_H
#define SYSTEM_HELPER_DINKUMWARE_H

#if (defined(_YVALS) && !defined(__IBMCPP__)) || defined(_CPPLIB_VER)

    ///  Dinkumware ��׼�����ã�

    #ifdef _CPPLIB_VER

        #define TCRE_DINKUMWARE_STD_LIB _CPPLIB_VER

    #else  // !_CPPLIB_VER

        #define TCRE_DINKUMWARE_STD_LIB 1

    #endif  // _CPPLIB_VER

    #ifndef TCRE_CPP_LIB_VERSION

        #define TCRE_CPP_LIB_VERSION TCRE_DINKUMWARE_STD_LIB

    #endif  // TCRE_CPP_LIB_VERSION

    #ifdef _CPPLIB_VER

        #define TCRE_SYSTEM_STD_LIB "Dinkumware ��׼��汾 " SYSTEM_STRINGIZE(TCRE_CPP_LIB_VERSION)

    #else  // !_CPPLIB_VER

        #define TCRE_SYSTEM_STD_LIB "Dinkumware ��׼��汾 1.x"

    #endif  // _CPPLIB_VER

    #define TCRE_USE_DINKUMWARE static_cast<void>(0)

#endif  // (defined(_YVALS) && !defined(__IBMCPP__)) || defined(_CPPLIB_VER)

#endif  // SYSTEM_HELPER_DINKUMWARE_H
