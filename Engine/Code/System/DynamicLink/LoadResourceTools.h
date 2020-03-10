// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 14:47)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_H
#define SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_H

#include "System/SystemDll.h" 

#include "Fwd/DynamicLinkDataFwd.h"
#include "Using/LoadLibraryUsing.h"
#include "Using/LoadResourceToolsUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputDataFwd.h"

namespace System
{
	// 加载动态链接库资源的辅助函数。

	DynamicLinkResource SYSTEM_DEFAULT_DECLARE FindResourceInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name) noexcept;
	DynamicLinkResource SYSTEM_DEFAULT_DECLARE FindResourceInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type,
																	 const DynamicLinkCharType* name, const LanguageIDData& language) noexcept;
	DynamicLinkGlobal SYSTEM_DEFAULT_DECLARE LoadResourceInLibrary(DynamicLinkModule module, DynamicLinkResource resourceInfo) noexcept;
	WindowVoidPtr SYSTEM_DEFAULT_DECLARE LockResourceInLibrary(DynamicLinkGlobal resourceData) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE SizeofResourceInLibrary(DynamicLinkModule module, DynamicLinkResource resourceInfo) noexcept;
	bool SYSTEM_DEFAULT_DECLARE UpdateResourceInLibrary(WindowHandle update, const DynamicLinkCharType* type, const DynamicLinkCharType* name,
														const LanguageIDData& language, WindowVoidPtr resourceLock, WindowDWord size) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE BeginUpdateResourceInLibrary(const DynamicLinkCharType* fileName, bool deleteExistingResources) noexcept;
	bool SYSTEM_DEFAULT_DECLARE EndUpdateResourceInLibrary(WindowHandle update, bool discard) noexcept;
	int SYSTEM_DEFAULT_DECLARE LoadStringInLibrary(WindowHInstance instance, WindowUInt id, DynamicLinkCharType* buffer, int size) noexcept;
}

#endif // SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_H
