/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 18:03)

#ifndef SYSTEM_HELPER_CONFIG_MACRO_H
#define SYSTEM_HELPER_CONFIG_MACRO_H

#include "StringizeMacro.h"

// �ض���ƽ̨����Ϣ��
#include "SelectPlatformConfig.h"

// �ض��ڱ���������Ϣ��
#include "SelectCompilerConfig.h"

// �ض��ڱ�׼�����Ϣ��
#include "SelectStdlibConfig.h"

#if !defined(SYSTEM_LITTLE_ENDIAN) && !defined(SYSTEM_BIG_ENDIAN)

    #define SYSTEM_LITTLE_ENDIAN static_cast<void>(0)

#endif  // !defined(SYSTEM_LITTLE_ENDIAN) && !defined(SYSTEM_BIG_ENDIAN)

#ifndef SYSTEM_CPP_STANDARD

    #define SYSTEM_CPP_STANDARD 3

#endif  // SYSTEM_CPP_STANDARD

#if SYSTEM_CPP_STANDARD < 17

    #error "ʹ��C++17��׼�����ټ���C++98��C++03��������"

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

    #error "û�ж���ƽ̨��"

#endif  // TCRE_SYSTEM_PLATFORM

#ifndef TCRE_COMPILER_VERSION

    #error "û�ж���������汾��"

#endif  // TCRE_COMPILER_VERSION

#ifndef TCRE_SYSTEM_COMPILER

    #error "û�ж����������"

#endif  // TCRE_SYSTEM_COMPILER

#ifndef TCRE_CPPLIB_VERSION

    #error "û�ж����׼��汾��"

#endif  // TCRE_CPPLIB_VERSION

#ifndef TCRE_SYSTEM_STDLIB

    #error "û�ж����׼�⡣"

#endif  // TCRE_SYSTEM_STDLIB

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
