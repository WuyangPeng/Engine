///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:42)

#include "Network/NetworkExport.h"

#include "NetworkSockConnector.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"

Network::NetworkSockConnector::NetworkSockConnector() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkSockConnector)

bool Network::NetworkSockConnector::Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(sockStream, sockAddress);

    if (System::Connect(sockStream->GetNetworkSockStream(), &sockAddress->GetWinSockInternetAddress()))
        return true;
    else
        return false;
}

void Network::NetworkSockConnector::AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(eventInterface, sockStream, sockAddress);

    MAYBE_UNUSED const auto result = System::Connect(sockStream->GetNetworkSockStream(), &sockAddress->GetWinSockInternetAddress());
}

Network::NetworkSockConnector::SockConnectorSharedPtr Network::NetworkSockConnector::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}
