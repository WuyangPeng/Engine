/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:57)

#include "Network/NetworkExport.h"

#include "ServiceProducerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ServiceProducerImpl::ServiceProducerImpl(ConfigurationStrategy configurationStrategy) noexcept
    : configurationStrategy{ std::move(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ServiceProducerImpl::~ServiceProducerImpl() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ServiceProducerImpl::ServiceProducerImpl(ServiceProducerImpl&& rhs) noexcept
    : configurationStrategy{ std::move(rhs.configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ServiceProducerImpl& Network::ServiceProducerImpl::operator=(ServiceProducerImpl&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    configurationStrategy = std::move(rhs.configurationStrategy);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ServiceProducerImpl)

void Network::ServiceProducerImpl::SendTextMessage(ServiceSession& serviceSession, const std::string& message)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(serviceSession, message);

    CoreTools::DisableNoexcept();
}
