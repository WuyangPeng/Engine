//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 10:03)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H
#define SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H

#include "System/SystemDll.h"

#include "Fwd/DynamicLinkFlagsFwd.h"
#include "Using/LoadLibraryUsing.h"

namespace System
{
    // 加载和释放动态链接库。

    [[nodiscard]] DynamicLinkModule SYSTEM_DEFAULT_DECLARE LoadDynamicLibrary(const DynamicLinkCharType* fileName, LoadLibraryType flag) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE FreeDynamicLibrary(DynamicLinkModule module) noexcept;
    [[nodiscard]] DynamicLinkProcess SYSTEM_DEFAULT_DECLARE GetProcessAddress(DynamicLinkModule module, const char* processName) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE DisableThreadDynamicLibraryCalls(DynamicLinkModule module) noexcept;
}

#endif  // SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_H
