/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 19:53)

#ifndef SYSTEM_HELPER_BEOS_H
#define SYSTEM_HELPER_BEOS_H

#if defined(__BEOS__)

    ///  BeOS ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "BeOS"
    #define SYSTEM_PLATFORM_BEOS static_cast<void>(0)

#endif  // __BEOS__

#endif  // SYSTEM_HELPER_BEOS_H
