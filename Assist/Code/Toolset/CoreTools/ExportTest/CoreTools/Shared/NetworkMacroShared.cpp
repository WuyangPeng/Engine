///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:25)

#include "Network/NetworkExport.h"

#include "NetworkMacroShared.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Shared/NetworkMacroSharedImpl.h"

Network::NetworkMacroShared::NetworkMacroShared(int count)
    : impl{ count }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkMacroShared)

int Network::NetworkMacroShared::GetCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Network::NetworkMacroShared::SetCount(int count) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Network::NetworkMacroShared::GetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}