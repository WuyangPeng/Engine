/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 21:43)

#ifndef SYSTEM_HELPER_ROGUE_WAVE_H
#define SYSTEM_HELPER_ROGUE_WAVE_H

#if defined(__STD_RWCOMPILER_H__) || defined(_RWSTD_VER)

    ///  Rogue Wave ��׼��

    #define TCRE_ROGUE_WAVE_STD_LIB 1

    #ifndef _RWSTD_VER

        #define TCRE_RW_STD_VERSION 0x010000

    #elif _RWSTD_VER < 0x010000

        #define TCRE_RW_STD_VERSION (_RWSTD_VER << 8)

    #else  // 0x010000 <= _RWSTD_VER

        #define TCRE_RW_STD_VERSION _RWSTD_VER

    #endif  // _RWSTD_VER

    #ifndef TCRE_CPP_LIB_VERSION

        #define TCRE_CPP_LIB_VERSION TCRE_RW_STD_VERSION

    #endif  // TCRE_CPP_LIB_VERSION

    #ifndef _RWSTD_VER

        #define TCRE_SYSTEM_STD_LIB "Rogue Wave ��׼��汾 (δ֪�汾)"

    #elif _RWSTD_VER < 0x04010200

        #define TCRE_SYSTEM_STD_LIB "Rogue Wave ��׼��汾 " SYSTEM_STRINGIZE(TCRE_CPP_LIB_VERSION)

    #else  // 0x04010200 <= _RWSTD_VER

        #ifdef _RWSTD_VER_STR

            #define TCRE_SYSTEM_STD_LIB "Apache STDCXX ��׼��汾 " _RWSTD_VER_STR

        #else  // !_RWSTD_VER_STR

            #define TCRE_SYSTEM_STD_LIB "Apache STDCXX ��׼��汾 " SYSTEM_STRINGIZE(TCRE_CPP_LIB_VERSION)

        #endif  // _RWSTD_VER_STR

    #endif  // _RWSTD_VER

    #define TCRE_USE_ROGUE_WAVE static_cast<void>(0)

#endif  // defined(__STD_RWCOMPILER_H__) || defined(_RWSTD_VER)

#endif  // SYSTEM_HELPER_ROGUE_WAVE_H
