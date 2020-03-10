// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:36)

#ifndef SYSTEM_WINDOW_WINDOW_REGISTER_FWD_H 
#define SYSTEM_WINDOW_WINDOW_REGISTER_FWD_H  

#include "WindowFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/Using/WindowPictorialUsing.h" 

namespace System
{
	WindowHGdiObj GetSystemStockObject(WindowBrushTypes background) noexcept;
	WindowHCursor LoadSystemCursor(WindowHInstance instance, const TChar* cursor) noexcept;
	WindowHIcon LoadSystemIcon(WindowHInstance instance, const TChar* icon) noexcept;
	WindowAtom RegisterSystemClass(const WindowClassEx* wndClassEx) noexcept;
	WindowUInt RegisterSystemWindowMessage(const TChar* string) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_REGISTER_FWD_H