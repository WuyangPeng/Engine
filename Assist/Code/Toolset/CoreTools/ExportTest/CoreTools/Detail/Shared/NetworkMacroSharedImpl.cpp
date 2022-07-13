///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 19:01)

#include "Network/NetworkExport.h"

#include "NetworkMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::NetworkMacroSharedImpl::NetworkMacroSharedImpl(int count) noexcept
    : mCount{ count }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkMacroSharedImpl)

int Network::NetworkMacroSharedImpl::GetCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Network::NetworkMacroSharedImpl::SetCount(int count) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    mCount = count;
}
