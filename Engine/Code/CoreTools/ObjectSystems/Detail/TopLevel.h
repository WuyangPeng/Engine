//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/13 14:03)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_TOP_LEVEL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_TOP_LEVEL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE TopLevel
    {
    public:
        using ClassType = TopLevel;

    public:
        static std::string GetTopLevelDescription();
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_TOP_LEVEL_H
