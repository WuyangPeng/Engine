///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:49)

#ifndef INSTANCE_PLACEHOLDER_PLACEHOLDER_H
#define INSTANCE_PLACEHOLDER_PLACEHOLDER_H

#include "Instance/InstanceDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace Instance
{
    class INSTANCE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // INSTANCE_PLACEHOLDER_PLACEHOLDER_H
