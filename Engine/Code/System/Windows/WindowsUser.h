/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 15:37)

#ifndef SYSTEM_WINDOWS_WINDOW_USER_H
#define SYSTEM_WINDOWS_WINDOW_USER_H

#include "System/SystemDll.h"

#include "Fwd/WindowsFlagsFwd.h"
#include "Using/WindowsUsing.h"

/// Windows�û�����������
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE PostSystemThreadMessage(WindowsDWord threadId,
                                                                  WindowsMessages message,
                                                                  WindowsWParam wParam,
                                                                  WindowsLParam lParam) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemInvalidateRect(WindowsHWnd hWnd) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE UpdateSystemWindows(WindowsHWnd hWnd) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOW_REGISTER_H