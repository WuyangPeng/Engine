///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/08 12:36)

#ifndef SYSTEM_HELPER_WIN32_H
#define SYSTEM_HELPER_WIN32_H

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

    //  Win32 ��������ѡ�

    // ΢��Windowsƽ̨
    #define TCRE_SYSTEM_PLATFORM "Win32"
    #define SYSTEM_PLATFORM_WIN32 static_cast<void>(0)

    // ��ȡ�й�MinGW����ʱ����Ϣ����__MINGW32_ * VERSION��
    #if defined(__MINGW32__)
        #include <_mingw.h>
    #endif  // defined(__MINGW32__)

    #ifndef _WIN32
        #define _WIN32
    #endif  // _WIN32

    #ifndef WIN32
        #define WIN32 static_cast<void>(0)
    #endif  // WIN32

    #ifndef __WIN32__
        #define __WIN32__ static_cast<void>(0)
    #endif  // __WIN32__

    #define SYSTEM_LITTLE_ENDIAN static_cast<void>(0)

    // ���ø�����ϵͳ�� windows.h.
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN 1
    #endif  // WIN32_LEAN_AND_MEAN

    // ����windows.h�еġ�min���͡�max���꣬����std::numeric_limits<type>::max()��ͻ��
    #ifndef NOMINMAX
        #define NOMINMAX static_cast<void>(0)
    #endif  // NOMINMAX

#endif  // defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

#endif  // SYSTEM_HELPER_WIN32_H
