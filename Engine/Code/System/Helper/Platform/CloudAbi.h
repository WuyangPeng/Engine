///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.5 (2022/12/16 22:06)

#ifndef SYSTEM_HELPER_CLOUD_ABI_H
#define SYSTEM_HELPER_CLOUD_ABI_H

#if defined(__CloudABI__)

    #define TCRE_SYSTEM_PLATFORM "CloudABI"
    #define SYSTEM_PLATFORM_CLOUD_ABI static_cast<void>(0)

#endif  // __CloudABI__

#endif  // SYSTEM_HELPER_CLOUD_ABI_H
