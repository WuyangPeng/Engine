///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.8 (2023/05/10 18:18)

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
