///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 17:54)

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

#include "UserMacro.h"

#endif  // SYSTEM_HELPER_CONFIG_MACRO_H
