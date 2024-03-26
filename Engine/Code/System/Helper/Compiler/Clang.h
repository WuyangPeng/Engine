/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 17:24)

#ifndef SYSTEM_HELPER_CLANG_H
#define SYSTEM_HELPER_CLANG_H

/// Clang���������ã�

#if defined(__clang__) && !defined(__CUDACC__) && !defined(__ibmxl__)

    #if defined(__CUDACC__)

        #if defined(__GXX_EXPERIMENTAL_CXX0X__) || (201103L <= __cplusplus)

            #define SYSTEM_CPP_STANDARD 11

        #else  // !defined(__GXX_EXPERIMENTAL_CXX0X__) || (__cplusplus < 201103L)

            #define SYSTEM_CPP_STANDARD 3

        #endif  // defined(__GXX_EXPERIMENTAL_CXX0X__) || (201103L <= __cplusplus)

    #endif  // __CUDACC__

    #ifndef TCRE_USE_CLANG

        #define TCRE_USE_CLANG 1

    #endif  // TCRE_USE_CLANG

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __clang_version__

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "Clang �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

    /// �ڶ���__has_extension֮ǰʹ��clang���б���ʱ��
    /// ��ʹ��д�ˡ�defined(__has_extension) && __has_extension(xxx)����
    /// clangҲ�ᱨ���������������Ψһ�Ľ�������ǣ�
    #ifndef __has_extension

        #define __has_extension __has_feature

    #endif  // __has_extension

    #ifndef __has_attribute

        #define __has_attribute(x) 0

    #endif  // __has_attribute

    #ifndef __has_cpp_attribute

        #define __has_cpp_attribute(x) 0

    #endif  // __has_cpp_attribute

    /// �Ե�һ���汾������Clangһֱ֧�֡�unused�����ԡ�
    #define MAYBE_UNUSED __attribute__((__unused__))

    /// FALLTHROUGH�������ע��switch��ǩ֮�����ʽ��fall-through��
    #if 201103L <= __cplusplus && defined(__has_warning)

        #if __has_feature(cxx_attributes) && __has_warning("-Wimplicit-fallthrough")

            #define FALLTHROUGH [[clang::fallthrough]]

        #endif  //  __has_feature(cxx_attributes) && __has_warning("-Wimplicit-fallthrough")

    #endif  // 201103L <= __cplusplus && defined(__has_warning)

#endif  // defined(__clang__) && !defined(__CUDACC__) && !defined(__ibmxl__)

#endif  // SYSTEM_HELPER_CLANG_H
