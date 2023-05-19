///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 17:01)

#include "Network/NetworkExport.h"

#include "Producer.h"
#include "Detail/ProducerFactory.h"
#include "Detail/ProducerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::Producer::Producer(const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, Producer)

void Network::Producer::SendServerMessage(const String& address, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->SendServerMessage(address, message);
}
