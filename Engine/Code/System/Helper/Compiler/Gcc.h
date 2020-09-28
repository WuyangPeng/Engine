//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 11:04)

#ifndef SYSTEM_HELPER_GCC_H
#define SYSTEM_HELPER_GCC_H

#if defined(__GNUC__) && !defined(__ibmxl__)

    // GNU C++ ���������ã�

    #ifndef TCRE_USE_GCC
        #define TCRE_USE_GCC __GNUC__
    #endif  // TCRE_USE_GCC

    #ifndef GCC_VERSION
        #define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
    #endif  // GCC_VERSION

    // �汾��飺
    #if (GCC_VERSION < 30300)
        #error "������δ����"
    #endif  // GCC_VERSION < 30300

    #if !defined(__CUDACC__)
        #ifndef TCRE_COMPILER_VERSION
            #define TCRE_COMPILER_VERSION GCC_VERSION
        #endif  // TCRE_COMPILER_VERSION
    #endif  // __CUDACC__

    #ifndef TCRE_SYSTEM_COMPILER
        #ifdef __GXX_CONCEPTS__
            // ConceptGCC ��������http://www.generic-programming.org/software/ConceptGCC/
            #define TCRE_SYSTEM_COMPILER "ConceptGCC �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
        #else  // !__GXX_CONCEPTS__
            #define TCRE_SYSTEM_COMPILER "GNU C++ �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
        #endif  // __GXX_CONCEPTS__
    #endif  // TCRE_SYSTEM_COMPILER

    #ifndef SYSTEM_CPP_STANDARD
        #if defined(__cpp_if_constexpr) && (201606 <= __cpp_if_constexpr)
            #define SYSTEM_CPP_STANDARD 17
        #elif (201300L <= __cplusplus)
            #define SYSTEM_CPP_STANDARD 14
        #elif defined(__GXX_EXPERIMENTAL_CXX0X__) || (201103L <= __cplusplus)
            #define SYSTEM_CPP_STANDARD 11
        #else  // !defined(__GXX_EXPERIMENTAL_CXX0X__) && (__cplusplus < 201103L)
            #define SYSTEM_CPP_STANDARD 3
        #endif  // defined(__GXX_EXPERIMENTAL_CXX0X__) || (201103L <= __cplusplus)
    #endif  // SYSTEM_CPP_STANDARD

    #include <cstddef>

    #if 4 <= __GNUC__
        #define SYSTEM_ATTRIBUTE_UNUSED __attribute__((__unused__))
    #endif  // 4 <= __GNUC__

#endif  // defined(__GNUC__) && !defined(__ibmxl__)

#endif  // SYSTEM_HELPER_GCC_H
