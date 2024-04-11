/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 17:29)

#ifndef SYSTEM_HELPER_XLCPP_H
#define SYSTEM_HELPER_XLCPP_H

#if defined(__ibmxl__)

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_XL_CPP

        #define TCRE_USE_XL_CPP 1

    #endif  // TCRE_USE_XL_CPP

    #ifndef TCRE_CLANG

        #define TCRE_CLANG 1

    #endif  // TCRE_CLANG

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __clang_version__

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "Clang �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

    #if defined(__GNUC__) && (4 <= __GNUC__)

        #define MAYBE_UNUSED __attribute__((unused))

    #endif  // defined(__GNUC__) && (4 <= __GNUC__)

    /// �ڶ���__has_extension֮ǰʹ��clang���б���ʱ��
    /// ��ʹд��'defined(__has_extension) && __has_extension(xxx)'��
    /// clangҲ�������������
    /// ��ˣ��ҵ���Ψһ��������ǣ�

    #ifndef __has_extension

        #define __has_extension __has_feature

    #endif  // __has_extension

    #ifndef __has_cpp_attribute

        #define __has_cpp_attribute(x) 0

    #endif  // __has_cpp_attribute

    /// ��֧Ԥ����ʾ
    #if defined(__has_builtin)

        #if __has_builtin(__builtin_expect)

            #define TCRE_LIKELY(x) __builtin_expect(x, 1)
            #define TCRE_UNLIKELY(x) __builtin_expect(x, 0)

        #endif  // __has_builtin(__builtin_expect)

    #endif  // defined(__has_builtin)

    /// FALLTHROUGH�������ע��switch��ǩ֮�����ʽ��fall-through��
    #if 201103L <= __cplusplus && defined(__has_warning)

        #if __has_feature(cxx_attributes) && __has_warning("-Wimplicit-fallthrough")

            #define FALLTHROUGH [[clang::fallthrough]]

        #endif  //  __has_feature(cxx_attributes) && __has_warning("-Wimplicit-fallthrough")

    #endif  // 201103L <= __cplusplus && defined(__has_warning)

#endif  // defined(__ibmxl__)

#endif  // SYSTEM_HELPER_XLCPP_H