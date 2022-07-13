///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/01 14:09)

#include "Network/NetworkExport.h"

#include "NetworkTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::NetworkTestExportMacroImpl::NetworkTestExportMacroImpl(int count) noexcept
    : mCount{ count }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkTestExportMacroImpl)

int Network::NetworkTestExportMacroImpl::GetCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Network::NetworkTestExportMacroImpl::SetCount(int count) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    mCount = count;
}
