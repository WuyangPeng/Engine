//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/21 10:24)

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
        [[nodiscard]] static std::string GetTopLevelDescription();
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_TOP_LEVEL_H
