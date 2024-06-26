/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 21:44)

#ifndef SYSTEM_HELPER_CONFIG_MACRO_H
#define SYSTEM_HELPER_CONFIG_MACRO_H

#include "StringizeMacro.h"

/// 特定于平台的信息。
#include "SelectPlatformConfig.h"

/// 特定于编译器的信息。
#include "SelectCompilerConfig.h"

/// 特定于标准库的信息。
#include "SelectStdlibConfig.h"

#if !defined(SYSTEM_LITTLE_ENDIAN) && !defined(SYSTEM_BIG_ENDIAN)

    #define SYSTEM_LITTLE_ENDIAN static_cast<void>(0)

#endif  // !defined(SYSTEM_LITTLE_ENDIAN) && !defined(SYSTEM_BIG_ENDIAN)

#ifndef SYSTEM_CPP_STANDARD

    #define SYSTEM_CPP_STANDARD 3

#endif  // SYSTEM_CPP_STANDARD

#if SYSTEM_CPP_STANDARD < 20

    #error "使用C++20标准，不再兼容C++98、C++03编译器。"

#endif  // SYSTEM_CPP_STANDARD < 20

#ifndef MAYBE_UNUSED

    #define MAYBE_UNUSED [[maybe_unused]]

#endif  // MAYBE_UNUSED

#ifndef FALLTHROUGH

    #define FALLTHROUGH [[fallthrough]]

#endif  // FALLTHROUGH

#ifndef NODISCARD

    #define NODISCARD [[nodiscard]]

#endif  // NODISCARD

#ifndef MAYBE_NULLPTR

    #define MAYBE_NULLPTR [[nodiscard]]

#endif  // MAYBE_NULLPTR

#ifndef SYSTEM_DEPRECATED

    #define SYSTEM_DEPRECATED(x) [[deprecated(x)]]

#endif  // SYSTEM_DEPRECATED

#ifndef SYSTEM_NORETURN

    #define SYSTEM_NORETURN [[noreturn]]

#endif  // SYSTEM_NORETURN

#ifndef TCRE_SYSTEM_PLATFORM

    #error "没有定义平台。"

#endif  // TCRE_SYSTEM_PLATFORM

#ifndef TCRE_COMPILER_VERSION

    #error "没有定义编译器版本。"

#endif  // TCRE_COMPILER_VERSION

#ifndef TCRE_SYSTEM_COMPILER

    #error "没有定义编译器。"

#endif  // TCRE_SYSTEM_COMPILER

#ifndef TCRE_CPP_LIB_VERSION

    #error "没有定义标准库版本。"

#endif  // TCRE_CPP_LIB_VERSION

#ifndef TCRE_SYSTEM_STD_LIB

    #error "没有定义标准库。"

#endif  // TCRE_SYSTEM_STD_LIB

#if defined(__x86_64__) ||  \
    defined(_M_X64) ||      \
    defined(_M_AMD64) ||    \
    defined(__ppc64__) ||   \
    defined(__PPC64__) ||   \
    defined(__arm64__) ||   \
    defined(__aarch64__) || \
    defined(_M_ARM64) ||    \
    defined(__mips64) ||    \
    defined(__mips64_) ||   \
    defined(__alpha__) ||   \
    defined(__ia64__) ||    \
    defined(__e2k__) ||     \
    defined(__s390__) ||    \
    defined(__s390x__)

    #define TCRE_ARCHITECTURE_TYPE_64 static_cast<void>(0)

#else  // !defined(All)

    #define TCRE_ARCHITECTURE_TYPE_32 static_cast<void>(0)

#endif  // defined(All)

#include "UserMacro.h"

#endif  // SYSTEM_HELPER_CONFIG_MACRO_H
