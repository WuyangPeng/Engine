//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/27 11:35)

#ifndef SYSTEM_WINDOW_LAST_PLATFORM_ERROR_H
#define SYSTEM_WINDOW_LAST_PLATFORM_ERROR_H

#include "System/SystemDll.h"

#include "Fwd/WindowFlagsFwd.h"

namespace System
{
    // ��ȡ������ϵͳ�����롣

    [[nodiscard]] WindowError SYSTEM_DEFAULT_DECLARE GetPlatformLastError() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetPlatformLastError(WindowError error) noexcept;
    [[nodiscard]] ErrorMode SYSTEM_DEFAULT_DECLARE GetPlatformErrorMode() noexcept;
    [[nodiscard]] ErrorMode SYSTEM_DEFAULT_DECLARE SetPlatformErrorMode(ErrorMode flag) noexcept;
}

#endif  // SYSTEM_WINDOW_LAST_PLATFORM_ERROR_H
