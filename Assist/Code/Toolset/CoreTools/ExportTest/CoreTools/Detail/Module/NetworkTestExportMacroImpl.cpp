/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:10)

#include "Network/NetworkExport.h"

#include "NetworkTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::NetworkTestExportMacroImpl::NetworkTestExportMacroImpl(int count) noexcept
    : count{ count }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkTestExportMacroImpl)

int Network::NetworkTestExportMacroImpl::GetCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return count;
}

void Network::NetworkTestExportMacroImpl::SetCount(int aCount) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    count = aCount;
}
