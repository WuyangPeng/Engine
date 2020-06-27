// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/09 13:40)

#ifndef SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_H
#define SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_H

#include "System/SystemDll.h" 

#include "Using/LoadLibraryUsing.h"
#include "Fwd/DynamicLinkFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 使用动态链接库的辅助函数。

	DynamicLinkModule SYSTEM_DEFAULT_DECLARE GetDynamicLinkHandle(const DynamicLinkCharType* moduleName) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetDynamicLinkFileName(DynamicLinkModule module, DynamicLinkCharType* filename, WindowDWord size) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetDynamicLinkHandle(GetModuleHandle flags, const DynamicLinkCharType* moduleName, DynamicLinkModule* module) noexcept;
}

#endif // SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_H
