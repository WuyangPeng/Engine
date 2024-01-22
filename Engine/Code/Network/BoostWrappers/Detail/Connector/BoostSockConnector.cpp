/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:25)

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

using namespace std::literals;

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

bool Network::BoostSockConnector::Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(sockStream, sockAddress);

    auto& ioService = BASE_MAIN_MANAGER_SINGLETON.GetContext();

    boost::asio::ip::tcp::resolver resolver{ ioService };
    ErrorCodeType errorCode{};

    BoostSockConnectorHelper::PrintConnectorLog(synchronizeConnector.data(), AddressData{ *sockAddress });

    boost::asio::connect(sockStream->GetBoostSockStream(), resolver.resolve(sockAddress->GetBoostInternetAddress()), errorCode);

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

void Network::BoostSockConnector::AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(eventInterface, sockStream, sockAddress);

    auto& ioService = BASE_MAIN_MANAGER_SINGLETON.GetContext();

    boost::asio::ip::tcp::resolver resolver{ ioService };

    BoostSockConnectorHelper::PrintConnectorLog(asynchronousConnector.data(), AddressData{ *sockAddress });

    boost::asio::async_connect(sockStream->GetBoostSockStream(), resolver.resolve(sockAddress->GetBoostInternetAddress()), [eventInterface](const ErrorCodeType& errorCode, const BoostInternetAddressType& endpoint) {
        BoostSockConnectorHelper::EventFunction(errorCode, eventInterface, AddressData{ endpoint.address().to_string() + ":" + std::to_string(endpoint.port()), endpoint.port() });
    });
}

Network::BoostSockConnector::SockConnectorSharedPtr Network::BoostSockConnector::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}
