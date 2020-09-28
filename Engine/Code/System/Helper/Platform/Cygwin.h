//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 11:15)

#ifndef SYSTEM_HELPER_CYGWIN_H
#define SYSTEM_HELPER_CYGWIN_H

#if defined(__CYGWIN__)

    //  cygwin ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "Cygwin"
    #define SYSTEM_PLATFORM_CYGWIN

    #include <unistd.h>
    #include <sys/types.h>

#endif  // defined(__CYGWIN__)

#endif  // SYSTEM_HELPER_CYGWIN_H
