///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/11 23:22)

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

        #define TCRE_SYSTEM_STDLIB "GNU libstdc++ 版本 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)

    #endif  // !TCRE_STDLIB

    #define TCRE_USE_LIBSTDCPP3 static_cast<void>(0)

#endif  // defined(__GLIBCPP__) || defined(__GLIBCXX__)

#endif  // SYSTEM_HELPER_LIBSTDCPP3_H
