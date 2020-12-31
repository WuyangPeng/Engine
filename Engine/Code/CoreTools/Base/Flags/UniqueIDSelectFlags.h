//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 9:51)

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
        ResourceHandle = 3,
        Resource = 4,
        Entity = 5,
        Network = 6,
        Renderer = 7,
        Max,
    };
}

#endif  // CORE_TOOLS_BASE_UNIQUE_ID_SELECT_H