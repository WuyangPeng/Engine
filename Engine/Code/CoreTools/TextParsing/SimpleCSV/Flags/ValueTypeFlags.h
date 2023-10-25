///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 14:55)

#ifndef CORE_TOOLS_TEXT_PARSING_VALUE_TYPE_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_VALUE_TYPE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools::SimpleCSV
{
    // ����Excel���ӱ��Ԫ�����Чֵ���͵�ö�١�
    enum class ValueType
    {
        Empty,
        Boolean,
        Integer,
        Float,
        Error,
        String
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_VALUE_TYPE_FLAGS_H