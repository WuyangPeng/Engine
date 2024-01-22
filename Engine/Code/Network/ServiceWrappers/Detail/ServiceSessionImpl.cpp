/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:56)

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
