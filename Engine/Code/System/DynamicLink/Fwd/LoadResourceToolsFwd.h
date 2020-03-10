// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 14:45)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_FWD_H
#define SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_FWD_H

#include "DynamicLinkDataFwd.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/DynamicLink/Using/LoadResourceToolsUsing.h"

namespace System
{
	DynamicLinkResource FindResourceInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name) noexcept;
	DynamicLinkResource FindResourceInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type,
											  const DynamicLinkCharType* name, const LanguageIDData& language) noexcept;
	DynamicLinkGlobal LoadResourceInLibrary(DynamicLinkModule module, DynamicLinkResource resourceInfo) noexcept;
	WindowVoidPtr LockResourceInLibrary(DynamicLinkGlobal resourceData) noexcept;
	WindowDWord SizeofResourceInLibrary(DynamicLinkModule module, DynamicLinkResource resourceInfo) noexcept;
	bool UpdateResourceInLibrary(WindowHandle update, const DynamicLinkCharType* type, const DynamicLinkCharType* name,
								 const LanguageIDData& language, WindowVoidPtr resourceLock, WindowDWord size) noexcept;
	WindowHandle BeginUpdateResourceInLibrary(const DynamicLinkCharType* fileName, bool deleteExistingResources) noexcept;
	bool EndUpdateResourceInLibrary(WindowHandle update, bool discard) noexcept;
	int LoadStringInLibrary(WindowHInstance instance, WindowUInt id, DynamicLinkCharType* buffer, int size) noexcept;
}

#endif // SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_FWD_H
