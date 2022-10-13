///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/11 23:17)

#ifndef SYSTEM_HELPER_XLCPP_H
#define SYSTEM_HELPER_XLCPP_H

#if defined(__ibmxl__)

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_XLCPP

        #define TCRE_USE_XLCPP 1

    #endif  // TCRE_USE_XLCPP

    #ifndef TCRE_CLANG

        #define TCRE_CLANG 1

    #endif  // TCRE_CLANG

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __clang_version__

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "Clang 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

    #if defined(__GNUC__) && (4 <= __GNUC__)

        #define MAYBE_UNUSED __attribute__((unused))

    #endif  // defined(__GNUC__) && (4 <= __GNUC__)

    // 在定义__has_extension之前使用clang进行编译时，
    // 即使写了'defined(__has_extension) && __has_extension(xxx)'，
    // clang也报告编译器错误。 因此，找到的唯一解决方法是：

    #ifndef __has_extension

        #define __has_extension __has_feature

    #endif  // __has_extension

    #ifndef __has_cpp_attribute

        #define __has_cpp_attribute(x) 0

    #endif  // __has_cpp_attribute

    // 分支预测提示
    #if defined(__has_builtin)

        #if __has_builtin(__builtin_expect)

            #define TCRE_LIKELY(x) __builtin_expect(x, 1)
            #define TCRE_UNLIKELY(x) __builtin_expect(x, 0)

        #endif  // __has_builtin(__builtin_expect)

    #endif  // defined(__has_builtin)

    // FALLTHROUGH宏可用于注释switch标签之间的隐式的fall-through。
    #if 201103L <= __cplusplus && defined(__has_warning)

        #if __has_feature(cxx_attributes) && __has_warning("-Wimplicit-fallthrough")

            #define FALLTHROUGH [[clang::fallthrough]]

        #endif  //  __has_feature(cxx_attributes) && __has_warning("-Wimplicit-fallthrough")

    #endif  // 201103L <= __cplusplus && defined(__has_warning)

#endif  // defined(__ibmxl__)

#endif  // SYSTEM_HELPER_XLCPP_H
