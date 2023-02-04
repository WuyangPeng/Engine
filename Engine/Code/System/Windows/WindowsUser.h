///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.1 (2023/02/02 14:41)

#ifndef SYSTEM_WINDOWS_WINDOW_USER_H
#define SYSTEM_WINDOWS_WINDOW_USER_H

#include "System/SystemDll.h"

#include "Fwd/WindowsFlagsFwd.h"
#include "Using/WindowsUsing.h"

// Windows�û�����������
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE PostSystemThreadMessage(WindowsDWord threadID, WindowsMessages msg, WindowsWParam wParam, WindowsLParam lParam) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemInvalidateRect(WindowsHWnd hwnd) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE UpdateSystemWindows(WindowsHWnd hwnd) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOW_REGISTER_H