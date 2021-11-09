///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:20)

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
