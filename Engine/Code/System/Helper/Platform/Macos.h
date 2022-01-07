///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 18:36)

#ifndef SYSTEM_HELPER_MACOS_H
#define SYSTEM_HELPER_MACOS_H

#if defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)

    //  Mac OS ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "Mac OS"
    #define SYSTEM_PLATFORM_MACOS static_cast<void>(0)

    #if defined(__BIG_ENDIAN__)
        #define SYSTEM_BIG_ENDIAN static_cast<void>(0)
    #else  // !defined(__BIG_ENDIAN__)
        #define SYSTEM_LITTLE_ENDIAN static_cast<void>(0)
    #endif  // defined(__BIG_ENDIAN__)

#endif  // defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)

#endif  // SYSTEM_HELPER_MACOS_H
