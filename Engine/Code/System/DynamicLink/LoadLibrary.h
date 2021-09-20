///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/24 15:02)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H
#define SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H

#include "System/SystemDll.h"

#include "Fwd/DynamicLinkFlagsFwd.h"
#include "Using/LoadLibraryUsing.h"

namespace System
{
    // 加载和释放动态链接库。

    NODISCARD DynamicLinkModule SYSTEM_DEFAULT_DECLARE LoadDynamicLibrary(const DynamicLinkCharType* fileName, LoadLibraryType flag) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FreeDynamicLibrary(DynamicLinkModule module) noexcept;
    NODISCARD DynamicLinkProcess SYSTEM_DEFAULT_DECLARE GetProcessAddress(DynamicLinkModule module, const char* processName) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE DisableThreadDynamicLibraryCalls(DynamicLinkModule module) noexcept;
}

#endif  // SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H
