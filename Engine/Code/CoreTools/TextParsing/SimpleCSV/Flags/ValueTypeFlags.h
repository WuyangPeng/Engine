///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/17 15:58)

#ifndef CORE_TOOLS_TEXT_PARSING_VALUE_TYPE_FLAGS_H
#define CORE_TOOLS_TEXT_PARSING_VALUE_TYPE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
    namespace SimpleCSV
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
}

#endif  // CORE_TOOLS_TEXT_PARSING_VALUE_TYPE_FLAGS_H