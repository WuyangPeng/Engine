/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 21:43)

#ifndef SYSTEM_HELPER_LIB_STD_CPP3_H
#define SYSTEM_HELPER_LIB_STD_CPP3_H

#if defined(__GLIBCPP__) || defined(__GLIBCXX__)

    #ifndef TCRE_CPP_LIB_VERSION

        #ifdef __GLIBCXX__

            #define TCRE_CPP_LIB_VERSION __GLIBCXX__

        #else  // !__GLIBCXX__

            #define TCRE_CPP_LIB_VERSION __GLIBCPP__

        #endif  // __GLIBCXX__

    #endif  // TCRE_CPP_LIB_VERSION

    #ifndef TCRE_SYSTEM_STD_LIB

        #define TCRE_SYSTEM_STD_LIB "GNU libstdc++ �汾 " SYSTEM_STRINGIZE(TCRE_CPP_LIB_VERSION)

    #endif  // !TCRE_SYSTEM_STD_LIB

    #define TCRE_USE_LIB_STD_CPP3 static_cast<void>(0)

#endif  // defined(__GLIBCPP__) || defined(__GLIBCXX__)

#endif  // SYSTEM_HELPER_LIB_STD_CPP3_H
