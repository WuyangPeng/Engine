///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.2 (2021/08/27 22:22)

#ifndef COMPUTER_NETWORKS_PLACEHOLDER_H
#define COMPUTER_NETWORKS_PLACEHOLDER_H

#include "Example/BookOperatingSystem/ComputerNetworks/ComputerNetworksDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ComputerNetworks
{
    class COMPUTER_NETWORKS_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // COMPUTER_NETWORKS_PLACEHOLDER_H
