///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.5 (2022/12/16 22:06)

#ifndef SYSTEM_HELPER_HAIKU_H
#define SYSTEM_HELPER_HAIKU_H

#if defined(__HAIKU__)

    //  Haiku ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "Haiku"
    #define SYSTEM_PLATFORM_HAIKU static_cast<void>(0)

#endif  // __HAIKU__

#endif  // SYSTEM_HELPER_HAIKU_H
