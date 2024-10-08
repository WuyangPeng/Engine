/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 16:38)

#ifndef SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_H
#define SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/DynamicLinkFlagsFwd.h"
#include "Using/LoadLibraryUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

/// 使用动态链接库的辅助函数。
namespace System
{
    /// GetDynamicLinkHandle不增加句柄的引用计数。
    NODISCARD DynamicLinkModule SYSTEM_DEFAULT_DECLARE GetDynamicLinkHandle(const DynamicLinkCharType* moduleName) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetDynamicLinkHandle(GetModuleHandleType flags, const DynamicLinkCharType* moduleName, DynamicLinkModule* module) noexcept;

    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetDynamicLinkFileName(DynamicLinkModule module, DynamicLinkCharType* filename, WindowsDWord size) noexcept;
    NODISCARD DynamicLinkString SYSTEM_DEFAULT_DECLARE GetDynamicLinkFileName(DynamicLinkModule module);
    NODISCARD std::string SYSTEM_DEFAULT_DECLARE GetExecutableName();
    NODISCARD std::string SYSTEM_DEFAULT_DECLARE GetExecutableNameRemoveSuffix();
}

#endif  // SYSTEM_DYNAMIC_LINK_LIBRARY_TOOLS_H
