///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/29 11:23)

#ifndef SYSTEM_HELPER_BEOS_H
#define SYSTEM_HELPER_BEOS_H

#if defined(__BEOS__)

    //  BeOS ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "BeOS"
    #define SYSTEM_PLATFORM_BEOS static_cast<void>(0)

#endif  // __BEOS__

#endif  // SYSTEM_HELPER_BEOS_H
