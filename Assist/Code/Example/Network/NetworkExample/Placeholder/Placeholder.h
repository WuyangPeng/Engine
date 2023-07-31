///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 11:19)

#ifndef NETWORK_EXAMPLE_PLACEHOLDER_H
#define NETWORK_EXAMPLE_PLACEHOLDER_H

#include "Example/Network/NetworkExample/NetworkExampleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace NetworkExample
{
    class NETWORK_EXAMPLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // NETWORK_EXAMPLE_PLACEHOLDER_H
