/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 19:53)

#ifndef SYSTEM_HELPER_CLOUD_ABI_H
#define SYSTEM_HELPER_CLOUD_ABI_H

#if defined(__CloudABI__)

    #define TCRE_SYSTEM_PLATFORM "CloudABI"
    #define SYSTEM_PLATFORM_CLOUD_ABI static_cast<void>(0)

#endif  // __CloudABI__

#endif  // SYSTEM_HELPER_CLOUD_ABI_H
