///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 18:35)

#ifndef SYSTEM_HELPER_ZOS_H
#define SYSTEM_HELPER_ZOS_H

#if defined(__TOS_MVS__)

    //  IBM z/OS ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "IBM z/OS"
    #define SYSTEM_PLATFORM_ZOS static_cast<void>(0)

    // �� __UU, __C99, __TR1, ...
    #include <features.h>

#endif  // defined(__TOS_MVS__)

#endif  // SYSTEM_HELPER_ZOS_H
