///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/02/23 14:43)

#ifndef CORE_TOOLS_BASE_UNIQUE_ID_SELECT_H
#define CORE_TOOLS_BASE_UNIQUE_ID_SELECT_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
    enum class UniqueIdSelect
    {
        Default = 0, 
        Object = 1,
        Entity = 2,
        Network = 3,
        Renderer = 4,
        ZipFile = 5,
        Max,
    };
}

#endif  // CORE_TOOLS_BASE_UNIQUE_ID_SELECT_H