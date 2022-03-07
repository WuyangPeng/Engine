///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/23 0:03)

#include "Network/NetworkExport.h"

#include "BoostSockConnector.h"
#include "BoostSockConnectorHelper.h"
#include "System/Helper/PragmaWarning/AsioConnect.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/Data/AddressData.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"

using std::make_shared;
using std::to_string;
using namespace std::literals;
using boost::asio::async_connect;
using boost::asio::connect;
using TcpType = boost::asio::ip::tcp;

namespace
{
    constexpr auto synchronizeConnector = SYSTEM_TEXT("准备进行同步连接，地址："sv);
    constexpr auto asynchronousConnector = SYSTEM_TEXT("准备进行异步连接，地址："sv);
    constexpr auto synchronizeConnectorSuccess = SYSTEM_TEXT("同步连接成功，地址："sv);
}

Network::BoostSockConnector::BoostSockConnector() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostSockConnector)

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
bool Network::BoostSockConnector::Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto& ioService = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    TcpType::resolver resolver{ ioService };
    ErrorCodeType errorCode;

    BoostSockConnectorHelper::PrintConnectorLog(synchronizeConnector.data(), AddressData{ *sockAddress });

    connect(sockStream->GetBoostSockStream(), resolver.resolve(sockAddress->GetBoostInetAddress()), errorCode);

    if (errorCode == ErrorCodeType{})
    {
        BoostSockConnectorHelper::PrintConnectorSuccessLog(synchronizeConnectorSuccess.data(), AddressData{ *sockAddress });

        return true;
    }
    else
    {
        return false;
    }
}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
void Network::BoostSockConnector::AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto& ioService = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    TcpType::resolver resolver{ ioService };

    BoostSockConnectorHelper::PrintConnectorLog(asynchronousConnector.data(), AddressData{ *sockAddress });

    async_connect(sockStream->GetBoostSockStream(), resolver.resolve(sockAddress->GetBoostInetAddress()), [eventInterface](const ErrorCodeType& errorCode, const BoostInetAddressType& endpoint) {
        BoostSockConnectorHelper::EventFunction(errorCode, eventInterface, AddressData{ endpoint.address().to_string() + ":" + to_string(endpoint.port()), endpoint.port() });
    });
}
#include STSTEM_WARNING_POP

Network::BoostSockConnector::SockConnectorSharedPtr Network::BoostSockConnector::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}
