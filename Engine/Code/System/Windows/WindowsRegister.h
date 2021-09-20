///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.6 (2021/07/03 21:53)

#ifndef SYSTEM_WINDOWS_WINDOWS_REGISTER_H
#define SYSTEM_WINDOWS_WINDOWS_REGISTER_H

#include "System/SystemDll.h"

#include "Fwd/WindowsFlagsFwd.h"
#include "Using/WindowsPictorialUsing.h"
#include "Using/WindowsUsing.h"
#include "System/Helper/UnicodeUsing.h"

namespace System
{
    // Windows����ע����ص��á�

    NODISCARD WindowsHGdiObj SYSTEM_DEFAULT_DECLARE GetSystemStockObject(WindowsBrushTypes background) noexcept;
    NODISCARD WindowsHCursor SYSTEM_DEFAULT_DECLARE LoadSystemCursor(WindowsHInstance instance, const TChar* cursor) noexcept;
    NODISCARD WindowsHIcon SYSTEM_DEFAULT_DECLARE LoadSystemIcon(WindowsHInstance instance, const TChar* icon) noexcept;
    NODISCARD WindowsAtom SYSTEM_DEFAULT_DECLARE RegisterSystemClass(const WindowsClassEx* wndClassEx) noexcept;
    NODISCARD WindowsUInt SYSTEM_DEFAULT_DECLARE RegisterSystemWindowMessage(const TChar* string) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOWS_REGISTER_H