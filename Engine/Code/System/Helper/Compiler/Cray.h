/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 18:13)

#ifndef SYSTEM_HELPER_COMPAQ_CXX_H
#define SYSTEM_HELPER_COMPAQ_CXX_H

#ifdef _CRAYC

    // Greenhills C ���������ã�

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_CRAY

        #define TCRE_USE_CRAY 1

    #endif  // TCRE_USE_CRAY

    #define TCRE_CRAY_x 9867657  // ��������
    #define TCRE_CRAY_APPEND(MACRO) TCRE_CRAY_APPEND_INTERNAL(MACRO)
    #define TCRE_CRAY_APPEND_INTERNAL(MACRO) SYSTEM_CONCATENATOR(TCRE_CRAY_, MACRO)

    #if TCRE_CRAY_x == TCRE_CRAY_APPEND(_RELEASE_PATCHLEVEL)

        /// ����һ��������Ա������
        /// _RELEASE_PATCHLEVEL����Ϊx��
        /// xδ����Ϊ�꣬
        /// ��װ_RELEASE_PATCHLEVELΪ99��
        /// ������ǻ���˴˰汾�����²�����������á�

        #define CRAY_VERSION (_RELEASE_MAJOR * 10000 + _RELEASE_MINOR * 100 + 99)

    #else  // !TCRE_CRAY_x == TCRE_CRAY_APPEND(_RELEASE_PATCHLEVEL)

        /// ����һ�������汾,
        /// _RELEASE_PATCHLEVELδ����Ϊx��
        /// ��x������Ϊ�ꡣ

        #define CRAY_VERSION (_RELEASE_MAJOR * 10000 + _RELEASE_MINOR * 100 + _RELEASE_PATCHLEVEL)

    #endif  // BOOST_CRAY_x == BOOST_CRAY_APPEND(_RELEASE_PATCHLEVEL)

    #undef TCRE_CRAY_APPEND_INTERNAL
    #undef TCRE_CRAY_APPEND
    #undef TCRE_CRAY_x

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION CRAY_VERSION

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "Cray C �汾 " SYSTEM_STRINGIZE(_RELEASE_MAJOR) "." SYSTEM_STRINGIZE(_RELEASE_MINOR) "." SYSTEM_STRINGIZE(_RELEASE_PATCHLEVEL)

    #endif  // TCRE_SYSTEM_COMPILER

    #if CRAY_VERSION < 80000

        #error "�ڰ汾8֮ǰû��ΪCray���������á������������ýű���"

    #endif  // CRAY_VERSION < 80000

    // ��Щ����Ӧ���ɱ������ṩ��������������������-hgnuʱ��
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
