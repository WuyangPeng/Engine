///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 17:54)

#ifndef SYSTEM_HELPER_CONFIG_MACRO_H
#define SYSTEM_HELPER_CONFIG_MACRO_H

#include "StringizeMacro.h"

// 特定于平台的信息。
#include "SelectPlatformConfig.h"

// 特定于编译器的信息。
#include "SelectCompilerConfig.h"

// 特定于标准库的信息。
#include "SelectStdlibConfig.h"

#if !defined(SYSTEM_LITTLE_ENDIAN) && !defined(SYSTEM_BIG_ENDIAN)
    #define SYSTEM_LITTLE_ENDIAN static_cast<void>(0)
#endif  // !defined(SYSTEM_LITTLE_ENDIAN) && !defined(SYSTEM_BIG_ENDIAN)

#ifndef SYSTEM_CPP_STANDARD
    #define SYSTEM_CPP_STANDARD 3
#endif  // SYSTEM_CPP_STANDARD

#if SYSTEM_CPP_STANDARD < 17
    #error "使用C++17标准，不再兼容C++98、C++03编译器。"
#endif  // SYSTEM_CPP_STANDARD < 17

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

#ifndef TCRE_CPPLIB_VERSION
    #error "没有定义标准库版本。"
#endif  // TCRE_CPPLIB_VERSION

#ifndef TCRE_SYSTEM_STDLIB
    #error "没有定义标准库。"
#endif  // TCRE_SYSTEM_STDLIB

#include "UserMacro.h"

#endif  // SYSTEM_HELPER_CONFIG_MACRO_H
