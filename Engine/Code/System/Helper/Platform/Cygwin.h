///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 18:37)

#ifndef SYSTEM_HELPER_CYGWIN_H
#define SYSTEM_HELPER_CYGWIN_H

#if defined(__CYGWIN__)

    //  cygwin ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "Cygwin"
    #define SYSTEM_PLATFORM_CYGWIN static_cast<void>(0)

    #include <sys/types.h>
    #include <unistd.h>

#endif  // defined(__CYGWIN__)

#endif  // SYSTEM_HELPER_CYGWIN_H
