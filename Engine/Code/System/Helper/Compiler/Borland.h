//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 10:22)

#ifndef SYSTEM_HELPER_BORLAND_H
#define SYSTEM_HELPER_BORLAND_H

// Borland C++���������ã�

#ifdef __BORLANDC__

    // �汾��飺
    #if __BORLANDC__ < 0x540

        // ���ǲ�֧�ְ汾5.4֮ǰ��Borland��
        #error "��������֧�����á�������������"

    #elif (0x613 < __BORLANDC__)

        // ��֪�����ı������汾��
        #error "δ֪�ı������汾"

    #elif (__BORLANDC__ == 0x600)

        #error "����֧��CBuilderXԤ��������"

    #endif  // __BORLANDC__

    #ifndef SYSTEM_CPP_STANDARD
        #define SYSTEM_CPP_STANDARD 3
    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_BORLANDC
        #define TCRE_USE_BORLANDC 1
    #endif  // TCRE_USE_BORLANDC

    #ifndef TCRE_COMPILER_VERSION
        #define TCRE_COMPILER_VERSION __BORLANDC__
    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER
        #define TCRE_SYSTEM_COMPILER "Borland C++ �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #endif  // TCRE_SYSTEM_COMPILER

    // ֧�ֺ��԰�����׼����
    #if (__BORLANDC__ < 0x560) || defined(_USE_OLD_RW_STL)
        #define TCRE_BCB_WITH_ROGUE_WAVE
    #elif __BORLANDC__ < 0x570
        #define TCRE_BCB_WITH_STLPORT
    #else  // 0x570 <= __BORLANDC__
        #define TCRE_BCB_WITH_DINKUMWARE
    #endif  // __BORLANDC__

    // �汾5.51�����£�
    #if (__BORLANDC__ <= 0x551)

        // ȱ��WCHAR_MAX/WCHAR_MIN�Ľ������
        #include <climits>
        #include <cwchar>

        #ifndef WCHAR_MAX
            #define WCHAR_MAX 0xFFFF
        #endif  // WCHAR_MAX

        #ifndef WCHAR_MIN
            #define WCHAR_MIN 0
        #endif  // WCHAR_MIN

    #endif  // (__BORLANDC__ <= 0x551)

    // Borland C ++ Builder 6�����°汾��
    #if (__BORLANDC__ <= 0x564)

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

    #endif  // (__BORLANDC__ <= 0x564)

    // Borland C ++ Builder 2006 Update 2�����߰汾��
    #if (__BORLANDC__ <= 0x582)

        #ifdef defined(linux) || defined(__linux__) || defined(__linux)
            // _CPPUNWIND����ĳ��ԭ��δ�Զ�����
            #pragma defineonoption CPPUNWIND - x
        #endif  // defined(linux) || defined(__linux__) || defined(__linux)

    #endif  // (__BORLANDC__ <= 0x582)

    // Borland C++ Builder 6Ĭ��ʹ��STLPort��
    // �������_USE_OLD_RW_STL����ô���Ƕ�Rogue Waveʵ�־���0x560����߰汾���������std::DBL_MAX����
    #if defined(TCRE_BCB_WITH_ROGUE_WAVE)

        // <climits>���ֲ��ϱ�׼��һЩ�궨���������������ռ�std�еķ��ţ�
        // ���������ղ��ò�ʹ��std::DBL_MAX�����ķǷ����죬��Ϊһ���޸�������ֻ��Ҫ����float.h��
        #include <float.h>

    #endif  // defined(TCRE_BCB_WITH_ROGUE_WAVE)

#endif  // __BORLANDC__

#endif  // SYSTEM_HELPER_BORLAND_H
