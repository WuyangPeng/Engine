/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 18:08)

#ifndef SYSTEM_HELPER_IRIX_H
#define SYSTEM_HELPER_IRIX_H

#if defined(__sgi)

    //  SGI Irix ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "SGI Irix"
    #define SYSTEM_PLATFORM_IRIX static_cast<void>(0)

#endif  // __sgi

#endif  // SYSTEM_HELPER_IRIX_H
