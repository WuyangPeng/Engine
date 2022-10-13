///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/11 23:21)

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

    #define TCRE_USE_LIBCOMO static_cast<void>(0)

#endif  // __LIBCOMO__

#endif  // SYSTEM_HELPER_LIBCOMO_H
