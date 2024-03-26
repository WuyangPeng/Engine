/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 21:42)

#ifndef SYSTEM_HELPER_LIB_COMO_H
#define SYSTEM_HELPER_LIB_COMO_H

#if defined(__LIBCOMO__)

    ///  Comeau STL:

    #ifndef TCRE_CPP_LIB_VERSION

        #define TCRE_CPP_LIB_VERSION __LIBCOMO_VERSION__

    #endif  // TCRE_CPP_LIB_VERSION

    #ifndef TCRE_SYSTEM_STD_LIB

        #define TCRE_SYSTEM_STD_LIB "Comeau ��׼��汾 " SYSTEM_STRINGIZE(TCRE_CPP_LIB_VERSION)

    #endif  // !TCRE_SYSTEM_STD_LIB

    #define TCRE_USE_LIB_COMO static_cast<void>(0)

#endif  // __LIBCOMO__

#endif  // SYSTEM_HELPER_LIB_COMO_H
