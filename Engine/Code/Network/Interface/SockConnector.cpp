//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 13:12)

#include "Network/NetworkExport.h"

#include "SockConnector.h"
#include "Detail/SockConnectorFactory.h"
#include "Detail/SockConnectorImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

DELAY_COPY_CONSTRUCTION_CLONE_DEFINE(Network, SockConnector)

Network::SockConnector::SockConnector(const ConfigurationStrategy& configurationStrategy)
    : m_Impl{ SockConnectorFactory::Create(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, SockConnector)

bool Network::SockConnector::Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Connect(sockStream, sockAddress);
}

void Network::SockConnector::AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->AsyncConnect(eventInterface, sockStream, sockAddress);
}
