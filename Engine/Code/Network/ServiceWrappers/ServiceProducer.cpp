/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:54)

#include "Network/NetworkExport.h"

#include "ServiceProducer.h"
#include "Detail/ServiceProducerFactory.h"
#include "Detail/ServiceProducerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ServiceProducer::ServiceProducer(ServiceSession& serviceSession, const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, serviceSession, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ServiceProducer)

void Network::ServiceProducer::SendTextMessage(const std::string& message)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->SendTextMessage(message);
}
