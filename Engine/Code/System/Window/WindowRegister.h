//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 11:37)

#ifndef SYSTEM_WINDOW_WINDOW_REGISTER_H
#define SYSTEM_WINDOW_WINDOW_REGISTER_H

#include "System/SystemDll.h"

#include "Fwd/WindowFlagsFwd.h"
#include "Using/WindowPictorialUsing.h"
#include "Using/WindowUsing.h"
#include "System/Helper/UnicodeUsing.h"

namespace System
{
    // Window窗口注册相关调用。

    [[nodiscard]] WindowHGdiObj SYSTEM_DEFAULT_DECLARE GetSystemStockObject(WindowBrushTypes background) noexcept;
    [[nodiscard]] WindowHCursor SYSTEM_DEFAULT_DECLARE LoadSystemCursor(WindowHInstance instance, const TChar* cursor) noexcept;
    [[nodiscard]] WindowHIcon SYSTEM_DEFAULT_DECLARE LoadSystemIcon(WindowHInstance instance, const TChar* icon) noexcept;
    [[nodiscard]] WindowAtom SYSTEM_DEFAULT_DECLARE RegisterSystemClass(const WindowClassEx* wndClassEx) noexcept;
    [[nodiscard]] WindowUInt SYSTEM_DEFAULT_DECLARE RegisterSystemWindowMessage(const TChar* string) noexcept;
}

#endif  // SYSTEM_WINDOW_WINDOW_REGISTER_H