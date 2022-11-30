///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/17 21:40)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_H
#define SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/DynamicLinkDataFwd.h"
#include "Using/LoadLibraryUsing.h"
#include "Using/LoadResourceToolsUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputDataFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

// 加载动态链接库资源的辅助函数。
namespace System
{
    // 调整了type和name的参数顺序，使两个函数使用相同的顺序。
    NODISCARD DynamicLinkResource SYSTEM_DEFAULT_DECLARE FindResourceInLibrary(DynamicLinkModule module,
                                                                               const DynamicLinkCharType* type,
                                                                               const DynamicLinkCharType* name) noexcept;
    NODISCARD DynamicLinkResource SYSTEM_DEFAULT_DECLARE FindResourceInLibrary(DynamicLinkModule module,
                                                                               const DynamicLinkCharType* type,
                                                                               const DynamicLinkCharType* name,
                                                                               const LanguageIDData& language) noexcept;

    NODISCARD DynamicLinkGlobal SYSTEM_DEFAULT_DECLARE LoadResourceInLibrary(DynamicLinkModule module,
                                                                             DynamicLinkResource resourceInfo) noexcept;
    NODISCARD WindowsVoidPtr SYSTEM_DEFAULT_DECLARE LockResourceInLibrary(DynamicLinkGlobal resourceData) noexcept;
    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE SizeofResourceInLibrary(DynamicLinkModule module,
                                                                          DynamicLinkResource resourceInfo) noexcept;

    NODISCARD int SYSTEM_DEFAULT_DECLARE LoadStringInLibrary(WindowsHInstance instance,
                                                             WindowsUInt id,
                                                             DynamicLinkCharType* buffer,
                                                             int size) noexcept;
}

#endif  // SYSTEM_DYNAMIC_LINK_LOAD_RESOURCE_TOOLS_H
