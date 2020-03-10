// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:38)

#ifndef SYSTEM_WINDOW_WINDOW_REGISTER_H
#define SYSTEM_WINDOW_WINDOW_REGISTER_H

#include "System/SystemDll.h"

#include "Using/WindowUsing.h"
#include "Using/WindowPictorialUsing.h"
#include "Fwd/WindowFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"

namespace System
{
	// Window����ע����ص��á� 

	WindowHGdiObj SYSTEM_DEFAULT_DECLARE GetSystemStockObject(WindowBrushTypes background) noexcept;
	WindowHCursor SYSTEM_DEFAULT_DECLARE LoadSystemCursor(WindowHInstance instance, const TChar* cursor) noexcept;
	WindowHIcon SYSTEM_DEFAULT_DECLARE LoadSystemIcon(WindowHInstance instance, const TChar* icon) noexcept;
	WindowAtom SYSTEM_DEFAULT_DECLARE RegisterSystemClass(const WindowClassEx* wndClassEx) noexcept;
	WindowUInt SYSTEM_DEFAULT_DECLARE RegisterSystemWindowMessage(const TChar* string) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_REGISTER_H