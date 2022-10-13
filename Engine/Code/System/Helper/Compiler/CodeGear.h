///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/10 13:13)

#ifndef SYSTEM_HELPER_CODE_GEAR_H
#define SYSTEM_HELPER_CODE_GEAR_H

#ifdef __CODEGEARC__

    // CodeGear C++���������ã�

    // �汾��飺�����֪�İ汾��0x621
    #if (0x740 < __CODEGEARC__)

        #error "δ֪�汾"

    #endif  // 0x621 < __CODEGEARC__

    // Clang��ǿ��Windows������
    #ifdef __clang__

        #include "Clang.h"

        // Embarcadero����������ض�����
        #define TCRE_EMBTC __CODEGEARC__
        #define TCRE_EMBTC_FULL_VER ((__clang_major__ << 16) | (__clang_minor__ << 8) | __clang_patchlevel__)

        // �������ʹ���ĸ�Embarcadero��������
        #if defined(TCRE_EMBTC)

            #if defined(_WIN64)

                #define TCRE_EMBTC_WIN64 1
                #define TCRE_EMBTC_WINDOWS 1

            #elif defined(_WIN32)

                #define TCRE_EMBTC_WIN32C 1
                #define TCRE_EMBTC_WINDOWS 1

            #elif defined(__APPLE__) && defined(__arm__)

                #define TCRE_EMBTC_IOSARM 1
                #define TCRE_EMBTC_IOS 1

            #elif defined(__APPLE__) && defined(__aarch64__)

                #define TCRE_EMBTC_IOSARM64 1
                #define TCRE_EMBTC_IOS 1

            #elif defined(__ANDROID__) && defined(__arm__)

                #define TCRE_EMBTC_AARM 1
                #define TCRE_EMBTC_ANDROID 1

            #elif  // !defined(ALL)

                #error "δ֪��Embarcadero��������"

            #endif  // defined(ALL)

        #endif  // defined(TCRE_EMBTC)

        #if defined(TCRE_EMBTC_WINDOWS)

            #if !defined(_chdir)

                #define _chdir(x) chdir(x)

            #endif  // !defined(_chdir)

            #if !defined(_dup2)

                #define _dup2(x, y) dup2(x, y)

            #endif  // !defined(_dup2)

        #endif  // TCRE_EMBTC_WINDOWS

        #undef TCRE_SYSTEM_COMPILER
        #define TCRE_SYSTEM_COMPILER "Embarcadero-Clang C++ �汾 " SYSTEM_STRINGIZE(TCRE_EMBTC) " clang: " SYSTEM_STRINGIZE(__clang_version__)

    #else  // !__clang__

        #ifndef SYSTEM_CPP_STANDARD

            #define SYSTEM_CPP_STANDARD 3

        #endif  // SYSTEM_CPP_STANDARD

        #ifndef TCRE_USE_CODE_GEAR

            #define TCRE_USE_CODE_GEAR 1

        #endif  // TCRE_USE_CODE_GEAR

        #ifndef TCRE_COMPILER_VERSION

            #define TCRE_COMPILER_VERSION __CODEGEARC__

        #endif  // TCRE_COMPILER_VERSION

        #ifndef TCRE_SYSTEM_COMPILER

            #define TCRE_SYSTEM_COMPILER "CodeGear C++ �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

        #endif  // TCRE_SYSTEM_COMPILER

        // ��Щ����Ƶ���������Ż���ģ�������
        #pragma warn - 8004  // var��ֵ������δʹ��
        #pragma warn - 8008  // ����������/��
        #pragma warn - 8066  // ��������Զ����ִ��
        #pragma warn - 8104  // ��̬��Ա���캯�������̰߳�ȫ
        #pragma warn - 8105  // ���ó�Ա��û�й��캯��������

        #if defined(NDEBUG)

            // �޸����ϱ�׼��<cstring>
            #include <cstring>
            #undef strcmp

        #endif  // defined(NDEBUG)

        // �޸����ϱ�׼��errno������
        #include <errno.h>
        #ifndef errno

            #define errno errno

        #endif  // errno

    #endif  // __clang__

#endif  // __CODEGEARC__

#endif  // SYSTEM_HELPER_CODE_GEAR_H
