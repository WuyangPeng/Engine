///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 18:37)

#ifndef SYSTEM_HELPER_HAIKU_H
#define SYSTEM_HELPER_HAIKU_H

#if defined(__HAIKU__)

    //  Haiku ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "Haiku"
    #define SYSTEM_PLATFORM_HAIKU static_cast<void>(0)

#endif  // __HAIKU__

#endif  // SYSTEM_HELPER_HAIKU_H
