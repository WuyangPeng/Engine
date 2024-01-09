/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 19:20)

#ifndef SYSTEM_CONSOLE_CONSOLE_HANDLE_H
#define SYSTEM_CONSOLE_CONSOLE_HANDLE_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

// ����̨����Ļ�ȡ�����á�
namespace System
{
    NODISCARD WindowsHandle SYSTEM_DEFAULT_DECLARE GetStandardHandle(StandardHandle standardHandle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsHandleValid(WindowsHandle handle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetStandardHandle(StandardHandle standardHandle, WindowsHandle handle) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetStandardHandle(StandardHandle standardHandle, WindowsHandle handle, WindowsHandlePtr previousHandle) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_HANDLE_H