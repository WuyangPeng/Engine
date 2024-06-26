/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 16:33)

#ifndef SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_FLAGS_H
#define SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class ResourceEnum
    {
        Default = 0x0000,
        Ln = RESOURCE_ENUM_LN,
        Mui = RESOURCE_ENUM_MUI,
        MuiSystem = RESOURCE_ENUM_MUI_SYSTEM,
        Validate = RESOURCE_ENUM_VALIDATE,
        ModuleExact = RESOURCE_ENUM_MODULE_EXACT,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class ResourceEnum
    {
        Default = 0x0000,
        Ln = 0x0001,
        Mui = 0x0002,
        MuiSystem = 0x0004,
        Validate = 0x0008,
        ModuleExact = 0x0010,
    };

#endif  // SYSTEM_PLATFORM_WIN32

}

#endif  // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_FLAGS_H
