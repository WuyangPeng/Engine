///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 15:46)

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
