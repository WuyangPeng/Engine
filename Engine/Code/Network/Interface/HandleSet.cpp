/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:28)

#include "Network/NetworkExport.h"

#include "HandleSet.h"
#include "Detail/HandleSetFactory.h"
#include "Detail/HandleSetImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Network, HandleSet)

Network::HandleSet::HandleSet(const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSet)

void Network::HandleSet::SetBit(ACEHandleType handle)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->SetBit(handle);
}

int64_t Network::HandleSet::GetMaxSet() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetMaxSet();
}

Network::SockFdSet* Network::HandleSet::GetFdSet()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->GetFdSet();
}

void Network::HandleSet::Sync(ACEHandleType maxHandle)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->Sync(maxHandle);
}

bool Network::HandleSet::IsSet(ACEHandleType handle) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsSet(handle);
}

void Network::HandleSet::ClearBit(ACEHandleType handle)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->ClearBit(handle);
}

const Network::ACEHandleSet& Network::HandleSet::GetACEHandleSet() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetACEHandleSet();
}

bool Network::HandleSet::IsFdSetFull() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsFdSetFull();
}

int Network::HandleSet::IsFdSetCount() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsFdSetCount();
}

bool Network::HandleSet::IsFdSetCountIsOne() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsFdSetCountIsOne();
}

bool Network::HandleSet::Select(int width)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->Select(width);
}
