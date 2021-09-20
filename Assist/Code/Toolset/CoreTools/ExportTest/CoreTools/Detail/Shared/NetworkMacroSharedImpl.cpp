///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 22:03)

#include "Network/NetworkExport.h"

#include "NetworkMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::NetworkMacroSharedImpl::NetworkMacroSharedImpl(int count) noexcept
    : m_Count{ count }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkMacroSharedImpl)

int Network::NetworkMacroSharedImpl::GetCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Network::NetworkMacroSharedImpl::SetCount(int count) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    m_Count = count;
}
