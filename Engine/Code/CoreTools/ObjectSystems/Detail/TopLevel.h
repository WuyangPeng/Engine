///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:23)

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
