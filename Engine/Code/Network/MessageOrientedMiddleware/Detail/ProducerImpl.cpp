/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:26)

#include "Network/NetworkExport.h"

#include "ProducerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ProducerImpl::ProducerImpl(ConfigurationStrategy configurationStrategy) noexcept
    : configurationStrategy{ std::move(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ProducerImpl::~ProducerImpl() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ProducerImpl::ProducerImpl(ProducerImpl&& rhs) noexcept
    : configurationStrategy{ std::move(rhs.configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ProducerImpl& Network::ProducerImpl::operator=(ProducerImpl&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    configurationStrategy = std::move(rhs.configurationStrategy);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ProducerImpl)
