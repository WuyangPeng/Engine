//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/27 11:37)

#ifndef SYSTEM_WINDOW_WINDOW_REGISTER_H
#define SYSTEM_WINDOW_WINDOW_REGISTER_H

#include "System/SystemDll.h"

#include "Fwd/WindowFlagsFwd.h"
#include "Using/WindowPictorialUsing.h"
#include "Using/WindowUsing.h"
#include "System/Helper/UnicodeUsing.h"

namespace System
{
    // Window����ע����ص��á�

    [[nodiscard]] WindowHGdiObj SYSTEM_DEFAULT_DECLARE GetSystemStockObject(WindowBrushTypes background) noexcept;
    [[nodiscard]] WindowHCursor SYSTEM_DEFAULT_DECLARE LoadSystemCursor(WindowHInstance instance, const TChar* cursor) noexcept;
    [[nodiscard]] WindowHIcon SYSTEM_DEFAULT_DECLARE LoadSystemIcon(WindowHInstance instance, const TChar* icon) noexcept;
    [[nodiscard]] WindowAtom SYSTEM_DEFAULT_DECLARE RegisterSystemClass(const WindowClassEx* wndClassEx) noexcept;
    [[nodiscard]] WindowUInt SYSTEM_DEFAULT_DECLARE RegisterSystemWindowMessage(const TChar* string) noexcept;
}

#endif  // SYSTEM_WINDOW_WINDOW_REGISTER_H