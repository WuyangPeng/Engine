///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:54)

#ifndef INTERFACE_PLACEHOLDER_PLACEHOLDER_H
#define INTERFACE_PLACEHOLDER_PLACEHOLDER_H

#include "Interface/InterfaceDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace Interface
{
    class INTERFACE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // INTERFACE_PLACEHOLDER_PLACEHOLDER_H
