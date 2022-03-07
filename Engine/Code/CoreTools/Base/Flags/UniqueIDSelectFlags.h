///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 14:27)

#ifndef CORE_TOOLS_BASE_UNIQUE_ID_SELECT_H
#define CORE_TOOLS_BASE_UNIQUE_ID_SELECT_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
    enum class UniqueIDSelect
    {
        Default = 0,
        MemoryInformation = 1,
        Object = 2,
        Entity = 3,
        Network = 4,
        Renderer = 5,
        ZipFile = 6,
        Max,
    };
}

#endif  // CORE_TOOLS_BASE_UNIQUE_ID_SELECT_H