///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.8 (2023/05/10 18:21)

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
