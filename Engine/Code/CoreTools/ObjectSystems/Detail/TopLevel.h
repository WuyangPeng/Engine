///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 14:40)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_TOP_LEVEL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_TOP_LEVEL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE TopLevel final
    {
    public:
        using ClassType = TopLevel;

    public:
        NODISCARD constexpr static std::string_view GetTopLevelDescription()
        {
            using namespace std::literals;

            return "Top Level"sv;
        }
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_TOP_LEVEL_H
