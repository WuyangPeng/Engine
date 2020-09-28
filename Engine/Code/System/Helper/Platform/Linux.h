//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 11:16)

#ifndef SYSTEM_HELPER_LINUX_H
#define SYSTEM_HELPER_LINUX_H

#if (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)

    //  linux ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "linux"
    #define SYSTEM_PLATFORM_LINUX

    // �������,ȷ��������__GLIBC_PREREQ
    #include <cstdlib>

    // PC Linux ƽ̨
    #if !defined(__LINUX__) && defined(__linux__)
        // ��Ȼ����� PC Linux �汾����__linux__����������ʹ��__LINUX__
        // Ϊ�˱����ƻ�����ͨ��__LINUX__�滻__linux__������ֻ����__LINUX__��
        #define __LINUX__
    #endif  // __LINUX__

    // ֧�ֱ�׼���������͡�
    #include <inttypes.h>

    #define SYSTEM_LITTLE_ENDIAN

    #ifndef __GNUC__

        // �������������gcc��������Ȼ��Ҫ�ܹ�����GNUϵͳͷ������һЩ����Ҫ��<stdint.h>��ʹ��GNU�ض�����չ��

        #ifndef __extension__
            #define __extension__
        #endif  // __extension__

        #ifndef __const__
            #define __const__ const
        #endif  // __const__

        #ifndef __volatile__
            #define __volatile__ volatile
        #endif  // __volatile__

        #ifndef __signed__
            #define __signed__ signed
        #endif  // __signed__

        #ifndef __typeof__
            #define __typeof__ typeof
        #endif  // __typeof__

        #ifndef __inline__
            #define __inline__ inline
        #endif  // __inline__

    #endif  // __GNUC__

    #ifdef __ANDROID__
        #define SYSTEM_PLATFORM_ANDROID
    #endif  // __ANDROID__

#endif  // (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)

#endif  // SYSTEM_HELPER_LINUX_H
