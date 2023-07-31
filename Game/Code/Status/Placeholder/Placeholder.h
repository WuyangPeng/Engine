///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:27)

#ifndef STATUS_PLACEHOLDER_PLACEHOLDER_H
#define STATUS_PLACEHOLDER_PLACEHOLDER_H

#include "Status/StatusDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace Status
{
    class STATUS_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // STATUS_PLACEHOLDER_PLACEHOLDER_H
