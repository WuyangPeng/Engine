/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 18:08)

#ifndef SYSTEM_HELPER_CLOUD_CRAY_H
#define SYSTEM_HELPER_CLOUD_CRAY_H

#if defined(_CRAYC)

    //  SGI Irix ��������ѡ�

    #define TCRE_SYSTEM_PLATFORM "Cray"
    #define SYSTEM_PLATFORM_CRAY static_cast<void>(0)

#endif  // _CRAYC

#endif  // SYSTEM_HELPER_CLOUD_CRAY_H
