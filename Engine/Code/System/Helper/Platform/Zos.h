/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 18:07)

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
