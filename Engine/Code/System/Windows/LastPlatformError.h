///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.1 (2023/02/02 14:39)

#ifndef SYSTEM_WINDOWS_LAST_PLATFORM_ERROR_H
#define SYSTEM_WINDOWS_LAST_PLATFORM_ERROR_H

#include "System/SystemDll.h"

#include "Fwd/WindowsFlagsFwd.h"

// ��ȡ������ϵͳ�����롣
namespace System
{
    NODISCARD WindowError SYSTEM_DEFAULT_DECLARE GetPlatformLastError() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetPlatformLastError(WindowError error) noexcept;
    NODISCARD ErrorMode SYSTEM_DEFAULT_DECLARE GetPlatformErrorMode() noexcept;
    NODISCARD ErrorMode SYSTEM_DEFAULT_DECLARE SetPlatformErrorMode(ErrorMode flag) noexcept;
}

#endif  // SYSTEM_WINDOWS_LAST_PLATFORM_ERROR_H
