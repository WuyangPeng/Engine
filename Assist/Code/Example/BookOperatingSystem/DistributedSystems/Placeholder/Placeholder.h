///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/28 22:20)

#ifndef DISTRIBUTED_SYSTEMS_PLACEHOLDER_H
#define DISTRIBUTED_SYSTEMS_PLACEHOLDER_H

#include "Example/BookOperatingSystem/DistributedSystems/DistributedSystemsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace DistributedSystems
{
    class DISTRIBUTED_SYSTEMS_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // DISTRIBUTED_SYSTEMS_PLACEHOLDER_H
