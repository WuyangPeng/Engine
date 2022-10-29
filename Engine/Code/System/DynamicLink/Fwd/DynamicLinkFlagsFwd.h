///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/08 21:47)

#ifndef SYSTEM_DYNAMIC_LINK_DYNAMIC_LINK_FLAGS_FWD_H
#define SYSTEM_DYNAMIC_LINK_DYNAMIC_LINK_FLAGS_FWD_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    // EnumResourceTools
    enum class ResourceEnum;

    // GetModuleHandle
    enum class GetModuleHandleType;

    // LoadLibrary
    enum class LoadLibraryType : uint32_t;
    enum class DllMain;
}

#endif  // SYSTEM_DYNAMIC_LINK_DYNAMIC_LINK_FLAGS_FWD_H