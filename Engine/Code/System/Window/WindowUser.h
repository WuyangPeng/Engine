//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 13:13)

#ifndef SYSTEM_WINDOW_WINDOW_USER_H
#define SYSTEM_WINDOW_WINDOW_USER_H

#include "System/SystemDll.h"

#include "Fwd/WindowFlagsFwd.h"
#include "Using/WindowUsing.h"

namespace System
{
    // Window用户辅助函数。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE PostSystemThreadMessage(WindowDWord threadID, WindowMessages msg, WindowWParam wParam, WindowLParam lParam) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SystemInvalidateRect(WindowHWnd hwnd) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE UpdateSystemWindows(WindowHWnd hwnd) noexcept;
}

#endif  // SYSTEM_WINDOW_WINDOW_REGISTER_H