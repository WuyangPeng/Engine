///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/27 22:22)

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