// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:45)

#ifndef SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_FWD_H
#define SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_FWD_H 

#include "DynamicLinkDataFwd.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"

namespace System
{
	DynamicLinkModule GetDynamicLinkHandle(const DynamicLinkCharType* moduleName) noexcept;
	WindowDWord GetDynamicLinkFileName(DynamicLinkModule module, DynamicLinkCharType* filename, WindowDWord size) noexcept;
	bool GetDynamicLinkHandle(GetModuleHandle flags, const DynamicLinkCharType* moduleName, DynamicLinkModule* module) noexcept;
}

#endif // SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_FWD_H