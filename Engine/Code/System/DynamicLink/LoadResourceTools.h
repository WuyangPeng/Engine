//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 10:04)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_H
#define SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/DynamicLinkDataFwd.h"
#include "Using/LoadLibraryUsing.h"
#include "Using/LoadResourceToolsUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputDataFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // 加载动态链接库资源的辅助函数。

    [[nodiscard]] DynamicLinkResource SYSTEM_DEFAULT_DECLARE FindResourceInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name) noexcept;
    [[nodiscard]] DynamicLinkResource SYSTEM_DEFAULT_DECLARE FindResourceInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type,
                                                                                   const DynamicLinkCharType* name, const LanguageIDData& language) noexcept;
    [[nodiscard]] DynamicLinkGlobal SYSTEM_DEFAULT_DECLARE LoadResourceInLibrary(DynamicLinkModule module, DynamicLinkResource resourceInfo) noexcept;
    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE LockResourceInLibrary(DynamicLinkGlobal resourceData) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE SizeofResourceInLibrary(DynamicLinkModule module, DynamicLinkResource resourceInfo) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE UpdateResourceInLibrary(WindowHandle update, const DynamicLinkCharType* type, const DynamicLinkCharType* name,
                                                                      const LanguageIDData& language, WindowVoidPtr resourceLock, WindowDWord size) noexcept;
    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE BeginUpdateResourceInLibrary(const DynamicLinkCharType* fileName, bool deleteExistingResources) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE EndUpdateResourceInLibrary(WindowHandle update, bool discard) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE LoadStringInLibrary(WindowHInstance instance, WindowUInt id, DynamicLinkCharType* buffer, int size) noexcept;
}

#endif  // SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_H
