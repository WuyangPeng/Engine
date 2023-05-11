///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/14 10:23)

#ifndef ACTIVITY_PLACEHOLDER_PLACEHOLDER_H
#define ACTIVITY_PLACEHOLDER_PLACEHOLDER_H

#include "Interface/InterfaceDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace Interface
{
    class ACTIVITY_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ACTIVITY_PLACEHOLDER_PLACEHOLDER_H