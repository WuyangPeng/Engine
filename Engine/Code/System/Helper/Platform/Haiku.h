/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 18:08)

#ifndef SYSTEM_HELPER_HAIKU_H
#define SYSTEM_HELPER_HAIKU_H

#if defined(__HAIKU__)

    //  Haiku ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "Haiku"
    #define SYSTEM_PLATFORM_HAIKU static_cast<void>(0)

#endif  // __HAIKU__

#endif  // SYSTEM_HELPER_HAIKU_H
