///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 23:14)

#ifndef SYSTEM_WINDOWS_WINDOWS_REGISTER_H
#define SYSTEM_WINDOWS_WINDOWS_REGISTER_H

#include "System/SystemDll.h"

#include "Fwd/WindowsFlagsFwd.h"
#include "Using/WindowsPictorialUsing.h"
#include "Using/WindowsUsing.h"
#include "System/Helper/UnicodeUsing.h"

namespace System
{
    // Windows窗口注册相关调用。

    NODISCARD WindowsHGdiObj SYSTEM_DEFAULT_DECLARE GetSystemStockObject(WindowsBrushTypes background) noexcept;
    NODISCARD WindowsHCursor SYSTEM_DEFAULT_DECLARE LoadSystemCursor(WindowsHInstance instance, const TChar* cursor) noexcept;
    NODISCARD WindowsHIcon SYSTEM_DEFAULT_DECLARE LoadSystemIcon(WindowsHInstance instance, const TChar* icon) noexcept;
    NODISCARD WindowsAtom SYSTEM_DEFAULT_DECLARE RegisterSystemClass(const WindowsClassEx* wndClassEx) noexcept;
    NODISCARD WindowsUInt SYSTEM_DEFAULT_DECLARE RegisterSystemWindowMessage(const TChar* string) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOWS_REGISTER_H