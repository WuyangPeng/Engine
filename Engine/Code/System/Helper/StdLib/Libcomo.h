//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 11:18)

#ifndef SYSTEM_HELPER_LIBCOMO_H
#define SYSTEM_HELPER_LIBCOMO_H

#if defined(__LIBCOMO__)

    //  Comeau STL:

    #ifndef TCRE_CPPLIB_VERSION
        #define TCRE_CPPLIB_VERSION __LIBCOMO_VERSION__
    #endif  // TCRE_CPPLIB_VERSION

    #ifndef TCRE_STDLIB
        #define TCRE_SYSTEM_STDLIB "Comeau ��׼��汾 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)
    #endif  // !TCRE_STDLIB

    #define TCRE_USE_LIBCOMO

#endif  // __LIBCOMO__

#endif  // SYSTEM_HELPER_LIBCOMO_H
