///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.8 (2023/05/10 18:21)

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
