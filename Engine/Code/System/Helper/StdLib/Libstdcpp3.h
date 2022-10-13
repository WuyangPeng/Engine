///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/11 23:22)

#ifndef SYSTEM_HELPER_LIBSTDCPP3_H
#define SYSTEM_HELPER_LIBSTDCPP3_H

#if defined(__GLIBCPP__) || defined(__GLIBCXX__)

    #ifndef TCRE_CPPLIB_VERSION

        #ifdef __GLIBCXX__

            #define TCRE_CPPLIB_VERSION __GLIBCXX__

        #else  // !__GLIBCXX__

            #define TCRE_CPPLIB_VERSION __GLIBCPP__

        #endif  // __GLIBCXX__

    #endif  // TCRE_CPPLIB_VERSION

    #ifndef TCRE_STDLIB

        #define TCRE_SYSTEM_STDLIB "GNU libstdc++ �汾 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)

    #endif  // !TCRE_STDLIB

    #define TCRE_USE_LIBSTDCPP3 static_cast<void>(0)

#endif  // defined(__GLIBCPP__) || defined(__GLIBCXX__)

#endif  // SYSTEM_HELPER_LIBSTDCPP3_H
