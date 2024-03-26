/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 21:43)

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

        #define TCRE_SYSTEM_STD_LIB "GNU libstdc++ 版本 " SYSTEM_STRINGIZE(TCRE_CPP_LIB_VERSION)

    #endif  // !TCRE_SYSTEM_STD_LIB

    #define TCRE_USE_LIB_STD_CPP3 static_cast<void>(0)

#endif  // defined(__GLIBCPP__) || defined(__GLIBCXX__)

#endif  // SYSTEM_HELPER_LIB_STD_CPP3_H
