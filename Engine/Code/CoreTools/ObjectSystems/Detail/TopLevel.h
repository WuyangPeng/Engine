/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 22:10)

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
