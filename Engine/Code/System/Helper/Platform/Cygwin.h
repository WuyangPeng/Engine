///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/29 11:22)

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
