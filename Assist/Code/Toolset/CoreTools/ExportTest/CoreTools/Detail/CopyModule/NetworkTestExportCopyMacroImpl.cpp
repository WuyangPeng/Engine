///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 09:09)

#include "Network/NetworkExport.h"

#include "NetworkTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::NetworkTestExportCopyMacroImpl::NetworkTestExportCopyMacroImpl(int count) noexcept
    : count{ count }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkTestExportCopyMacroImpl)

int Network::NetworkTestExportCopyMacroImpl::GetCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return count;
}

void Network::NetworkTestExportCopyMacroImpl::SetCount(int aCount) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    count = aCount;
}
