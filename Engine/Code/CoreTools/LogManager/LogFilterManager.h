//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/15 11:46)

// ��־������������
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_FILTER_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_LOG_FILTER_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogFilterManager final
    {
    public:
        using ClassType = LogFilterManager;
        using String = System::String;

    public:
        [[nodiscard]] static String GetLogFilterDescribe(LogFilter logFilterType);
        [[nodiscard]] static LogFilter GetLogFilterType(const String& describe);
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_FILTER_MANAGER_H
