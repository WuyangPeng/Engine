/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 18:08)

#ifndef SYSTEM_HELPER_SOLARIS_H
#define SYSTEM_HELPER_SOLARIS_H

#if defined(sun) || defined(__sun)

    //  sun ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "Sun Solaris"
    #define SYSTEM_PLATFORM_SOLARIS static_cast<void>(0)

#endif  // defined(sun) || defined(__sun)

#endif  // SYSTEM_HELPER_SOLARIS_H
