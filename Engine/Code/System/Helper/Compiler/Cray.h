/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 18:13)

#ifndef SYSTEM_HELPER_COMPAQ_CXX_H
#define SYSTEM_HELPER_COMPAQ_CXX_H

#ifdef _CRAYC

    // Greenhills C 编译器设置：

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_CRAY

        #define TCRE_USE_CRAY 1

    #endif  // TCRE_USE_CRAY

    #define TCRE_CRAY_x 9867657  // 任意数量
    #define TCRE_CRAY_APPEND(MACRO) TCRE_CRAY_APPEND_INTERNAL(MACRO)
    #define TCRE_CRAY_APPEND_INTERNAL(MACRO) SYSTEM_CONCATENATOR(TCRE_CRAY_, MACRO)

    #if TCRE_CRAY_x == TCRE_CRAY_APPEND(_RELEASE_PATCHLEVEL)

        /// 这是一个开发人员构建。
        /// _RELEASE_PATCHLEVEL定义为x，
        /// x未定义为宏，
        /// 假装_RELEASE_PATCHLEVEL为99，
        /// 因此我们获得了此版本中最新补丁级别的配置。

        #define CRAY_VERSION (_RELEASE_MAJOR * 10000 + _RELEASE_MINOR * 100 + 99)

    #else  // !TCRE_CRAY_x == TCRE_CRAY_APPEND(_RELEASE_PATCHLEVEL)

        /// 这是一个生产版本,
        /// _RELEASE_PATCHLEVEL未定义为x，
        /// 或x被定义为宏。

        #define CRAY_VERSION (_RELEASE_MAJOR * 10000 + _RELEASE_MINOR * 100 + _RELEASE_PATCHLEVEL)

    #endif  // BOOST_CRAY_x == BOOST_CRAY_APPEND(_RELEASE_PATCHLEVEL)

    #undef TCRE_CRAY_APPEND_INTERNAL
    #undef TCRE_CRAY_APPEND
    #undef TCRE_CRAY_x

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION CRAY_VERSION

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "Cray C 版本 " SYSTEM_STRINGIZE(_RELEASE_MAJOR) "." SYSTEM_STRINGIZE(_RELEASE_MINOR) "." SYSTEM_STRINGIZE(_RELEASE_PATCHLEVEL)

    #endif  // TCRE_SYSTEM_COMPILER

    #if CRAY_VERSION < 80000

        #error "在版本8之前没有为Cray编译器配置——请重新配置脚本。"

    #endif  // CRAY_VERSION < 80000

    // 这些常量应该由编译器提供，至少在命令行上声明-hgnu时。
    #ifndef __ATOMIC_RELAXED

        #define __ATOMIC_RELAXED 0
        #define __ATOMIC_CONSUME 1
        #define __ATOMIC_ACQUIRE 2
        #define __ATOMIC_RELEASE 3
        #define __ATOMIC_ACQ_REL 4
        #define __ATOMIC_SEQ_CST 5

    #endif  // __ATOMIC_RELAXED

#endif  // _CRAYC

#endif  // SYSTEM_HELPER_COMPAQ_CXX_H
