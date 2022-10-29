///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:35)

#include "Network/NetworkExport.h"

#include "NetworkPerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::NetworkPerformanceUnsharedMacroImpl::NetworkPerformanceUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkPerformanceUnsharedMacroImpl)

int Network::NetworkPerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return count;
}

 