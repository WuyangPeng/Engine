/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:56)

#include "Network/NetworkExport.h"

#include "ServiceSessionImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ServiceSessionImpl::ServiceSessionImpl(ConfigurationStrategy configurationStrategy) noexcept
    : configurationStrategy{ std::move(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ServiceSessionImpl::~ServiceSessionImpl() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ServiceSessionImpl::ServiceSessionImpl(ServiceSessionImpl&& rhs) noexcept
    : configurationStrategy{ std::move(rhs.configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ServiceSessionImpl& Network::ServiceSessionImpl::operator=(ServiceSessionImpl&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    configurationStrategy = std::move(rhs.configurationStrategy);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ServiceSessionImpl)

void Network::ServiceSessionImpl::SendTextMessage(const std::string& message)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(message);

    CoreTools::DisableNoexcept();
}

void Network::ServiceSessionImpl::Response(const std::function<void(const std::string&)>& processDataCallback)
{
    System::UnusedFunction(processDataCallback);

    CoreTools::DisableNoexcept();
}

void Network::ServiceSessionImpl::Run()
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

void Network::ServiceSessionImpl::Stop()
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

std::string Network::ServiceSessionImpl::GetHost() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return configurationStrategy.GetHost();
}

int Network::ServiceSessionImpl::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return configurationStrategy.GetPort();
}
