///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 09:25)

#ifndef SYSTEM_WINDOWS_WINDOW_USER_H
#define SYSTEM_WINDOWS_WINDOW_USER_H

#include "System/SystemDll.h"

#include "Fwd/WindowsFlagsFwd.h"
#include "Using/WindowsUsing.h"

// Windows用户辅助函数。
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE PostSystemThreadMessage(WindowsDWord threadId, WindowsMessages message, WindowsWParam wParam, WindowsLParam lParam) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemInvalidateRect(WindowsHWnd hWnd) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE UpdateSystemWindows(WindowsHWnd hWnd) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOW_REGISTER_H