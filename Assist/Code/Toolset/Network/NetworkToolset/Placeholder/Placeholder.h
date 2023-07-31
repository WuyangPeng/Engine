///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 10:38)

#ifndef NETWORK_TOOLSET_PLACEHOLDER_H
#define NETWORK_TOOLSET_PLACEHOLDER_H

#include "Toolset/Network/NetworkToolset/NetworkToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace NetworkToolset
{
    class NETWORK_TOOLSET_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // NETWORK_TOOLSET_PLACEHOLDER_H
